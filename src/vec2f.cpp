#include "../include/vec2f.hpp"

namespace ds
{

std::ostream & operator<<(std::ostream &out, const vec2f &v)
{
    return out << "[" << v.x << ", " << v.y << "]";
}

bool operator==(const vec2f &left, const vec2f &right)
{
    return (left.x == right.x) && (left.y == right.y);
}

vec2f operator+(const vec2f &left, const vec2f &right)
{
    return vec2f(
        left.x + right.x,
        left.y + right.y
    );
}

vec2f operator-(const vec2f &left, const vec2f &right)
{
    return vec2f(
        left.x - right.x,
        left.y - right.y
    );
}

vec2f operator*(const vec2f &vec, const float &scalar)
{
    return vec2f(
        vec.x * scalar,
        vec.y * scalar  
    );
}

vec2f operator*(const float &scalar, const vec2f &vec)
{
    return vec * scalar;
}

vec2f operator/(const vec2f &vec, const float &scalar)
{
    if (scalar == 0.f)
        throw std::runtime_error("Scalar division by 0");
    else {
        return vec2f(
            vec.x / scalar,
            vec.y / scalar
        );
    }
}

float dot(const vec2f &left, const vec2f &right)
{
    return (left.x * right.x) + (left.y * right.y);
}

float dist(const point2D &start, const point2D &end)
{
    float x = abs(end.x - start.x);
    float y = abs(end.y - start.y);
    
    return sqrtf(powf(x, 2.f) + pow(y, 2.f));
}


} // ### End of namespace ds ###