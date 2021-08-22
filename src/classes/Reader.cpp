#include "Reader.h"

Reader::Reader(std::string path) {
    this->path = path;
}

void Reader::ReadFile(std::function<void(std::string)> onLineCallback) {
    std::fstream InputFile;
	InputFile.open(path, std::ios::in);
	if (InputFile.is_open()) {
		std::string line;
		while (std::getline(InputFile, line)) {
			onLineCallback(line);
		}
		InputFile.close();
	}
}