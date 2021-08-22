#include "UI.h"

UI::UI() {

}

void UI::GetPaths(std::string *inputPath, std::string *outputPath) {
    // get input path
    std::cout << "Please enter input path (relative) | Press enter for default (input.txt): ";
    std::getline(std::cin, *inputPath);

    // get output path
    std::cout << "Please enter output path (relative) | Press enter for default (output.txt): ";
    std::getline(std::cin, *outputPath);
}