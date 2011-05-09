#include <iostream>
#include <cstdlib>
#include "controller.h"

int main (int argc, char *argv[]) {
	Controller *ctr = new Controller(argc, argv);
	delete ctr;	
	return EXIT_SUCCESS;
}
