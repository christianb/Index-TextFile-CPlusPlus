

using namespace std;

#include "index.h"

Index::Index() {
	cout << "Konstruktor Index" << endl;
}

Index::~Index() {
	cout << "Destruktor Index" << endl;
}

void Index::createIndex(string *outputfile, string *inputfile) {
	cout << "create Index" << endl;
	
	vector<string>* wort = new vector<string>() ;
	list<string>* wortlist = new list<string>() ;
	
	// read from inputfile
	ifstream in(inputfile->c_str());
	istream_iterator<string> pos(in), end ;
	
	if(pos == end) {
		cout << "Eingabedatei nicht gefunden!" << endl;
		return;
	};
	
	copy(pos, end, back_inserter(*wort)) ;
	
	in.close() ; // Datei schließen
	
	copy(wort->begin(), wort->end(), back_inserter(*wortlist)) ;
	
	copy(wortlist->begin(), wortlist->end(), 
		ostream_iterator<string>(cout, "\n")) ;
}