#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

class InputHandler {
public:
	static void setVersionName(const char*);
	static int handleCommandLineArgs(int, char**);

private:
	static std::string versionName;
	static const char* HELP_DOC;
};
