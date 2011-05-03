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
	void readFile(string *in_file);
	
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
	void createIndex(string *outputfile, string *inputfile);
	
};

#endif	/* _INDEX_H */