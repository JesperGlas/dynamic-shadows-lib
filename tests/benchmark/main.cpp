#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>

const std::string OUT = "../benchmark_out/";

int main(int argc, char **argv)
{
    // Generate file name
    std::stringstream ss;
    time_t t = time(0);
    struct tm * now = localtime(&t);
    ss << OUT;
    ss << "Benchmark_";
    ss << "T" << now->tm_hour << ":" << now->tm_min; // Time
    ss << "_";
    ss << "D" << now->tm_mday << "-" << now->tm_mon + 1 << "-" << now->tm_year + 1900;
    ss << ".txt\n";
    std::string file_name = ss.str();

    // Create/open file
    std::fstream file;
    file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!file)
    {
        std::cout << "[Error] Could not open file " << file_name << std::endl;
    }
    else
    {
        std::cout << "writing to file" << std::endl;
        file << "Hello benchmark" << std::endl;
    }

    file.close();

    return 0;
}