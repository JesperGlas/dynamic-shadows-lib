#ifndef __LINE2D_HPP__
#define __LINE2D_HPP__

#include "vec2f.hpp"

namespace ds
{

/**
 * @brief Class for representing 2D vectors (with float values).
 * 
 */
class line2D
{
public:
    point2D start; // (point2D = vec2f)
    point2D end;

    line2D() : start(point2D(0, 0)), end(point2D(0, 0)) {}
    line2D(point2D s, point2D e) : start(s), end(e) {}

    /* ### Setters ### */

    /**
     * @brief Transforms the line2D instance by flipping its x-value.
     * 
     * @return line2D& reference to flipped self.
     */
    line2D & transformFlipX();

    /**
     * @brief Transforms the line2D instance by flipping its y-value.
     * 
     * @return line2D& reference to flipped self.
     */
    line2D & transformFlipY();

    /**
     * @brief Transforms the line2D instance by flipping it in both directions.
     * 
     * @return line2D& reference to self.
     */
    line2D & transformFlip();

    /* ### Accessors ### */

    /**
     * @brief Accessor for the line2D instance as a vector relative to origo [0 0].
     * 
     * @return vec2f line as a vector with start in [0 0]
     */
    vec2f vector() const;

    /**
     * @brief Accessor for the line2Ds length.
     * 
     * @return float length of the line
     */
    float length() const;

    /**
     * @brief Accessor for the direction of the line in 2D space as a unitvector.
     *  
     * @return vec2f direction (unit vector)
     */
    vec2f direction() const;

    /**
     * @brief Accessor to the normal direction of the line in 2D space.
     * 
     * @return vec2f direction of normal (unit vector)
     */
    vec2f normalDirection() const;

    /**
     * @brief Accessor for the lines angle (Relative to start point)
     * 
     * @return float angle of line in degrees
     */
    float angle() const;

    /**
     * @brief Accessor for the lines normal angle (Relative to start point)
     * 
     * @return float angle of normal in degrees
     */
    float normalAngle() const;

}; // class line2D

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
 * @brief Overloaded operator== for line2D class to allow eq comparison between instances.
 * 
 * @param left const line2D ref
 * @param right const line2D ref
 * @return true if the line2D instances is equal
 * @return false if the line2D instances are not equal
 */
bool operator==(const line2D &left, const line2D &right);


} // ### END OF NAMESPACE DS ###

#endif