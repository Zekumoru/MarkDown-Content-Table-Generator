#pragma once
#include <iostream>
#include <cstdlib>

class InputHandler {
public:
	static int handleCommandLineArgs(int, char**);

private:
	static const char* HELP_DOC;
};
