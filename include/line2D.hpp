#ifndef __LINE2D_HPP__
#define __LINE2D_HPP__

#include "vec2f.hpp"

namespace ds
{

enum face {
    LEFT = 1,
    RIGHT = -1
};

class line2D
{
public:
    point2D start; // (point2D = vec2f)
    point2D end;

    line2D() : start(point2D(0, 0)), end(point2D(0, 0)) {}
    line2D(point2D s, point2D e) : start(s), end(e) {}
};

// TODO: Find out why this results in "Undefined Reference".
/**
 * @brief Overload of operator<< for line2D class to allow to print it to std::cout.
 * 
 * @param out const osteam ref
 * @param l const line2D ref
 * @return std::ostream& output stream
 */
std::ostream & operator<<(std::ostream &out, const line2D &l);

/**
 * @brief Calculates the length of the line in 2D space.
 * 
 * @param line const line2D ref
 * @return float length of the line
 */
float length(const line2D &line);

/**
 * @brief Returns a normalized line facing either left or right of the original line.
 * 
 * @param l const line2D ref
 * @param f const face [LEFT/RIGHT]
 * @return line2D normalized
 */
line2D normal(const line2D &l, const face f);

/**
 * @brief Returns a new line with flipped x- and v-value relative to the start point.
 * 
 * @param l const line2D ref
 * @return line2D flipped
 */
line2D flip(const line2D &l);

/**
 * @brief Returns a new line with flipped x-value relative to the start point.
 * 
 * @param l const line2D ref 
 * @return line2D flipped x-value
 */
line2D flipX(const line2D &l);

/**
 * @brief Returns a new line with flipped y-value relative to the start point.
 * 
 * @param l const line2D ref
 * @return line2D flipped y-value
 */
line2D flipY(const line2D &l);


} // ### END OF NAMESPACE DS ###

#endif