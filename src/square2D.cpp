#include "square2D.hpp"

namespace ds
{

square2D::square2D(vec2f center, float radius) : m_center(center), m_radius(radius)
{
    auto top_right = ds::point2D(
        m_center.x + m_radius,
        m_center.y + ds::tanf(ds::PI/4) * m_radius
    );

    m_corners.push_back(top_right); // Top right
    m_corners.push_back(top_right.flipXRelTo(m_center)); // Top left
    m_corners.push_back(top_right.flipRelTo(m_center)); // Bottom left
    m_corners.push_back(top_right.flipYRelTo(m_center));  // Bottom right
}

const point2D & square2D::topRight() const
{
    return this->m_corners.at(0);
}

const point2D & square2D::topLeft() const
{
    return this->m_corners.at(1);
}

const point2D & square2D::bottomLeft() const
{
    return this->m_corners.at(2);
}

const point2D & square2D::bottomRight() const
{
    return this->m_corners.at(3);
}

const std::vector<point2D> & square2D::corners() const
{
    return this->m_corners;
}


/* ### Free functions ### */
std::ostream & operator<<(std::ostream &out, const square2D &sq)
{
    out << "| ";
    for (auto corner : sq.corners())
        out << corner << " -> ";
    out << " |\n";

    return out;
}

} // namespace ds