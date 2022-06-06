#include "../include/vec2f.hpp"

namespace ds
{

/* ### Member methods ### */

float vec2f::magnitude() const
{
    return sqrtf(this->x * this->x + this->y * this->y);
}

float vec2f::magnitude(const vec2f &origin) const
{
    auto uv = vec2f(this->x - origin.x, this->y - origin.y);
    return uv.magnitude();
}

vec2f vec2f::unit() const
{
    return (*this) / this->magnitude();
}

vec2f vec2f::unit(const vec2f &origin) const
{
    auto uv = vec2f(this->x - origin.x, this->y - origin.y);
    return uv.unit();
}

float vec2f::angle() const
{
    float rad_angle = atan2f(this->y, this->x);

    while (rad_angle < 0.f)
        rad_angle += 2*PI;

    return rad_angle;
}

float vec2f::angle(const vec2f &origin) const
{
    auto uv = vec2f(
        this->x - origin.x,
        this->y - origin.y
        );

    return uv.angle();
}

float vec2f::dotAngle(const vec2f &left, const vec2f &right) const
{
    vec2f u = left - *this;
    vec2f v = right - *this;

    return acosf(dot(u, v) / (u.magnitude() * v.magnitude()));
}

float vec2f::lineDistance(const vec2f &start, const vec2f &end) const
{
    auto p0 = *this;
    auto p1 = start;
    auto p2 = end;

    return ((p2.x - p1.x) * (p1.y - p0.y) - (p1.x - p0.x) * (p2.y - p1.y)) / ds::sqrtf(ds::powf(p2.x - p1.x, 2.f) + ds::powf(p2.y - p1.y, 2.f));
}

vec2f vec2f::flipX() const
{
    return vec2f(
        (-1) * this->x, 
        this->y
        );
}

vec2f vec2f::flipX(const vec2f &start) const
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

vec2f vec2f::flipY(const vec2f &start) const
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

vec2f vec2f::flip(const vec2f &start) const
{
    vec2f uv = (*this) - start;

    return start + uv.flip();
}

vec2f vec2f::rotate(const float ang) const
{
    return vec2f(
        this->x * cosf(ang) - this->y * sinf(ang),
        this->x * sinf(ang) + this->y * cosf(ang)
    );
}

vec2f vec2f::rotate(const float ang, const vec2f &origin) const
{
    vec2f uv = (*this) - origin;

    return origin + uv.rotate(ang);
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
    ds::addToCounter(ADD, 2);
    return vec2f(
        left.x + right.x,
        left.y + right.y
    );
}

vec2f operator-(const vec2f &left, const vec2f &right)
{
    ds::addToCounter(SUB, 2);
    return vec2f(
        left.x - right.x,
        left.y - right.y
    );
}

vec2f operator*(const vec2f &vec, const float &scalar)
{
    ds::addToCounter(MULT, 2);
    return vec2f(
        vec.x * scalar,
        vec.y * scalar  
    );
}

vec2f operator/(const vec2f &vec, const float &scalar)
{
    if (scalar == 0.f)
        throw std::runtime_error("vec2f::Scalar division by 0");
    else {
        ds::addToCounter(DIV, 2);
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

} // ### END OF NAMESPACE DS ###