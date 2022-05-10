#include "triangle2D.hpp"

namespace ds
{

triangle2D::triangle2D(vec2f center, float radius) : m_center(center), m_radius(radius)
{
    auto top = point2D(m_center.x, m_center.y + m_radius);
    auto left = top.rotate(degToRad(120));

    m_corners.push_back(top);
    m_corners.push_back(left);
    m_corners.push_back(left.flipX());

}

const point2D & triangle2D::top() const
{
    return this->m_corners.at(0);
}

const point2D & triangle2D::left() const
{
    return this->m_corners.at(1);
}

const point2D & triangle2D::right() const
{
    return this->m_corners.at(2);
}

const std::vector<point2D> & triangle2D::corners() const
{
    return this->m_corners;
}

/* ### Free functions ### */
std::ostream & operator<<(std::ostream &out, const triangle2D &sq)
{
    out << "| ";
    for (auto corner : sq.corners())
        out << corner << " -> ";
    out << " |\n";

    return out;
}

} // namespace ds