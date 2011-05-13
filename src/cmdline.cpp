
using namespace std;

#include "cmdline.h"

/**
 * Konstruktor
 */
CmdLine::CmdLine(int argc, char *argv[]) {	
	opt = new options;
	arg = new arguments;

	// if there is at least one parameter
	if (argc > 1) {
		size_t found;
		
		for (int i = 1; i < argc; i++) {	
			// get next parameter
			string s = string(argv[i]);
			string::iterator s_it = s.begin();
			
			// if the first char is an minus (-)
			found=s.find("-");
			
			// if there is no minus given, then it is an argument
			/*if ( (found != 0 && found != string::npos) || ) {
				// save the argument
				arg->push_back(s);
				
				continue;
			}*/
			
			// if the equal sign is not at first position
		/*	if (found != string::npos && found != 0) {
				// the minus is not at first position
				cout << "Error: please set the minus sign before the parameter!" << endl;
				return;
			}*/
			
			// if the equal sign is at first position than get the param and the value
			if (found == 0) {
				// minus sign is at first position.
				// now check if the param name is valid
				s_it++;
				const char cur_opt = *s_it;
				if (this->isOptionValid(cur_opt)) {
					// the option is valid
					
					// now check if the option need a value;
					if (this->optionNeedValue(cur_opt)){
						// test if the next char is an equal sign
						s_it++;
						if (*s_it == '=') {
							// now extract the value;
							// from s_it++; to s->end();
							string value;
							for (s_it++; s_it != s.end(); s_it++) {
								const char *c = new char(*s_it);
								value.append(c);
							}
							
							// check if there is at least one character given for the value, due emtpy values are not allowed.
							if (value.empty()) {
								cout << "Error: no emtpy values are allowed!" << endl;
								return;
							}
							
							string param = this->charToString(cur_opt);
							
							//if (i != (argc-1)) {
							//	cout << "insert param: " << param << " with value: " << value << "i : " << i << " argc : " << argc << endl;

								// insert option and value in map
								this->insertToOptions(param, value);
						/*	} else {
								cout << "Error: No argument has been given!" << endl;
								return;
							}*/
														
							
							
						} else {
							// we have an option which needs a value, but has not an equal sign at the right position
							cout << "Error: the option -" << cur_opt << " requires a value, so either there is no equal sign or it is not at right place i.e. -" << cur_opt << "=value" << endl;
							return;
						}
					} else {
						// if option needs no value
						// insert in map
						this->insertToOptions(this->charToString(cur_opt), "");
					}
					
				} else {
					cout << "Error: the given option -" << *s_it << " is not a valid option!" << endl;
					return;
				}
				
				continue;
			} else {
				// either there is no minus or it is not at first position
				// so use the param as an argument
				// save the argument
				arg->push_back(s);
				
				continue;
			}
		}
	}
}


CmdLine::~CmdLine() {
	delete opt;
	delete arg;
}

void CmdLine::insertToOptions(string key, string value) {
//	if (this->opt->size() < 1) {
		this->opt->insert(pair<string,string>(key, value));
/*		return true;
	}
	
	cout << "Warning: just one parameter is allowed, using first parameter!" << endl;
	return false;*/
}

string CmdLine::charToString(const char c) {
	string param;
	ostringstream os;
	os << c;
	param.append(os.str());
	
	return param;
}

bool CmdLine::isOptionValid(const char c) {
	if (c == 'p' || c == 'i' || c == 'q' || c == 's' || c == 't') {
		return true;
	}
	
	return false;
}

bool CmdLine::optionNeedValue(const char c) {
	if (c == 'q' || c == 's' || c == 't') {
		return true;
	}
	
	return false;
}

bool CmdLine::optionNeedArguments(const char c) {
	// all options need at least one argument
	return this->isOptionValid(c);
}

void CmdLine::printOptions() {
	for (map<string, string>::iterator m_it = opt->begin(); m_it!=opt->end(); m_it++) {
	    cout << m_it->first << endl;
	}
}

void CmdLine::printArguments() {
	for (vector<string>::iterator it = arg->begin(); it!=arg->end(); ++it) {
	    cout << *it << endl;
	}
}

bool CmdLine::hasOptions() {	
	return !opt->empty();
}

bool CmdLine::hasArguments() {
	return !arg->empty();
}

map<string,string> CmdLine::getOptions() {
	return *opt;
}

vector<string> CmdLine::getArguments() {
	return *arg;
}