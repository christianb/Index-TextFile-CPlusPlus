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