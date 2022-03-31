#include "../include/vec2f.hpp"

/**
 * @brief Overload of << operator for ds::vec2f class to allow for printing it in std::cout.
 * 
 * @param out std::ostream reference (&)
 * @param v ds::vec2f reference (&)
 * @return std::ostream& out
 */
std::ostream & operator<<(std::ostream &out, const ds::vec2f &v)
{
    return out << "[" << v.x << ", " << v.y << "]";
}

/**
 * @brief Overload of + operator for ds::vec2f class to allow for vector addition.
 * 
 * @param left ds::vec2f
 * @param right ds::vec2f
 * @return ds::vec2f sum
 */
ds::vec2f operator+(const ds::vec2f &left, const ds::vec2f &right)
{
    return ds::vec2f(
        left.x + right.x,
        left.y + right.y
    );
}

float num3()
{
    return 3;
}