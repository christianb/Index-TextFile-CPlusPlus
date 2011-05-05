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
	
	vector<string>::iterator position = find(options->begin(), options->end(), "-i") ;
	if (position != options->end()) {
		cout << "Erstelle Index!" << endl;
		
		//cout << "Der Parameter -i wurde an Position " << (position - options->begin()) << " gefunden!" << endl ;
		// create index
		vector<string> *in_files = new vector<string>();
		
		// before we can delete the params instance, we must assign the arguments in
		// another pointer to prevent segmentation fault!
		in_files->assign(params->getArguments()->begin(), params->getArguments()->end());

		// this instance is no longer needed. we swaped the content of the arguments pointer
		// so this instance can safely deleted
		delete params;
		
		string *out = new string("output.txt");
		/*
		vector<string> *in_files = new vector<string>();
		in_files->push_back(string("input2.txt"));
		in_files->push_back(string("input.txt"));
		in_files->push_back(string("input3.txt"));
		*/
		Index *index = new Index(out,in_files);

		delete index;
	} else {
		position = find(options->begin(), options->end(), "-p") ;
		if (position != options->end()) {
			cout << "Ausgabe der Indexliste am Terminal" << endl;
		}
	}

}

Controller::~Controller() {
	cout << "Destruktor: Controller" << endl;
}