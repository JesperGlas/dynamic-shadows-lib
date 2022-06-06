#include "visualTests.hpp"

void generateTests()
{
    std::cout << "Generating visual tests..." << std::endl;

    /**###############################################
     * ONLY 20 VISUAL TESTS CAN BE ACTIVE AT ANY TIME!
     * There is some bug (or missunderstanding) in how
     * to close figures in matplotlibcpp.
     #################################################*/

    //testPoint2D();
    //testRotateVec2D();

    //testLine2D();

    //testSquare2D();
    //testSquareRotate();
    testSquareBlock();
    //testSquareShadowConcept();

    //testTriangle2D();
    testTriangleBlock();

    //testshape2D();
    testEvenShapeBlock();
    testShapeNaiveBlock();
    testShapeHybridBlock();
}

void testPoint2D()
{
    // Test config
    std::string test = "Point2D";
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

    saveTestFigure(test);
}

void testRotateVec2D()
{
    // Test config
    std::string test = "RotateVec2f";
    std::cout << "Generating " << test << " visual..." << std::endl;

    setupDefaultFigure();

    // Geometry
    auto origo = ds::point2D(0, 0);
    auto p1 = ds::point2D(3, 0);

    // Plots
    plot(origo, ".g", "Origo");
    plot(p1, "ob", "P1");
    plot(p1.rotate(ds::degToRad(90)), "or", "Rotate p1 by 90");
    plot(p1.rotate(ds::degToRad(243)), "om", "Rotate p1 by 243");

    saveTestFigure(test);
}

void testLine2D()
{
    std::string test = "Line2D";
    std::cout << "Generating " << test << " visual..." << std::endl;

    setupDefaultFigure();

    // Geometry
    auto p1 = ds::point2D(-3, 2);
    auto p2 = ds::point2D(7, -6);
    auto l1 = ds::line2D(p1, p2);

    // Plots
    plot(l1, "b", "line2D { [-3 2] -> [7 -6] }");

    saveTestFigure(test);
}

void testSquare2D()
{
    std::string test = "Square2D";
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

    saveTestFigure(test);
}

void testSquareRotate()
{
    std::string test = "SquareRotate";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto origo = ds::point2D(0, 0);
    float sq_radius = 4.f;
    auto sq = ds::square2D(origo, sq_radius);
    float cl_radius = ds::distance(sq.m_center, sq.corners()[0]);
    auto cl = ds::shape2D(origo, cl_radius, 32);

    // Plots
    plot(sq, "b");
    plot(cl, "--g");
    plot(origo, "b");

    saveTestFigure(test);
}

void testSquareBlock()
{
    std::string test = "SquareBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ls = ds::point2D(2.f, -2.f);
    auto sq = ds::square2D(
        ds::point2D(-2, -2),
        2, ds::degToRad(0.f)
    );

    ls = ls.rotate(ds::degToRad(190.f), sq.m_center);

    auto sq_ls = ds::line2D(sq.m_center, ls);
    ds::line2D be = sq.getBlockingEdge(ls);

    // Plots
    plot(sq, "b");
    plot(ls, "om", "Light Source");
    plot(sq.m_center, ".b", "Square Center");
    plot(be, "m--", "Blocking Edge");
    plot(be.start, "og");
    plot(be.end, "or");

    plot(ds::line2D(ls, be.start), "m");
    plot(ds::line2D(ls, be.end), "m");

    plot(ds::line2D(
        be.start,
        be.start + be.start.unit(ls) * 20.f
    ), "m:");
    plot(ds::line2D(
        be.end,
        be.end + be.end.unit(ls) * 20.f
    ), "m:");

    saveTestFigure(test);
}

void testSquareShadowConcept()
{
    std::string test = "SquareShadowConcept";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ls = ds::point2D(-5, 2);
    auto sq = ds::square2D(
        ds::point2D(2, -3),
        2
    );
    auto sq_ls = ds::line2D(sq.m_center, ls);
    auto ls_sq_tr = ds::line2D(ls, sq.right());
    auto ls_sq_bl = ds::line2D(ls, sq.left());

    float light_intensity = 5;

    auto blocking_edge = ds::line2D(
        ls_sq_tr.end,
        ls_sq_bl.end
    );

    // Plots
    plot(ls, "or", "Light Source");
    plot(sq.m_center, "ob", "Square Center");
    plot(sq_ls, "r--", "LS -> SQ");
    plot(sq, "b");

    plot(ls_sq_tr, "m:");
    plot(ls_sq_bl, "m:");

    plot(blocking_edge, "m--", "Blocking Edge");

    saveTestFigure(test);
}

void testTriangle2D()
{
    std::string test = "Triangle2D";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto tri = ds::triangle2D(ori, 4);

    // Plots
    plot(ori, ".g", "Center");
    plot(tri, "b");

    std::cout << tri << std::endl;

    saveTestFigure(test);
}

void testTriangleBlock()
{
    std::string test = "TriangleBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ls = ds::point2D(2.f, -2.f);
    auto tri = ds::triangle2D(
        ds::point2D(-2, -2),
        2
    );

    ls = ls.rotate(ds::degToRad(110.f), tri.m_center);

    auto tri_ls = ds::line2D(tri.m_center, ls);
    ds::line2D be = tri.getBlockingEdge(ls);

    // Plots
    plot(tri, "b");
    plot(ls, "om", "Light Source");
    plot(tri.m_center, ".b", "Triangle Center");
    plot(be, "m--", "Blocking Edge");
    plot(be.start, "og");
    plot(be.end, "or");

    plot(ds::line2D(ls, be.start), "m");
    plot(ds::line2D(ls, be.end), "m");

    plot(ds::line2D(
        be.start,
        be.start + be.start.unit(ls) * 20.f
    ), "m:");
    plot(ds::line2D(
        be.end,
        be.end + be.end.unit(ls) * 20.f
    ), "m:");

    saveTestFigure(test);
}

void testshape2D()
{
    std::string test = "shape2D";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    auto ori = ds::point2D(1, 1);
    auto shape = ds::shape2D(ori, 4, 16);

    plot(shape, "b");
    plot(ori, ".b", "Center");

    saveTestFigure(test);
}

void testEvenShapeBlock()
{
    std::cout << "Generating " << __FUNCTION__ << " visual..." << std::endl;
    
    setupDefaultFigure();

    auto c = ds::point2D(-1.f, -1.f);
    auto ls = ds::point2D(2.f, 1.f); //0.68/120d inside
    auto r = 3.f;

    ls = ls.rotate(ds::degToRad(5.f), c);

    auto sh = ds::shape2D(c, r, 6);
    auto circ = ds::shape2D(c, r, 32);

    ds::resetCounters(); // Reset math counters
    auto be = sh.getBlockingEdge(ls);
    ds::printMathStats(__FUNCTION__);

    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(sh, "b");
    plot(circ, ":y");
    plot(be, "m--", "Blocking Edge");
    plot(ds::line2D(ls, be.start), "m");
    plot(ds::line2D(ls, be.end), "m");
    plot(ds::line2D(
        be.start,
        be.start + be.start.unit(ls) * 20.f
    ), "m:");
    plot(ds::line2D(
        be.end,
        be.end + be.end.unit(ls) * 20.f
    ), "m:");

    plot(sh, ".y");
    plot(be.start, ".g");
    plot(be.end, ".r");

    saveTestFigure(__FUNCTION__);
}

void testShapeNaiveBlock()
{
    std::cout << "Generating " << __FUNCTION__ << " visual..." << std::endl;
    
    setupDefaultFigure();

    auto c = ds::point2D(-1.f, -1.f);
    auto ls = ds::point2D(3.f, 2.f); //0.68/120d inside
    auto r = 3.f;

    ls = ls.rotate(ds::degToRad(292.f), c);

    auto sh = ds::shape2D(c, r, 8);
    auto circ = ds::shape2D(c, r, 32);

    ds::resetCounters(); // Reset math counters
    auto be = sh.getBlockingEdgeNaive(ls);
    ds::printMathStats(__FUNCTION__);

    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(sh, "b");
    plot(circ, ":y");
    plot(be, "m--", "Blocking Edge");
    plot(ds::line2D(ls, be.start), "m");
    plot(ds::line2D(ls, be.end), "m");
    plot(ds::line2D(
        be.start,
        be.start + be.start.unit(ls) * 20.f
    ), "m:");
    plot(ds::line2D(
        be.end,
        be.end + be.end.unit(ls) * 20.f
    ), "m:");

    plot(sh, ".y");
    plot(be.start, ".g");
    plot(be.end, ".r");

    saveTestFigure(__FUNCTION__);
}

void testShapeHybridBlock()
{
    std::cout << "Generating " << __FUNCTION__ << " visual..." << std::endl;
    
    setupDefaultFigure();

    auto c = ds::point2D(-1.f, -1.f);
    auto ls = ds::point2D(5.f, 2.f); //0.68/120d inside
    auto r = 3.f;

    ls = ls.rotate(ds::degToRad(285.f), c);

    auto sh = ds::shape2D(c, r, 5);
    auto circ = ds::shape2D(c, r, 32);

    ds::resetCounters(); // Reset math counters
    auto be = sh.getBlockingEdgeHybrid(ls);
    ds::printMathStats(__FUNCTION__);

    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(sh, "b");
    plot(circ, ":y");
    plot(be, "m--", "Blocking Edge");
    plot(ds::line2D(ls, be.start), "m");
    plot(ds::line2D(ls, be.end), "m");
    plot(ds::line2D(
        be.start,
        be.start + be.start.unit(ls) * 20.f
    ), "m:");
    plot(ds::line2D(
        be.end,
        be.end + be.end.unit(ls) * 20.f
    ), "m:");

    plot(sh, ".y");
    plot(be.start, ".g");
    plot(be.end, ".r");

    saveTestFigure(__FUNCTION__);
}
