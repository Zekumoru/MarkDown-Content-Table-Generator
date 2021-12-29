#include "InputHandler.h"

const char* InputHandler::HELP_DOC =
    "MarkDown Table of Contents Generator (by ZekumoruDGH) - Help Section\n"
	"-h --help  \t opens this help section\n"
	"<filename> \t provide file by filename\n"
	"\n"
	"<filename> <headerLevel> \t provide file by filename, must also include extension '.md'\n"
	"                         \t headerLevel must be an int between 1 - 6\n"
	"\n"
	"Header level ignores previous header levels\n"
	"Example: Providing 3 will ignore header level 1 and 2, in other words,\n"
	"         headers that start with '#' and '##'\n";

int InputHandler::handleCommandLineArgs(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "Please specify a file. Type -h or --help to see available commands." << std::endl;
		return -1;
	}

	std::string arg1 = argv[1];
	// Check if help
	if (arg1 == "-h" || arg1 == "--help") {
		std::cout << HELP_DOC;
		return -1;
	}

	// Check extension if '.md'
	if (arg1.size() <= 3 ||
		arg1.substr(arg1.size() - 3) != ".md") {
		std::cout << "Make sure the file has an '.md' extension." << std::endl;
		return -1;
	}

	// Check if second argument is an integer between 1 - 6
	if (argc > 2) {
		std::string arg2 = argv[2];
		if (arg2.size() > 1 || !std::isdigit(arg2.front()))
			std::cout << "Invalid second argument: " << arg2 <<
			". Insert integer between 1 and 6." << std::endl;
		int n = std::atoi(argv[2]);
		if (n < 1 || n > 6) std::cout << "Second argument out of bounds." <<
			". Insert integer between 1 and 6." << std::endl;
	}

	return 0;
}
