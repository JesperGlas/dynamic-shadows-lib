#ifndef __VEC2F_HPP__
#define __VEC2F_HPP__

#include "math.hpp"

namespace ds {

class vec2f {

public:
    float x;
    float y;

    vec2f() : x(0.f), y(0.f) {}
    vec2f(float x_value, float y_value) : x(x_value), y(y_value) {}

    /* ### Accessors ### */

    /**
     * @brief Returns the vectors magnitude (Relative to origin [0 0])
     * 
     * @return float magnitude (length from origin)
     */
    float magnitude() const;

    /**
     * @brief Calculate the normal of a vector (Relative to [0 0]).
     * 
     * @param v const vec2f ref
     * @return vec2f the vectors normal
     */
    vec2f normal() const;

    /**
     * @brief Calculates the unit vector of a vec2f.
     * 
     * @param v const vec2f ref
     * @return vec2f unit vector
     */
    vec2f unitVector() const;

    float angle() const;

    float angleRelTo(const vec2f &start) const;

    /**
     * @brief Flips the vectors x-value relative to origin [0 0].
     * 
     * @return vec2f flipped vector
     */
    vec2f flipX() const;

    /**
     * @brief Flips the vectors x-axis relative to a point.
     * 
     * @param start const vec2f ref
     * @return vec2f with flipped x-axis
     */
    vec2f flipXRelTo(const vec2f &start) const;

    /**
     * @brief Flips the vectors y-value relative to origin [0 0].
     * 
     * @return vec2f flipped vector
     */
    vec2f flipY() const;
    
    /**
     * @brief Flips the vectors y-value relative to a point.
     * 
     * @param start const vec2f ref
     * @return vec2f with flipped y-axis
     */
    vec2f flipYRelTo(const vec2f &start) const;

    /**
     * @brief Flips the vector around both x- and y-axis relative to origin [0 0].
     * 
     * @return vec2f flipped vector
     */
    vec2f flip() const;

    /**
     * @brief Flips the vectors around both x- and y-axis relative to a point.
     * 
     * @param start const vec2f ref
     * @return vec2f with both axis flipped
     */
    vec2f flipRelTo(const vec2f &start) const;

    /**
     * @brief Rotates the vector by angles (Counter clockwise).
     * 
     * @param vec const vec2f ref
     * @param ang float angles 
     * @return vec2f rotated vector
     */
    vec2f rotate(const float ang) const;

    vec2f rotateRelTo(const vec2f &origin, const float ang) const;

}; // class vec2f

/* ### Aliases ### */
using point2D = vec2f;

/* ### Vector Functions ### */

/**
 * @brief Overload of << operator for vec2f class to allow for printing it to std::cout.
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
inline vec2f operator+(const vec2f &vec, const float &arg) { return vec + vec2f(arg, arg); }
inline vec2f operator+(const float &arg, const vec2f &vec) { return vec + arg; }

/**
 * @brief Overload of - operator for vec2f class to allow for vector subtraction.
 * 
 * @param left const vec2f ref
 * @param right const vec2f ref
 * @return vec2f difference between vectors left and right
 */
vec2f operator-(const vec2f &left, const vec2f &right);
inline vec2f operator-(const vec2f &vec, const float &arg) { return vec - vec2f(arg, arg); }

/**
 * @brief Overload of * operator for vec2f class to allow for scalar multiplication.
 * 
 * @param vec const vec2f ref
 * @param scalar float const ref
 * @return vec2f scalar product of vec
 */
vec2f operator*(const vec2f &vec, const float &scalar);
inline vec2f operator*(const float &scalar, const vec2f &vec) { return vec * scalar; }

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

/* ### 2D Space Functions ### */

/**
 * @brief Calculates the distance between to point2D (length of vec2f).
 * 
 * @param start const point2D (vec2f alias) ref
 * @param end const point2D (vec2f alias) ref
 * @return float magnitude (Distance between them in a 2D plane).
 */
float distance(const point2D &start, const point2D &end);


} // End of namespace ds


#endif