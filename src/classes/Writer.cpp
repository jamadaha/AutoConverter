#include "Writer.h"

Writer::Writer(std::string path) {
    this->path = path;

	
}

void Writer::WriteToFile(std::vector<std::string> lines) {
	for (int i = 0; i < lines.size(); i++)
		outFile << lines[i] << std::endl;
}

void Writer::InitiateWrite(std::string keybind) {
	outFile.open(path);
	outFile.clear();
	outFile << 	"#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.; "
				"#Warn  ; Enable warnings to assist with detecting common errors."
				"SendMode Input  ; Recommended for new scripts due to its superior speed and reliability."
				"SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory."
				<< std::endl <<
				keybind << "::" << std::endl;
}

void Writer::Finish() {
	outFile.close();
}