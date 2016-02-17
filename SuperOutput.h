#include <bits/stringfwd.h>

#ifndef COMPUTERGAME_SUPEROUTPUT_H
#define COMPUTERGAME_SUPEROUTPUT_H

#include <iostream>
#include <stdlib.h>
#include <fstream>

class SuperOutput
{
private:
    std::ofstream file;
public:
    SuperOutput(std::string filename);
    void to_string(int num);
    void print(std::string input);
    void println();
    void println(std::string input);
    void printFile(std::string input);
    void printlnFile();
    void printlnFile(std::string input);
    void close();
};

#endif COMPUTERGAME_SUPEROUTPUT_H
