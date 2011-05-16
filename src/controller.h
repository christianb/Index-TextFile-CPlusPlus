/** Class Controller
 *
 *  This class controlls the flow of this programm.
 *
 *  author  Christian Bunk
 *  date    3.5.2011
 *  version 0.1
 */

#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <algorithm>

#include "cmdline.h"
#include "index.h"
#include "indexparser.h"

using namespace std;

class Controller {
private:

public:
	/**
	 * Takes the arguments from main function call.s
	 */
	Controller(int argc, char *argv[]);
	~Controller();
	
};

#endif	/* _CONTROLLER_H */