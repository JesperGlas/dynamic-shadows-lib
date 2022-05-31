#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <map>

#include "math.hpp"
#include "shape2D.hpp"

std::map<size_t, std::map<std::string, size_t>> T_DATA;
std::map<size_t, std::map<std::string, size_t>> N_DATA;
const std::string OUT = "../benchmark_out/";

void buildColumns(size_t vert_size)
{   
    auto ls = ds::point2D(8.f, 8.f);
    auto c = ds::point2D(-2.f, -2.f);
    auto r = 5.f;
    auto sh = ds::shape2D(c, r, vert_size);
    auto be = ds::line2D();

    ds::resetCounters();
    try
    {
        be = sh.getBlockingEdge(ls);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    T_DATA[vert_size] = std::map<std::string, size_t>(ds::copyCounter());

    ds::resetCounters();    
    try
    {
        be = sh.getBlockingEdgeNaive(ls);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    N_DATA[vert_size] = std::map<std::string, size_t>(ds::copyCounter());
}

void buildTable(std::fstream &out)
{
    std::vector<std::string> funcs = {
        "ds::sinf",
        "ds::asinf",
        "ds::cosf",
        "ds::acosf",
        "ds::tanf",
        "ds::atanf",
        "ds::sqrtf",
        "ds::powf",
        "ds::fmodf"
    };

    std::vector<size_t> vert_n;
    std::map<size_t, std::map<std::string, size_t>>::iterator it;
    for (it = T_DATA.begin(); it != T_DATA.end(); it++)
        vert_n.push_back(it->first);
    
    out << "\\begin{tabular}{l|";
    for (size_t i {0}; i < T_DATA.size(); i++)
        out << "cc|";
    out << "r}\n";

    out << "\tVertices &";

    for (size_t i : vert_n)
        out << "\\multicolumn{2}{|c|}{" << i << "} &";

    out << "\\\\\n";

    out << "\tF &";
    for (size_t i {0}; i < T_DATA.size(); i++)
        out << " T & N &";
    out << "\\\\\n";

    out << "\t\\hline\n";

    for (size_t row {0}; row < funcs.size(); row++)
    {
        out << "\t" << funcs.at(row) << " & ";
        for (size_t i : vert_n)
        {
            if (T_DATA.find(i) != T_DATA.end())
            {
                if (T_DATA.at(i).find(funcs.at(row)) == T_DATA.at(i).end())
                    out << "0";
                else
                    out << T_DATA.at(i).at(funcs.at(row));
            }

            out << " & ";

            if (N_DATA.find(i) != N_DATA.end())
            {
                if (N_DATA.at(i).find(funcs.at(row)) == N_DATA.at(i).end())
                    out << "0";
                else
                    out << N_DATA.at(i).at(funcs.at(row));
            }

            out << " & ";
        }
        out << "\\\\ \n";
    }

    out << "\\end{tabular}\n";
}

void generateBenchmark()
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
        std::cout << "[SUCCESS] Writing to file..." << std::endl;
        
        buildColumns(3);
        buildColumns(10);
        buildColumns(1000);
        buildTable(file);
    }

    file.close();
}

void generateFlopData()
{
    auto c = ds::point2D(2, 2);
    auto ls = ds::point2D(20, 20);
    auto r = 10.f;
    auto sh = ds::shape2D(c, r, 3);
    auto be = ds::line2D();

    int n {25};
    std::vector<int> x(n);
    std::vector<int> yN;
    std::vector<int> yT;

    for (size_t i {0}; i < n; i++)
    {

        sh = ds::shape2D(c, r, i+3);

        ds::resetCounters();
        be = sh.getBlockingEdge(ls);
        yT.push_back(ds::getFlops());

        ds::resetCounters();
        be = sh.getBlockingEdgeNaive(ls);
        yN.push_back(ds::getFlops());
    }

    std::stringstream ss;
    time_t t = time(0);
    struct tm * now = localtime(&t);
    ss << OUT;
    ss << "FlopData_";
    ss << "T" << now->tm_hour << ":" << now->tm_min; // Time
    ss << "_";
    ss << "D" << now->tm_mday << "-" << now->tm_mon + 1 << "-" << now->tm_year + 1900;
    ss << ".csv\n";
    std::string file_name = ss.str();
    
    // Create/open file
    std::fstream file;
    file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::app);

    for (size_t i {0}; i < yN.size(); i++)
    {
        file << i+3 << ", " << yN.at(i) << ", " << yT.at(i) << "\n";
    }

    file.close();
}

int main(int argc, char **argv)
{
    // generateBenchmark();
    generateFlopData();

    return 0;
}