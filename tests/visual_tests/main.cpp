#include "visual_tests.hpp"
#include "mathplotUtil.hpp" // Contains matplotlib header

int main(int argc, char **argv)
{
    std::cout << "Generating visual tests..." << std::endl;

    testLine2D();
    testLine2DNormal();

    return 0;
}

void testLine2D()
{
    std::string test = "testLine2D";
    std::cout << "Generating " << test << " visual..." << std::endl;

    // Geometry
    auto p1 = ds::point2D(-3, 2);
    auto p2 = ds::point2D(7, -6);
    auto l1 = ds::line2D(p1, p2);
    
    // Figure settings
    plt::figure();
    plt::title(test);
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);

    // Plots
    plot(l1, "b");

    plt::save(OUT_PATH + test + ".png");
}

void testLine2DNormal()
{
    std::string test = "testLine2DNormal";
    std::cout << "Generating " << test << " visual..." << std::endl;

    // Geometry
    auto p1 = ds::point2D(0, 0);
    auto p2 = ds::point2D(5, 5);
    auto l1 = ds::line2D(p1, p2);
    
    // Figure settings
    plt::figure();
    plt::title(test);
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);

    // Plots
    plot(l1, "b");
    plot(ds::normal(l1, ds::LEFT), "g--");
    plot(ds::normal(l1, ds::RIGHT), "r--");

    plt::save(OUT_PATH + test + ".png");
}