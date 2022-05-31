#include "shape2D.hpp"

namespace ds
{

/* ### CONSTRUCTOR ### */
shape2D::shape2D(
    const point2D center,
    const float radius,
    const size_t size
) : m_center(center),
    m_radius(radius),
    m_size(size)
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
    float d = ls.magnitude(this->m_center);
    float r = this->m_radius;

    return (PI * 0.5f) - asinf(r / d);
}

const line2D shape2D::getFacingEdge(const point2D &ls) const
{
    point2D ref = this->m_center + ls.unit(this->m_center) * this->m_radius;
    float of = fmod(ls.angle(this->m_center), this->m_vertSeparation);
    
    point2D start = ref.rotate((-1) * of, this->m_center);
    point2D end = ref.rotate(this->m_vertSeparation - of, this->m_center);

    return line2D(start, end);
}

line2D shape2D::getBlockingEdge(const point2D &ls) const
{
    /* # Find facing edge (Base case) #*/
    if (ls.magnitude(this->m_center) < this->m_radius)
        return this->getFacingEdge(ls);
    
    float vert_serparation = this->m_vertSeparation; // Separation between vertices [Radians]
    vec2f ref = this->m_center + ls.unit(this->m_center) * this->m_radius; // Find point on bounding circle at same angle as light source [vec2f]
    vec2f start {vec2f()};
    vec2f end {vec2f()};
    float lsa = this->getMaxRayAngle(ls);

    // Initiate start and end point with lsa angle
    start = ref.rotate((-1) * lsa, this->m_center);
    end = ref.rotate(lsa, this->m_center);

    // Find how much start/end point overflows vertex separation
    float start_of = fmod(start.angle(this->m_center), vert_serparation);
    float end_of = fmod(end.angle(this->m_center), vert_serparation);

    // Adjust points to overflow, creating a facing edge    
    start = start.rotate(vert_serparation - start_of, this->m_center);
    vec2f start_next = start.rotate((-1) * vert_serparation, this->m_center);    

    end = end.rotate((-1) * end_of, this->m_center);
    vec2f end_next = end.rotate(vert_serparation, this->m_center);

    auto start_angle = start_next.dotAngle(this->m_center, ls);
    auto start_bound = start_next.dotAngle(this->m_center, start);
    if (start_angle > start_bound)
        start = start_next;

    auto end_angle = end_next.dotAngle(this->m_center, ls);
    auto end_bound = end_next.dotAngle(this->m_center, end);
    if (end_angle > end_bound)
        end = end_next;

    return line2D(start, end);
}

line2D shape2D::getBlockingEdgeNaive(const point2D &ls) const
{
    auto start {vec2f()};
    auto end {vec2f()};
    auto set_start {false};
    auto set_end {false};

    size_t offset = ls.angle(this->m_center) / this->m_vertSeparation;
    
    /**
     * Offset makes sure we start with a facing edge which we needs for our
     * if-else-statements to work. The +1 makes sure we check the last edge
     * for the end point.
     */
    for (size_t i {offset}; i < this->size() + offset + 1; i++)
    {
        if (set_start && set_end)
            break;

        auto previous = this->operator[](i-1);
        auto current = this->operator[](i);
        auto next = this->operator[](i+1);
        auto pt = current + next.unit(current) * next.magnitude(current) * 0.5f;

        auto indicator = ls.lineDistance(current, next);

        if (!set_start && indicator < 0)
        {
            set_start = true;
            start = current;
        }
        if (set_start && indicator >= 0)
        {
            set_end = true;
            end = current;
        }
    }

    return line2D(start, end); 
}


} // namespace ds