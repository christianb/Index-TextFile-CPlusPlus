/** Class FileUtil
 *
 *  This class provides methods to read content from file and vice versa.
 *
 *  author  Christian Bunk
 *  date    15.5.2011
 *  version 0.1
 */

#ifndef _FILETUIL_H
#define _FILEUTIL_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

class FileUtil {
public:	
	/**
	 * Read content from a given File.
	 * returns a map with the file nameas the key and the content of the file as the value
	 */	
	map<string, vector<string>* > readFiles(vector<string> files);
	
	/**
	 * Write content to file.
	 * @param out_file The file where the content will be written.
	 * @param content The content to be written into file.
	 */
	void writeFile(string out_file, string content);

private:
	/**
	 * Read all lines within a file.
	 * @return vector<string>* All lines within the file.
	 */
	vector<string>* readAllLinesFromFile(string f);
};

#endif	/* _FILEUTIL_H */
