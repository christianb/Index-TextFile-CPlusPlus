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
	

	IndexParser *parser = new IndexParser(index);	

	//  create new index
	map<string,string>::iterator position = options.find("i");
	if (position != options.end()) {
		// need at least two arguments (one the output file and at least one input file)
		if (arguments.size() >= 2) {
			string out = *arguments.begin();
			
			// delete the first argument, the others are the input files
			arguments.erase(arguments.begin());

			// create the index, read the input files and write the index in the output file
			index->createIndex(out, arguments);
		} else {
			cout << "Error: not enough arguments. Need at least one output file and one input file i.e. -i out.txt in.txt" << endl;
		}
		
		
		
	}
	
	// print the entire index
	position = options.find("p");
	if (position != options.end()) {
		// need at least one argument (the output file to be read in for the parser)
		if (!arguments.empty()) {
			parser->readIndexFile(*arguments.begin());
		
			// TODO: how many arguments
			index->printIndexFromOutputFile(*arguments.begin());
		}
	}
	
	// print index for the word
	position = options.find("q");
	if (position != options.end()) {
		// need at least one argument (the output file to be read in for the parser)
		if (!arguments.empty()) {
			parser->readIndexFile(*arguments.begin());
			
			cout << "suche nach dem Wort: " << position->second << endl;
			index->printIndexForWord(position->second);
		} else {
			cout << "Error: need output file as an argument i.e. -q=word out.txt" << endl;
		}
	}
	
	// print index for words who matches characters
	position = options.find("s");
	if (position != options.end()) {
		if (!arguments.empty()) {
			parser->readIndexFile(*arguments.begin());
			
			cout << "suche nach dem Teilwort: " << position->second;
			index->printWordsMatchesCharactersAtBeginning(position->second);
		} else {
			cout << "Error: need output file as an argument i.e. -s=word out.txt" << endl;
		}
	}
	
	// print index file
	position = options.find("t");
	if (position != options.end()) {
		if (!arguments.empty()) {
			parser->readIndexFile(*arguments.begin());
			
			index->printIndexForFile(position->second);
		} else {
			cout << "Error: need output file as an argument i.e. -t=word out.txt" << endl;
		}
	}
	
	delete parser;
	delete index;
}

Controller::~Controller() {
	
}
