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
    vec2f ref = this->m_center + ls.unit(this->m_center) * this->m_radius; // Find point on bounding circle at same angle as light source [vec2f]
    vec2f start {vec2f()};
    vec2f end {vec2f()};
    float lsa = this->getMaxRayAngle(ls);
    std::cout << "LSA: " << radToDeg(lsa) << std::endl;
    if (lsa < vert_serparation) // Base case
    {
        float of = fmod(ls.angle(this->m_center), vert_serparation);
        start = ref.rotate((-1) * of, this->m_center);
        end = ref.rotate(vert_serparation - of, this->m_center);

        int q = ls.angle(this->m_center) / vert_serparation;
        auto start_norm = start.rotate((-q) * vert_serparation, this->m_center);
        auto end_norm = end.rotate((-q) * vert_serparation, this->m_center);
        auto ls_norm = ls.rotate((-q) * vert_serparation, this->m_center);

        float start_angle = ls_norm.angle(start_norm);
        float end_angle = ls_norm.angle(end_norm);

        float start_bound = 2*PI - vert_serparation - PI;
        float end_bound = vert_serparation - start_bound;

        if (start_angle < start_bound)
            start = start.rotate((-1) * vert_serparation, this->m_center);
        else if (end_angle < end_bound)
            end = end.rotate(vert_serparation, this->m_center);
    }
    else // Extended case
    {

        // Initiate start and end point with lsa angle
        start = ref.rotate((-1) * lsa, this->m_center);
        end = ref.rotate(lsa, this->m_center);

        // Find how much start/end point overflows vertex separation
        float start_of = fmod(start.angle(this->m_center), vert_serparation);
        float end_of = fmod(end.angle(this->m_center), vert_serparation);

        std::cout << "Limit: " << radToDeg(vert_serparation * 0.5f) << std::endl;
        std::cout << "Start OF: " << radToDeg(start_of) << std::endl;
        std::cout << "Start limit: " << radToDeg(vert_serparation - start_of) << std::endl;
        // Adjust start point based on its overflow
        if ((vert_serparation - start_of) < vert_serparation * 0.5f)
            start = start.rotate(vert_serparation - start_of, this->m_center);
        else
            start = start.rotate((-1) * start_of, this->m_center);

        // Adjust end point based on its overflow
        std::cout << "End OF: " << radToDeg(end_of) << std::endl;
        if (end_of < vert_serparation * 0.5f)
            end = end.rotate((-1) * end_of, this->m_center);
        else
            end = end.rotate(vert_serparation - end_of, this->m_center);
    }

    return line2D(start, end);
}

line2D evenShape2D::getBlockingEdgeNaive(const point2D &ls) const
{
    auto start = point2D(0.f, 0.f);
    auto end = point2D(0.f, 0.f);

    return line2D(start, end);
}

} // namespace ds