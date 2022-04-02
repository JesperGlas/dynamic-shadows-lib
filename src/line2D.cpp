#include "../include/line2D.hpp"

namespace ds
{

// TODO: Find out why this results in "Undefined Reference".
std::ostream & operator<<(std::ostream &out, const line2D &l)
{
    return out << "{" << l.start << " -> " << l.end << "}";
}

float length(const line2D &line)
{
    return distance(line.start, line.end);
}

line2D normal(const line2D &l, face f)
{
    vec2f uv = vec2f(
        l.end.x - l.start.x,
        l.end.y - l.start.y
    );

    float uv_len = length(l);
    vec2f uv_unit = unitVector(uv);
    vec2f uv_unit_normal = normal(uv_unit);

    return line2D(
        l.start,
        l.start + f *uv_unit_normal * uv_len
    );

}

line2D flip(const line2D &l)
{
    return line2D(l.start, flip(l.start, l.end));
}

line2D flipX(const line2D &l)
{
    return line2D(l.start, flipX(l.start, l.end));
}

line2D flipY(const line2D &l)
{
    return line2D(l.start, flipY(l.start, l.end));
}


} // ### END OF NAMESPACE DS ###