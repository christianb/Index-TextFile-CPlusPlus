using namespace std;

#include "index.h"

void Index::init() {
	// create new map
	_word_index = new words();
	
	_validCharacters = new set<char>();
	
	char c[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'_','-',
	'0','1','2','3','4','5','6','7','8','9',
	};
	
	_validFirstWordChar = new set<char>(c, c+26+26+2);
	
	//26+26+10+2
	_validCharacters = new set<char>(c,c+26+26+2+10);	
}

Index::Index(string *outputfile, vector<string> *inputfile) {
	this->init();
	
	//_word_index->insert(pair<word, map_files>("Hallo", *new map<file, list<line> >()));
	this->readFile(inputfile);
	this->writeFile(outputfile);
}

Index::~Index() {
	delete _word_index;
	delete _validCharacters;
	delete _validFirstWordChar;
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
	if (_validCharacters->end() != _validCharacters->find(c)) {
		return true;
	}
	
	return false;
}

vector<string> Index::extractAllWordsFromLine(string line) {
	vector<string> *words = new vector<string>(); 
	
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
				words->push_back(*word);
				word->clear();
			}
			// clear word
			continue;
		}
    }
	
	if (word->size()>0) {
		words->push_back(*word);
	}

	return *words;
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
	cout << endl;
	cout << "call addToIndex, word: " << w << ", in file: " << f << ", at line: " << l << endl;
	
	// the word is in the map and we get an iterator to its position.
	words::iterator word_it = this->addWord(w);
	
	// now we can add the file to that word
	files::iterator file_it = this->addFile(word_it, f);
	
	// now we can add the line to the given file iterator
	this->addLine(file_it, l);	
}

words::iterator Index::addWord(word w) {
		pair<words::iterator,bool> ret;
		ret = _word_index->insert(pair<word, files*>(w, new files()));
		
		if (ret.second == false) {
			cout << ret.first->first << " is already in map!" << endl;
		} else {
			cout << "insert '" << ret.first->first << "' in map!" << endl;
		}
		
		return ret.first;
}

files::iterator Index::addFile(words::iterator word_it, file f) {
	// get the value (map_files) from iterator
	files *m_files = word_it->second;

	pair<files::iterator,bool> ret;
	ret = m_files->insert(pair<file, line_numbers* >(f, new line_numbers()));
	
	if (ret.second == false) {
		cout << "file: '" << f << "' is already in map for the word: " << word_it->first << " so no changes!" << endl;
	} else {
		cout << "insert file: '" << f << "' successfully in map for word: '" << word_it->first << endl;
	}
	
	return ret.first;
}

void Index::addLine(files::iterator file_it, line_number l) {
	file_it->second->insert(l);
}

/** FILE OPERATIONS **/

void Index::readFile(vector<string> *in_files) {
	// for each file
	for (vector<string>::iterator files_it=in_files->begin() ; files_it != in_files->end() ; files_it++) // Hier wird ein Iterator verwendet.
	{
		// this vectore stores each line in the file
		vector<string> *lines = new vector<string>();
		string line;
		
		// read from inputfile
		ifstream in(files_it->c_str());
		//istream_iterator<string> pos(in), end ;
		
		// test if file exist
		if (!in) {
			cout << "Eingabedatei "<< *files_it << " nicht gefunden!" << endl;
			continue;
		};
		
		// read each line of file
		while (getline(in, line, '\n')) {
			// put line at the end of vector.
		    lines->push_back(line);
		}
		
		// how many lines have been read
		//cout << "Read " << lines->size() << " lines." << endl;
		
		/** at this we have each line of this file in a vector 
		 * now its time to read each character of that line **/
		
		vector<string> *words = new vector<string>();
		
		//string *word = new string();
		
		int line_number = 0;
		// for each line in vector
		for (vector<string>::iterator line_it=lines->begin() ; line_it != lines->end() ; line_it++) {
			string line = *line_it;
			
			// extract all words from line
			vector<string> words = this->extractAllWordsFromLine(line);
			
			// now we can insert all the words, from current line, from current file in map
			this->addToIndex(words, *files_it, ++line_number);
		}

		in.close() ; // Datei schließen
	}
	
	
}

void Index::writeFile(string *out_file) {
	ofstream out(out_file->c_str()); 
	if (!out) { 
		cerr << "Datei " << out_file << " kann nicht geoeffnet werden." << endl; 
	} else {
		
		for (words::iterator word_it=_word_index->begin(); word_it != _word_index->end(); word_it++) {
			// write each word, followed by a BLANK
			cout << word_it->first;
			files *m_files = word_it->second;
			
			for (files::iterator file_it = m_files->begin(); file_it != m_files->end(); file_it++) {
				// write out the filename followed by a BLANk and a (
				cout << " " << file_it->first << " ( ";
				line_numbers *l_list = file_it->second;
				
				for (line_numbers::iterator line_it = l_list->begin(); line_it != l_list->end(); line_it++) {
					// write out line number followed by a BLANK 
					cout << *line_it << " ";
				}
				// close with a )
				cout << ")";
			}
			
			cout << endl;
			//ostream.write(out, "ha"));
		}
		
		/*copy(_words->begin(), _words->end(), 
			ostream_iterator<string>(out, "\n")) ;*/
	}
	
	out.close();
}

