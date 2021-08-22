#include "Controller.h"

Controller::Controller(UI *ui) {
    this->ui = ui;

    converter = new Converter();

    std::string inputPath;
    std::string outputPath;

    ui->GetPaths(&inputPath, &outputPath);

    if (inputPath.length() == 0) {
        std::cout << "No input path given. Using input.txt" << std::endl;
        reader = new Reader("input.txt");
    } else
        reader = new Reader(inputPath);

    if (outputPath.length() == 0) {
        std::cout << "No output path given. Using output.ahk" << std::endl;
        writer = new Writer("output.ahk");
    } else
        writer = new Writer(outputPath);
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
    std::cout << "Done"; // write time taken

    writer->Finish();
}