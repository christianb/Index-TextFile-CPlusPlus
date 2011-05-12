/** Class Ltstr
 *
 *  author  Christian Bunk
 *  date    12.5.2011
 *  version 0.1
 */

#ifndef _LTSTR_H
#define _LTSTR_H

#include <string>

using namespace std;

class Ltstr {
public: 
	bool operator()(string s1, string s2);
};

#endif	/* _LTSTR_H */