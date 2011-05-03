#include "Controller.h"
#include "cmdline.h"
#include "index.h"

Controller::Controller(int argc, char *argv[]) {
	cout << "Konstruktor: Controller" << endl;
	
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
}

Controller::~Controller() {
	cout << "Destruktor: Controller" << endl;
}