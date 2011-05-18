#include "Lexic.h"

bool Lexic::operator()(string s1, string s2) const {
	return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp);
}

// a case-insensitive comparison function:
bool Lexic::mycomp (char c1, char c2)
{ return tolower(c1)<tolower(c2); }