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
#include <sstream>

using namespace std;

// TODO comment type defs
typedef string word; 
/**
 * a file is a string.
 */						// a word is a string
typedef string file;						// a file is a string
typedef int line_number; 					// a line number is an integer

typedef set<line_number> line_numbers; 		// a set of line numbers
typedef map<file, line_numbers* > files; 	// maps a file to a list of line_numbers
typedef map<word, files*> words; 			// maps a word to a map of files

class Index {
private:	
	// this map stores for each word, another map
	words *_word_index; // stores a pointer to map_files
	
	void init();
	
	/**
	 * Read content from a given File.
	 * 
	 */	
	void readFiles(vector<file> files);
	
	/**
	 * Read each line from file.
	 * Then seperate words from each line. 
	 * Insert word (with line number and filename) in index map.
	 * @param file The file to be read.
	 */
	void readFile(file f);
	
	/**
	 * To be implement!
	 * Write index to file.
	 */
	void writeFile(file out_file);
	
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
	vector<word> extractAllWordsFromLine(string line);
	
	/**
	 * check if the word is valid (christian)
	 */
	bool isWordValid(word w);
	
	bool isCharValid(char c);
	
	bool isFirstCharValid(char c);
	
	void addToIndex(word w, file f, line_number l);
	
	void addToIndex(vector<string> words, file f, line_number l);
	
	// To be implement (alexander)
	words* parseIndexFile(file *f);
	
	/**
	 * Read all lines within a file.
	 * @return vector<string>* All lines within the file.
	 */
	vector<string>* readAllLines(file f);

public:
	/**
	 * Create an object.
	 */
	Index();
	
	/**
	 * Destroy the object.
	 */
	~Index();	
	
	/**
	 * To be implement!
	 * Print the given index file in shell.
	 * @param index File with the index.
	 */
	void print(file *f);
	
	/**
	 * Create a new Index.
	 * @param out The outputfile to write the index in.
	 * @param in_files Reads from these input files to create an index.
	 */
	void createIndex(file out, vector<file> in_files);
	
	/**
	 * To be implement! (christian)
	 * Prints the index for the given word in shell.
	 * @param w The word the index is printed.
	 */
	void printIndexForWord(word *w);
	
	/**
	 * To be implement! (christan)
	 * Print all words which matches with the first characters the given string.
	 * @param characters The letters the word must fit at the beginning.
	 */
	void printWordsMatchesCharacters(string *characters);
	
	/**
	 * To be implement! (christian)
	 * Print all words in given file in shell.
	 * @param f Print all words occuring in the given file.
	 */
	void printIndexForFile(file *f);
};

#endif	/* _INDEX_H */