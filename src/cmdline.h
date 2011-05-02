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
	
	options getOptions() {
		return *opt;
	}
};

#endif	/* _CMDLINE_H */