#ifndef CONFIG_H
#define CONFIG_H

#include "Reader.h"
#include "Consts.h"

#include <string>
#include <vector>
#include <tuple>

class Config {
    public:
    std::string inputFile;
    std::string GMInput;
    std::string outputFile;
    std::string GMOutput;

    std::string keybind;
    std::vector<std::tuple<CommandType, std::string>> commands;

    void ReadConfig();

    private:
    Reader *reader;
    bool readingCommands = false;
    void HandleConfigLine(std::vector<std::string> line);
    void RegisterCommand(std::string line);
};

#endif