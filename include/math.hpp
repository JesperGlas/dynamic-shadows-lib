#ifndef __MATH_HPP__
#define __MATH_HPP__

namespace ds
{

/* ### CONSTANTS ### */
const float PI = 3.14159265358979323846;


/* ### FUNCTIONS ### */

/**
 * @brief Custom tangent function with the option to log how many times it's used.
 * 
 * @param ang float angle
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