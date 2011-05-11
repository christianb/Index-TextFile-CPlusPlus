
using namespace std;

#include "cmdline.h"

/**
 * Konstruktor
 */
CmdLine::CmdLine(int argc, char *argv[]) {	
	opt = new options;
	arg = new arguments;

	// if there is at least one parameter
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			// wenn der parameter eine option ist (also ein Bindestrich "-" enthält)
			size_t found;
			string s = string(argv[i]);
			found=s.find("-");
			
			// insert options
			if (found!=string::npos) {
				opt->push_back(string(argv[i]));
			} else {
				// insert arguments
				arg->push_back(string(argv[i]));
			}
		}
	}
}


CmdLine::~CmdLine() {
	delete opt;
	delete arg;
}

void CmdLine::printOptions() {
	for (vector<string>::iterator it = opt->begin(); it!=opt->end(); ++it) {
	    cout << *it << endl;
	}
}

void CmdLine::printArguments() {
	for (vector<string>::iterator it = arg->begin(); it!=arg->end(); ++it) {
	    cout << *it << endl;
	}
}

bool CmdLine::hasOptions() {	
	return !opt->empty();
}

bool CmdLine::hasArguments() {
	return !arg->empty();
}

vector<string> CmdLine::getOptions() {
	return *opt;
}

vector<string> CmdLine::getArguments() {
	return *arg;
}