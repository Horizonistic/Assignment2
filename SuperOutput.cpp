#include <iostream>
#include <fstream>

using namespace std;

class SuperOutput
{
private:
    ofstream file;

public:
    SuperOutput(string filename) {
        this->file.open(filename);
    }

    void print(string input) {
        cout << input;
        this->file << input;
    }

    void println() {
        cout << "\n";
        this->file << "\n";
    }

    void println(string input) {
        cout << endl << input;
        this->file << endl << input;
    }

    void printFile(string input) {
        this->file << input;
    }

    void printlnFile()
    {
        this->file << endl;
    }

    void printlnFile(string input)
    {
        this->file << endl << input;
    }

    void close()
    {
        this->file.close();
    }
};
