#include <iostream>


using namespace std;

#include "cmdline.h"

/**
 * Konstruktor
 */
CmdLine::CmdLine(int argc, char *argv[]) {
	cout << "Konstruktor CmdLine" << endl;
	
	options = new vector<string>();
	arguments = new vector<string>();

	// if there are at least one parameter
	if (argc > 1) {
		// puts all command line parameters in vector
		for (int i = 1; i < argc; i++) {
			// wenn der parameter eine option ist (also ein Bindestrich "-" enthält)
			size_t found;
			string s = string(argv[i]);
			found=s.find("-");
			
			/*cout << "Gib die Parameter aus Zielenweise" << endl;
			for (string::iterator it = s.begin(); it!=s.end(); ++it) {
			    cout << *it << endl;
			}*/
			
			// insert options
			if (found!=string::npos) {
				options->push_back(string(argv[i]));
			} else {
				// insert arguments
				arguments->push_back(string(argv[i]));
			}
		}
	}
}

/**
 * Destruktor.
 * Free all member.
 */
CmdLine::~CmdLine() {
	cout << "Destruktor CmdLine" << endl;
	delete options; // free vector
	delete arguments;
}

void CmdLine::printOptions() {
	cout << "Options:" << endl;
	// Gib alle options im vector aus.
	// nutze einen Iterator.
	for (vector<string>::iterator it = options->begin(); it!=options->end(); ++it) {
	    cout << *it << endl;
	}
}

void CmdLine::printArguments() {
	cout << "Arguments:" << endl;
	// Gib alle options im vector aus.
	// nutze einen Iterator.
	for (vector<string>::iterator it = arguments->begin(); it!=arguments->end(); ++it) {
	    cout << *it << endl;
	}
}