/** Class StringUtil
 *
 *  This class provides some usefull string methods.
 *
 *  author  Christian Bunk
 *  date    15.5.2011
 *  version 0.1
 */

#ifndef _STRINGUTIL_H
#define _STRINGUTIL_H

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class StringUtil {
public:
	/**
	 * Convert a single value into a string.
	 * @param value The value to be convert into a string.
	 * @return string The string representation of the value.
	 */
	template <typename Type>
	string toString(Type value) {
		ostringstream strout;
		strout << value;
		
		return (strout.str());
	}
	
	/**
	 * Convert a string into a given data type (call-by-reference)
	 * @param str The string to be converted into a special data type.
	 * @param &wert The variable where the representation of the string definded by the data type is stored.
	 */
	template <typename Typ>
	void stringTo(string str, Typ &wert) {
	    istringstream strin; // Unser Eingabe-Stream

	    strin.str(str);           // Streaminhalt mit String-Variable füllen
	    strin >> wert;            // Variable von Eingabe-Stream einlesen
	}
	
	/**
	 * Transfomrs a given string to lower case letters.
	 * @param &str The string to be transformed given as an reference.
	 */
	void toLowerCase(string &str);
	
};

#endif	/* _STRINGUTIL_H */
