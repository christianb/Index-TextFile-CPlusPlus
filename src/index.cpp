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

void Index::createIndex(file out, vector<file> in) {	
	this->readFiles(in);
	this->writeFile(out);
}

void Index::readFiles(vector<file> files) {
	for (vector<file>::iterator f_it = files.begin(); f_it != files.end(); f_it++) {
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

void Index::writeFile(string out_file) {
	ofstream out(out_file.c_str()); 
	if (!out) { 
		cerr << "Datei " << out_file << " kann nicht geoeffnet werden." << endl; 
	} else {
		
		for (words::iterator word_it=_word_index->begin(); word_it != _word_index->end(); word_it++) {
			string word = word_it->first;
			out << word.data();
			//
			files *m_files = word_it->second;
			
			for (files::iterator file_it = m_files->begin(); file_it != m_files->end(); file_it++) {
				string file =  file_it->first;
				out << " " << file.data() << " ( ";
				
				line_numbers *l_list = file_it->second;
				
				for (line_numbers::iterator line_it = l_list->begin(); line_it != l_list->end(); line_it++) {
					// write out line number followed by a BLANK 
					stringstream o;
					o << *line_it;
					string line = o.str();
					out << line.data() << " ";
				}
				out << ")\n";
			}
		}
	}

	out.close();
}

// TODO : to be implement (christian)
bool Index::isWordValid(word w) {	
	int i = 0;
	for (string::iterator word_it=w.begin(); word_it != w.end(); word_it++) {
		if (i == 0) {
			if (!this->isFirstCharValid(*word_it)) {
				return false;
			} 
		} else {
			if (!this->isCharValid(*word_it)) {
					return false;
			}
		}
		i++;
	}
	
	return true;
}

bool Index::isCharValid(char c) {
	// alternative implementation
	if ( this->isFirstCharValid(c) || (c >= '0' && c <= '9')  || c == '-') {
		return true;
	}
	
	return false;
}

// check the first character
bool Index::isFirstCharValid(char c) {
	if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_') {
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
			continue;
		}
    }
	
	if (word->size()>0) {
		words.push_back(*word);
	}
	
	delete word;
	return words;
}


void addToIndex(word w, map<file, set<line_number> >) {
	// to be implemented.
}

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
		pair<words::iterator,bool> ret;
		files *f = new files();
		ret = _word_index->insert(pair<word, files*>(w, f));
		
		if (ret.second == false) {
			//cout << ret.first->first << " is already in map!" << endl;
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
		//cout << "file: '" << f << "' is already in map for the word: " << word_it->first << " so no changes!" << endl;
		delete l;
	}
	
	return ret.first;
}

void Index::addLine(files::iterator file_it, line_number l) {
	file_it->second->insert(l);
}

void Index::print(file *f) {
	// to be implement
	// parse the given (index) file.
	return;
}

// alexander
words* Index::parseIndexFile(file *f) {
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

void Index::printIndexFromOutputFile(file f) {
	cout << "printIndexFromOutputFile : " << f << endl;
	
	// TODO: read from parser!
	// indexParser->parseOutputfile(f);

	cout << this->wordsToString();
}

string Index::linesToString(line_numbers *l_set) {
	string lines;
	lines.append("(");
	for (line_numbers::iterator l_it = l_set->begin(); l_it != l_set->end(); l_it++) {
		lines.append(" ");
		lines.append(this->lineToString(*l_it));
	}
	
	lines.append(" )");
	
	return lines;
}

string Index::lineToString(line_number l) {
	string number;
	ostringstream os;
	os << l;
	number.append(os.str());
	
	return number;
}

string Index::filesToString(files *f_map) {
	string files;
	for (files::iterator f_it = f_map->begin(); f_it != f_map->end(); f_it++) {
		files.append(this->fileToString(f_it->first, f_it->second));
	}
	
	return files;
}

string Index::fileToString(file f, line_numbers *l) {
	string file;
	file.append(" ");
	file.append(f);
	file.append(" ");
	file.append(this->linesToString(l));
	file.append("\n");
	return file;
}

string Index::wordsToString() {
	string words;
	for (words::iterator w_it = _word_index->begin(); w_it != _word_index->end(); w_it++) {
		words.append(this->wordToString(w_it->first, w_it->second));
	}
	
	return words;
}

string Index::wordToString(word w, files *f_map) {
	string word;
	word.append(w);
	word.append(this->filesToString(f_map));
	
	return word;
}

// print the Index for one word.
// TODO, can be used for other methods
void Index::printIndexForWord(string pWord) {
	cout << "Index for word " << endl;
	// find given word	
	words::iterator w_it = _word_index->find(pWord);
	
	// if word is in map
	if (w_it != _word_index->end()) {
		cout << this->wordToString(w_it->first, w_it->second);
	} else {
		cout << "The word: " << pWord << " is not an element of the index!" << endl;
	}
}

void Index::printWordsMatchesCharactersAtBeginning(string chars) {
	cout << "call printWordMatchesCharactersAtBeginning() with chars: '" << chars << "'" << endl;

	for (words::iterator w_it = _word_index->begin(); w_it != _word_index->end(); w_it++) {
		string word = w_it->first;
		size_t found;
		found = word.find(chars);
		
		if (found == 0) {
			cout << this->wordToString(w_it->first, w_it->second);
		}
	}
}

void Index::printWordsMatchesCharactersAnywhere(string chars) {
	cout << "call printWordMatchesCharactersAnywhere() with chars: '" << chars << "'" << endl;
	
	for (words::iterator w_it = _word_index->begin(); w_it != _word_index->end(); w_it++) {
		string word = w_it->first;
		
		size_t found;
		found = word.find(chars);
		
		if (found!=string::npos) {
			cout << this->wordToString(w_it->first, w_it->second);
		}
	}
}

void Index::printIndexForFile(file f) {
	cout << "call printIndexForFile() with file: " << f << endl;
	for (words::iterator w_it = _word_index->begin(); w_it != _word_index->end(); w_it++) {
		word w = w_it->first;
		files *f_map = w_it->second;
		
		files::iterator f_it = f_map->find(f);
		if (f_it != f_map->end()) {
				cout << w << " " << f << this->linesToString(f_it->second) << endl;
			}
	}
}

void Index::addToIndex(word w, file f, line_numbers lines) {
	for (line_numbers::iterator l_it = lines.begin(); l_it != lines.end(); l_it++) {
		this->addToIndex(w, f, *l_it);
	}
}