#ifndef _CMDLINE_H
#define _CMDLINE_H

#include <vector>
#include <iterator>
#include <string.h>

using namespace std;

class CmdLine {
private:	
	vector<string>* options; // Alle Parameter die mit einem Bindestrich beginnen wie: "-p"
	vector<string>* arguments; // alle anderen Parameter ohne Bindestrich, z.B. Dateinamen "Index.txt"
public:
	CmdLine(int argc, char *argv[]);
	~CmdLine();
	
	// info
	void printOptions();
	void printArguments();
};

#endif	/* _CMDLINE_H */