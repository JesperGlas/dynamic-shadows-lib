#include "square2D.hpp"

namespace ds
{

square2D::square2D(vec2f center, float radius) : m_center(center), m_radius(radius)
{
    auto right = ds::point2D(
        m_center.x + m_radius,
        m_center.y
    );

    m_corners.push_back(right); // Top right
    m_corners.push_back(right.rotateRelTo(m_center, degToRad(90.f))); // Top left
    m_corners.push_back(right.flipRelTo(m_center)); // Bottom left
    m_corners.push_back(right.rotateRelTo(m_center, degToRad(270.f)));  // Bottom right
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
    int mod_index = index % this->size();
    size_t pos_index = (mod_index < 0) ? mod_index + this->size() : mod_index;
    return this->m_corners.at(mod_index);
}

const size_t square2D::size() const
{
    return this->m_corners.size();
}

const line2D square2D::getBlockingEdge(const point2D &ls) const
{
    // Determine which is the relevant vertex
    float vert_separation = degToRad(90.f);
    float rel_ls = ls.angle(this->m_center) + degToRad(45.f);
    int q = (int) rel_ls / vert_separation;

    // Determine starting index
    int start {q};
    float start_angle = this->operator[](q).angle(this->operator[](q-1));
    if (ls.angle(this->operator[](q)) < start_angle)
        start--;

    // Determine end index
    int end {q};
    float end_angle = this->operator[](q).angle(this->operator[](q+1));
    if (ls.angle(this->operator[](q)) > end_angle)
        end++;


    return line2D(
        this->operator[](start),
        this->operator[](end)
    );
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