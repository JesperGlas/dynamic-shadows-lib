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
    auto res = ds::line2D();
    auto current = this->operator[](0);
    auto next = this->operator[](1);
    auto edge = ds::line2D(current, next);
    auto set_start {false};
    auto set_end {false};

    // keep track of facing direction of last edge
    bool start_facing {false};
    bool last_facing {false};
    for (size_t i {0}; i < this->size() + 1; i++)
    {
        if (set_start && set_end) // break if both points are set
            break;

        current = this->operator[](i);
        next = this->operator[](i+1);
        edge = ds::line2D(current, next);

        if (i == 0) // first edge
        {
            start_facing = edge.isFacing(ls); // set variable for first edge facing direction
            last_facing = start_facing; // initiate variable for last edge facing direction
        }
        
        if (last_facing != edge.isFacing(ls)) // if facing direction changes
        {
            if (!set_start) // set start point if not set
            {
                res.start = current;
                set_start = true;
            }
            else // set end point if start point is set
            {
                res.end = current;
                set_end = true;
            }
            last_facing = !last_facing; // change last edge direction variable 
        }
    }

    if (start_facing) // if first edge faced away from ls, swap start and end points
        res = ds::line2D(res.end, res.start);

    return res;
}

line2D shape2D::getBlockingEdgeHybrid(const point2D &ls) const
{
    // facing edge if point is inside of bounding circle (base case)
    if (ls.magnitude(this->m_center) < this->m_radius)
        return this->getFacingEdge(ls);

    // find reference point on bounding circle (same angle as light source)
    vec2f ref = this->m_center + ls.unit(this->m_center) * this->m_radius; // Find point on bounding circle at same angle as light source [vec2f]

    // find max angle to tangent on bounding circle (90 degrees towards light source)
    float lsa = this->getMaxRayAngle(ls);

    // set start and end point reference points on bounding circle based on lsa
    vec2f start_ref = ref.rotate((-1) * lsa, this->m_center);
    vec2f end_ref = ref.rotate(lsa, this->m_center);

    // initiate start and and point index
    int si = start_ref.angle(this->m_center) / this->m_vertSeparation; // start index
    int ei = end_ref.angle(this->m_center) / this->m_vertSeparation; // end index

    // adjust start and end point based on relevant edge facing direction
    vec2f start = this->operator[](si);
    vec2f start_next = this->operator[](si+1);
    if (ls.lineDistance(start, start_next) < 0)
        si += 1;

    vec2f end = this->operator[](ei);
    vec2f end_next = this->operator[](ei+1);
    if (ls.lineDistance(end, end_next) > 0)
        ei += 1;

    return line2D(
        this->operator[](si),
        this->operator[](ei)
    );
}



} // namespace ds