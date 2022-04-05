#ifndef __SHAPE2D_HPP__
#define __SHAPE2D_HPP__

#include "line2D.hpp"

namespace ds
{

class shape2D
{
public:
    const point2D m_center;
    const float m_radius;
    const float m_rotation;

private:
    std::vector<point2D> m_corners;

public:
    shape2D(const point2D center, const float radius, const float rotation)
    : m_center(center), m_radius(radius), m_rotation(rotation) {}

    virtual line2D getBlockingEdge(const point2D ls) = 0;
};

} // namespace ds

#endif