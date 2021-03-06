#include "visualDocs.hpp"

void generateDocs()
{
    std::cout << "Generating visual docs..." << std::endl;

    /**###############################################
     * ONLY 20 VISUAL TESTS CAN BE ACTIVE AT ANY TIME!
     * There is some bug (or missunderstanding) in how
     * to close figures in matplotlibcpp.
     #################################################*/

    docsSquare();
    docsSquarePerp();
    docsSquareDiag();
    //docsSquareQuadrant();
    //docsSquareStart();
    //docsSquareBlock();

    //docsCircleDirectional();
    //docsCirclePoint();
    //docsCircleZoom();
    //docsCircleTangent();
    
    docsTriangle();
    docsTrianglePerp();
    docsTriangleDiag();
    docsTriangleQuadrant();

    docsEvenShape();
    docsEvenShapeAreas();
    docsEvenShapeTangent();
    docsEvenShapeCheck();
    docsShapeNaive();
    docsBlockingBenchmark();

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
    float circ_radius = ori.magnitude(sq[0]);
    auto circ = ds::shape2D(ori, circ_radius, 32);

    // Plots
    plot(ori, "ob", "Center");
    plot(ds::line2D(ori, sq[0]), "y--", "Radius");
    plot(sq, "b");
    plot(circ, "y:");
    plot(circ[0], "y:", "Bounding Circle");
    plot(sq, "or");
    plot(sq[0], "or", "Vertices");

    saveDocsFigure(test);
}

void docsSquarePerp()
{
    std::string test = "SquareSequential";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto ls = ds::point2D(1, 3.5f);
    auto sq = ds::square2D(ori, 3);

    // Plots
    plot(ori, "ob", "Origin");
    plot(ls, "om", "Light Source");
    plot(sq, "b");
    plot(
        ds::line2D(sq.corners().at(0), sq.corners().at(1)),
        "m--", "Blocking Edge"
    );

    plot(ds::line2D(ori, ori + ls.unit(ori) * 20.f), "r:", "Light Source Direction");
    plot(ds::line2D(sq[0], sq[0] + ds::vec2f(0, 1).unit() * 10.f), "g--", "Enclosing Area");
    plot(ds::line2D(sq[1], sq[1] + ds::vec2f(0, 1).unit() * 10.f), "g--");

    plot(ds::line2D(ls, sq[0]), "y:", "Edge Rays");
    plot(ds::line2D(ls, sq[1]), "y:");

    plot(ori, "ob");
    plot(ls, "om");

    saveDocsFigure(test);
}

void docsSquareDiag()
{
    std::string test = "SquareOpposite";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, 0);
    auto ls = ds::point2D(3, 5);
    auto sq = ds::square2D(ori, 3);

    // Plots
    plot(ori, "ob", "Origin");
    plot(ls, "om", "Light Source");
    plot(sq, "b");
    plot(
        ds::line2D(sq[1], sq[3]),
        "m--", "Blocking Edge"
    );

    plot(ds::line2D(ori, ori + ls.unit(ori) * 20.f), "r:", "Light Source Direction");
    plot(ds::line2D(sq[1], sq[1] + sq[1].unit(sq[2]) * 10.f), "g--", "Enclosing Area");
    plot(ds::line2D(sq[3], sq[3] + sq[3].unit(sq[2]) * 10.f), "g--");

    plot(ds::line2D(ls, sq[1]), "y:", "Edge Rays");
    plot(ds::line2D(ls, sq[3]), "y:");

    plot(ori, "ob");
    plot(ls, "om");

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
    plot(sq[0], "og", "Starting Vertex");
    plot(sq[1], "or", "Ending Vertex");
    plot(ds::line2D(c, sq[0]), ":y", "Radius");
    plot(ds::line2D(c, c + ds::point2D(1, 0) * 20.f), "m--", "Vertex separation (Quadrant)");
    plot(ds::line2D(c, c + ds::point2D(0, 1) * 20.f), "m--");
    plot(ds::line2D(sq[0], sq[0] + ds::point2D(1, 1) * 20.f), ":g");
    plot(ds::line2D(sq[1], sq[1] + ds::point2D(1, 1) * 20.f), ":r");
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

void docsCircleDirectional()
{
    std::string test = "CircleDirectional";
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
    auto bs = ds::point2D(0, 0);
    auto be = bs.flip(ori);

    for(int i = -10; i <= 10; i++)
    {
        auto start = ds::point2D(7, i);
        auto end = ds::point2D(6, i);
        plot(ds::line2D(start, end), "y:");
    }

    // Plots
    plot(ori, "ob", "Origin");
    plot(circ, "b");
    plot(bs, "og", "Silhouette Edge Start");
    plot(be, "or", "Silhouette Edge End");
    plot(ls, "m", "Directional Light Source");
    plot(ls_ori, "y:", "Light Direction");
    plot(ds::line2D(bs, be), "m:", "Silhouette Edge");
    plot(
        ds::line2D(ds::point2D(7, 0), ds::point2D(0, 0)),
        ":y"
    );
    plot(
        ds::line2D(ds::point2D(7, -4), ds::point2D(0, -4)),
        ":y"
    );
    plot(
        ds::line2D(ds::point2D(0, 0), ds::point2D(-10, 0)),
        ":k", "Shadow Bounds"
    );
    plot(
        ds::line2D(ds::point2D(0, -4), ds::point2D(-10, -4)),
        ":k"
    );

    saveDocsFigure(test);
}

void docsCirclePoint()
{
    std::string test = "CirclePoint";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto ori = ds::point2D(0, -2);
    auto ls = ds::point2D(7, -2);
    auto circ = ds::shape2D(ori, 2, 32);
    auto ls_ori = ds::line2D(ori, ds::point2D(7, -2));
    auto lsa = circ.getMaxRayAngle(ls);
    auto bs = circ[0];
    bs = bs.rotate(lsa, ori);
    auto be = bs.rotate((-2.f) * lsa, ori);

    // Plots
    plot(ori, "ob", "Origin");
    plot(ls, "om", "Point Light Source");
    plot(circ, "b");
    plot(bs, "og", "Silhouette Edge Start");
    plot(be, "or", "Silhouette Edge End");
    plot(ls_ori, "y:", "Light Direction");
    plot(ds::line2D(bs, be), "m:", "Silhouette Edge");

    plot(ds::line2D(bs, bs + bs.unit(ls) * 10.f), "k:");
    plot(ds::line2D(be, be + be.unit(ls) * 10.f), "k:");

    plot(ds::line2D(ls, bs), "y:");
    plot(ds::line2D(ls, be), "y:");

    plot(ori, "k:", "Shadow Bounds");

    plot(ori, "ob");
    plot(ls, "om");
    plot(bs, "og");
    plot(be, "or");

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
    plot(circ, "y:");
    plot(tri[0], "or", "Vertices");
    plot(ds::line2D(c, tri[0]), "y--", "Radius");
    plot(circ[0], "y:", "Bounding Circle");

    saveDocsFigure(test);
}

void docsTrianglePerp()
{
    std::string test = "TriangleNearEdge";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(0, 0);
    auto ls = ds::point2D(5, 1.5f);
    auto tri = ds::triangle2D(c, 4);
    auto be = ds::line2D(tri[0], tri[1]);

    // Plots
    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(tri, "b");
    plot(be, "m--", "Silhouette Edge");

    plot(ds::line2D(
        tri[0],
        tri[0] + tri[0].unit(tri[-1]) * 10.f
    ), "g--", "Enclosing Area");
    plot(ds::line2D(
        tri[1],
        tri[1] + tri[1].unit(tri[2]) * 10.f
    ), "g--");

    plot(ds::line2D(c, c + ls.unit(c) * 20.f), "m:", "Light Source Direction");

    plot(ds::line2D(ls, tri[0]), "y:", "Edge Rays");
    plot(ds::line2D(ls, tri[1]), "y:");

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
    plot(be, "m--", "Silhouette Edge");

    plot(ds::line2D(
        tri[0],
        tri[0] + tri[0].unit(tri[-1]) * 10.f
    ), "g--", "Enclosing Area");
    plot(ds::line2D(
        tri[2],
        tri[2] + tri[2].unit(tri[3]) * 10.f
    ), "g--");

    plot(ds::line2D(c, c + ls.unit(c) * 20.f), "m:", "Light Source Direction");

    plot(ds::line2D(ls, tri[2]), "y:", "Edge Rays");
    plot(ds::line2D(ls, tri[0]), "y:");

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
    plot(rad, ":y");
    plot(tri[0], "og", "Starting Vertex");
    plot(tri[1], "or", "Starting Vertex");
    plot(ds::line2D(c, tri[0]), ":y", "Radius");

    plot(ds::line2D(tri.m_center, tri.m_center + tri[0].unit(tri.m_center) * 20.f), "m--", "Vertex Separation (Section)");
    plot(ds::line2D(tri.m_center, tri.m_center + tri[1].unit(tri.m_center) * 20.f), "m--");

    plot(start, ":g");
    plot(end, ":r");

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
    plot(bc, "y:");
    plot(sh, "or", "Vertices");
    plot(ds::line2D(c, bc[0]), "y--", "Radius");
    plot(bc[0], "y:", "Bounding Circle");

    saveDocsFigure(test);
}

void docsEvenShapeAreas()
{
    std::string test = "EvenShapeAreas";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(-8.f, -6.f);
    auto r = 8.f;
    auto ls = ds::point2D(7.f, -6.f);
    auto sh = ds::shape2D(c, r, 8);
    auto circ = ds::shape2D(c, r, 32);
    auto xa = ds::line2D(c, ds::point2D(10.f, -6.f));
    auto p1 = ds::point2D(sh[2].x, c.y);
    auto p2 = ds::point2D(sh[2] + sh[2].unit(sh[3]) * 20.f);

    auto lsa = sh.getMaxRayAngle(ls);
    auto max = sh[0].rotate(lsa, c);

    // Plots
    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(sh[1], "or", "Previous (Vertex)");
    plot(sh[2], "og", "Next (Vertex)");
    plot(max, "oy", "Reference Point");
    plot(ds::line2D(
        ls,
        sh[1] + sh[2].unit(sh[1]) * sh[2].magnitude(sh[1]) * 0.5f
    ), "m:", "Ray of Light");
    plot(ds::line2D(sh[0], sh[0] + sh[0].unit(sh[1]) * 20.f), "r--");
    plot(ds::line2D(sh[1], sh[1] + sh[1].unit(sh[0]) * 20.f), "r--");
    plot(ds::line2D(sh[1], sh[1] + sh[1].unit(sh[2]) * 20.f), "g--");
    plot(ds::line2D(sh[2], sh[2] + sh[2].unit(sh[1]) * 20.f), "g--");
    plot(circ, "y:", "Bounding Circle");
    plot(xa, "k:", "x-axis");
    plot(sh, "b");
    plot(sh[1], "or");
    plot(sh[2], "og");

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
    auto ls = ds::point2D(7.f, -8.f);
    auto sh = ds::shape2D(c, r, 8);
    auto circ = ds::shape2D(c, r, 32);
    auto xa = ds::line2D(c, ds::point2D(10.f, -8.f));
    auto p1 = ds::point2D(sh[2].x, c.y);
    auto p2 = ds::point2D(sh[2] + sh[2].unit(sh[3]) * 20.f);

    auto lsa = sh.getMaxRayAngle(ls);
    auto max = sh[0].rotate(lsa, c);

    // Plots
    plot(c, "ob", "Center");
    plot(ls, "om", "Light Source");
    plot(max, "oy", "Tangent Point");
    plot(sh[1], "or", "Previous (Vertex)");
    plot(sh[2], "og", "Next (Vertex)");
    plot(ds::line2D(c, max), "y--", "Radius");
    plot(circ, "y:", "Bounding Circle");
    plot(xa, "k:", "x-axis");
    plot(sh, "b");
    plot(ds::line2D(ls, max), ":m");
    plot(ds::line2D(c, sh[1]), "r--");
    plot(ds::line2D(c, sh[2]), "g--");

    saveDocsFigure(test);
}

void docsEvenShapeCheck()
{
    std::string test = "EvenShapeCheck";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(-8.f, -8.f);
    auto r = 8.f;
    auto ls = ds::point2D(7.f, -8.f);
    auto sh = ds::shape2D(c, r, 8);
    auto circ = ds::shape2D(c, r, 32);
    auto xa = ds::line2D(c, ds::point2D(10.f, -8.f));
    auto p1 = ds::point2D(sh[2].x, c.y);
    auto p2 = ds::point2D(sh[2] + sh[2].unit(sh[3]) * 20.f);

    auto lsa = sh.getMaxRayAngle(ls);
    auto max = sh[0].rotate(lsa, c);

    // Plots
    plot(c, "ob", "C (Center)");
    plot(ls, "om", "L (Light Source)");
    plot(sh[1], "or", "P (Previous Vertex)");
    plot(sh[2], "og", "N (Next Vertex)");
    plot(sh, "b:");
    // ls tri
    plot(ds::line2D(ls, sh[2]), "m--");
    plot(ds::line2D(ls, c), "m--");
    plot(ds::line2D(c, sh[2]), "m--");

    // start tri
    plot(ds::line2D(sh[2], sh[1]), "g--");
    plot(ds::line2D(sh[2], c), "g--");
    plot(ds::line2D(c, sh[1]), "g--");

    saveDocsFigure(test);
}

void docsShapeNaive()
{
    std::string test = "ShapeNaive";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(-2.f, -2.f);
    auto r = 3.f;
    auto sh = ds::shape2D(c, r, 6);
    auto ls = ds::point2D(3.f, 5.f);
    auto be = sh.getBlockingEdge(ls);
    std::vector<ds::point2D> pts;

    // Plots
    plot(c, "ob", "Center");
    plot(sh, "b");
    plot(ls, "om", "Light Source");

    for (size_t i {0}; i < sh.size(); i++)
    {
        auto curr = sh[i];
        auto next = sh[i+1];
        auto p = curr + next.unit(curr) * next.magnitude(curr) * 0.5f;
        pts.push_back(p);
        auto norm = p + p.unit(c) * 1.f;
        plot(ds::line2D(p, p + ls.unit(p) * 1.f), "m:");
        if (i < 2)
        {
            plot(ds::line2D(p, norm), "g:");
        }
        else
            plot(ds::line2D(p, norm), "r:");
    }

    plot(be.start, "og");
    plot(be.end, "or");
    plot(ds::line2D(ls, pts[0]), "m:");
    plot(c, "m:", "Angle of Light");
    plot(c, "g:", "Facing Light Source");
    plot(c, "r:", "Facing Away");

    saveDocsFigure(test);
}

void docsBlockingBenchmark()
{
    std::string test = "BlockingBenchmark";
    std::cout << "Generating " << test << " visual..." << std::endl;
    
    setupDefaultFigure();

    // Geometry
    auto c = ds::point2D(4.f, 4.f);
    auto r = 2.f;
    auto sh = ds::shape2D(c, r, 6);
    auto ls = c + (r * 1.1f);
    auto path = ds::shape2D(c-r, ls.magnitude(c-r), 32);

    // Plots
    plot(c, "ob", "Center");
    plot(sh, "b");
    plot(ls, "om", "Light Source");
    plot(path, ":m", "Light Source Path");

    saveDocsFigure(test);
}