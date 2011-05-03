

using namespace std;

#include "index.h"

Index::Index() {
	cout << "Konstruktor Index" << endl;
	_words = new vector<string>();
}

Index::~Index() {
	cout << "Destruktor Index" << endl;
	delete _words;
}

void Index::readFile(vector<string> *in_files) {
	for (vector<string>::iterator it=in_files->begin() ; it != in_files->end() ; it++) // Hier wird ein Iterator verwendet.
	{
		// read from inputfile
		ifstream in(it->c_str());
		istream_iterator<string> pos(in), end ;

		if (!in) {
			cout << "Eingabedatei "<< *it << " nicht gefunden!" << endl;
			continue;
		};

		// kopiere Wörter in vector wort
		copy(pos, end, back_inserter(*_words)) ;

		in.close() ; // Datei schließen
	}
	
	
}

void Index::writeFile(string *out_file) {
	// kopiere wörter in output datei
	ofstream out(out_file->c_str()); 
	if (!out) { 
		cerr << "Datei " << out_file << " kann nicht geoeffnet werden." << endl; 
	} else {
		copy(_words->begin(), _words->end(), 
			ostream_iterator<string>(out, "\n")) ;
	}
	
	out.close();
}

void Index::createIndex(string *outputfile, vector<string> *inputfile) {
	this->readFile(inputfile);
	this->writeFile(outputfile);
}