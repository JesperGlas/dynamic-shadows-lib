#include "visualTests.hpp"
#include "map"

int main(int argc, char **argv)
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
    //testLine2DNormal();
    //testLine2DFlip();

    //testSquare2D();
    //testSquareRotate();
    testSquareBlock();
    //testSquareShadowConcept();

    //testTriangle2D();

    //testEvenShape2D();
    //testEvenShape2DBlock();

    docsSquare();
    docsSquarePerp();
    docsSquareDiag();
    docsSquareQuadrant();
    docsSquareStart();
    docsSquareBlock();
    docsCircleBlock();
    docsCircleZoom();
    docsTriangle();
    docsTrianglePerp();
    docsTriangleDiag();

    ds::printMathStats();

    return 0;
}

void setupDefaultFigure()
{
    // Figure settings
    plt::figure();
    plt::figure_size(500, 500);
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
    plt::close();
}

void saveFigure(std::string dir, std::string title)
{
    // Plot visuals
    plt::title(title);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();
    plt::save(dir + title + ".png");
    plt::close();
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
    plot(p1.rotate(ds::degToRad(90)), "or", "Rotate p1 by 90");
    plot(p1.rotate(ds::degToRad(243)), "om", "Rotate p1 by 243");

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
    auto p1 = ds::point2D(-2, -2);
    auto p2 = ds::point2D(5, 5);
    auto l1 = ds::line2D(p1, p2);
    auto l1_norm = ds::line2D(l1.start, l1.start + l1.normalDirection());

    // Plots
    plot(p1, "og", "Start");
    plot(p2, "or", "End");
    plot(l1, "b", "line2D");
    plot(l1_norm, "r--", "Outside-facing Normal");
    plot(l1_norm.transformFlip(), "g--", "Inside-facing Normal");

    plot(p1, "og");
    plot(p2, "or");

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
    line.transformFlip();
    plot(line, "b--", "Line with flipped axis");
    line.transformFlipX();
    plot(line, "r:", "Line with flipped x-value");
    line.transformFlipY();
    plot(line, "g:", "Line with flipped y-value");

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

void testSquareRotate()
{
    std::string test = "testSquareRotate";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto origo = ds::point2D(0, 0);
    float sq_radius = 4.f;
    auto sq = ds::square2D(origo, sq_radius);
    float cl_radius = ds::distance(sq.m_center, sq.corners()[0]);
    auto cl = ds::evenShape2D(origo, cl_radius, 32);

    // Plots
    plot(sq, "b");
    plot(cl, "--g");
    plot(origo, "b");

    saveDefaultFigure(test);
}

void testSquareBlock()
{
    std::string test = "testSquareBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ls = ds::point2D(0.f, -2.f);
    auto sq = ds::square2D(
        ds::point2D(-2, -2),
        2, ds::degToRad(0.f)
    );

    ls = ls.rotate(ds::degToRad(265.f), sq.m_center);

    auto sq_ls = ds::line2D(sq.m_center, ls);
    ds::line2D blocking_edge = sq.getBlockingEdge(ls);

    // Plots
    plot(sq, "b");
    plot(ls, "om", "Light Source");
    plot(sq.m_center, ".b", "Square Center");
    plot(sq_ls, "m:", "LS -> SQ");
    plot(blocking_edge, "m--", "Blocking Edge");
    plot(blocking_edge.start, "og");
    plot(blocking_edge.end, "or");

    plot(ds::line2D(ls, blocking_edge.start), ":m");
    plot(ds::line2D(ls, blocking_edge.end), ":m");

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
    auto ls_sq_tr = ds::line2D(ls, sq.right());
    auto ls_sq_bl = ds::line2D(ls, sq.left());

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

void testEvenShape2D()
{
    std::string test = "testEvenShape2D";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    auto ori = ds::point2D(1, 1);
    auto shape = ds::evenShape2D(ori, 4, 16);

    plot(shape, "b");
    plot(ori, ".b", "Center");

    saveDefaultFigure(test);
}

void testEvenShape2DBlock()
{
    std::string test = "testEvenShape2DBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    auto ls = ds::point2D(6, 1);
    auto center = ds::point2D(1, 1);
    auto shape = ds::evenShape2D(center, 3, 8);

    ls = ls.rotate(ds::degToRad(25), shape.m_center);
    ds::line2D block = shape.getBlockingEdge(ls);
    ds::line2D blockNaive = shape.getBlockingEdgeNaive(ls);

    plot(shape, "b");
    plot(ls, ".r", "Light Source");
    plot(blockNaive, "--m", "blockNaiveing Edge");
    plot(shape.m_center, "ob");
    plot(ds::line2D(ls, blockNaive.start), ":m");
    plot(ds::line2D(ls, blockNaive.end), ":m");

    saveDefaultFigure(test);
}

// Docs
void testSquareConceptDocs()
{
    std::string test = "squareConcept";
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

    saveFigure(DOCS_PATH, "docsConcept");
}

void docsSquare()
{
    std::string test = "square2D";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto sq = ds::square2D(ori, 4);
    float circ_radius = ds::distance(ori, sq.corners().at(0));
    auto circ = ds::evenShape2D(ori, circ_radius, 32);

    // Plots
    plot(ori, "ob", "Center");
    plot(ds::line2D(ori, sq[0]), "--g", "Radius");
    plot(sq, "b");
    plot(circ, ":g");
    plot(sq, "or");

    saveFigure(DOCS_PATH, test);
}

void docsSquarePerp()
{
    std::string test = "squarePerp";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto ls = ds::point2D(2, 3);
    auto sq = ds::square2D(ori, 2);

    // Plots
    plot(ori, "ob", "Origin");
    plot(ls, "or", "Light Source");
    plot(sq, "b");
    plot(
        ds::line2D(sq.corners().at(0), sq.corners().at(1)),
        "--m", "Blocking Edge"
    );

    plot(ds::line2D(sq[0], sq[0] + ds::vec2f(1, 1).unit() * 10), "g--");
    plot(ds::line2D(sq[1], sq[1] + ds::vec2f(1, 1).unit() * 10), "g--");

    saveFigure(DOCS_PATH, test);
}

void docsSquareDiag()
{
    std::string test = "squareDiag";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto ls = ds::point2D(1, 5);
    auto sq = ds::square2D(ori, 2);

    // Plots
    plot(ori, "ob", "Origin");
    plot(ls, "or", "Light Source");
    plot(sq, "b");
    plot(
        ds::line2D(sq.corners().at(0), sq.corners().at(2)),
        "--m", "Blocking Edge"
    );

    plot(ds::line2D(sq[1], sq[1] + ds::point2D(1, 1) * 10), "g--");
    plot(ds::line2D(sq[1], sq[1] + ds::point2D(-1, 1) * 10), "g--");

    saveFigure(DOCS_PATH, test);
}

void docsSquareStart()
{
    std::string test = "SquareStartEnd";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    float r {3};
    auto sq = ds::square2D(c, r, 0.f);
    auto ls = ds::point2D(-3, 6);
    auto circ = ds::evenShape2D(c, r, 32);

    // Plots
    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(sq, "b");
    plot(circ, ":y");
    plot(ds::line2D(c, ls), ":m", "C -> LS");
    plot(c + ls.unit(c) * r, "oy");
    plot(sq[1], "og", "Start");
    plot(sq[2], "or", "End");

    saveFigure(DOCS_PATH, test);
}

void docsSquareBlock()
{
    std::string test = "SquareBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    float r {4};
    auto sq = ds::square2D(c, r, 0.f);
    auto circ = ds::evenShape2D(c, r, 32);

    // Plots
    plot(c, "ob", "Center");
    plot(sq, "b");
    plot(circ, ":y");
    plot(ds::line2D(c, sq[0]), ":y", "Radius");
    plot(ds::line2D(c, c + ds::point2D(1, 0) * 20.f), "m--", "Vertex separation (Section)");
    plot(ds::line2D(c, c + ds::point2D(0, 1) * 20.f), "m--");
    plot(ds::line2D(sq[0], sq[0] + ds::point2D(1, 1) * 20.f), ":g", "Start Check");
    plot(ds::line2D(sq[1], sq[1] + ds::point2D(1, 1) * 20.f), ":r", "End Check");
    plot(sq[0], "og");
    plot(sq[1], "or");
    plot(c, "ob");

    saveFigure(DOCS_PATH, test);
}

void docsSquareQuadrant()
{
    std::string test = "squareQuadrant";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto ls = ds::point2D(-2, 5);
    auto sq = ds::square2D(ori, 3);

    // Plots
    plot(ori, "ob", "Origin");
    plot(ls, "*m", "Light Source");
    plot(sq, "b");
    plot(sq[0], "or", "Vertices");

    plot(ds::line2D(sq.m_center, sq.m_center + ds::point2D(1, 0) * 10), "g--");
    plot(ds::line2D(sq.m_center, sq.m_center + ds::point2D(0, 1) * 10), "g--");
    plot(ds::line2D(sq.m_center, sq.m_center + ds::point2D(-1, 0) * 10), "g--");
    plot(ds::line2D(sq.m_center, sq.m_center + ds::point2D(0, -1) * 10), "g--", "Quadrant Borders");

    plot(sq, "or");
    plot(ori, "ob");

    saveFigure(DOCS_PATH, test);
}

void docsCircleBlock()
{
    std::string test = "circleBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, -2);
    auto ls = ds::line2D(
        ds::point2D(7, 10),
        ds::point2D(7, -10)
    );
    auto circ = ds::evenShape2D(ori, 2, 32);
    auto ls_ori = ds::line2D(ori, ds::point2D(7, -2));
    auto block_start = ds::line2D(ori, ds::point2D(0, 0));
    auto block_end = block_start.flipEnd();

    for(int i = -10; i <= 10; i++)
    {
        auto start = ds::point2D(7, i);
        auto end = ds::point2D(6, i);
        plot(ds::line2D(start, end), "--m");
    }

    // Plots
    plot(ori, "ob", "Origin");
    plot(ls, "m", "Directional Light");
    plot(circ, "b");
    plot(ls_ori, "--m", "Light Direction");
    plot(block_start, ":g", "Find blocking edge start");
    plot(block_end, ":r", "Find blocking edge end");
    plot(
        ds::line2D(ds::point2D(7, 0), ds::point2D(0, 0)),
        ":y", "Light"
    );
    plot(
        ds::line2D(ds::point2D(7, -4), ds::point2D(0, -4)),
        ":y"
    );
    plot(
        ds::line2D(ds::point2D(0, 0), ds::point2D(-10, 0)),
        ":k", "Shadow"
    );
    plot(
        ds::line2D(ds::point2D(0, -4), ds::point2D(-10, -4)),
        ":k"
    );

    saveFigure(DOCS_PATH, test);
}

void docsCircleZoom()
{
    std::string test = "circleZoom";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(-9, -9);
    auto circ = ds::evenShape2D(c, 10, 16);
    auto dir = ds::line2D(
        ds::point2D(-9, 1),
        ds::point2D(10, 1)
    );
    auto ls = ds::point2D(4, -9);
    auto ls_v = ds::line2D(ls, circ[2]);
    auto cut = ds::line2D(ls, circ[4]);

    // Plots
    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(circ, "b");
    plot(dir, "--y", "Perpendicular Light to Blocking Vertex");
    plot(cut, ":r", "Direct Path to Perpendicular Blocking Vertex");
    plot(ls_v, "--m", "Point Light Path to Blocking Vertex");
    plot(ds::line2D(c, circ[0]), ":b");
    plot(ds::line2D(c, circ[4]), ":b");
    plot(ds::line2D(ds::point2D(10, -9), circ[0]), "--y");
    plot(circ, ".r");
    plot(c, "ob");
    plot(ls, "om");

    saveFigure(DOCS_PATH, test);
}

void docsTriangle()
{
    std::string test = "triangle2D";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    auto tri = ds::triangle2D(c, 4);
    auto circ = ds::evenShape2D(c, 4, 32);

    // Plots
    plot(c, "ob", "Center");
    plot(tri, "b");
    plot(tri, "or");
    plot(circ, ":g");
    plot(ds::line2D(c, tri[0]), "g--", "Radius");
    plot(tri[0], "or", "Vertices");

    saveFigure(DOCS_PATH, test);
}

void docsTrianglePerp()
{
    std::string test = "TrianglePerp";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    auto ls = ds::point2D(7, 4);
    auto tri = ds::triangle2D(c, 4);
    auto be = ds::line2D(tri[0], tri[1]);

    // Plots
    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(tri, "b");
    plot(tri, "or");
    plot(be, "m--", "Blocking Edge");

    plot(ds::line2D(
        tri[0],
        tri[0] + tri[0].unit(tri[-1]) * 10.f
    ), ":g");
    plot(ds::line2D(
        tri[1],
        tri[1] + tri[1].unit(tri[2]) * 10.f
    ), ":g");

    plot(ds::line2D(ls, be.start), ":m");
    plot(ds::line2D(ls, be.end), ":m");

    saveFigure(DOCS_PATH, test);
}

void docsTriangleDiag()
{
    std::string test = "TriangleDiag";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    auto ls = ds::point2D(-5, 7);
    auto tri = ds::triangle2D(c, 4);
    auto be = ds::line2D(tri[2], tri[3]);

    // Plots
    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(tri, "b");
    plot(tri, "or");
    plot(be, "m--", "Blocking Edge");

    plot(ds::line2D(
        tri[0],
        tri[0] + tri[0].unit(tri[-1]) * 10.f
    ), ":g");
    plot(ds::line2D(
        tri[2],
        tri[2] + tri[2].unit(tri[3]) * 10.f
    ), ":g");

    plot(ds::line2D(ls, be.start), ":m");
    plot(ds::line2D(ls, be.end), ":m");

    saveFigure(DOCS_PATH, test);
}