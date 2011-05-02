#include <iostream>
#include "cmdline.h"

int main (int argc, char *argv[]) {
	CmdLine *params = new CmdLine(argc, argv);
	params->printOptions();
	params->printArguments();
	return EXIT_SUCCESS;
}