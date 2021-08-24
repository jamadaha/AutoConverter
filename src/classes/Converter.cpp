#include "Converter.h"
#include <regex>

Converter::Converter(Config *config) {
    this->config = config;
}

std::vector<std::string> Converter::Convert(std::vector<std::string> line) {
    std::vector<std::string> lines;
    for (int i = 0; i < config->commands.size(); i++) {
        std::string lineToPush;
        if (std::get<0>(config->commands[i]) == CommandType::AHS)
            lines.push_back(std::get<1>(config->commands[i]));
        else {
            std::string lineToPush = "SEND, " + std::get<1>(config->commands[i]);
            for (int argumentIndex = 0; argumentIndex < line.size(); argumentIndex++) {
                lineToPush = std::regex_replace(lineToPush, std::regex("(\\$" + std::to_string(argumentIndex) + ")+"), line[argumentIndex]);
            }
            lines.push_back(lineToPush);
        }
            
    }

    return lines;
}