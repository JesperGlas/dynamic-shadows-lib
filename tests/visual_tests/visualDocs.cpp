#include "visualDocs.hpp"

void generateDocs()
{
    std::cout << "Generating visual docs..." << std::endl;

    /**###############################################
     * ONLY 20 VISUAL TESTS CAN BE ACTIVE AT ANY TIME!
     * There is some bug (or missunderstanding) in how
     * to close figures in matplotlibcpp.
     #################################################*/

    //docsSquare();
    //docsSquarePerp();
    //docsSquareDiag();
    //docsSquareQuadrant();
    //docsSquareStart();
    //docsSquareBlock();

    docsCircleBlock();
    docsCircleZoom();
    docsCircleTangent();
    
    docsTriangle();
    docsTrianglePerp();
    docsTriangleDiag();
    docsTriangleQuadrant();

    docsEvenShape();
    docsEvenShapeLen();
    docsEvenShapeTangent();

    ds::printMathStats();
}

void docsSquare()
{
    std::string test = "Square2D";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto sq = ds::square2D(ori, 4, 0.f);
    float circ_radius = ds::distance(ori, sq.corners().at(0));
    auto circ = ds::shape2D(ori, circ_radius, 32);

    // Plots
    plot(ori, "ob", "Center");
    plot(ds::line2D(ori, sq[0]), "--g", "Radius");
    plot(sq, "b");
    plot(circ, ":g");
    plot(sq, "or");

    saveDocsFigure(test);
}

void docsSquarePerp()
{
    std::string test = "SquareSequential";
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

    saveDocsFigure(test);
}

void docsSquareDiag()
{
    std::string test = "SquareOpposite";
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

    saveDocsFigure(test);
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
    auto circ = ds::shape2D(c, r, 32);

    // Plots
    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(sq, "b");
    plot(circ, ":y");
    plot(ds::line2D(c, ls), ":m", "C -> LS");
    plot(c + ls.unit(c) * r, "oy");
    plot(sq[1], "og", "Start");
    plot(sq[2], "or", "End");

    saveDocsFigure(test);
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
    auto circ = ds::shape2D(c, r, 32);

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

    saveDocsFigure(test);
}

void docsSquareQuadrant()
{
    std::string test = "SquareQuadrant";
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

    saveDocsFigure(test);
}

void docsCircleBlock()
{
    std::string test = "CircleBlock";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, -2);
    auto ls = ds::line2D(
        ds::point2D(7, 10),
        ds::point2D(7, -10)
    );
    auto circ = ds::shape2D(ori, 2, 32);
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

    saveDocsFigure(test);
}

void docsCircleZoom()
{
    std::string test = "CircleZoom";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(-9, -9);
    auto circ = ds::shape2D(c, 10, 16);
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

    saveDocsFigure(test);
}

void docsCircleTangent()
{
    std::string test = "CircleTangent";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(-8.f, -8.f);
    auto ls = ds::point2D(100.5f, -8.f);

    // Known variables
    auto r = 8.f;
    auto d = ls.magnitude(c);

    // Shapes
    auto circ = ds::shape2D(c, r, 32);
    auto xa = ds::line2D(c, ds::point2D(10.f, -8.f));

    float lsa = circ.getMaxRayAngle(ls);

    // Point on circle
    auto p = circ[0].rotate(lsa, c);

    // Plots
    plot(circ, "y--");
    plot(ds::line2D(
        c - ds::point2D(10.f, 0.f),
        ls + ds::point2D(10.f, 0.f)
    ), "k:", "x-axis");

    plot(ds::line2D(p, ls), "b--", "a (Unknown Distance)");
    plot(ds::line2D(c, p), "m--", "r (Radius)");
    plot(ds::line2D(c, ls), "r--", "d (Distance)");

    plot(c, "ob", "C (Center Point)");
    plot(ls, "om", "L (Light Source)");
    plot(p, "or", "P (Unknown Point)");

    saveDocsFigure(test);
}

void docsTriangle()
{
    std::string test = "Triangle2D";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    auto tri = ds::triangle2D(c, 4);
    auto circ = ds::shape2D(c, 4, 32);

    // Plots
    plot(c, "ob", "Center");
    plot(tri, "b");
    plot(tri, "or");
    plot(circ, ":g");
    plot(ds::line2D(c, tri[0]), "g--", "Radius");
    plot(tri[0], "or", "Vertices");

    saveDocsFigure(test);
}

void docsTrianglePerp()
{
    std::string test = "TriangleNearEdge";
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

    saveDocsFigure(test);
}

void docsTriangleDiag()
{
    std::string test = "TriangleFarEdge";
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

    saveDocsFigure(test);
}

void docsTriangleQuadrant()
{
    std::string test = "TriangleQuadrant";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    auto tri = ds::triangle2D(c, 4);
    auto rad = ds::shape2D(c, 4, 32);
    auto start = ds::line2D(tri[0], tri[0] + tri[0].unit(tri[-1]) * 10.f);
    auto end = ds::line2D(tri[1], tri[1] + tri[1].unit(tri[2]) * 10.f);

    // Plots
    plot(c, "ob", "Center");
    plot(tri, "b");
    plot(tri, "or");
    plot(rad, ":y");
    plot(ds::line2D(c, tri[0]), ":y", "Radius");

    plot(ds::line2D(tri.m_center, tri.m_center + tri[0].unit(tri.m_center) * 20.f), "m--", "Vertex Separation (Section)");
    plot(ds::line2D(tri.m_center, tri.m_center + tri[1].unit(tri.m_center) * 20.f), "m--");

    std::cout   << "Start: " << ds::radToDeg(start.angle()) << "\n"
                << "End: " << ds::radToDeg(end.angle())
                << std::endl;

    plot(start, ":g", "Start Check");
    plot(end, ":r", "End Check");

    saveDocsFigure(test);
}

void docsEvenShape()
{
    std::string test = "EvenShape";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    auto r = 5.f;
    auto sh = ds::shape2D(c, r, 6);
    auto bc = ds::shape2D(c, r, 32);

    // Plots
    plot(c, "ob", "Center");
    plot(sh, "b");
    plot(bc, ":y");
    plot(ds::line2D(c, bc[0]), ":y", "Radius");

    saveDocsFigure(test);
}

void docsEvenShapeLen()
{
    std::string test = "EvenShapeLength";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(-8.f, -8.f);
    auto r = 4.f;
    auto sh = ds::shape2D(c, r, 16);
    auto xa = ds::line2D(c, ds::point2D(10.f, -8.f));

    // Plots
    plot(c, "ob", "Center");
    plot(sh, "b");
    plot(xa, "k--", "x-axis");
    plot(sh[0], ".r", "Vertices");
    plot(ds::line2D(
        sh[1], 
        sh[1] + sh[1].unit(sh[2]) * 10.f
    ), ":g", "1st Limit");
    plot(ds::line2D(
        sh[2],
        sh[2] + sh[2].unit(sh[3]) * 20.f
    ), ":m", "2nd Limit");
    plot(ds::line2D(
        sh[3],
        sh[3] + sh[3].unit(sh[4]) * 30.f
    ), ":y", "3rd Limit");

    plot(sh, ".r");

    saveDocsFigure(test);
}

void docsEvenShapeTangent()
{
    std::string test = "EvenShapeTangent";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(-8.f, -8.f);
    auto r = 8.f;
    auto ls = ds::point2D(5.f, -8.f);
    auto sh = ds::shape2D(c, r, 16);
    auto xa = ds::line2D(c, ds::point2D(10.f, -8.f));
    auto p1 = ds::point2D(sh[2].x, c.y);
    auto p2 = ds::point2D(sh[2] + sh[2].unit(sh[3]) * 20.f);

    auto lsa = sh.getMaxRayAngle(ls);
    auto max = sh[0].rotate(lsa, c);

    // Plots
    plot(c, "ob", "Center");
    plot(sh, "b");
    plot(ls, "om", "Light Source");
    plot(max, ".y", "Max");
    plot(xa, "k--", "x-axis");

    saveDocsFigure(test);
}