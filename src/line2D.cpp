#include "../include/line2D.hpp"

namespace ds
{

/* ##### Member functions ##### */

line2D & line2D::transformFlipX()
{
    this->end = flipX(this->start, this->end);
    
    return *this;
}

line2D & line2D::transformFlipY()
{
    this->end = flipY(this->start, this->end);
    
    return *this;
}

line2D & line2D::transformFlip()
{
    this->end = flip(this->start, this->end);
    
    return *this;
}

vec2f line2D::vector() const
{
    return this->end - this->start;
}

float line2D::length() const
{
    return distance(this->start, this->end);
}

vec2f line2D::direction() const
{
    return this->vector() / this->length();
}

vec2f line2D::normalDirection() const
{
    return this->direction().normal();
}


/* ##### Free functions ##### */

std::ostream & operator<<(std::ostream &out, const line2D &l)
{
    return out << "{" << l.start << " -> " << l.end << "}";
}

bool operator==(const line2D &left, const line2D &right)
{
    return (left.start == right.start) && (left.end == right.end);
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