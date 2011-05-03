#include "Controller.h"
#include "cmdline.h"
#include "index.h"

Controller::Controller(int argc, char *argv[]) {
	cout << "Konstruktor: Controller" << endl;
	
	// read command line parameters
	CmdLine *params = new CmdLine(argc, argv);
	params->printOptions();
	params->printArguments();
	
	vector<string> *options = params->getOptions();
	for (vector<string>::iterator it = options->begin(); it!=options->end(); ++it) {
	    cout << "options within cmdline: " << *it << endl;
	}
	
	vector<string> *in_files = params->getArguments();
	
	string *out = new string("output.txt");
	/*
	vector<string> *in_files = new vector<string>();
	in_files->push_back(string("input2.txt"));
	in_files->push_back(string("input.txt"));
	in_files->push_back(string("input3.txt"));
	*/
	Index *index = new Index();
	index->createIndex(out,in_files);
	
	delete index;
}

Controller::~Controller() {
	cout << "Destruktor: Controller" << endl;
}