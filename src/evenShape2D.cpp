#include "evenShape2D.hpp"

namespace ds
{

evenShape2D::evenShape2D(
    const point2D center,
    const float radius,
    const size_t size
) : shape2D(center, radius, size)
{
    this->m_vertSeparation = 360 / size; // set separation between vertices (in degrees)

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
    line2D cen2ls = line2D(this->m_center, ls);
    float nerest_vert_angle = this->m_vertSeparation * round(cen2ls.normalDirection().degAngle() / this->m_vertSeparation);
    point2D start = this->m_vertices[0].rotateRelTo(
        this->m_center,
        nerest_vert_angle
    );

    std::cout << "Angle: " << nerest_vert_angle << std::endl;

    point2D end = start.flipRelTo(this->m_center);

    return line2D(
        start,
        end
    );
}

line2D evenShape2D::getBlockingEdgeNaive(const point2D &ls) const
{
    point2D start = point2D();
    point2D end = point2D();

    for (size_t i {0}; i < this->m_size; i++)
    {
        point2D current_vertex = this->m_vertices.at(i);
        point2D next_vertex = this->m_vertices.at(i % (this->m_size-1));

        std::cout   << "Current index is: " << i << "\n"
                    << "Next index is: " << i % (this->m_size-1)
                    << std::endl;

        float ls_angle = current_vertex.degAngleRelTo(ls);
        float start_angle = next_vertex.degAngleRelTo(current_vertex);
        float end_angle = current_vertex.degAngleRelTo(next_vertex);

        if (start_angle > ls_angle)
            start = current_vertex;
        if (end_angle > ls_angle)
            end = next_vertex;
    }

    return line2D(
        start,
        end
    );
}

} // namespace ds