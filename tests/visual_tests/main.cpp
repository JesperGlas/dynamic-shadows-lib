#include "visual_tests.hpp"
#include "mathplotUtil.hpp" // Contains matplotlib header

int main(int argc, char **argv)
{
    std::cout << "Generating visual tests..." << std::endl;

    testPoint2D();
    testLine2D();
    testLine2DNormal();

    return 0;
}

void testPoint2D()
{
    // Test config
    std::string test = "testPoint2D";
    std::cout << "Generating " << test << " visual..." << std::endl;

    // Geometry
    auto origo = ds::point2D(0, 0);
    auto p1 = ds::point2D(-3, 5);
    auto p2 = ds::point2D(4, -3);

    // Figure settings
    plt::figure();
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);
    plt::tight_layout();

    // Plots
    plot(origo, "ob", "Origo");
    plot(p1, "og");
    plot(p2, "or");

    // Plot visuals
    plt::title(test);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
    plt::save(OUT_PATH + test + ".png");
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
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);
    plt::tight_layout();

    // Plots
    plot(l1, "b", "line2D { [-3 2] -> [7 -6] }");

    // Plot visuals
    plt::title(test);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
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
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);
    plt::tight_layout();

    // Plots
    plot(l1, "b", "line2D");
    plot(ds::normal(l1, ds::LEFT), "g--", "Left normal");
    plot(ds::normal(l1, ds::RIGHT), "r--", "Right normal");

    // Plot visuals
    plt::title(test);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
    plt::save(OUT_PATH + test + ".png");
}