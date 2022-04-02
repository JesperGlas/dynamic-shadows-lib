#include "square2D.hpp"

namespace ds
{

square2D::square2D(vec2f center, float radius) : m_center(center), m_radius(radius)
{
    auto top_left = ds::point2D(
        m_center.x + m_radius,
        m_center.y + tanf(M_PI/4) * m_radius
    );

    m_corners.push_back(top_left);      // Top left
    m_corners.push_back(flipX(m_center, top_left));  // Top right
    m_corners.push_back(flip(m_center, top_left)); // Bottom right
    m_corners.push_back(flipY(m_center, top_left));  // Bottom left
}

const point2D & square2D::topLeft() const
{
    return this->m_corners.at(0);
}

const point2D & square2D::topRight() const
{
    return this->m_corners.at(1);
}

const point2D & square2D::bottomRight() const
{
    return this->m_corners.at(2);
}

const point2D & square2D::bottomLeft() const
{
    return this->m_corners.at(3);
}

} // namespace ds