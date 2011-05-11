/** Class Index
 *
 *  This class creates an index of different input files.
 *
 *  author  Alexander Miller
 *  date    11.5.2011
 *  version 0.1
 */

#ifndef _INDEXPARSER_H
#define _INDEXPARSER_H

#include <string>
#include <iostream>
#include "index.h"

using namespace std;

class IndexParser {
private:	

	string *testword;  // This variable is only for testing of class construct

	Index *index; // this is our reference to the index instance
	
	/**
	 * Read each line from given index file.
	 * Parse word, file and index from each line. 
	 * Insert parsed data in index map.
	 * @param index_file  index file to be read.
	 */
	void readIndexFile(string index_file);  

	/**
	 * Print Index parsed from given IndexFile.
	 */
	void printIndex();

public:
	/**
	 * Create an object.
	 */
	IndexParser(Index *index);
	
	/**
	 * Destroy the object.
	 */
	~IndexParser();	
};

#endif	/* _INDEXPARSER_H */
