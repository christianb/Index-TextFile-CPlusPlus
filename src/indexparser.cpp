using namespace std;

#include "indexparser.h"



IndexParser::IndexParser(Index *i) {
	testword = new string();
	cout<< "IndexParser Konstruktor\n";

	this->index = i;
}

IndexParser::~IndexParser() {
	delete testword;
	cout<< "IndexParser Destruktor\n ";
	
	delete index;
}


void IndexParser::printIndex() {	
	cout << "Print index\n";
}



void IndexParser::readIndexFile(string index_file) {
	vector<string> *lines = new vector<string>();
	ifstream in(index_file.data()) ; // Open given IndexFile
	string line;
		
	// test if file exist
	if (!in) {
		cout << "Eingabedatei "<< index_file << " nicht gefunden!" << endl;
		in.close() ; // Datei schließen
	}
	else{
	// read each line of file
	while (getline(in, line, '\n')) {
		// put line at the end of vector.
		lines->push_back(line);
		cout << line << "\n";
	}
	}
	in.close() ; // Close IndexFile



//	void addToIndex(word w, map<file, set<line_number> >);
	delete lines;
}


