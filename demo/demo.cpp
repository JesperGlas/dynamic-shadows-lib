#include "mathplotUtil.hpp" // Contains matplotlib header

int main(int argc, char **argv)
{
    std::cout << "Hello Demo!" << std::endl;

    ds::vec2f v = ds::vec2f(0, 0); // define a vec2f
    std::cout << "Test vec2f operator<< " << v << std::endl; // test vec2f << overloaded operator

    ds::point2D e = ds::point2D(5, 5); // define a point2D (vec2f alias)
    ds::line2D line = ds::line2D(v, e); // define a line2D (using v and e)
    std::cout << "Test line2D operator<< " << line << std::endl; // test line2D << overloaded operator

    auto sq = ds::square2D(ds::point2D(1, 1), 4); // define a square2D
    std::cout << "Test square2D operator<< " << sq << std::endl; // test square2D << overloaded operator

    ds::tanf(12);
    ds::sqrtf(4);
    ds::sqrtf(40);
    ds::tanf(24);
    ds::tanf(45);

    // Matplot
    plt::figure_size(400, 400); // set figure size
    plt::set_aspect(1); // set aspect ratio of figure
    plt::xlim(-10, 10); // set x-limits
    plt::ylim(-10, 10); // set y-limits
    plot(line, "b"); // plot the line as a solid blue line
    plot(sq, "r--"); // plot the square as a dashed red line
    plt::show(); // show the plot

    ds::printMathStats(); // Prints how many times each function in math.hpp has been called.

    return 0;
}