#include "Config.h"

void Config::ReadConfig() {
    reader = new Reader("config.txt");
    reader->ReadFile(std::bind(&Config::HandleConfigLine, this, std::placeholders::_1));
}

void Config::HandleConfigLine(std::vector<std::string> line) {
    if (line[0] == "InputFile")
        inputFile = line[1];
    else if (line[0] == "GMInput")
        GMInput = line[1];
    else if (line[0] == "OutputFile")
        outputFile = line[1];
    else if (line[0] == "GMInput")
        GMOutput = line[1];
    else if (line[0] == "Keybind")
        keybind = line[1];
    else if (line[0] == "Commands")
        readingCommands = true;
    else if (readingCommands) {
        std::string stringLine = "";
        for (int i = 0; i < line.size(); i++)
            stringLine += line[i] + " ";
        RegisterCommand(stringLine);
    }
}

void Config::RegisterCommand(std::string line) {
    CommandType type;
    // ignore comments
    if (line[0] == '#' || line.length() == 0)
        return;
    else if (line[0] == '-')
        type = CommandType::Say;
    else if (line[0] == '_')
        type = CommandType::AHS;
    else
        type = CommandType::None;

    line.erase(0, 1);

    commands.push_back(std::tuple<CommandType, std::string>(type, line));
}