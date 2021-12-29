// MarkDown Content Table Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "InputHandler.h"
#include "MDContentTableGenerator.h"
using namespace std; 

int main(int argc, char** argv) {
	if (InputHandler::handleCommandLineArgs(argc, argv) == -1) return 0;

	string filename = argv[1];
	string outputFileName = filename.substr(0, filename.size() - 3) + " (ctable-gen).md";

	MDContentTableGenerator* generator = new MDContentTableGenerator(filename);
	if (argc > 2) generator->setHeaderLevelStart(atoi(argv[2]));

	//// NOTE: Don't forget to call generate()
	generator->generate();
	generator->saveGeneratedToFile(outputFileName);
	cout << outputFileName << " has been generated successfully!" << endl;

	return 0;
}
