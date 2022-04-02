#ifndef __SQUARE2D_HPP__
#define __SQUARE2D_HPP__

#include "line2D.hpp"

namespace ds
{

class square2D
{
public:
    vec2f m_center;
    float m_radius;

private:
    std::vector<point2D> m_corners;

public:
    square2D(vec2f center, float radius);

    const point2D & topLeft() const;
    const point2D & topRight() const;
    const point2D & bottomRight() const;
    const point2D & bottomLeft() const;
};

} // namespace ds

#endif