#pragma once
#include <string>
#include <fstream>
#include <unordered_map>

class MDContentTableGenerator {
public:
	MDContentTableGenerator(std::string);
	MDContentTableGenerator(std::string, int);
	~MDContentTableGenerator();

	void openFile(std::string);
	void setHeaderLevelStart(int);
	int generate();

	void saveGeneratedToFile(std::string);

private:
	int startWithHeaderLevel;
	std::ifstream* file;
	std::string generated;
	std::unordered_map<std::string, int> idTable;

	MDContentTableGenerator();
	std::string generateLine(std::string);
};