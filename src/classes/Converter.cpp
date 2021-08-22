#include "Converter.h"
#include <regex>

Converter::Converter() {
    reader = new Reader("config.txt");
    std::cout << "Reading config ..." << std::endl;
    reader->ReadFile(std::bind(&Converter::RegisterCommand, this, std::placeholders::_1));
    std::cout << "Done"; // write time taken
}

std::vector<std::string> Converter::Convert(std::vector<std::string> line) {
    std::vector<std::string> lines;
    for (int i = 0; i < commands.size(); i++) {
        std::string lineToPush;
        if (std::get<0>(commands[i]) == CommandType::AHS)
            lines.push_back(std::get<1>(commands[i]));
        else {
            std::string lineToPush = "SEND, " + std::get<1>(commands[i]);
            for (int argumentIndex = 0; argumentIndex < line.size(); argumentIndex++) {
                lineToPush = std::regex_replace(lineToPush, std::regex("(\\$" + std::to_string(argumentIndex) + ")+"), line[argumentIndex]);
            }
            lines.push_back(lineToPush);
        }
            
    }

    return lines;
}

void Converter::RegisterCommand(std::string line) {
    if (line == "Commands")
        readingCommands = true;
    else if (readingCommands) {
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
    } else
        return;
}