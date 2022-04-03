#include "visual_tests.hpp"
#include "mathplotUtil.hpp" // Contains matplotlib header

int main(int argc, char **argv)
{
    std::cout << "Generating visual tests..." << std::endl;

    testPoint2D();
    testLine2D();
    testLine2DNormal();
    testSquare2D();
    testLine2DFlip();
    testSquareBlock();
    testSquareShadowConcept();

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

void testSquare2D()
{
    std::string test = "testSquare2D";
    std::cout << "Generating " << test << " visual..." << std::endl;

    // Geometry
    auto origo = ds::point2D(0, 0);
    auto square_center = ds::point2D(1, -2);
    auto sq = ds::square2D(
        square_center,
        5
    );
    
    // Figure settings
    plt::figure();
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);
    plt::tight_layout();

    // Plots
    plot(origo, "og", "Origo");
    plot(sq.m_center, ".r", "Square Center");
    plot(sq, "b");

    // Plot visuals
    plt::title(test);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
    plt::save(OUT_PATH + test + ".png");
}

void testLine2DFlip()
{
    std::string test = "testLine2DFlip";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    // Figure settings
    plt::figure();
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);
    plt::tight_layout();

    // Geometry
    auto start = ds::point2D(-1, 2);
    auto end = ds::point2D(3, -3);
    auto line = ds::line2D(start, end);

    // Plots
    plot(line, "og-", "Original Line");
    plot(flip(line), "r--", "Line with flipped axis");
    plot(flipX(line), "r:", "Line with flipped x-value");
    plot(flipY(line), "g:", "Line with flipped y-value");

    // Plot visuals
    plt::title(test);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
    plt::save(OUT_PATH + test + ".png");
}

void testSquareBlock()
{
    std::string test = "testSquareBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    // Figure settings
    plt::figure();
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);
    plt::tight_layout();

    // Geometry
    auto ls = ds::point2D(-1, 2);
    auto sq = ds::square2D(
        ds::point2D(2, -3),
        2
    );
    auto sq_ls = ds::line2D(sq.m_center, ls);

    // Plots
    plot(ls, "or", "Light Source");
    plot(sq.m_center, "ob", "Square Center");
    plot(sq_ls, "r--", "LS -> SQ");
    plot(ds::normal(sq_ls, ds::LEFT), "g:");
    plot(ds::normal(sq_ls, ds::RIGHT), "g:");
    plot(sq, "b");

    // Plot visuals
    plt::title(test);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
    plt::save(OUT_PATH + test + ".png");
}

void testSquareShadowConcept()
{
    std::string test = "testSquareShadowConcept";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    // Figure settings
    plt::figure();
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-12, 12);
    plt::ylim(-12, 12);
    plt::tight_layout();

    // Geometry
    auto ls = ds::point2D(-5, 2);
    auto sq = ds::square2D(
        ds::point2D(2, -3),
        2
    );
    auto sq_ls = ds::line2D(sq.m_center, ls);
    auto ls_sq_tr = ds::line2D(ls, sq.topRight());
    auto ls_sq_bl = ds::line2D(ls, sq.bottomLeft());

    float light_intensity = 5;

    auto blocking_edge = ds::line2D(
        ls_sq_tr.end,
        ls_sq_bl.end
    );

    auto tr_shadow = ds::line2D(
        ls_sq_tr.end,
        ls_sq_tr.end + ls_sq_tr.direction() * light_intensity
    );

    auto bl_shadow = ds::line2D(
        ls_sq_bl.end,
        ls_sq_bl.end + ls_sq_bl.direction() * light_intensity
    );

    // Plots
    plot(ls, "or", "Light Source");
    plot(sq.m_center, "ob", "Square Center");
    plot(sq_ls, "r--", "LS -> SQ");
    plot(sq, "b");

    plot(ls_sq_tr, "m:");
    plot(ls_sq_bl, "m:");

    plot(blocking_edge, "m--", "Blocking Edge");
    plot(tr_shadow, "m-");
    plot(bl_shadow, "m-");

    // Plot visuals
    plt::title(test);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
    plt::save(OUT_PATH + test + ".png");
}