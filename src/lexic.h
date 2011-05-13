/** Class Lexic
 *
 *  author  Christian Bunk
 *  date    12.5.2011
 *  version 0.1
 */

#ifndef _LEXIC_H
#define _LEXIC_H

#include <string>

using namespace std;

class Lexic {
public: 
	bool operator()(string s1, string s2);
};

#endif	/* _LEXIC_H */