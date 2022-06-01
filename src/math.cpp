#include "math.hpp"

#include <cmath>

void ds::addToCounter(std::string func_name, const int n)
{
    if (COUNTERS.find(func_name) == COUNTERS.end())
        COUNTERS[func_name] = n;
    else
        COUNTERS[func_name] += n;
}

void ds::resetCounters()
{
    for (auto &item : COUNTERS)
        item.second = 0;
}

void ds::printMathStats(const std::string msg)
{
    std::cout << "Stats: " << msg << "\n";
    for (auto const & item : COUNTERS)
        std::cout << item.first << " - " << item.second << "\n";
}

const int ds::getFlops()
{
    int sum {0};
    std::map<std::string, size_t>::iterator it;
    for (it = COUNTERS.begin(); it != COUNTERS.end(); it++)
    {
        sum += it->second * ds::FLOPS.at(it->first);
    }

    return sum;
}

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

const std::map<std::string, size_t> ds::copyCounter()
{
    return std::map<std::string, size_t>(COUNTERS);
}

const std::vector<std::string> ds::getFuncNames()
{
    std::vector<std::string> res;

    std::map<std::string, int>::iterator it;
    for (it = ds::FLOPS.begin(); it != ds::FLOPS.end(); it++)
        res.push_back(it->first);

    return res;
}