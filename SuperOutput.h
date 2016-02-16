#ifndef COMPUTERGAME_SUPEROUTPUT_H
#define COMPUTERGAME_SUPEROUTPUT_H

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;



class SuperOutput
{
private:
    ofstream file;
public:
    SuperOutput(string filename);
    void print(string input);
    void println();
    void println(string input);
    void printFile(string input);
    void printlnFile();
    void printlnFile(string input);
    void close();
};

#endif COMPUTERGAME_SUPEROUTPUT_H
