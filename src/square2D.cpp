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
    float corner_separation_angle = 90.f; // 90 degrees between corners in a square
    line2D light_to_center = line2D(ls, this->m_center); // Define a line from ls to sq.center
    float rotation = light_to_center.direction().flip().degAngle(); // Get angle between light normal and x-axis
    int quadrant = ds::floor(rotation/corner_separation_angle); // Calculate which quadrant light normal is in

    std::cout << "Rotation: " << rotation << std::endl;

    // Define start point (Top right corner of square)
    point2D start = point2D(
        this->m_center.x + this->m_radius,
        this->m_center.y + ds::tanf(ds::PI/4) * this->m_radius
    );
    
    // Rotate start point based on the lights normal rotation
    start = start.rotateRelTo(
        this->m_center,
        quadrant * corner_separation_angle
    );

    auto end = start.rotateRelTo(this->m_center, corner_separation_angle); // Flip start to get end point

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