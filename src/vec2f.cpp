#include "../include/vec2f.hpp"

namespace ds
{

/**
 * @brief Overload of << operator for vec2f class to allow for printing it in std::cout.
 * 
 * @param out std::ostream reference (&)
 * @param v vec2f const ref
 * @return std::ostream& out
 */
std::ostream & operator<<(std::ostream &out, const vec2f &v)
{
    return out << "[" << v.x << ", " << v.y << "]";
}

/**
 * @brief Overload of == operator for vec2f class to allow equal checks.
 * 
 * @param left vec2f const ref
 * @param right vec2f const ref
 * @return true if left and right are equal
 * @return false if left and right is not equal
 */
bool operator==(const vec2f &left, const vec2f &right)
{
    return (left.x == right.x) && (left.y == right.y);
}

/**
 * @brief Overload of + operator for vec2f class to allow for vector addition.
 * 
 * @param left vec2f const ref
 * @param right vec2f const ref
 * @return vec2f sum of vectors left and right
 */
vec2f operator+(const vec2f &left, const vec2f &right)
{
    return vec2f(
        left.x + right.x,
        left.y + right.y
    );
}

/**
 * @brief Overload of - operator for vec2f class to allow for vector subtraction.
 * 
 * @param left vec2f const ref
 * @param right vec2f const ref
 * @return vec2f difference between vectors left and right
 */
vec2f operator-(const vec2f &left, const vec2f &right)
{
    return vec2f(
        left.x - right.x,
        left.y - right.y
    );
}

/**
 * @brief Overload of * operator for vec2f class to allow for scalar multiplication.
 * 
 * @param vec vec2f const ref
 * @param scalar float const ref
 * @return vec2f scalar product of vec
 */
vec2f operator*(const vec2f &vec, const float &scalar)
{
    return vec2f(
        vec.x * scalar,
        vec.y * scalar  
    );
}

vec2f operator*(const float &scalar, const vec2f &vec)
{
    return vec * scalar;
}

}