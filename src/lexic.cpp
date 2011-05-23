#include "lexic.h"

using namespace std;

bool Lexic::operator()(string s1, string s2) {
	cout << "compare s1: " << s1 << " and s2: " << s2 << endl;
	if (!lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp)) {
		string::iterator s1_it = s1.begin();
		string::iterator s2_it = s2.begin();
		
		cout << "s1: " << s1 << " is graeter or euqal s2: " << s2 << endl;
		
		// unix
/*		if  (strcasecmp(s1.c_str(), s2.c_str()) < 0) {
			return true;
		}*/
		
/*		if  (strcasecmp(s1.c_str(), s2.c_str()) > 0) {
			return false;
		}
		
		
*/		
		// checks the word is egual, case sensitive
		if ( this->isWordEqualCaseInsensitiv(s1, s2)) { 
			// if equal lexic test of asci difference
			do {
				if (*s1_it < *s2_it) {
					cout << "s1: " << *s1_it << " < s2: " << *s2_it << endl;
					return true;
				}
				
				if (*s1_it > *s2_it) {
					cout << "s1: " << *s1_it << " > s2: " << *s2_it << endl;
					return false;
				}
				
				if (*s1_it == *s2_it) {
					cout << "s1: " << *s1_it << " == s2: " << *s2_it << endl;
				}
				s1_it++;
				s2_it++;
			} while(s1_it != s1.end() || s2_it != s2.end());
		} else {
			cout << "s1: " << *s1_it << " != s2: " << *s2_it << endl;
		}
		
		
		return false;
	} else {
		return true;
	}
	
	//return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp);
	//return true;
}

bool Lexic::isWordEqualCaseInsensitiv(string s1, string s2) {
	// if both string have not same length both words are not equal
	if (s1.size() != s2.size()) {
		return false;
	}
	
	string::iterator s1_it = s1.begin();
	string::iterator s2_it = s2.begin();
	
	do {
		
		if (tolower(*s1_it) != tolower(*s2_it) ) {
			return false;
		}
		
		s1_it++;
		s2_it++;
	} while(s1_it != s1.end() || s2_it != s2.end());
	
	
	
	return true;
}

// a case-insensitive comparison function:
bool Lexic::mycomp (char c1, char c2) { 
	if (tolower(c1)<tolower(c2)) {
		cout << "c1: " << c1 << " < c2: " << c2 << endl;
		return true;
	} else {
		cout << "c1: " << c1 << " > or = c2: " << c2 << endl;
		return false;
	}
}
