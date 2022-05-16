#include "square2D.hpp"

namespace ds
{

square2D::square2D(vec2f center, float radius, float rotation) : m_center(center), m_radius(radius)
{
    auto right = ds::point2D(
        m_center.x + m_radius,
        m_center.y
    );

    // Set rotation and adjust first vertex
    this->m_rotation = fmod(rotation, degToRad(360.f));
    right = right.rotate(rotation, this->m_center);

    m_corners.push_back(right); // Top right
    m_corners.push_back(right.rotate(degToRad(90.f), m_center)); // Top left
    m_corners.push_back(right.flip(m_center)); // Bottom left
    m_corners.push_back(right.rotate(degToRad(270.f), m_center));  // Bottom right
}

const point2D & square2D::right() const
{
    return this->m_corners.at(0);
}

const point2D & square2D::top() const
{
    return this->m_corners.at(1);
}

const point2D & square2D::left() const
{
    return this->m_corners.at(2);
}

const point2D & square2D::bottom() const
{
    return this->m_corners.at(3);
}

const std::vector<point2D> & square2D::corners() const
{
    return this->m_corners;
}

const point2D & square2D::operator[](const int index) const
{
    size_t pos_index = (index < 0) ? index + this->size() : index;
    size_t mod_index = pos_index % this->size();
    return this->m_corners.at(mod_index);
}

const size_t square2D::size() const
{
    return this->m_corners.size();
}

const line2D square2D::getBlockingEdge(const point2D &ls) const
{
    float vert_serparation = degToRad(90.f); // Separation between vertices [Radians]
    float vert_overflow = fmod(ls.angle(this->m_center), vert_serparation); // Overflow between closest previous vertex and light source [Radians] 

    vec2f start = this->m_center + ls.unit(this->m_center) * this->m_radius; // Find point on bounding circle at same angle as light source [vec2f]
    start = start.rotate((-1) * vert_overflow, this->m_center); // Adjust point to find vertex [vec2f]
    vec2f end = start.rotate(vert_serparation, this->m_center); // Find vertex closest after start [vec2f]

    // Find what vertex quadrant the light source is at [float angle]
    int q = ls.angle(this->m_center) / vert_serparation;

    // Normalize positions of all points to first quadrant [copies the points to temp variables]
    auto start_norm = start.rotate((-q) * vert_serparation, this->m_center);
    auto end_norm = end.rotate((-q) * vert_serparation, this->m_center);
    auto ls_norm = ls.rotate((-q) * vert_serparation, this->m_center);

    // Get relative angles between normalized ls and start/end points [float angle]    
    float start_angle = ls_norm.angle(start_norm);
    float end_angle = ls_norm.angle(end_norm);

    // Rotate real start or end point depending on angles
    if ((start_angle < vert_serparation) && (start_angle < (vert_serparation * 0.5f)))
        start = start.rotate((-1) * vert_serparation, this->m_center);
    else if (end_angle < (vert_serparation * 1.5f) && (vert_serparation * 0.5f) < end_angle)
        end = end.rotate(vert_serparation, this->m_center);

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