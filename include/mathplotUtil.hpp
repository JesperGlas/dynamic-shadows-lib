#ifndef __MATHPLOTCPP_UTIL_HPP__
#define __MATHPLOTCPP_UTIL_HPP__

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#include <cmath>
#include <vector>
#include <string>

#include "vec2f.hpp"
#include "line2D.hpp"

/**
 * @brief Overloaded plot for line2D class
 * 
 * @param l const ds::line2D ref
 */
void plot(const ds::line2D &l, std::string options)
{
    std::vector<float> x = {
        l.start.x,
        l.end.x
    };

    std::vector<float> y = {
        l.start.y,
        l.end.y
    };

    plt::plot(x, y, options);
}

#endif