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
    std::vector<std::string> Convert(std::vector<std::string> line);

    private:
    Config *config;
    
};

#endif