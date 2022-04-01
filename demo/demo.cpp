#include "line2D.hpp"

int main(int argc, char **argv)
{
    std::cout << "Hello Demo!" << std::endl;

    ds::vec2f v = ds::vec2f(1, 1);
    std::cout << "Test vec2f operator<< " << v << std::endl; // Works

    ds::point2D e = ds::point2D(3, 8); // point2D = vec2f (alias)
    ds::line2D line = ds::line2D(v, e);
    //std::cout << "Test line2D operator<< " << line << std::endl; // Don't work

    return 0;
}