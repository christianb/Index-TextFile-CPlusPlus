/** Class Index
 *
 *  This class creates an index of different input files.
 *
 *  author  Christian Bunk
 *  date    3.5.2011
 *  version 0.1
 */

#ifndef _INDEX_H
#define _INDEX_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <regex.h>

using namespace std;

typedef string word;
typedef string file;
typedef int line_number;
typedef set<line_number> line_numbers; // stores all line numbers 
typedef map<file, line_numbers* > files;
typedef map<word, files*> words; // stores a pointer to list's

class Index {
private:
	// includes all valid characters
	set<char> *_validCharacters;
	set<char> *_validFirstWordChar;
	
	// this map stores for each word, another map
	words *_word_index; // stores a pointer to map_files
	
	void init();
	
	/**
	 * Read content from a given File.
	 * First read lines, then seperate words from each line.
	 */	
	void readFile(vector<string> *in_files);
	
	/**
	 * Write content within *_words into a file.
	 */
	void writeFile(string *out_file);
	
	/**
	 * Add a new Word and return the iterator to that position.
	 * If the word is in map already, then return the iterator with position of that word.
	 * @return map<word, map_files>::iterator with the position of the word in map.
	 */
	words::iterator addWord(word w);
	
	/**
	 * Add a file to a word and returns the iterator to the position of the file key
	 * If the file is already in map, then the iterator points to that file.
	 * 
	 * @param it the iterator pointing to the word where the fill will be added.
	 * @return map<file, list<line> >::iterator pointing to the file.
	 */
	files::iterator addFile(words::iterator it, file f);
	
	/**
	 * Adds a line to a given file (iterator).
	 * @param file_it
	 * @param l
	 * @return
	 */
	void addLine(files::iterator file_it, line_number l);
	
	/**
	 * Exctract all words from a line.
	 * Rules: each empty character will be ignored
	 */
	vector<string> extractAllWordsFromLine(string line);
	
	/**
	 * check if the word is valid
	 */
	bool isWordValid(word *w);
	
	bool isCharValid(char c);
	
	void addToIndex(word w, file f, line_number l);
	
	void addToIndex(vector<string> words, file f, line_number l);
	
	

public:
	/**
	 * Creates an Indexfile.
	 * @param outputfile the destination file
	 * @param inputfiles from these files the index will be created 
	 */
	Index(string *outputfile, vector<string> *inputfile);
	
	~Index();	
};

#endif	/* _INDEX_H */