#include <iostream>
#include <cstdlib>
#include "controller.h"
#include "indexparser.h"  // temporary including of IndexParser class

int main (int argc, char *argv[]) {
	Controller *ctr = new Controller(argc, argv);
	delete ctr;	
	
	// Temporary creating of IndexParser object. Will be deleted after testing.
	//IndexParser *ip = new IndexParser();
	//delete ip;
	
	return EXIT_SUCCESS;
}
