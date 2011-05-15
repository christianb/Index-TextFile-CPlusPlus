#include "fileutil.h"

map<string, vector<string>* > FileUtil::readFiles(vector<string> files) {
	map<string, vector<string>* > *file_map = new map<string, vector<string>* >();
	
	//cout << "call readFiles()" << endl;
	for (vector<string>::iterator f_it = files.begin(); f_it != files.end(); f_it++) {
		vector<string> *lines = this->readAllLinesFromFile(*f_it);
		
		pair<map<string, vector<string>* >::iterator,bool> ret;
		ret = file_map->insert(pair<string, vector<string>* >(*f_it, lines));
		
		if (ret.second == false) {
			delete lines;
		}
	}

	return *file_map;
}

// read all lines of a file and returns a vector of string with .
vector<string>* FileUtil::readAllLinesFromFile(string f) {
	// read the given index file
	// this vectore stores each line in the file
	vector<string> *lines = new vector<string>();
	string line;
	
	// read from inputfile
	ifstream in(f.c_str());
		
	// test if file exist
	if (!in) {
		cout << "Eingabedatei "<< f << " nicht gefunden!" << endl;
		in.close() ; // Datei schließen
		return lines;
	}
	
	// read each line of file
	while (getline(in, line, '\n')) {
		// put line at the end of vector.
	    lines->push_back(line);
	}
	
	in.close() ; // Datei schließen
	
	return lines;
}

void FileUtil::writeFile(string out_file, string content) {
	ofstream out(out_file.c_str()); 
	if (!out) { 
		cerr << "Datei " << out_file << " kann nicht geoeffnet werden." << endl; 
	} else {
		out << content;		
	}

	out.close();
}
