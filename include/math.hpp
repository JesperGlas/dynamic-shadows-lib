#ifndef __MATH_HPP__
#define __MATH_HPP__

#include <iostream>
#include <vector>
#include <map>
#include <string>

namespace ds
{

/* ### STATIC COUNTERS ### */
static std::map<std::string, std::size_t> COUNTERS;

static std::map<std::string, int> FLOPS =
{
    {"ds::sinf",    31},
    {"ds::asinf",   40},
    {"ds::cosf",    30},
    {"ds::acosf",   46},
    {"ds::tanf",    54},
    {"ds::atanf",   60},
    {"ds::sqrtf",   22},
    {"ds::powf",    40},
    {"ds::fmodf",   41}
};

/* ### STATS FUNCTIONS ### */

/**
 * @brief A function that adds/increments counters for statistics.
 * 
 * @param func_name std::string name for the function, serves as the key to the static COUNTERS map.
 */
void addToCounter(std::string func_name);

/**
 * @brief A function that resets the counters for the functioncalls.
 * 
 */
void resetCounters();

/**
 * @brief Prints the static map of counters.
 * 
 */
void printMathStats(const std::string msg);
inline void printMathStats() { printMathStats(""); }

const int getFlops();


/* ### CONSTANTS ### */
const float PI = 3.14159265358979323846;

/* ### MATH FUNCTIONS ### */

/**
 * @brief Converts an angle in degrees to radians.
 * 
 * @param deg float degree
 * @return float radian
 */
float degToRad(float deg);

/**
 * @brief Converts an angle in radians to degrees.
 * 
 * @param rad float radian
 * @return float degree
 */
float radToDeg(float rad);

/**
 * @brief Custom sine function with the option to log how many times it's been called.
 * 
 * @param ang angle in radians
 * @return float sin(angle)
 */
float sinf(float radians);

/**
 * @brief Custom arcsine function with the option to log how many times it's been called.
 * 
 * @param radians 
 * @return float 
 */
float asinf(float radians);

/**
 * @brief Custom cosine function with the option to log how many times it's been called.
 * 
 * @param ang angle in radians
 * @return float cos(angle)
 */
float cosf(float ang);

float acosf(const float radians);

/**
 * @brief Custom tangent function with the option to log how many times it's been called.
 * 
 * @param ang float angle in radians
 * @return float tan(angle)
 */
float tanf(float ang);

/**
 * @brief Custom atan2 function with the option to log how many times it's been called. 
 * 
 * @param u const float ref
 * @param v const float ref
 * @return float 
 */
float atan2f(const float &y, const float &x);

/**
 * @brief Custom square root function with the option to log how many times it's been called.
 * 
 * @param arg float argument value
 * @return float square root of arg
 */
float sqrtf(float arg);

/**
 * @brief Custom function to raise the base to the power of the exponent, with the option of logging how many times it's been used.
 * 
 * @param base float base
 * @param exp float exponent
 * @return float base raised to the power of the exponent (base^exp)
 */
float powf(float base, float exp);

int floor(float arg);

int round(const float arg);

float fmod(const float arg, const float div);

const std::map<std::string, size_t> copyCounter();

} // namespace ds

#endif