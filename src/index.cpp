using namespace std;

#include "index.h"

void Index::init() {
	// create new map
	_word_index = new words();
}

Index::Index() {
	this->init();
}

Index::~Index() {
	for (words::iterator w_it = _word_index->begin(); w_it != _word_index->end(); w_it++) {
		files *f_map = w_it->second;
		
		for (files::iterator f_it = f_map->begin(); f_it != f_map->end(); f_it++) {
			line_numbers *l = f_it->second;
			delete l; 
		}
		
		delete f_map;
	}
	
	delete _word_index;
}

void Index::createIndex(file* out, vector<file>* in) {	
	this->readFiles(in);
	this->writeFile(out);
}

void Index::readFiles(vector<file> *files) {
	for (vector<file>::iterator f_it = files->begin(); f_it != files->end(); f_it++) {
		this->readFile(*f_it);
	}
}

void Index::readFile(file f) {
	// this vectore stores each line in the file
	vector<string> *lines = this->readAllLines(f);
		
	/** at this we have each line of this file in a vector 
	 * now its time to read each character of that line **/
		
	int line_number = 0;
	
	// for each line in vector
	for (vector<string>::iterator line_it=lines->begin() ; line_it != lines->end() ; line_it++) {
		string line = *line_it;
			
		// extract all words from line
		vector<string> words = this->extractAllWordsFromLine(line);
			
		// now we can insert all the words, from current line, from current file in map
		this->addToIndex(words, f, ++line_number);
	}
	
	delete lines;
}

void Index::writeFile(string *out_file) {
	ofstream out(out_file->c_str()); 
	if (!out) { 
		cerr << "Datei " << out_file << " kann nicht geoeffnet werden." << endl; 
	} else {
		
		for (words::iterator word_it=_word_index->begin(); word_it != _word_index->end(); word_it++) {
			string word = word_it->first;
			out.write(word.data(), word.size());
			//
			files *m_files = word_it->second;
			
			for (files::iterator file_it = m_files->begin(); file_it != m_files->end(); file_it++) {
				string file =  file_it->first;
				out.write(" ", 1);
				out.write(file.data(), file.size());
				out.write(" ( ", 3);
				
				line_numbers *l_list = file_it->second;
				
				for (line_numbers::iterator line_it = l_list->begin(); line_it != l_list->end(); line_it++) {
					// write out line number followed by a BLANK 
					// cout << *line_it << " ";
					stringstream o;
					o << *line_it;
					string line = o.str();
					out.write(line.data(), line.size());
					out.write(" ", 1);
				}
				out.write(")\n", 3);
			}
		}
	}
	
	out.close();
}

// TODO : to be implemented
bool Index::isWordValid(word *w) {	
	for (string::iterator word_it=w->begin(); word_it != w->end(); word_it++) {
		cout << *word_it << endl;
	}
	
	return false;
}

bool Index::isCharValid(char c) {
	// if the character is part of the valid character set
	/*if (_validCharacters->end() != _validCharacters->find(c)) {
		return true;
	}*/
	
	// alternative implementation
	if ( this->isFirstCharValid(c) || (c >= '0' && c <= '9')) {
		return true;
	}
	
	return false;
}

bool Index::isFirstCharValid(char c) {
	if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || c == '-') {
		return true;
	}
	
	return false;
}

vector<word> Index::extractAllWordsFromLine(string line) {
	vector<string> words; 
	
	string *word = new string();
	
	// for each character in line
    for (string::iterator char_it=line.begin(); char_it!=line.end(); char_it++) {
		//cout << "call for each character in line, char: " << *char_it << endl;
		
		// if it is a valid character
		if (this->isCharValid(*char_it)) {
			word->push_back(*char_it);
		} else {
			// copy word in vector
			if (word->size()>0) {
				words.push_back(*word);
				word->clear();
			}
			// clear word
			continue;
		}
    }
	
	if (word->size()>0) {
		words.push_back(*word);
	}
	
	delete word;
	
	return words;
	
}


/** INDEX OPERATIONS **/

void Index::addToIndex(vector<string> words, file f, line_number l) {
	for (vector<string>::iterator words_it=words.begin() ; words_it != words.end() ; words_it++) {
		this->addToIndex(*words_it, f, l);
	}
}

/**
 * Adds a word to the map.
 * If the word already exists, append values.
 */
void Index::addToIndex(word w, file f, line_number l) {
	// cout << endl;
 	// cout << "call addToIndex, word: " << w << ", in file: " << f << ", at line: " << l << endl;	
	
	// the word is in the map and we get an iterator to its position.
	words::iterator word_it = this->addWord(w);
	
	// now we can add the file to that word
	files::iterator file_it = this->addFile(word_it, f);
	
	// now we can add the line to the given file iterator
	this->addLine(file_it, l);	
}

words::iterator Index::addWord(word w) {
	cout << "call addWord: " << w << endl;
		pair<words::iterator,bool> ret;
		files *f = new files();
		ret = _word_index->insert(pair<word, files*>(w, f));
		
		if (ret.second == false) {
			cout << ret.first->first << " is already in map!" << endl;
			delete f;
		}
		
		return ret.first;
}

files::iterator Index::addFile(words::iterator word_it, file f) {
	// get the value (map_files) from iterator
	files *m_files = word_it->second;

	pair<files::iterator,bool> ret;
	line_numbers *l = new line_numbers();
	ret = m_files->insert(pair<file, line_numbers* >(f, l));
	
	if (ret.second == false) {
		cout << "file: '" << f << "' is already in map for the word: " << word_it->first << " so no changes!" << endl;
		delete l;
	}
	
	return ret.first;
}

void Index::addLine(files::iterator file_it, line_number l) {
	file_it->second->insert(l);
}

/** FILE OPERATIONS **/

void Index::print(file *f) {
	// to be implement
	// parse the given (index) file.
	return;
}

void Index::parseIndexFile(file *f) {
	vector<string> *lines = this->readAllLines(*f);
	
	delete lines;
}

vector<string>* Index::readAllLines(file f) {
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