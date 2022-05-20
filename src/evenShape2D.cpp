#include "evenShape2D.hpp"

namespace ds
{

evenShape2D::evenShape2D(
    const point2D center,
    const float radius,
    const size_t size
) : shape2D(center, radius, size)
{
    this->m_vertSeparation = degToRad(360.f) / size; // set separation between vertices (in degrees)

    this->m_vertices.push_back(point2D(this->m_center.x + this->m_radius, this->m_center.y)); // set first vertex

    // TODO: Utilize flip for better performance
    for (size_t i {1}; i < this->m_size; i++)
    {
        this->m_vertices.push_back(
            this->m_vertices[i-1].rotate(this->m_vertSeparation, this->m_center)
        );
    }
}

line2D evenShape2D::getBlockingEdge(const point2D &ls) const
{
    float vert_serparation = this->m_vertSeparation; // Separation between vertices [Radians]
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

line2D evenShape2D::getBlockingEdgeNaive(const point2D &ls) const
{
    auto start = point2D(0, 0);
    auto end = point2D(0, 0);

    return line2D(start, end);
}

} // namespace ds