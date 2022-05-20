#ifndef __SHAPE2D_HPP__
#define __SHAPE2D_HPP__

#include "line2D.hpp"

namespace ds
{

class shape2D
{
protected:
    point2D m_center;
    float m_radius;
    size_t m_size;
    float m_vertSeparation;
    std::vector<point2D> m_vertices;

protected:
    shape2D(
        const point2D center,
        const float radius,
        const size_t size
    ) : m_center(center),
        m_radius(radius),
        m_size(size)
    {} // shape2D

    ~shape2D() {};

public:

    /**
     * @brief Accessor for the size of the shape (The amount of vertices)
     * 
     * @return const size_t amount of vertices
     */
    const size_t size() const;

    /**
     * @brief Accessor for a specific vertex of the shape.
     * Modulo operation allows to step any around the shape with index starting
     * over at 0 when over-/under flowing.
     * 
     * @param index int index (Can be both positive and negative)
     * @return const vec2f& reference to vertex at position index % size
     */
    const vec2f & operator[](int index) const;

    const float getMaxRayAngle(const point2D &ls) const;

    /**
     * @brief Get the Blocking Edge object
     * 
     * @param ls point2D ref of light source
     * @return line2D The blocking edge as a line
     */
    virtual line2D getBlockingEdge(const point2D &ls) const = 0;
};

} // namespace ds

#endif