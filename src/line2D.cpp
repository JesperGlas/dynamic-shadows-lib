#include "../include/line2D.hpp"

namespace ds
{

/* ##### Member functions ##### */

line2D & line2D::transformFlipX()
{
    this->end = this->end.flipX(this->start);
    
    return *this;
}

line2D & line2D::transformFlipY()
{
    this->end = this->end.flipY(this->start);
    
    return *this;
}

line2D & line2D::transformFlip()
{
    this->end = this->end.flip(this->start);
    
    return *this;
}

/* ### ACCESSORS ### */

vec2f line2D::vector() const
{
    return this->end - this->start;
}

float line2D::length() const
{
    return this->vector().magnitude();
}

vec2f line2D::direction() const
{
    return this->vector() / this->length();
}

vec2f line2D::rightNormalDirection() const
{
    return this->direction().rightNormal();
}

vec2f line2D::leftNormalDirection() const
{
    return this->direction().leftNormal();
}

float line2D::angle() const
{
    return this->direction().angle();
}

float line2D::rightNormalAngle() const
{
    return this->rightNormalDirection().angle();
}

float line2D::leftNormalAngle() const
{
    return this->leftNormalDirection().angle();
}

line2D line2D::flipEnd() const
{
    return line2D(this->start, this->end.flip(this->start));
}

line2D line2D::flipStart() const
{
    return line2D(this->start.flip(this->end), this->end);
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