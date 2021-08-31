#include "Converter.h"
#include <regex>

Converter::Converter(Config *config) {
    this->config = config;
}

std::vector<std::string> Converter::ConvertAHK(std::vector<std::string> line) {
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

std::vector<std::string> Converter::ConvertLog(std::vector<std::string> line) {
    std::vector<std::string> lines;
    lines.push_back(line[0]); // timestamp
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == "Command:") {
            lines.push_back(line[i + 1]); // command
            int offset = 2;
            int addedArgumentCount = 0;
            while (line[i + offset + addedArgumentCount][0] != '[') {
                lines.push_back(line[i + offset + addedArgumentCount]); // argument
                addedArgumentCount++;
            }
            for (int missingArgument = addedArgumentCount; missingArgument < maxArgumentCount; missingArgument++)
                lines.push_back("");
        } else if (line[i] == "[Player:") {
            lines.push_back(line[i + 1]); // player
            int appendIndex = 2;
            while (line[i + appendIndex] != "(GUID") {
                lines[lines.size() - 1] += " " + line[i + appendIndex];
                appendIndex++;
            }
        } else if (line[i] == "X:") {
            lines.push_back(line[i + 1]); // xCor
        } else if (line[i] == "Y:") {
            lines.push_back(line[i + 1]); // yCor
        } else if (line[i] == "Z:") {
            lines.push_back(line[i + 1]); // zCor
        } else if (line[i] == "Map:") {
            lines.push_back(line[i + 1]); // mapID
            lines.push_back(line[i + 2]); // mapName
            int appendIndex = 3;
            while (line[i + appendIndex] != "Area:") {
                lines[lines.size() - 1] += " " + line[i + appendIndex];
                appendIndex++;
            }
            lines[lines.size() - 1].erase(0, 1);
            lines[lines.size() - 1].erase(lines[lines.size() - 1].size() - 1);
        } else if (line[i] == "Area:") {
            lines.push_back(line[i + 1]); // areaID
            lines.push_back(line[i + 2]); // areaName
            int appendIndex = 3;
            while (line[i + appendIndex] != "Zone:") {
                lines[lines.size() - 1] += " " + line[i + appendIndex];
                appendIndex++;
            }
            lines[lines.size() - 1].erase(0, 1);
            lines[lines.size() - 1].erase(lines[lines.size() - 1].size() - 1);
        } else if (line[i] == "Zone:") {
            lines.push_back(line[i + 1]); // areaID
            lines.push_back(line[i + 2]); // areaName
            int appendIndex = 3;
            while (line[i + appendIndex] != "Selected:") {
                lines[lines.size() - 1] += " " + line[i + appendIndex];
                appendIndex++;
            }
            lines[lines.size() - 1].erase(0, 1);
            lines[lines.size() - 1].erase(lines[lines.size() - 1].size() - 1);
        }
            
    }

    return lines;
}

 void Converter::GetMaxArgumentCount(std::vector<std::string> line) {
    int tempArgCount = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == "Command:") {
            int offset = 2;
            while (line[i + offset][0] != '[') {
                tempArgCount++;
                i++;
            }
            if (tempArgCount > maxArgumentCount)
                maxArgumentCount = tempArgCount;
            return;
        }
    }
 }