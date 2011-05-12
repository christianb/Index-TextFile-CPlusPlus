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
	
	/**
	 * Add a word into the index, corresponding to a file and a line number.
	 * This mehtod is used by addToIndex(vector<word>, file, line_number)
	 * @param w
	 * @param f
	 * @param l
	 */
	void addToIndex(word w, file f, line_number l);
	
	/**
	 * Add a vector of words into the index, corresponding to a file and a line number.
	 * Use the method addToIndex(word, file, line_number)
	 * This method is used when the index is created.
	 * @param words
	 * @param f
	 * @param l
	 */
	void addToIndex(vector<word> words, file f, line_number l);
	
	// To be implement (alexander)
	words* parseIndexFile(file *f);
	
	/**
	 * Read all lines within a file.
	 * @return vector<string>* All lines within the file.
	 */
	vector<string>* readAllLines(file f);
	
	/**
	 * Converts a set of line numbers into a string.
	 * @param l_set The set with line numbers.
	 * @return string The string with line numbers.
	 */
	string linesToString(line_numbers *l_set);
	
	/**
	 * Convert a single line number into a string.
	 * @param l
	 * @return string
	 */
	string lineToString(line_number l);
	
	/**
	 * Converts a file map, into a string.
	 * @param f_map
	 * @return string
	 */
	string filesToString(files *f_map);
	
	/**
	 * Converts a file and its line numbers into a string.
	 * @param f
	 * @param l
	 * return string
	 */
	string fileToString(file f, line_numbers *l);
	
	/**
	 * Get a string with the index of all words.
	 */
	string wordsToString();
	
	string wordToString(word w, files *f);

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
	 * This method insert a w
	 */
	void addToIndex(word w, file f, line_numbers lines);
	
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
	 * Prints the index for the given word.
	 * Called with parameter -q
	 * @param w The word the index is printed for.
	 */
	void printIndexForWord(word w);
	
	/**
	 * Print all words which matches with the first characters the given string.
	 * Called with parameter -s
	 * @param characters The letters the word must fit at the beginning.
	 */
	void printWordsMatchesCharactersAtBeginning(string characters);
	
	/**
	 * Print all words which matches the given string anywhere.
	 * This is not a required method!
	 * @param characters
	 */
	void printWordsMatchesCharactersAnywhere(string characters);
	
	/**
	 * Print all words in given file in shell.
	 * Called with parameter -t
	 * @param f Print all words occuring in the given file.
	 */
	void printIndexForFile(file f);
	
	/**
	 * print the index for a given outputfile.
	 * Called with parameter -p
	 * TODO: update when parser is ready!
	 */
	void printIndexFromOutputFile(file outputfile);
};

#endif	/* _INDEX_H */