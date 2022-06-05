#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <map>
#include <chrono>
#include <cmath>

#include "math.hpp"
#include "shape2D.hpp"

std::map<size_t, std::map<std::string, double>> T_DATA;
std::map<size_t, std::map<std::string, double>> N_DATA;
std::map<size_t, std::map<std::string, double>> H_DATA;
const std::string OUT = "../benchmark_out/";

void generateColumn(size_t vert_size, size_t rounds)
{
    auto c = ds::point2D(2, 2);
    auto r = 10.f;
    auto ls = c + (r * 1.1f);
    auto ls_c = c - r;
    auto ls_r = ls.magnitude(ls_c);
    auto sh = ds::shape2D(c, r, vert_size);
    auto be = ds::line2D();
    const double div {1.0 / (double)rounds};
    std::map<std::string, double> avg;

    // init avg
    for (std::string func : ds::getFuncNames())
        avg.insert({func, 0.0});

    for (size_t i {0}; i < rounds; i++)
    {
        ls = ls.rotate(ds::degToRad(1.f), ls_c);
        ds::resetCounters();
        try
        {
            be = sh.getBlockingEdge(ls);
            auto copy = ds::copyCounter();
            std::map<std::string, double>::iterator it;
            for (it = copy.begin(); it != copy.end(); it++)
                avg.at(it->first) += it->second * div;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    T_DATA[vert_size] = std::map<std::string, double>(avg);

    avg.clear();
    for (std::string func : ds::getFuncNames())
        avg.insert({func, 0.0});

    for (size_t i {0}; i < rounds; i++)
    {
        ls = ls.rotate(ds::degToRad(1.f), ls_c);
        ds::resetCounters();
        try
        {
            be = sh.getBlockingEdgeNaive(ls);
            auto copy = ds::copyCounter();
            std::map<std::string, double>::iterator it;
            for (it = copy.begin(); it != copy.end(); it++)
                avg.at(it->first) += (it->second * div);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    N_DATA[vert_size] = std::map<std::string, double>(avg);

    avg.clear();
    for (std::string func : ds::getFuncNames())
        avg.insert({func, 0.0});

    for (size_t i {0}; i < rounds; i++)
    {
        ls = ls.rotate(ds::degToRad(1.f), ls_c);
        ds::resetCounters();
        try
        {
            be = sh.getBlockingEdgeHybrid(ls);
            auto copy = ds::copyCounter();
            std::map<std::string, double>::iterator it;
            for (it = copy.begin(); it != copy.end(); it++)
                avg.at(it->first) += it->second * div;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    H_DATA[vert_size] = std::map<std::string, double>(avg);
}

void buildTable(std::fstream &out)
{
    std::vector<std::string> funcs = ds::getFuncNames();

    std::vector<size_t> vert_n;
    std::map<size_t, std::map<std::string, double>>::iterator it;
    for (it = T_DATA.begin(); it != T_DATA.end(); it++)
        vert_n.push_back(it->first);
    
    out << "\\begin{tabular}{l|";
    for (size_t i {0}; i < T_DATA.size(); i++)
        out << "ccc|";
    out << "r}\n";

    out << "\tVertices &";

    for (size_t i : vert_n)
        out << "\\multicolumn{3}{|c|}{" << i << "} &";

    out << "\\\\\n";

    out << "\tF &";
    for (size_t i {0}; i < T_DATA.size(); i++)
        out << " T & N & H &";
    out << "\\\\\n";

    out << "\t\\hline\n";

    for (size_t row {0}; row < funcs.size(); row++)
    {
        out << "\t" << funcs.at(row) << " & ";
        for (size_t i : vert_n)
        {
            // trig output
            if (T_DATA.find(i) != T_DATA.end())
            {
                if (T_DATA.at(i).find(funcs.at(row)) == T_DATA.at(i).end())
                    out << "0";
                else
                    out << round(T_DATA.at(i).at(funcs.at(row)));
            }
            out << " & ";

            // naive output
            if (N_DATA.find(i) != N_DATA.end())
            {
                if (N_DATA.at(i).find(funcs.at(row)) == N_DATA.at(i).end())
                    out << "0";
                else
                    out << round(N_DATA.at(i).at(funcs.at(row)));
            }
            out << " & ";

            // hybrid output
            if (H_DATA.find(i) != H_DATA.end())
            {
                if (H_DATA.at(i).find(funcs.at(row)) == H_DATA.at(i).end())
                    out << "0";
                else
                    out << round(H_DATA.at(i).at(funcs.at(row)));
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
        
        generateColumn(3, 1000);
        generateColumn(50, 1000);
        buildTable(file);
    }

    file.close();
    std::cout << "Wrote to file: " << file_name << std::endl;
}

void generateFlopData(const int n, const int rounds)
{
    auto c = ds::point2D(2, 2);
    auto r = 10.f;
    auto ls = c + (r * 1.1f);
    auto ls_c = c - r;
    auto ls_r = ls.magnitude(ls_c);
    auto sh = ds::shape2D(c, r, 3);
    auto be = ds::line2D();

    std::vector<int> x(n);
    std::vector<int> yN;
    std::vector<int> yT;
    std::vector<int> yH;

    double avg {0};
    const double div = 1 / (double)rounds;

    for (size_t i {0}; i < x.size(); i++)
    {
        sh = ds::shape2D(c, r, i+3);

        avg = 0;
        for (size_t i {0}; i < rounds; i++)
        {
            ls = ls.rotate(ds::degToRad(1.f), ls_c);

            ds::resetCounters();
            be = sh.getBlockingEdge(ls);
            avg += ds::getFlops() * div;
        }
        yT.push_back(avg);

        avg = 0;
        for (size_t i {0}; i < rounds; i++)
        {
            ls = ls.rotate(ds::degToRad(1.f), ls_c);

            ds::resetCounters();
            be = sh.getBlockingEdgeNaive(ls);
            avg += ds::getFlops() * div;
        }
        yN.push_back(avg);

        avg = 0;
        for (size_t i {0}; i < rounds; i++)
        {
            ls = ls.rotate(ds::degToRad(1.f), ls_c);

            ds::resetCounters();
            be = sh.getBlockingEdgeHybrid(ls);
            avg += ds::getFlops() * div;
        }
        yH.push_back(avg);
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

    file << "Vertices, Naive, Trigonometric, Hybrid\n";
    for (size_t i {0}; i < yN.size(); i++)
    {
        file << i+3 << ", " << yN.at(i) << ", " << yT.at(i) << ", " << yH.at(i) << "\n";
    }

    file.close();
    std::cout << "Wrote to file: " << file_name << std::endl;
}

void generateRuntimeData(const int vert, const int rounds)
{
    auto c = ds::point2D(2, 2);
    auto r = 10.f;
    auto ls = c + (r * 1.1f);
    auto ls_c = c - r;
    auto ls_r = ls.magnitude(ls_c);
    auto sh = ds::shape2D(c, r, 3);
    auto be = ds::line2D();

    std::vector<int> x(vert);
    std::vector<int> yN;
    std::vector<int> yT;
    std::vector<int> yH;

    for (size_t i {0}; i < x.size(); i++)
    {
        sh = ds::shape2D(c, r, i+3);
        double avg {0};
        double div = 1 / (double)rounds;

        for (size_t n {0}; n < rounds; n++)
        {
            ls = ls.rotate(ds::degToRad(1.f), ls_c);

            auto start = std::chrono::steady_clock::now();
            be = sh.getBlockingEdge(ls);
            auto end = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            avg += elapsed * div;
        }
        yT.push_back(avg);
        avg = 0;

        for (size_t n {0}; n < rounds; n++)
        {
            ls = ls.rotate(ds::degToRad(1.f), ls_c);

            auto start = std::chrono::steady_clock::now();
            be = sh.getBlockingEdgeNaive(ls);
            auto end = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            avg += elapsed * div;
        }
        yN.push_back(avg);
        avg = 0;
                
        for (size_t n {0}; n < rounds; n++)
        {
            ls = ls.rotate(ds::degToRad(1.f), ls_c);

            auto start = std::chrono::steady_clock::now();
            be = sh.getBlockingEdgeHybrid(ls);
            auto end = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            avg += elapsed * div;
        }
        yH.push_back(avg);
        avg = 0;
    }

    std::stringstream ss;
    time_t t = time(0);
    struct tm * now = localtime(&t);
    ss << OUT;
    ss << "Runtime_";
    ss << "T" << now->tm_hour << ":" << now->tm_min; // Time
    ss << "_";
    ss << "D" << now->tm_mday << "-" << now->tm_mon + 1 << "-" << now->tm_year + 1900;
    ss << ".csv\n";
    std::string file_name = ss.str();
    
    // Create/open file
    std::fstream file;
    file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::app);

    file << "Vertices, Naive, Trigonometric, Hybrid\n";
    for (size_t i {0}; i < yN.size(); i++)
    {
        file << i+3 << ", " << yN.at(i) << ", " << yT.at(i) << ", " << yH.at(i) << "\n";
    }

    file.close();
    std::cout << "Wrote to file: " << file_name << std::endl;
}

int main(int argc, char **argv)
{
    generateBenchmark();
    generateFlopData(25, 1000);
    generateRuntimeData(25, 1000);

    return 0;
}