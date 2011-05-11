#include "controller.h"
#include "cmdline.h"
#include "index.h"
#include <algorithm>

Controller::Controller(int argc, char *argv[]) {
	cout << "Konstruktor: Controller" << endl;
	
	// read command line parameters
	CmdLine *params = new CmdLine(argc, argv);
	params->printOptions();
	params->printArguments();
	
	vector<string> *options = params->getOptions();
	
	// input files
	vector<string> *in_files = new vector<string>();

	// before we can delete the params instance, we must assign the arguments in
	// another pointer to prevent segmentation fault!
	in_files->assign(params->getArguments()->begin(), params->getArguments()->end());

	string *out =  new string(*in_files->begin());
	in_files->erase(in_files->begin());
	
	Index *index = new Index();

	// prüfen wie viele options angegeben wurden und entsprechend Meldung ausgeben
	if (options->size() > 1) {
		// Fehlermeldung...
		
		// delete pointers
		return;
	}
	
	if (options->size() == 0) {
		// Fehlermeldung
		
		return;
	}
	
	// now we have only one option
	
	//  create new index
	vector<string>::iterator position = find(options->begin(), options->end(), "-i") ;
	if (position != options->end()) {
		// create the index, read the input files and write the index in the output file
		index->createIndex(out,in_files);
	}
	/**
	// print the entire index
	position = find(options->begin(), options->end(), "-p") ;
	if (position != options->end()) {
		//index->print(out);
	}

	// print index for the word
	position = find(options->begin(), options->end(), "-q") ;
	if (position != options->end()) {
		//index->printIndexForWord(word *w);
	}
	
	// print index for words who matches characters
	position = find(options->begin(), options->end(), "-s") ;
	if (position != options->end()) {
		//index->printWordsMatchesCharacters(string *characters);
	}
	
	// print index file
	position = find(options->begin(), options->end(), "-t") ;
	if (position != options->end()) {
		//index->printIndexForFile(file *f);
	}
	
	// TODO: auswerten eines Strings um ggf. falsche Parameter abzufangen!
	
	*/
	delete in_files;
	delete out;
	delete index;
	delete params;
}

Controller::~Controller() {
	
}
