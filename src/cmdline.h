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
#include <string.h>

#include <iostream>

using namespace std;

typedef vector<string> parameter;
typedef parameter options;
typedef parameter arguments;

class CmdLine {
private:	
	options *opt; // Alle Parameter die mit einem Bindestrich beginnen wie: "-p"
	arguments *arg; // alle anderen Parameter ohne Bindestrich, z.B. Dateinamen "Index.txt"

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
	
	vector<string>* getOptions();
	
	// Instead we could return an Iterator, so we don't give the container back
	// the caller must not know something about the container itself.
	// He can use the iterator and is fine.
	vector<string>* getArguments();
};

#endif	/* _CMDLINE_H */