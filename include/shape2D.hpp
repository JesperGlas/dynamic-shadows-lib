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

public:
    shape2D(
        const point2D center,
        const float radius,
        const size_t size
    );

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

    const line2D getFacingEdge(const point2D &ls) const;

    /**
     * @brief Get the Blocking Edge object
     * 
     * @param ls point2D ref of light source
     * @return line2D The blocking edge as a line
     */
    line2D getBlockingEdge(const point2D &ls) const;

    line2D getBlockingEdgeNaive(const point2D &ls) const;
};

} // namespace ds

#endif