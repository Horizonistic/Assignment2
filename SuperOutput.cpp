#include <iostream>
#include <fstream>

class SuperOutput
{
private:
    std::ofstream file;

public:
    SuperOutput(std::string filename)
    {
        this->file.open(filename);
    }

    void to_string(int num)
    {
        // Divide by 10, remainder and such
    }

    void print(std::string input)
    {
        std::cout << input;
        this->file << input;
    }

    void println()
    {
        std::cout << "\n";
        this->file << "\n";
    }

    void println(std::string input)
    {
        std::cout << std::endl << input;
        this->file << std::endl << input;
    }

    void printFile(std::string input)
    {
        this->file << input;
    }

    void printlnFile()
    {
        this->file << std::endl;
    }

    void printlnFile(std::string input)
    {
        this->file << std::endl << input;
    }

    void close()
    {
        this->file.close();
    }
};
