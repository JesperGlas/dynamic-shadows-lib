#include "../include/line2D.hpp"

namespace ds
{

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