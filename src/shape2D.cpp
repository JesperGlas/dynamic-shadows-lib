#include "shape2D.hpp"

namespace ds
{
/* ### PUBLIC ### */

const size_t shape2D::size() const
{
    return this->m_vertices.size();
}

const vec2f & shape2D::operator[](int index) const
{
    return this->m_vertices.at(index % this->size());
}

const float shape2D::getMaxRayAngle(const point2D &ls) const
{
    float dist = ls.magnitude(this->m_center);

    std::cout   << "r: " << this->m_radius
                << "\nd: " << dist
                << std::endl;
    
    std::cout << "Arc: " << radToDeg(asinf(this->m_radius / dist)) << std::endl;

    return (PI * 0.5f) - asinf(this->m_radius / dist);
}

} // namespace ds