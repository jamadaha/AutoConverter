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
    void RegisterCommand(std::string line);

    private:
    enum class CommandType {
        None,
        AHS,
        Say
    };

    std::vector<std::tuple<CommandType, std::string>> commands;
    bool readingCommands = false;

    
};

#endif