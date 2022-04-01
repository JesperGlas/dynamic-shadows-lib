#include "mathplotUtil.hpp" // Contains matplotlib header

int main(int argc, char **argv)
{
    std::cout << "Hello Demo!" << std::endl;

    ds::vec2f v = ds::vec2f(0, 0);
    std::cout << "Test vec2f operator<< " << v << std::endl; // Works

    ds::point2D e = ds::point2D(5, 5); // point2D = vec2f (alias)
    ds::line2D line = ds::line2D(v, e);
    std::cout << "Test line2D operator<< " << line << std::endl; // Don't work

    // Matplot
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);
    plot(line, "b");
    plot(ds::normal(line, ds::LEFT), "r");
    std::cout << "Line: " << line << std::endl << "Norm: " << ds::normal(line, ds::LEFT) << std::endl;
    plt::show();

    return 0;
}