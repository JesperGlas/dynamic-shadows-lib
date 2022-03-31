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

std::ostream & operator<<(std::ostream &out, const vec2f &v);
bool operator==(const vec2f &left, const vec2f &right);
vec2f operator+(const vec2f &left, const vec2f &right);
vec2f operator-(const vec2f &left, const vec2f &right);

vec2f operator*(const vec2f &vec, const float &scalar);
vec2f operator*(const float &scalar, const vec2f &vec);

} // End of namespace ds


#endif