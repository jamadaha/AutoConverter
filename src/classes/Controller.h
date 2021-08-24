#ifndef Controller_H
#define Controller_H

#include "Reader.h"
#include "Writer.h"
#include "Converter.h"

#include <string>
#include <functional>
#include <vector>
#include <iostream>

class Controller {
    public:
    Controller();
    void CountLine(std::string line);
    void ConvertInputLine(std::vector<std::string> line);
    void Start();

    private:
    Reader *reader;
    Writer *writer;
    Converter *converter;
    int lineCount = 0;

    void Convert();
    void HandleConfigLine(std::vector<std::string> lines);
    void ReadConfig();

};

#endif