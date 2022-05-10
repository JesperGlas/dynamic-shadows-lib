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
            this->m_vertices[i-1].rotateRelTo(this->m_center, this->m_vertSeparation)
        );
    }
}

line2D evenShape2D::getBlockingEdge(const point2D &ls) const
{
    auto start = point2D(0, 0);
    auto end = point2D(1, 1);

    return line2D(start, end);
}

line2D evenShape2D::getBlockingEdgeNaive(const point2D &ls) const
{
    auto start = point2D(0, 0);
    auto end = point2D(0, 0);

    return line2D(start, end);
}

} // namespace ds