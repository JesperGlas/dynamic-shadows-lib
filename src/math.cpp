#include "math.hpp"

#include <cmath>
#include <iostream>

float ds::tanf(float ang)
{
    std::cout << "Using ds::tanf()" << std::endl;

    return std::tan(ang);
}

float ds::sqrtf(float arg)
{
    std::cout << "Using ds::sqrtf()" << std::endl;

    return std::sqrt(arg);
}

float ds::powf(float base, float exp)
{
    std::cout << "Using ds::powf()" << std::endl;

    return std::pow(base, exp);
}