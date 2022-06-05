#include "math.hpp"

#include <cmath>

float ds::degToRad(float degrees)
{
    return degrees * ds::PI / 180.f;
}

float ds::radToDeg(float radians)
{
    return (radians * 180.f) / ds::PI;
}

float ds::sinf(float radians)
{
    addToCounter("sin");

    return std::sin(radians);
}

float ds::asinf(float radians)
{
    addToCounter("asin");

    return std::asin(radians);
}

float ds::cosf(float radians)
{
    addToCounter("cos");

    return std::cos(radians);
}

float ds::acosf(const float radians)
{
    addToCounter("acos");

    return std::acos(radians);
}

float ds::tanf(float radians)
{
    addToCounter("tan");

    return std::tan(radians);
}

float ds::atan2f(const float &y, const float &x)
{
    addToCounter("atan2");

    return std::atan2(y, x);
}

float ds::sqrtf(float radians)
{
    addToCounter("sqrt");

    return std::sqrt(radians);
}

float ds::powf(float base, float exp)
{
    addToCounter("pow");

    return std::pow(base, exp);
}

float ds::fmod(const float radians, const float div)
{
    addToCounter("fmod");

    return std::fmod(radians, div);
}

/* ##### BENCHMARKING EXTENSION ##### */

void ds::addToCounter(std::string func_name, const int n)
{
    if (ds::COUNTERS.find(func_name) == ds::COUNTERS.end())
        ds::COUNTERS[func_name] = n;
    else
        ds::COUNTERS[func_name] += n;
}

/**
 * @brief A function that resets the counters for the functioncalls.
 * 
 */
void ds::resetCounters()
{
    for (auto &item : ds::COUNTERS)
        item.second = 0;
}

/**
 * @brief Prints the static map of counters.
 * 
 */
void ds::printMathStats(const std::string msg)
{
    std::cout << "Stats: " << msg << " Len: " << ds::COUNTERS.size() << "\n";
    for (auto const & item : ds::COUNTERS)
        std::cout << item.first << " - " << item.second << "\n";
}

const std::map<std::string, double> ds::copyCounter()
{
    std::map<std::string, double> res;

    std::map<std::string, size_t>::iterator it;
    for (it = ds::COUNTERS.begin(); it != ds::COUNTERS.end(); it++)
    {
        res.insert({it->first, (double)it->second});
    }

    return res;
}

const std::vector<std::string> ds::getFuncNames()
{
    std::vector<std::string> res;

    std::map<std::string, int>::iterator it;
    for (it = ds::FLOPS.begin(); it != ds::FLOPS.end(); it++)
        res.push_back(it->first);

    return res;
}

const int ds::getFlops()
{
    int sum {0};
    std::map<std::string, size_t>::iterator it;
    for (it = ds::COUNTERS.begin(); it != ds::COUNTERS.end(); it++)
    {
        sum += it->second * ds::FLOPS.at(it->first);
    }

    return sum;
}