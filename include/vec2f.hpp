#ifndef __VEC2F_HPP__
#define __VEC2F_HPP__

#include <iostream>
#include <math.h>

namespace ds {

class vec2f {

public:
    float x;
    float y;

    vec2f() : x(0.f), y(0.f) {}
    vec2f(float x_value, float y_value) : x(x_value), y(y_value) {}
};

using point2D = vec2f;

/**
 * @brief Overload of << operator for vec2f class to allow for printing it in std::cout.
 * 
 * @param out std::ostream reference (&)
 * @param v const vec2f ref
 * @return std::ostream& out
 */
std::ostream & operator<<(std::ostream &out, const vec2f &v);

/**
 * @brief Overload of == operator for vec2f class to allow equal checks.
 * 
 * @param left const vec2f ref
 * @param right const vec2f ref
 * @return true if left and right are equal
 * @return false if left and right is not equal
 */
bool operator==(const vec2f &left, const vec2f &right);

/**
 * @brief Overload of + operator for vec2f class to allow for vector addition.
 * 
 * @param left const vec2f ref
 * @param right const vec2f ref
 * @return vec2f sum of vectors left and right
 */
vec2f operator+(const vec2f &left, const vec2f &right);

/**
 * @brief Overload of - operator for vec2f class to allow for vector subtraction.
 * 
 * @param left const vec2f ref
 * @param right const vec2f ref
 * @return vec2f difference between vectors left and right
 */
vec2f operator-(const vec2f &left, const vec2f &right);

/**
 * @brief Overload of * operator for vec2f class to allow for scalar multiplication.
 * 
 * @param vec const vec2f ref
 * @param scalar float const ref
 * @return vec2f scalar product of vec
 */
vec2f operator*(const vec2f &vec, const float &scalar);

/**
 * @brief Overload of * operator for vec2f class to allow for scalar multiplication with a vector.
 * 
 * @param scalar float const ref
 * @param vec const vec2f ref
 * @return vec2f product vector
 */
vec2f operator*(const float &scalar, const vec2f &vec);

/**
 * @brief Overload of / operator for vec2f class to allow for scalar division. Division by 0 results in runtime errro.
 * 
 * @param vec const vec2f ref
 * @param scalar float const ref
 * @return vec2f quotient vector
 */
vec2f operator/(const vec2f &vec, const float &scalar);

/**
 * @brief Calculates the dot product of two vectors.
 * 
 * @param left const vec2f ref
 * @param right const vec2f ref
 * @return float dot product
 */
float dot(const vec2f &left, const vec2f &right);

/**
 * @brief Calculates the magnitude between to vectors (length)
 * 
 * @param start const point2D (vec2f alias) ref
 * @param end const point2D (vec2f alias) ref
 * @return float magnitude (Distance between them in a 2D plane).
 */
float dist(const point2D &start, const point2D &end);

} // End of namespace ds


#endif