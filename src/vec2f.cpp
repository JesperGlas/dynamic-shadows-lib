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
    return vec2f(
        (-1) * this->y, 
        this->x
        );
}

vec2f vec2f::unitVector() const
{
    return (*this) / this->magnitude();
}

float vec2f::angle() const
{
    float rad_angle = atan2f(this->y, this->x);

    while (rad_angle < 0.f)
        rad_angle += 2*PI;

    return rad_angle;
}

float vec2f::angleRelTo(const vec2f &start) const
{
    auto uv = vec2f(
        this->x - start.x,
        this->y - start.y
        );

    return uv.angle();
}

vec2f vec2f::flipX() const
{
    return vec2f(
        (-1) * this->x, 
        this->y
        );
}

vec2f vec2f::flipXRelTo(const vec2f &start) const
{
    vec2f uv = (*this) - start;

    return start + uv.flipX();
}

vec2f vec2f::flipY() const
{
    return vec2f(
        this->x, 
        (-1) * this->y
        );
}

vec2f vec2f::flipYRelTo(const vec2f &start) const
{
    vec2f uv = (*this) - start;

    return start + uv.flipY();
}

vec2f vec2f::flip() const
{
    return vec2f(
        (-1) * this->x,
        (-1) * this->y
        );
}

vec2f vec2f::flipRelTo(const vec2f &start) const
{
    vec2f uv = (*this) - start;

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