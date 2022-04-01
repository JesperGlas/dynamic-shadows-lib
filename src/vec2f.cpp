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

float magnitude(const vec2f &v)
{
    return sqrtf(v.x * v.x + v.y * v.y); 
}

vec2f normal(const vec2f &v)
{
    return vec2f(-v.y, v.x);
}

vec2f unitVector(const vec2f &v)
{
    return v / magnitude(v);
}

vec2f flipX(const vec2f &v)
{
    return vec2f(-v.x, v.y);
}

vec2f flipY(const vec2f &v)
{
    return vec2f(v.x, -v.y);
}

vec2f flip(const vec2f &v)
{
    return vec2f(-v.x, -v.y);
}

/* ### 2D Space Functions ### */

float distance(const point2D &start, const point2D &end)
{
    float u = abs(end.x - start.x);
    float v = abs(end.y - start.y);
    
    return magnitude(vec2f(u, v));
}


} // ### END OF NAMESPACE DS ###