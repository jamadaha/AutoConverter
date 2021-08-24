#include "Reader.h"

#include <regex>
#include <stdexcept>

Reader::Reader(std::string path) {
    this->path = path;
	std::fstream file;
	file.open(path);
	if (!file.is_open())
		throw std::invalid_argument("File does not exist");
	else
		file.close();
}

void Reader::ReadFile(std::function<void(std::string)> onLineCallback) {
	std::cout << "-Reading file " << path << std::endl;
    std::fstream InputFile;
	InputFile.open(path, std::ios::in);
	if (InputFile.is_open()) {
		std::string line;
		while (std::getline(InputFile, line)) {
			onLineCallback(line);
		}
		InputFile.close();
	}
	std::cout << "-Done" << std::endl;
}

void Reader::ReadFile(std::function<void(std::vector<std::string>)> onLineCallback) {
	std::cout << "-Reading file " << path << std::endl;
    std::fstream InputFile;
	InputFile.open(path, std::ios::in);
	if (InputFile.is_open()) {
		std::string line;
		while (std::getline(InputFile, line)) {
			onLineCallback(RegexSplit(line));
		}
		InputFile.close();
	}
	std::cout << "-Done" << std::endl;
}

std::vector<std::string> Reader::RegexSplit(std::string input) {
	std::regex regex ("(\\s|,)+");

	std::vector<std::string> out(
		std::sregex_token_iterator(input.begin(), input.end(), regex, -1),
        std::sregex_token_iterator());

	return out;
}