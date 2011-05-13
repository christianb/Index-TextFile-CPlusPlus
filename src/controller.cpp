#include "controller.h"
#include "cmdline.h"
#include "index.h"
#include "indexparser.h"
#include <algorithm>

Controller::Controller(int argc, char *argv[]) {
	
	// read command line parameters
	CmdLine *params = new CmdLine(argc, argv);

	map<string, string> options = params->getOptions();
	vector<string> arguments = params->getArguments();
	
/*	cout << "Options: " << endl;
	params->printOptions();
	
	cout << endl << "Arguments: " << endl;
	params->printArguments();
*/
	// params is no longer needed
	delete params;

	Index *index = new Index();

	// prüfen wie viele options angegeben wurden und entsprechend Meldung ausgeben
	if (options.size() > 1) {
		cout << "Error: please type in just one option i.e. -i or -q=value" << endl;
		
		delete index;
		return;
	}

	if (options.size() == 0) {
		cout << "Error: please type in one option" << endl;
		// -help option
		
		delete index;
		return;
	}
	
	// get the first argument param, this is our output file
	string out = *arguments.begin();
	IndexParser *parser = new IndexParser(index);
	
	
	//  create new index
	map<string,string>::iterator position = options.find("i");
	if (position != options.end()) {
		// delete the first argument, the others are the input files
		arguments.erase(arguments.begin());
		
		// create the index, read the input files and write the index in the output file
		index->createIndex(out, arguments);
		
	}
	
	// print the entire index
	position = options.find("p");
	if (position != options.end()) {
		arguments.erase(arguments.begin());
		index->createIndex(out, arguments);	// just until the parser is ready*/	
		
		// TODO: how many arguments
		index->printIndexFromOutputFile(*arguments.begin());
	}
	
	// print index for the word
	position = options.find("q");
	if (position != options.end()) {
		arguments.erase(arguments.begin());
		index->createIndex(out, arguments); // just until the parser is ready
		
		index->printIndexForWord("das");
	}
	
	// print index for words who matches characters
	position = options.find("s");
	if (position != options.end()) {
		arguments.erase(arguments.begin());
		index->createIndex(out, arguments); // just until the parser is ready
		
		index->printWordsMatchesCharactersAtBeginning("an");
	}
	
	// print index file
	position = options.find("t");
	if (position != options.end()) {
		parser->readIndexFile("output.txt");
		arguments.erase(arguments.begin());
		index->createIndex(out, arguments); // just until the parser is ready
		
		index->printIndexForFile(*arguments.begin());
	}
	
	delete parser;
	delete index;
}

Controller::~Controller() {
	
}
