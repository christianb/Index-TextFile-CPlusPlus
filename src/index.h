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

using namespace std;

class Index {
private:
	vector<string> *_words;
	
	/**
	 * Read content from a given File.
	 * Saves them into the member *_words;
	 */	
	void readFile(vector<string> *in_files);
	
	/**
	 * Write content within *_words into a file.
	 */
	void writeFile(string *out_file);

public:
	Index();
	~Index();
	
	/**
	 * Creates an Indexfile.
	 * @param outputfile the destination file
	 * @param inputfiles from these files the index will be created 
	 */
	void createIndex(string *out_files, vector<string> *in_files);
	
};

#endif	/* _INDEX_H */