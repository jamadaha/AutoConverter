#ifndef READER_H
#define READER_H

#include <string>
#include <fstream>
#include <functional>

class Reader {
    public:
    Reader(std::string path);
    void ReadFile(std::function<void(std::string)> onLineCallback);

    private:
    std::string path;
};

#endif