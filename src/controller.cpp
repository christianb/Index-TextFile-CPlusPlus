#include "controller.h"
#include "cmdline.h"
#include "index.h"
#include <algorithm>

Controller::Controller(int argc, char *argv[]) {
	
	// read command line parameters
	CmdLine *params = new CmdLine(argc, argv);

	vector<string> options = params->getOptions();
	vector<string> arguments = params->getArguments();
	
	// params is no longer needed
	delete params;

	// get the first argument param, this is our output file
	string out = *arguments.begin();
	
	// delete the first argument, the others are the input files
	arguments.erase(arguments.begin());
	
	Index *index = new Index();

	// prüfen wie viele options angegeben wurden und entsprechend Meldung ausgeben
	if (options.size() > 1) {
		// Fehlermeldung...
		
		// delete pointers
		return;
	}
	
	if (options.size() == 0) {
		// Fehlermeldung
		
		return;
	}
	
	// now we have only one option
	
	//  create new index
	vector<string>::iterator position = find(options.begin(), options.end(), "-i") ;
	if (position != options.end()) {
		// create the index, read the input files and write the index in the output file
		index->createIndex(out, arguments);
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
	//delete in_files;
	delete index;
	
}

Controller::~Controller() {
	
}
