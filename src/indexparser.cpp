using namespace std;

#include "indexparser.h"



IndexParser::IndexParser(Index *i) {
	testword = new string();
	cout<< "IndexParser Konstruktor\n";

	this->index = i;
}

IndexParser::~IndexParser() {
	delete testword;
	cout<< "IndexParser Destruktor\n";
	
	delete index;
}


void IndexParser::printIndex() {	
	cout << "Print index\n";
}



void IndexParser::readIndexFile(string index_file) {
	vector<string> *wort = new vector<string>() ;
	ifstream in(index_file.data()) ; // Oeffnen der Eingabedatei
	istream_iterator<string> pos(in), end ;
		
		if(pos == end)
		{
			cout << "Eingabedatei nicht gefunden!" << endl;
			//return EXIT_FAILURE ;
		} ;
	
	while(pos != end) // implizit einlesen
	{
		cout << *pos << endl;
		wort->push_back(*pos) ;
		++pos;
    	} ;
	in.close() ; // Datei schließen

  //      index->addToIndex("Hallo", "TESTFILE", 3);
//	void addToIndex(word w, map<file, set<line_number> >);
}


