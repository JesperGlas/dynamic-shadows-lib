#include "../include/line2D.hpp"

namespace ds
{

/* ##### Member functions ##### */

line2D & line2D::transformFlipX()
{
    this->end = this->end.flipXRelTo(this->start);
    
    return *this;
}

line2D & line2D::transformFlipY()
{
    this->end = this->end.flipYRelTo(this->start);
    
    return *this;
}

line2D & line2D::transformFlip()
{
    this->end = this->end.flipRelTo(this->start);
    
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

line2D line2D::flip() const
{
    return line2D(
        this->start,
        this->end.flipRelTo(this->start)
        );
}

line2D line2D::flipX() const
{
    return line2D(
        this->start,
        this->end.flipXRelTo(this->start)
        );
}

line2D line2D::flipY() const
{
    return line2D(
        this->start,
        this->end.flipYRelTo(this->start)
        );
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


} // ### END OF NAMESPACE DS ###