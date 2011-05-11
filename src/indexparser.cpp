using namespace std;

#include "indexparser.h"



IndexParser::IndexParser(Index *i) {
	testword = new string();
	cout<< "IndexParser Konstruktor\n";
	this->printIndex();
	this-> readIndexFile("HALLO\n");
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
	cout << index_file ;
}


