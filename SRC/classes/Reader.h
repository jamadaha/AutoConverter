#ifndef READER_H
#define READER_H

#include <string>
#include <fstream>
#include <functional>
#include <vector>
#include <iostream>

class Reader {
    public:
    Reader(std::string path);
    void ReadFile(std::function<void(std::string)> onLineCallback);
    void ReadFile(std::function<void(std::vector<std::string>)> onLineCallback);

    private:
    std::string path;

    // splits line based on whole words - use for csv files
    std::vector<std::string> RegexSplit(std::string input);
};

#endif