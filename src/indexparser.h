/** Class Index
 *
 *  This class creates an index of different input files.
 *
 *  author  Christian Bunk
 *  date    3.5.2011
 *  version 0.1
 */

#ifndef _INDEXPARSER_H
#define _INDEXPARSER_H

#include <string>
#include <iostream>

using namespace std;

class IndexParser {
private:	

	string *testword;  // This variable is only for testing of class construct

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
	IndexParser();
	
	/**
	 * Destroy the object.
	 */
	~IndexParser();	
};

#endif	/* _INDEXPARSER_H */
