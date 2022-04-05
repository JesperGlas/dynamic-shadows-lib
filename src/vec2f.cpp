#include "../include/vec2f.hpp"

namespace ds
{

/* ### Member methods ### */

float vec2f::vec2f::magnitude() const
{
    return sqrtf(this->x * this->x + this->y * this->y);
}

vec2f vec2f::normal() const
{
    return vec2f(-this->y, this->x);
}

vec2f vec2f::unitVector() const
{
    return *this / this->magnitude();
}

vec2f vec2f::flipX() const
{
    return vec2f(-this->x, this->y);
}

vec2f vec2f::flipX(const vec2f &start) const
{
    vec2f uv = *this - start;

    return start + uv.flipX();
}

vec2f vec2f::flipY() const
{
    return vec2f(this->x, -this->y);
}

vec2f vec2f::flipY(const vec2f &start) const
{
    vec2f uv = *this - start;

    return start + uv.flipY();
}

vec2f vec2f::flip() const
{
    return vec2f(-this->x, -this->y);
}

vec2f vec2f::flip(const vec2f &start) const
{
    vec2f uv = *this - start;

    return start + uv.flip();
}

vec2f vec2f::rotate(const float ang) const
{
    return vec2f(
        this->x * cosf(degToRad(ang)) - this->y * sinf(degToRad(ang)),
        this->x * sinf(degToRad(ang)) + this->y * cosf(degToRad(ang))
    );
}

/* ### Free methods ### */

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

/* ### 2D Space Functions ### */

float distance(const point2D &start, const point2D &end)
{
    float u = abs(end.x - start.x);
    float v = abs(end.y - start.y);
    
    return vec2f(u, v).magnitude();
}


} // ### END OF NAMESPACE DS ###