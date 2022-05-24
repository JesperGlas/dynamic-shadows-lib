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
    /* # Find facing edge (Base case) #*/
    float vert_serparation = this->m_vertSeparation; // Separation between vertices [Radians]
    float vert_overflow = fmod(ls.angle(this->m_center), vert_serparation); // Overflow between closest previous vertex and light source [Radians] 

    vec2f start = this->m_center + ls.unit(this->m_center) * this->m_radius; // Find point on bounding circle at same angle as light source [vec2f]
    start = start.rotate((-1) * vert_overflow, this->m_center); // Align start with a vertex
    vec2f end = start.rotate(vert_serparation, this->m_center); // Smallest silhouette is one edge

    float lsa = this->getMaxRayAngle(ls);
    int adjustment = lsa / vert_serparation;

    std::cout << "Adj: " << adjustment << std::endl;

    start = start.rotate((-1) * adjustment * vert_serparation, this->m_center);
    end = end.rotate(adjustment * vert_serparation, this->m_center);

    std::cout   << "Start: "
                << radToDeg(start.leftNormal(ls).angle(this->m_center))
                << std::endl;

    return line2D(start, end);
}

line2D evenShape2D::getBlockingEdgeNaive(const point2D &ls) const
{
    auto start = point2D(0.f, 0.f);
    auto end = point2D(0.f, 0.f);

    return line2D(start, end);
}

} // namespace ds