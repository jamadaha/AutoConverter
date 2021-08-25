#include "Controller.h"

Controller::Controller() {
    config = new Config();
    config->ReadConfig();
    converter = new Converter(config);
    try {
        std::cout << "Checking for GMLog input ..." << std::endl;
        reader = new Reader(config->GMInput);
        std::cout << "Found. Proceding with file" << std::endl;
        writer = new Writer(config->GMOutput);
        runningGMConversion = true;
    } catch (std::invalid_argument::exception e) {
        std::cout << "Found none, using default input" << std::endl;
        reader = new Reader(config->inputFile);
        writer = new Writer(config->outputFile);
    }
    if (runningGMConversion) {
        reader->ReadFile(std::bind(&Converter::GetMaxArgumentCount, converter, std::placeholders::_1));
        writer->InitiateWrite(converter->maxArgumentCount);
    } else
        writer->InitiateWrite(config->keybind);
}

void Controller::CountLine(std::string line) {
    lineCount++;
}

void Controller::ConvertInputLine(std::vector<std::string> line) {
    if (runningGMConversion)
        writer->WriteToCSVFile(converter->ConvertLog(line));
    else
        writer->WriteToFile(converter->ConvertAHK(line));
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