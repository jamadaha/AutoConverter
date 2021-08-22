#ifndef UI_H
#define UI_H

#include <string>
#include <tuple>
#include <iostream>


class UI {
    public:
    UI();

    void GetPaths(std::string *inputPath, std::string *outputPath);
};

#endif