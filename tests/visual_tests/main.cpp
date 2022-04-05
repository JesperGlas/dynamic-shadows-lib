#include "visualTests.hpp"

int main(int argc, char **argv)
{
    std::cout << "Generating visual tests..." << std::endl;

    // point2D
    testPoint2D();
    testRotateVec2D();

    // line2D
    testLine2D();
    testLine2DNormal();
    testLine2DFlip();

    // square2D
    testSquare2D();
    testSquareBlock();
    testSquareShadowConcept();

    // triangle2D
    testTriangle2D();

    return 0;
}

void setupDefaultFigure()
{
    // Figure settings
    plt::figure();
    plt::figure_size(400, 400);
    plt::set_aspect(1);
    plt::xlim(-10, 10);
    plt::ylim(-10, 10);
    plt::tight_layout();
}

void saveDefaultFigure(std::string title)
{
    // Plot visuals
    plt::title(title);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
    plt::save(OUT_PATH + title + ".png");
}

void testPoint2D()
{
    // Test config
    std::string test = "testPoint2D";
    std::cout << "Generating " << test << " visual..." << std::endl;

    setupDefaultFigure();

    // Geometry
    auto origo = ds::point2D(0, 0);
    auto p1 = ds::point2D(-3, 5);
    auto p2 = ds::point2D(4, -3);

    // Plots
    plot(origo, "ob", "Origo");
    plot(p1, "og");
    plot(p2, "or");

    saveDefaultFigure(test);
}

void testRotateVec2D()
{
    // Test config
    std::string test = "testRotateVec2f";
    std::cout << "Generating " << test << " visual..." << std::endl;

    setupDefaultFigure();

    // Geometry
    auto origo = ds::point2D(0, 0);
    auto p1 = ds::point2D(3, 0);

    // Plots
    plot(origo, ".g", "Origo");
    plot(p1, "ob", "P1");
    plot(ds::rotate(p1, 90), "or", "Rotate p1 by 90");

    saveDefaultFigure(test);
}

void testLine2D()
{
    std::string test = "testLine2D";
    std::cout << "Generating " << test << " visual..." << std::endl;

    setupDefaultFigure();

    // Geometry
    auto p1 = ds::point2D(-3, 2);
    auto p2 = ds::point2D(7, -6);
    auto l1 = ds::line2D(p1, p2);

    // Plots
    plot(l1, "b", "line2D { [-3 2] -> [7 -6] }");

    saveDefaultFigure(test);
}

void testLine2DNormal()
{
    std::string test = "testLine2DNormal";
    std::cout << "Generating " << test << " visual..." << std::endl;

    setupDefaultFigure();

    // Geometry
    auto p1 = ds::point2D(0, 0);
    auto p2 = ds::point2D(5, 5);
    auto l1 = ds::line2D(p1, p2);

    // Plots
    plot(l1, "b", "line2D");
    plot(ds::line2D(l1.start, l1.normalDirection()), "r--");

    saveDefaultFigure(test);
}

void testLine2DFlip()
{
    std::string test = "testLine2DFlip";
    std::cout << "Generating " << test << " visual..." << std::endl;

    setupDefaultFigure();

    // Geometry
    auto start = ds::point2D(-1, 2);
    auto end = ds::point2D(3, -3);
    auto line = ds::line2D(start, end);

    // Plots
    plot(line, "ob-", "Original Line");
    plot(flip(line), "b--", "Line with flipped axis");
    plot(flipX(line), "r:", "Line with flipped x-value");
    plot(flipY(line), "g:", "Line with flipped y-value");

    saveDefaultFigure(test);
}

void testSquare2D()
{
    std::string test = "testSquare2D";
    std::cout << "Generating " << test << " visual..." << std::endl;

    setupDefaultFigure();

    // Geometry
    auto origo = ds::point2D(0, 0);
    auto square_center = ds::point2D(1, -2);
    auto sq = ds::square2D(
        square_center,
        5
    );
    
    // Plots
    plot(origo, "og", "Origo");
    plot(sq.m_center, ".r", "Square Center");
    plot(sq, "b");

    saveDefaultFigure(test);
}

void testSquareBlock()
{
    std::string test = "testSquareBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ls = ds::point2D(-1, 2);
    auto sq = ds::square2D(
        ds::point2D(2, -3),
        2
    );
    auto sq_ls = ds::line2D(ls, sq.m_center);

    // Plots
    plot(ls, "or", "Light Source");
    plot(sq.m_center, "ob", "Square Center");
    plot(sq_ls, "r--", "LS -> SQ");
    plot(ds::line2D(sq_ls.end, sq_ls.end + sq_ls.normalDirection() * 2), "g:");
    plot(ds::line2D(sq_ls.end, sq_ls.end + flip(sq_ls.normalDirection()) * 2), "g:");
    plot(sq, "b");

    saveDefaultFigure(test);
}

void testSquareShadowConcept()
{
    std::string test = "testSquareShadowConcept";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

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

    saveDefaultFigure(test);
}

void testTriangle2D()
{
    std::string test = "testTriangle2D";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto tri = ds::triangle2D(ori, 4);

    // Plots
    plot(ori, ".g", "Center");
    plot(tri, "b");

    std::cout << tri << std::endl;

    saveDefaultFigure(test);
}