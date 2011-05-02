#include <iostream>
#include "cmdline.h"
#include "index.h"

int main (int argc, char *argv[]) {
	CmdLine *params = new CmdLine(argc, argv);
	params->printOptions();
	params->printArguments();
	
	//cout << "has options? " << params->hasOptions() << endl;
	string *out = new string("output.txt");
	string *in = new string("input.txt");
	Index *index = new Index();
	index->createIndex(out,in);
	return EXIT_SUCCESS;
}