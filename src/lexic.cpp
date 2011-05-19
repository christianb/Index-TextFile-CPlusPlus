#include "Lexic.h"

using namespace std;

bool Lexic::operator()(string s1, string s2) const {
	//if (!lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp)) {
		string::iterator s1_it = s1.begin();
		string::iterator s2_it = s2.begin();
		
		// unix
		if  (strcasecmp(s1.c_str(), s2.c_str()) < 0) {
			return true;
		}
		
		if  (strcasecmp(s1.c_str(), s2.c_str()) > 0) {
			return false;
		}
		
		if (strcasecmp(s1.c_str(), s2.c_str()) == 0) {
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
	//}
	
	//return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp);
	//return true;
}

// a case-insensitive comparison function:
bool Lexic::mycomp (char c1, char c2)
{ return tolower(c1)<tolower(c2); }