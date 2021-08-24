#include "Controller.h"

Controller::Controller() {
    converter = new Converter();

    ReadConfig();
}

void Controller::CountLine(std::string line) {
    lineCount++;
}

void Controller::ConvertInputLine(std::vector<std::string> line) {
    writer->WriteToFile(converter->Convert(line));
}

void Controller::Convert() {
    reader->ReadFile(std::bind(&Controller::ConvertInputLine, this, std::placeholders::_1));
}

void Controller::HandleConfigLine(std::vector<std::string> lines) {
    if (lines[0] == "InputFile")
        reader = new Reader(lines[1]);
    else if (lines[0] == "OutputFile")
        writer = new Writer(lines[1]);
    else if (lines[0] == "Keybind")
        writer->InitiateWrite(lines[1]);
}

void Controller::ReadConfig() {
    Reader *reader = new Reader("config.txt");
    reader->ReadFile(std::bind(&Controller::HandleConfigLine, this, std::placeholders::_1));
    reader->ReadFile(std::bind(&Converter::RegisterCommand, converter, std::placeholders::_1));
}

void Controller::Start() {
    std::cout << "Counting lines ..." << std::endl;
    reader->ReadFile(std::bind(&Controller::CountLine, this, std::placeholders::_1));
    std::cout << "Done - Counted " << lineCount << " lines" << std::endl;
    std::cout << "Converting lines ..." << std::endl;
    Convert();
    std::cout << "Done" << std::endl; // write time taken

    writer->Finish();
}