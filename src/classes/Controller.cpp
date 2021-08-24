#include "Controller.h"

Controller::Controller() {
    config = new Config();
    config->ReadConfig();
    converter = new Converter(config);
    reader = new Reader(config->inputFile);
    writer = new Writer(config->outputFile);
    writer->InitiateWrite(config->keybind);
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

void Controller::Start() {
    std::cout << "Counting lines ..." << std::endl;
    reader->ReadFile(std::bind(&Controller::CountLine, this, std::placeholders::_1));
    std::cout << "Done - Counted " << lineCount << " lines" << std::endl;
    std::cout << "Converting lines ..." << std::endl;
    Convert();
    std::cout << "Done" << std::endl; // write time taken

    writer->Finish();
}