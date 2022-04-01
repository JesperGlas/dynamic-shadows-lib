#include "../include/line2D.hpp"

namespace ds
{

// TODO: Find out why this results in "Undefined Reference".
std::ostream & operator<<(std::ostream &out, const line2D &l)
{
    return out << "{" << l.start << " ->" << l.end << "}";
}

float length(const line2D &line)
{
    return distance(line.start, line.end);
}

} // ### END OF NAMESPACE DS ###