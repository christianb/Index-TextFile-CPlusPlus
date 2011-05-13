#include <iostream>
#include <cstdlib>
#include "controller.h"
#include "indexparser.h"  // temporary including of IndexParser class

int main (int argc, char *argv[]) {
	Controller *ctr = new Controller(argc, argv);
	delete ctr;
	
	return EXIT_SUCCESS;
}
