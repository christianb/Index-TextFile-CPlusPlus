#include "ltstr.h"

bool Ltstr::operator()(string s1, string s2)
{ 
	const char* c1 = s1.c_str();
	const char* c2 = s2.c_str();
	return tolower(*c1) < tolower(*c2) ; 
}
