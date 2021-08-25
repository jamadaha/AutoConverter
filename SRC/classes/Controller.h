#ifndef Controller_H
#define Controller_H

#include "Reader.h"
#include "Writer.h"
#include "Converter.h"
#include "Config.h"
#include "Consts.h"

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
    Config *config;
    Reader *reader;
    Writer *writer;
    Converter *converter;
    int lineCount = 0;
    bool runningGMConversion = false;

    void Convert();

};

#endif