/** Class CmdLine
 *
 *  This class split the command line parameters into options and arguments.
 *
 *  author  Christian Bunk
 *  date    3.5.2011
 *  version 0.1
 */

#ifndef _CMDLINE_H
#define _CMDLINE_H

#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

typedef map<string, string> options; // option value
typedef vector<string> arguments; // list of arguments

class CmdLine {
private:	
	options *opt; // Alle Parameter die mit einem Bindestrich beginnen wie: "-p"
	arguments *arg; // alle anderen Parameter ohne Bindestrich, z.B. Dateinamen "Index.txt"
	
	/**
	 * 
	 */
	bool isOptionValid(const char c); 
	
	/**
	 * 
	 */
	bool optionNeedValue(const char c);
	
	/**
	 *
	 */
	bool optionNeedArguments(const char c);
	
	string charToString(const char c);
	
	void insertToOptions(string key, string value);

public:
	/**
	 * Create new CmdLine.
	 * @param argc number of parameter.
	 * @param argv parameter in an array.
	 */ 
	CmdLine(int argc, char *argv[]);
	~CmdLine();
	
	/**
	 * Print all options.
	 */
	void printOptions();
	
	/**
	 * Print all Arguments.
	 */
	void printArguments();
	
	/** 
	 * Check if there are options or not.
	 * @return true if options exists, otherwhise false.
	 */ 
	bool hasOptions();
	
	/**
	 * Check if there are arguments or not.
	 * @return true if arguments exists, otherwise false.
	 */
	bool hasArguments();
	
	map<string,string> getOptions();
	
	vector<string> getArguments();
};

#endif	/* _CMDLINE_H */