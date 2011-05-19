#include <iostream>
#include <string>

#include "controller.h"

using namespace std;

int main (int argc, char *argv[]) {
	Controller *ctr = new Controller(argc, argv);
	delete ctr;
	
	return EXIT_SUCCESS;
}
