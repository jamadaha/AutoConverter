#ifndef WRITER_H
#define WRITER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class Writer {
    public:
    Writer(std::string path);
    void WriteToFile(std::vector<std::string> lines);
    void WriteToCSVFile(std::vector<std::string> lines);

    void InitiateWrite(int maxArgumentCount);
    void InitiateWrite(std::string keybind);
    void Finish();

    private:
    std::string path;
    std::ofstream outFile;
};

#endif