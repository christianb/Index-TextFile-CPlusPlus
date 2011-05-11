using namespace std;

#include "indexparser.h"



IndexParser::IndexParser() {
	testword = new string();
	cout<< "IndexParser Konstruktor\n";
	this->printIndex();
	this-> readIndexFile("HALLO\n");

}

IndexParser::~IndexParser() {
	delete testword;
	cout<< "IndexParser Destruktor\n";
}


void IndexParser::printIndex() {	
	cout << "Print index\n";
}



void IndexParser::readIndexFile(string index_file) {
	cout << index_file ;
}


