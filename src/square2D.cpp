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

const line2D square2D::getBlockingEdge(const point2D &ls) const
{
    float vert_ang = 90.f; // 90 degrees between corners in a square
    line2D cen_to_ls = line2D(this->m_center, ls); // Define a line from ls to sq.center
    float ls_ang = cen_to_ls.angle();
    float norm_ang = cen_to_ls.normalAngle();

    // Define start point (Top right corner of square)
    point2D start = point2D(
        this->m_center.x + this->m_radius,
        this->m_center.y - ds::tanf(ds::PI/4) * this->m_radius
    );

    auto end = start.rotateRelTo(this->m_center, vert_ang); // Flip start to get end point

    return line2D(start, end);
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