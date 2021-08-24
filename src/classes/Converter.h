#ifndef CONVERTER_H
#define CONVERTER_H

#include "Reader.h"
#include "Consts.h"
#include "Config.h"

#include <string>
#include <iostream>
#include <vector>
#include <tuple>


class Converter {
    public:
    Converter(Config *config);
    std::vector<std::string> ConvertAHK(std::vector<std::string> line);
    std::vector<std::string> ConvertLog(std::vector<std::string> line);
    void GetMaxArgumentCount(std::vector<std::string> line);
    int maxArgumentCount = 0;

    private:
    Config *config;
    

};

#endif