using namespace std;

#include "index.h"

void Index::init() {
	// create new map
	_word_index = new map<word, map_files>();
	
	_validCharacters = new set<char>();
	
	char c[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9',
	'_','-'};
	
	//26+26+10+2
	_validCharacters = new set<char>(c,c+26+26+10+2);	
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
	cout << endl;
	//cout << "call extractAllWordsFromLine() with param line: " << line << endl;
	
	//cout << "call extractAllWordsFromLine: " << line << endl;
	vector<string> *words = new vector<string>(); 
	
	string *word = new string();
	
	// for each character in line
    for (string::iterator char_it=line.begin(); char_it!=line.end(); char_it++) {
		//cout << "call for each character in line, char: " << *char_it << endl;
		
		// if it is not a valid character
		if (this->isCharValid(*char_it)) {
			word->push_back(*char_it);
		} else {
			//cout << "ungueltiges zeichen gefunden" << endl;
			//cout << "extracted word: '" << *word << "'" << endl;
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

void Index::addToIndex(vector<string> words, file f, line l) {
	for (vector<string>::iterator words_it=words.begin() ; words_it != words.end() ; words_it++) {
		this->addToIndex(*words_it, f, l);
	}
}

/**
 * Adds a word to the map.
 * If the word already exists, append values.
 */
void Index::addToIndex(word w, file f, line l) {
	cout << endl;
	cout << "call addToIndex, word: " << w << ", in file: " << f << ", at line: " << l << endl;
	
	// the word is in the map and we get an iterator to its position.
	map<word, map_files>::iterator word_it = this->addWord(w);
	
	// now we can add the file to that word
	map<file, list<line> >::iterator file_it = this->addFile(word_it, f);
	
	// now we can add the line to the given file iterator
	this->addLine(file_it, l);	
}

map<word, map_files>::iterator Index::addWord(word w) {
/*	map<word, map_files>::iterator it = _word_index->find(w);
	
	// if the word is in map, so the iterator points not at the end
	if (it != _word_index->end()) {
		// just return the iterator pointing to the word in map
		cout << w << " is already in map!" << endl;
		map_files m_file = it->second;
		
		map_files::iterator file_it = m_file.begin();
		cout << file_it->first << endl;
		
		return it;
	} else {		
		cout << "insert '" << w << "' in map!" << endl;
		
		// if the word is not in the map, that means the iterator points to the end of the map
		// we must insert the word and return the iterator to that position
		return _word_index->insert(pair<word, map_files>(w, *new map<file, list<line> >())).first;
	}*/
	
		pair<map<word, map_files>::iterator,bool> ret;
		ret = _word_index->insert(pair<word, map_files>(w, *new map<file, list<line> >()));
		
		if (ret.second == false) {
			cout << ret.first->first << " is already in map!" << endl;
		} else {
			cout << "insert '" << ret.first->first << "' in map!" << endl;
		}
		
		return ret.first;
}

map<file, list<line> >::iterator Index::addFile(map<word, map_files>::iterator word_it, file f) {
	// get the value (map_files) from iterator
	map<file, list<line> > m_files = word_it->second; // TODO; hier wird keine map_file gespeichert !!!
	/* 
	// Variante 1
	// find file in map_files
	map<file, list<line> >::iterator file_it = m_files.find(f);
	
	// if its not at the end
	if (file_it != m_files.end()) {
		cout << "file: '" << f << "' is already in map for the word: " << word_it->first << endl;
		return file_it;
	} else {
		cout << "add file: '" << f << "' to word: " << word_it->first << endl;
		m_files.insert(pair<file, list<line> >(f, *new list<line>())).first;
		
		word_it->second = m_files;
		
		return m_files.find(f);
	}*/
	
	// Variante 2
	pair<map<file,list<line> >::iterator,bool> ret;
	ret = m_files.insert(pair<file, list<line> >(f, list<line>()));
	
	if (ret.second == false) {
		cout << "file: '" << f << "' is already in map for the word: " << word_it->first << " so no changes!" << endl;
	} else {
		cout << "insert file: '" << f << "' successfully in map for word: '" << word_it->first << endl;
		word_it->second = m_files; // assign new map_files to word
	}
	
	map<file, list<line> >::iterator test = ret.first;
	cout << "Test if file exist, f: " << test->first << endl;
	
	return ret.first;
}

void Index::addLine(map<file, list<line> >::iterator file_it, line l) {
	cout << "add line: " << l << " to file: " << file_it->first << endl;
	
	// get the list with line numbers for this file
	list<line> line_list = file_it->second;
	
	line_list.push_back(l);
}

/** FILE OPERATIONS **/

void Index::readFile(vector<string> *in_files) {
	cout << "call readFile()" << endl;
	
	// for each file
	for (vector<string>::iterator files_it=in_files->begin() ; files_it != in_files->end() ; files_it++) // Hier wird ein Iterator verwendet.
	{
		// this vectore stores each line in the file
		vector<string> *lines = new vector<string>();
		string line;
		
		cout << "read from inputfile: " << *files_it << endl;
		// read from inputfile
		ifstream in(files_it->c_str());
		//istream_iterator<string> pos(in), end ;
		
		cout << "test if file exist" << endl;
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
	// kopiere wörter in output datei
	ofstream out(out_file->c_str()); 
	if (!out) { 
		cerr << "Datei " << out_file << " kann nicht geoeffnet werden." << endl; 
	} else {
		
		for (map<string, map_files>::iterator word_it=_word_index->begin(); word_it != _word_index->end(); word_it++) {
			cout << word_it->first << " ";
			map_files m_files = word_it->second;
			for (map<file, list<line> >::iterator file_it = m_files.begin(); file_it != m_files.end(); file_it++) {
				cout << file_it->first << " ( ";
				list<line> l_list;
				for (list<line>::iterator line_it = l_list.begin(); line_it != l_list.end(); line_it++) {
					cout << *line_it << " ";
				}
				cout << ")" << endl;
			}
			
			//ostream.write(out, "ha"));
		}
		
		/*copy(_words->begin(), _words->end(), 
			ostream_iterator<string>(out, "\n")) ;*/
	}
	
	out.close();
}

