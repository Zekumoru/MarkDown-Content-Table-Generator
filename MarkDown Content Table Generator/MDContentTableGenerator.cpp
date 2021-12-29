#include "MDContentTableGenerator.h"

MDContentTableGenerator::MDContentTableGenerator() : startWithHeaderLevel(1), file(nullptr), generated("") {}

MDContentTableGenerator::MDContentTableGenerator(std::string filename) : MDContentTableGenerator() {
	openFile(filename);
}

MDContentTableGenerator::MDContentTableGenerator(std::string filename, int startWithHeaderLevel) : MDContentTableGenerator() {
	openFile(filename);
	setHeaderLevelStart(startWithHeaderLevel);
}

MDContentTableGenerator::~MDContentTableGenerator() {
	if (file != nullptr) file->close();
}

void MDContentTableGenerator::openFile(std::string filename) {
	file = new std::ifstream(filename);
}

void MDContentTableGenerator::setHeaderLevelStart(int startWithHeaderLevel) {
	this->startWithHeaderLevel = startWithHeaderLevel;
}

std::string MDContentTableGenerator::generate() {
	if (file == nullptr) return "";
	std::string line;
	while (std::getline(*file, line)) {
		generated += generateLine(line);
	}
	return generated;
}

/**
* syntax: - [text](#link)
*/
std::string MDContentTableGenerator::generateLine(std::string line) {
	if (line.empty()) return "";

	// check if it does not start with '#'
	if (line.front() != '#') return "";

	// identify how many #, ie., header level
	int headerLevel;
	for (headerLevel = 0; headerLevel < 7; headerLevel++)
		if (line.at(headerLevel) != '#') break;

	// ignore line if it has 7 or more '#'
	if (headerLevel == 7) return "";

	// check if header level is to ignore
	if (headerLevel < startWithHeaderLevel) return "";

	// remove leading '#' and whitespaces after it
	line = line.substr(headerLevel);
	line = line.substr(line.find_first_not_of(" \t"));

	// generate table row
	std::string generatedLine = "";

	// handle indentation and bullet list
	for (int i = startWithHeaderLevel; i < headerLevel; i++)
		generatedLine += "  ";
	if (startWithHeaderLevel != headerLevel) generatedLine += "- ";

	// handle text
	generatedLine += "[" + line + "](#";

	// handle link
	bool shouldIgnoreHyphen = true;
	std::string link = "";
	for (int i = 0; i < line.size(); i++)
		if (std::isalnum(line.at(i)) || line.at(i) == '-')
			link += std::tolower(line.at(i));
		else if (line.at(i) == ' ')
			link += "-";
	generatedLine += link;

	// handle duplicates
	if (idTable.find(link) == idTable.end()) {
		idTable[link] = 0;
	}
	else {
		idTable[link]++;
		generatedLine += "-" + std::to_string(idTable[link]);
	}

	// done
	return generatedLine + ")\n";
}

void MDContentTableGenerator::saveGeneratedToFile(std::string outputFileName) {
	std::ofstream output(outputFileName);
	output << generated;
	output.close();
}