#include <iostream>
#include "cmdline.h"
#include "index.h"

int main (int argc, char *argv[]) {
	CmdLine *params = new CmdLine(argc, argv);
	params->printOptions();
	params->printArguments();
	
	//cout << "has options? " << params->hasOptions() << endl;
	string *out = new string("output.txt");
	
	vector<string> *in_files = new vector<string>();
	
	in_files->push_back(string("input2.txt"));
	in_files->push_back(string("input.txt"));
	in_files->push_back(string("input3.txt"));
	
	Index *index = new Index();
	index->createIndex(out,in_files);
	
	delete index;
	return EXIT_SUCCESS;
}