#ifndef __TRIANGLE2D_HPP__
#define __TRIANGLE2D_HPP__

#include "vec2f.hpp"

namespace ds
{

class triangle2D
{
public:
    point2D m_center;
    float m_radius;

private:
    std::vector<point2D> m_corners;

public:
    // Constructor
    triangle2D(vec2f center, float radius);

    /**
     * @brief Accessor for the triangles top corner.
     * 
     * @return const point2D& top corner of the triangle.
     */
    const point2D & top() const;

    /**
     * @brief Accessor for the triangles top left corner.
     * 
     * @return const point2D& top left corner of the triangle.
     */
    const point2D & left() const;

    /**
     * @brief Accessor for the triangles bottom left corner.
     * 
     * @return const point2D& bottom left corner of the triangle.
     */
    const point2D & right() const;

    /**
     * @brief Accessor for the triangles corners.
     * 
     * @return const std::vector<point2D>& of corners. TL-> TR -> BR -> TL
     */
    const std::vector<point2D> & corners() const;
};

/**
 * @brief Overloaded << operator for triangle2D class.
 * 
 * @param out std::ostream out stream
 * @param sq const ds::triangle2D ref
 * @return std::ostream& out stream
 */
std::ostream & operator<<(std::ostream &out, const triangle2D &tri);

}

#endif