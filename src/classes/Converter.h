#ifndef CONVERTER_H
#define CONVERTER_H

#include "Reader.h"

#include <string>
#include <iostream>
#include <vector>
#include <tuple>


class Converter {
    public:
    Converter();
    std::vector<std::string> Convert(std::vector<std::string> line);

    private:
    enum class CommandType {
        None,
        AHS,
        Say
    };

    std::vector<std::tuple<CommandType, std::string>> commands;
    Reader *reader;
    bool readingCommands = false;

    void OnLine(std::string line);
};

#endif