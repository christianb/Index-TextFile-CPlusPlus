

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
	
	if (!in) {
		cout << "Eingabedatei nicht gefunden!" << endl;
		return;
	};
	
	// kopiere Wörter in vector wort
	copy(pos, end, back_inserter(*wort)) ;
	
	in.close() ; // Datei schließen
	
	// kopiere in wortlist, eigentlich überflüssig...
	copy(wort->begin(), wort->end(), back_inserter(*wortlist)) ;
	
	copy(wortlist->begin(), wortlist->end(), 
		ostream_iterator<string>(cout, "\n")) ;
		
	// kopiere wörter in output datei
	ofstream out(outputfile->c_str()); 
	if (!out) { 
		cerr << "Datei " << outputfile << " kann nicht geoeffnet werden." << endl; 
	} else {
		copy(wortlist->begin(), wortlist->end(), 
			ostream_iterator<string>(out, "\n")) ;
	}
	
	out.close();
}