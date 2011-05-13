using namespace std;

#include "indexparser.h"



IndexParser::IndexParser(Index *i) {
	this->index = i;
}

IndexParser::~IndexParser() {
	delete index;
}

void IndexParser::FileToLines(vector<string> *lines, string index_file){
	ifstream in(index_file.data()) ; // Open given IndexFile	
	string line;

	// Test if file exist. If exists --> store lines in verctor<string>
	if (!in){
		cout << "Eingabedatei "<< index_file << " nicht gefunden!" << endl;
		in.close() ; // Datei schließen
	}
	else{
		// Read each line of file
		while (getline(in, line, '\n')) {
		lines->push_back(line); // Put line at the end of vector.
		}
	}
	in.close() ; // Close IndexFile
}

void IndexParser::ParseLine(string linie, bool flag_wort, bool flag_file, bool flag_index){
	string wort, file, ind;
	stringstream out;
	int index = 0;	
	set<int> *index_set = new set<int>();

  	// Parse given line and differ strings between WORD, FILE and INDEX
	for (string::iterator s_it = linie.begin(); s_it != linie.end(); s_it++) {
		out.str("");
		out << *s_it;
		string character = out.str();

		// Read rest --> INDEX
		if (flag_wort == true && flag_file == true && flag_index == false && character != " " && character != "(" && character != ")")
			ind += character;
		else if (flag_wort == true && flag_file == true && flag_index == false && character == " " && ind != "") {
			out.str(ind);
			string ind_string = out.str();
			index = atoi(ind_string.c_str());
			index_set->insert(index);
			out.str((ind = ""));		
		}
		else if (flag_wort == true && flag_file == true && flag_index == false  && character == ")")
			flag_file = true;

		// Read second string --> FILE
		if (flag_wort == true && flag_file == false && flag_index == false && character != " ")
			file += character;		
		else if (flag_wort == true && flag_file == false && flag_index == false && character == " ")
			flag_file = true;

		// Read first string --> WORD
		if (flag_wort == false && flag_file == false && flag_index == false && character != " ")
			wort += character;		
		else if (flag_wort == false && flag_file == false && flag_index == false && character == " ")
			flag_wort = true;	
	}

	//index->AddToIndex(wort, file, index_set);
	// TEST FUNKTION ZUR AUSGABE AM TERMINAL
	cout << wort << " " << file << " ";
	for (set<int>::iterator line_it = index_set->begin(); line_it != index_set->end(); line_it++) {
		// write out line number followed by a BLANK 
		stringstream o;
		o << *line_it;
		string line = o.str();
		cout << *line_it << " ";
	}
	cout << "\n";
	delete index_set;
}

void IndexParser::ParseAllLines(vector<string> *lines){
	string linie;

	// Linie für Linie duchgehen
	for (vector<string>::iterator lines_it = lines->begin(); lines_it != lines->end(); lines_it++) {
		bool flag_wort = false;
		bool flag_file = false;
		bool flag_index = false;
		stringstream out;
		out << *lines_it;
		linie = out.str();
		// Parse given line anf write values into the index
		this->ParseLine(linie, flag_wort, flag_file, flag_index);
	}
}

void IndexParser::readIndexFile(string index_file) {
	vector<string> *lines = new vector<string>();
	this->FileToLines(lines, index_file);
	this->ParseAllLines(lines);
	delete lines;
}


