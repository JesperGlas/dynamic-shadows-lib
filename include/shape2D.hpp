#ifndef __SHAPE2D_HPP__
#define __SHAPE2D_HPP__

#include "line2D.hpp"

namespace ds
{

class shape2D
{
public:
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
    ) : m_center(center),
        m_radius(radius),
        m_size(size)
    {} // shape2D

    ~shape2D() {};

    const size_t size() const { return this->m_vertices.size(); }

    const vec2f & operator[](int index) const { return this->m_vertices.at(index % this->size()); }

    virtual line2D getBlockingEdge(const point2D &ls) const = 0;
};

} // namespace ds

#endif