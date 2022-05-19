#include "triangle2D.hpp"

namespace ds
{

triangle2D::triangle2D(vec2f center, float radius) : m_center(center), m_radius(radius)
{
    auto right = ds::point2D(this->m_center.x + this->m_radius, this->m_center.y);
    auto top_left = right.rotate(degToRad(120.f), this->m_center);

    m_corners.push_back(right);
    m_corners.push_back(top_left);
    m_corners.push_back(top_left.flipY(this->m_center));

}

const std::vector<point2D> & triangle2D::corners() const
{
    return this->m_corners;
}

const vec2f & triangle2D::operator[](int index) const
{
    size_t pos_index = (index < 0) ? index + this->size() : index;
    size_t mod_index = pos_index % this->size();
    return this->m_corners.at(mod_index);
}

const size_t triangle2D::size() const
{
    return this->m_corners.size();
}

const line2D triangle2D::getBlockingEdge(const point2D &ls) const
{
    float vert_serparation = degToRad(120.f); // Separation between vertices [Radians]
    float vert_overflow = fmod(ls.angle(this->m_center), vert_serparation); // Overflow between closest previous vertex and light source [Radians] 

    vec2f start = this->m_center + ls.unit(this->m_center) * this->m_radius; // Find point on bounding circle at same angle as light source [vec2f]
    start = start.rotate((-1) * vert_overflow, this->m_center); // Adjust point to find vertex [vec2f]
    vec2f end = start.rotate(vert_serparation, this->m_center); // Find vertex closest after start [vec2f]

    // Find what vertex quadrant the light source is at [float radians]
    int q = ls.angle(this->m_center) / vert_serparation;

    // Normalize positions of all points to first quadrant [copies the points to temp variables]
    auto start_norm = start.rotate((-q) * vert_serparation, this->m_center);
    auto end_norm = end.rotate((-q) * vert_serparation, this->m_center);
    auto ls_norm = ls.rotate((-q) * vert_serparation, this->m_center);

    // Get relative angles between normalized ls and start/end points [float radians]
    float start_angle = ls_norm.angle(start_norm);
    float end_angle = ls_norm.angle(end_norm);

    std::cout   << "Start:\n"
                << radToDeg(start_angle) << " < " << radToDeg(vert_serparation)
                << "\n&&\n"
                << radToDeg(start_angle) << " < " << radToDeg(vert_serparation * 0.5f)
                << "\n\n"
                << "End:\n"
                << radToDeg(end_angle) << " < " << radToDeg(vert_serparation * 1.5f)
                << "\n&&\n"
                << radToDeg(vert_serparation * 0.5f) << " < " << radToDeg(end_angle)
                << std::endl;

    float perp = vert_serparation * 0.5f; // Perpendicular to the vertex sepration [float radians]
    float start_bound = (degToRad(180.f) - vert_serparation) / 2.f;
    float end_bound = vert_serparation - start_bound;

    // Rotate real start or end point depending on angles
    if (start_angle < start_bound)
        start = start.rotate((-1) * vert_serparation, this->m_center);
    else if ((end_angle < vert_serparation) && (end_bound < end_angle))
        end = end.rotate(vert_serparation, this->m_center);

    return line2D(start, end);
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