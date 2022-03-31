#ifndef __VEC2F_HPP__
#define __VEC2F_HPP__

#include <iostream>

namespace ds {

class vec2f {

public:
    float x;
    float y;

    vec2f(float x_value, float y_value) : x(x_value), y(y_value) {}
};

} // End of namespace ds

std::ostream & operator<<(std::ostream &out, const ds::vec2f &v);

ds::vec2f operator+(const ds::vec2f &left, const ds::vec2f &right);

#endif