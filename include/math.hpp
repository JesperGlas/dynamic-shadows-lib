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

/* ### STATS FUNCTIONS ### */

/**
 * @brief A function that adds/increments counters for statistics.
 * 
 * @param func_name std::string name for the function, serves as the key to the static COUNTERS map.
 */
void addToCounter(std::string func_name);

/**
 * @brief Prints the static map of counters.
 * 
 */
void printMathStats();

/* ### CONSTANTS ### */
const float PI = 3.14159265358979323846;

/* ### MATH FUNCTIONS ### */

float degToRad(float deg);

/**
 * @brief Custom sine function with the option to log how many times it's used.
 * 
 * @param ang angle in radians
 * @return float sin(angle)
 */
float sinf(float ang);

/**
 * @brief Custom cosine function with the option to log how many times it's used.
 * 
 * @param ang angle in radians
 * @return float cos(angle)
 */
float cosf(float ang);

/**
 * @brief Custom tangent function with the option to log how many times it's used.
 * 
 * @param ang float angle in radians
 * @return float tan(angle)
 */
float tanf(float ang);

/**
 * @brief Custom square root function with the option to log how many times it's used.
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

}

#endif