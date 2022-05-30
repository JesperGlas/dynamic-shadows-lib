#include "math.hpp"

#include <cmath>
#include <iostream>

void ds::addToCounter(std::string func_name)
{
    if (COUNTERS.find(func_name) == COUNTERS.end())
        COUNTERS[func_name] = 1;
    else
        COUNTERS[func_name]++;
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

    std::cout << std::endl;
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
    addToCounter("ds::sinf");

    return std::sin(radians);
}

float ds::asinf(float radians)
{
    addToCounter("ds::asinf");

    return std::asin(radians);
}

float ds::cosf(float radians)
{
    addToCounter("ds::cosf");

    return std::cos(radians);
}

float ds::acosf(const float radians)
{
    addToCounter("ds::acosf");

    return std::acos(radians);
}

float ds::tanf(float radians)
{
    addToCounter("ds::tanf");

    return std::tan(radians);
}

float ds::atan2f(const float &y, const float &x)
{
    addToCounter("ds::atanf");

    return std::atan2(y, x);
}

float ds::sqrtf(float radians)
{
    addToCounter("ds::sqrtf");

    return std::sqrt(radians);
}

float ds::powf(float base, float exp)
{
    addToCounter("ds::powf");

    return std::pow(base, exp);
}

int ds::floor(float radians)
{
    return std::floor(radians);
}

int ds::round(const float radians)
{
    return std::roundf(radians);
}

float ds::fmod(const float radians, const float div)
{
    return std::fmod(radians, div);
}
