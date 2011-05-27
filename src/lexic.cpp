#include "lexic.h"

using namespace std;

bool Lexic::operator()(string s1, string s2) {
	string::iterator s1_it = s1.begin();
	string::iterator s2_it = s2.begin();
	
	// check strings of case insensitive equality
	do {
		// s1 is lower than s2
		if (tolower(*s1_it) < tolower(*s2_it)) {
			return true;
		}
		
		// s1 is greater than s2
		if (tolower(*s1_it) > tolower(*s2_it)) {
			return false;
		}	
		
		s1_it++;
		s2_it++;
	} while (s1_it != s1.end() || s2_it != s2.end()); 
	
	// here either both strings are euqal or one is longer and contains the other string
	
	// if both are equal make a check for CASE SENSITIVE difference
	if (s1.size() == s2.size()) {
		s1_it = s1.begin();
		s2_it = s2.begin();
		
		do {
			// s1 is lower than s2 (CASE SENSITIVE)
			if (*s1_it < *s2_it) {
				return true;
			}
			
			// s1 is greater than s2 (CASE SENSITVE)
			if (*s1_it > *s2_it) {
				return false;
			}

			s1_it++;
			s2_it++;
		} while(s1_it != s1.end() && s2_it != s2.end());
		
		// if it comes here both strings are even CASE SENSITIVE exactly the same
		return false;
	} else {
		return (s1.size() < s2.size()); // true if s1 is lower than s2, false otherwise
	}
	/*
	// 
	if (!lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp)) {
		string::iterator s1_it = s1.begin();
		string::iterator s2_it = s2.begin();
		
		// up to here s1 is either greater or equal than s2
		
		// checks the word is egual, case sensitive
		if ( this->isWordEqualCaseInsensitiv(s1, s2)) { 
			// if equal lexic test of asci difference
			do {
				if (*s1_it < *s2_it) {
					return true;
				}
				
				if (*s1_it > *s2_it) {
					return false;
				}

				s1_it++;
				s2_it++;
			} while(s1_it != s1.end() || s2_it != s2.end());
		}		
		return false;
	}
	return true;*/
}
/*
bool Lexic::isWordEqualCaseInsensitiv(string s1, string s2) {
	// if both string have not same length both words are not equal
	if (s1.size() != s2.size()) {
		return false;
	}
	
	// so both strings must have the same size up to here
	string::iterator s1_it = s1.begin();
	string::iterator s2_it = s2.begin();
	
	do {
		if (tolower(*s1_it) != tolower(*s2_it) ) { return false; }
		
		s1_it++;
		s2_it++;
	} while(s1_it != s1.end() && s2_it != s2.end()); // is possible because both strings have the same size
	
	return true;
}

// a case-insensitive comparison function:
bool Lexic::mycomp (char c1, char c2) { 
	if (tolower(c1)<tolower(c2)) { return true; }
	
	// c1 is greater or equal than c2
	return false;
}*/
