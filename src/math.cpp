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

float ds::tanf(float ang)
{
    addToCounter("ds::tanf");

    return std::tan(ang);
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