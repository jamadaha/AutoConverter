#ifndef Controller_H
#define Controller_H

#include "UI.h"
#include "Reader.h"
#include "Writer.h"
#include "Converter.h"

#include <string>
#include <functional>
#include <vector>
#include <iostream>

class Controller {
    public:
    Controller(UI *ui);
    void CountLine(std::string line);
    void ConvertInputLine(std::vector<std::string> line);
    void Start();

    private:
    UI *ui;
    Reader *reader;
    Writer *writer;
    Converter *converter;
    int lineCount = 0;

    void Convert();

};

#endif