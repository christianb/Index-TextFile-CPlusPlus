#include "lexic.h"

bool Lexic::operator()(string s1, string s2) { 	
	bool s1_IsSmaller_s2; // flag if s1 is lexicografic smaller than s2
		
	// get an iterator of both strings
	string::iterator s1_it = s1.begin();
	string::iterator s2_it = s2.begin();
			
	bool loop_flag = false;
			
	do {
		const char c1 = *s1_it;
		const char c2 = *s2_it;
			
		// if the character c1 is lower than c2
		if (tolower(c1) < tolower(c2)) {
			//cout << c1 << " ist kleiner als " << c2 << endl;
			s1_IsSmaller_s2 = true; // the string s1 is lexicografically lower than s2, done
			loop_flag = false;
		}
			
		// if the character c1 is grater than c2
		if (tolower(c1) > tolower(c2)) {
			//cout << c1 << " ist groesser als " << c2 << endl;
			s1_IsSmaller_s2 = false; // the string s1 is lexicografically grater than s2, done
			loop_flag = false;
		}
				
		// if both characters are the same
		if (tolower(c1) == tolower(c2)) {
			//cout << c1 << " ist gleich " << c2 << endl;
			loop_flag = true;
					
			s1_it++; // go to next character
			s2_it++;
					
			// check if both strings are emtpy
			if (s1_it == s1.end() && s2_it == s2.end()) {
				loop_flag = false; // done
			} else {
				// if one of both is empty, than the shorter string is smaller
				if (s1_it == s1.end()) {
					// if s1 is empty, s1 is lexicorafically smaller than s2
					s1_IsSmaller_s2 = true;
					loop_flag = false;
				}

				if (s2_it == s2.end()) {
					// if s2 is empty, s1 is lexicorafically grater than s2
					s1_IsSmaller_s2 = false;
					loop_flag = false;
				}
			}
		}

	} while (loop_flag);
			
	/*cout << "Ergebnis: ";
	if (s1_IsSmaller_s2) {
			cout << s1 << " ist kleiner als " << s2 << endl;
		} else {
			cout << s1 << " ist größer als " << s2 << endl;
		}
		cout << endl;*/
	
	return s1_IsSmaller_s2;
}