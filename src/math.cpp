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


void ds::printMathStats()
{
    for (auto const & item : COUNTERS)
        std::cout << item.first << " - " << item.second << "\n";

    std::cout << std::endl;
}

float ds::degToRad(float deg)
{
    // rad = deg * PI/180
    return deg * ds::PI / 180.f;
}

float ds::radToDeg(float rad)
{
    return rad / (ds::PI / 180.f);
}

float ds::sinf(float ang)
{
    addToCounter("ds::sinf");

    return std::sin(ang);
}

float ds::cosf(float ang)
{
    addToCounter("ds::cosf");

    return std::cos(ang);
}

float ds::tanf(float ang)
{
    addToCounter("ds::tanf");

    return std::tan(ang);
}

float ds::atan2f(const float &y, const float &x)
{
    addToCounter("ds::atanf");

    return std::atan2(y, x);
}

float ds::sqrtf(float arg)
{
    addToCounter("ds::sqrtf");

    return std::sqrt(arg);
}

float ds::powf(float base, float exp)
{
    addToCounter("ds::powf");

    return std::pow(base, exp);
}

int ds::floor(float arg)
{
    return std::floor(arg);
}

int ds::round(const float arg)
{
    return std::roundf(arg);
}

float ds::fmod(const float arg, const float div)
{
    return std::fmod(arg, div);
}
