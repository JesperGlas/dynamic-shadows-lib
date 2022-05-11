#include "triangle2D.hpp"

namespace ds
{

triangle2D::triangle2D(vec2f center, float radius) : m_center(center), m_radius(radius)
{
    auto right = ds::point2D(this->m_center.x + this->m_radius, this->m_center.y);
    auto top_left = right.rotate(degToRad(120.f));

    m_corners.push_back(right);
    m_corners.push_back(top_left);
    m_corners.push_back(top_left.flipY());

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