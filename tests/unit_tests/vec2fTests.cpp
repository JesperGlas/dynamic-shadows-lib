#include "gtest/gtest.h"
#include "vec2f.hpp"

using namespace ds;

// Tests the overloaded operator==
TEST(vec2fTests, EqualOperatorBaseCase)
{
    auto v1 = vec2f(1, 2);
    auto v2 = vec2f(1, 2);
    auto v3 = vec2f(2, 1);

    ASSERT_TRUE(v1 == v1);
    ASSERT_TRUE(v1 == v2);
    ASSERT_FALSE(v1 == v3);

    ASSERT_EQ(v1, v1);
    ASSERT_EQ(v1, v2);
}

// Tests the overloaded operator+
TEST(vec2fTests, AdditionBaseCase)
{
    auto v1 = vec2f(1, 2);
    auto v2 = vec2f(-2, 5);

    ASSERT_EQ(v1 + v2, vec2f(-1, 7));
}

TEST(vec2fTests, AdditionChainCase)
{
    auto v1 = vec2f(1, 2);
    auto v2 = vec2f(-2, 5);
    auto v3 = vec2f(4, 8);

    ASSERT_EQ(v1 + v2 + v3, vec2f(3, 15));
}

// Tests the overloaded operator-
TEST(vec2fTests, SubtractionBaseCase)
{
    auto v1 = vec2f(8, 2);
    auto v2 = vec2f(4, -1);

    ASSERT_EQ(v1 - v2, vec2f(4, 3));
}

TEST(vec2fTests, SubtractionChainCase)
{
    auto v1 = vec2f(8, 2);
    auto v2 = vec2f(4, -1);
    auto v3 = vec2f(7, 4);

    ASSERT_EQ(v1 - v2 - v3, vec2f(-3, -1));
}

// Tests the overloaded operator* (Scalar multiplilcation)
TEST(vec2fTests, ScalarMultiplicationBaseCase)
{
    auto v1 = vec2f(4, 3);
    auto v2 = vec2f(-2, 5);

    ASSERT_EQ(v1 * 2, vec2f(8, 6));
    ASSERT_EQ(v2 * 4, vec2f(-8, 20));
    ASSERT_EQ(v2 * -4, vec2f(8, -20));

    ASSERT_EQ(2 * v1, vec2f(8, 6));
    ASSERT_EQ(4 * v2, vec2f(-8, 20));
    ASSERT_EQ(-4 * v2, vec2f(8, -20));
}

// Tests the overloaded operator/ (Scalar division)
TEST(vec2fTests, ScalarDivisionBaseCase)
{
    auto v1 = vec2f(4, 3);
    auto v2 = vec2f(8, -4);

    ASSERT_EQ(v1 / 2, vec2f(2, 1.5));
    ASSERT_EQ(v2 / 4, vec2f(2, -1));
    ASSERT_EQ(v2 / -4, vec2f(-2, 1));
    ASSERT_THROW(v2 / 0, std::runtime_error);
}

// Tests the dot function
TEST(vec2fTests, DotProductBaseCase)
{
    auto v1 = vec2f(4, 3);
    auto v2 = vec2f(2, 5);

    ASSERT_EQ(dot(v1, v2), 23);
}

TEST(vec2fTests, MagnitudeBaseCase)
{
    auto v1 = vec2f(4, 3);
    auto v2 = vec2f(-2, 1);    
    /*
    Magnitude of vector in 2D space in Pythogoras theorem.
    Hence sqrt(x^2, y^2) = sqrt(x*x + y*y)
    */
   ASSERT_FLOAT_EQ(
       v1.magnitude(),
       sqrtf(v1.x*v1.x + v1.y*v1.y)
    );

    ASSERT_FLOAT_EQ(
        v2.magnitude(),
        sqrtf(v2.x*v2.x + v2.y*v2.y)
    );
}

TEST(vec2fTests, UnitVectorBaseCase)
{
    auto v1 = vec2f(1, 1);
    auto v1_unit = v1.unit();

    ASSERT_NEAR(v1_unit.x, 0.7071, 1e-3);
    ASSERT_NEAR(v1_unit.y, 0.7071, 1e-3);
}

TEST(vec2fTests, UnitVectorAdvancedCase)
{
    auto v2 = vec2f(-8, 3);
    auto v2_unit = v2.unit();

    ASSERT_NEAR(v2_unit.x, -0.9363, 1e-3);
    ASSERT_NEAR(v2_unit.y, 0.3511, 1e-3);
}

TEST(vec2fTests, NormalBaseCase)
{
    auto v1 = vec2f(1, 1);
    auto v2 = vec2f(-8, 3);

    ASSERT_EQ(v1.rightNormal(), vec2f(1, -1));
    ASSERT_EQ(v2.rightNormal(), vec2f(3, 8));
    ASSERT_EQ(v1.leftNormal(), vec2f(-1, 1));
    ASSERT_EQ(v2.leftNormal(), vec2f(-3, -8));
}

TEST(vec2fTests, NormalExtendedCase)
{
    auto v1 = vec2f(1, 1);
    auto v2 = vec2f(-8, 3);

    ASSERT_EQ(v2.rightNormal(v1), vec2f(3, 10));
    ASSERT_EQ(v2.leftNormal(v1), vec2f(-1, -8));
}

TEST(vec2fTests, NormalUnitCase)
{
    auto v1 = vec2f(1, 1);
    auto v2 = vec2f(-8, 3);
    auto l = v2.magnitude(v1);

    auto n1r = v1 + v2.rightUnitNormal(v1) * l;
    auto n1l = v1 + v2.leftUnitNormal(v1) * l;
    auto n2r = v2 + v2.rightUnitNormal(v1) * l;
    auto n2l = v2 + v2.leftUnitNormal(v1) * l;

    ASSERT_EQ(n1r, vec2f(3, 10));
    ASSERT_EQ(n1l, vec2f(-1, -8));
    ASSERT_EQ(n2r, vec2f(-6, 12));
    ASSERT_EQ(n2l, vec2f(-10, -6));
}

TEST(vec2fTests, FlipVec2fBaseCase)
{
    auto v1 = vec2f(1, 1);

    ASSERT_EQ(v1.flipY(), vec2f(1, -1));
    ASSERT_EQ(v1.flipX(), vec2f(-1, 1));
    ASSERT_EQ(v1.flip(), vec2f(-1, -1));
}

TEST(vec2fTests, FlipVec2fAdvancedCase)
{
    auto v2 = vec2f(0, -8);

    ASSERT_EQ(v2.flipY(), vec2f(0, 8));
    ASSERT_EQ(v2.flipX(), vec2f(0, -8));

    // Check that original is unchanged
    ASSERT_EQ(v2, vec2f(0, -8));

    ASSERT_EQ(v2.flip(), vec2f(0, 8));
}

TEST(vec2fTests, RotateVec2fBaseCase)
{
    auto v1 = vec2f(1, 1);
    auto v1_r90 = v1.rotate(degToRad(90));

    ASSERT_NEAR(v1_r90.x, -1, 1e-3f); // test x
    ASSERT_NEAR(v1_r90.y, 1, 1e-3f); // test y
}

TEST(vec2fTests, RotateExtendedVec2fBaseCase)
{
    auto v1 = vec2f(1, 1);
    auto v2 = vec2f(2, 2);
    auto v2_r90 = v2.rotate(degToRad(90), v1);

    ASSERT_NEAR(v2_r90.x, 0, 1e-3f); // test x
    ASSERT_NEAR(v2_r90.y, 2, 1e-3f); // test y
}

TEST(vec2fTests, DistanceBaseCase)
{
    auto ori = point2D(0, 0);
    auto p1 = point2D(1, 1);
    auto p2 = point2D (-3, 5);

    // Subtest 1 [0 0] -> [1 1] ~= 1.41
    float ori_to_p1 = sqrtf(powf(1, 2) + powf(1, 2));
    
    ASSERT_FLOAT_EQ(distance(ori, p1), ori_to_p1);
    ASSERT_FLOAT_EQ(distance(p1, ori), ori_to_p1);

    // Subtest 2 [0 0] -> [-3 5] ~= 5.83
    float ori_to_p2 = sqrtf(

        powf(abs(p2.x - ori.x), 2) +
        powf(abs(p2.y - ori.y), 2)
    );
    ASSERT_FLOAT_EQ(distance(ori, p2), ori_to_p2);
    ASSERT_FLOAT_EQ(distance(p2, ori), ori_to_p2);
}

TEST(vec2fTests, DistanceAdvCase)
{
    auto p1 = point2D(4, 9);
    auto p2 = point2D (-3, 5);

    // Subtest 3 [4 9] -> [-3 5] ~= 8.06
    float p1_to_p2 = sqrtf(
        powf(abs(p2.x - p1.x), 2) +
        powf(abs(p2.y - p1.y), 2)
    );
    ASSERT_FLOAT_EQ(distance(p1, p2), p1_to_p2);
    ASSERT_FLOAT_EQ(distance(p2, p1), p1_to_p2);
}

TEST(vec2fTests, FlipPoint2DBaseCase)
{
    auto ori = point2D(0, 0);
    auto p1 = point2D(1, 1);
    auto p2 = point2D(2, 2);
    auto p3 = point2D(-3, 7);

    ASSERT_EQ(p2.flipX(p1), point2D(0, 2));
    ASSERT_EQ(p2.flipY(p1), point2D(2, 0));
    ASSERT_EQ(p2.flip(p1), point2D(0, 0));

    ASSERT_EQ(p3.flipX(p2), point2D(7, 7));
    ASSERT_EQ(p3.flipY(p2), point2D(-3, -3));
    ASSERT_EQ(p3.flip(p2), point2D(7, -3));
}

TEST(vec2fTests, AngleTest)
{
    auto p0 = vec2f(1, 0);
    auto p45 = vec2f(1, 1);
    auto p135 = vec2f(-1, 1);
    auto p225 = vec2f(-1, -1);
    auto p315 = vec2f(1, -1);

    ASSERT_FLOAT_EQ(p0.angle(),     degToRad(0.f));
    ASSERT_FLOAT_EQ(p45.angle(),    degToRad(45.f));
    ASSERT_FLOAT_EQ(p135.angle(),   degToRad(135.f));
    ASSERT_FLOAT_EQ(p225.angle(),   degToRad(225.f));
    ASSERT_FLOAT_EQ(p315.angle(),   degToRad(315.f));
}

TEST(vec2fTests, AngleExtendedTest)
{
    auto origin = vec2f(1, 1);
    auto p0 = vec2f(2, 1);
    auto p45 = vec2f(2, 2);
    auto p135 = vec2f(0, 2);
    auto p225 = vec2f(0, 0);
    auto p315 = vec2f(2, 0);

    ASSERT_FLOAT_EQ(p0.angle(origin),      degToRad(0.f));
    ASSERT_FLOAT_EQ(p45.angle(origin),     degToRad(45.f));
    ASSERT_FLOAT_EQ(p135.angle(origin),    degToRad(135.f));
    ASSERT_FLOAT_EQ(p225.angle(origin),    degToRad(225.f));
    ASSERT_FLOAT_EQ(p315.angle(origin),    degToRad(315.f));
}

TEST(vec2fTests, OriginTests)
{
    vec2f p1 = vec2f (0, 1);

    vec2f p1_rot270 = p1.rotate(degToRad(270));
    vec2f p1_norm = p1.rightNormal();

    ASSERT_NEAR(p1_rot270.x, p1_norm.x, 1e-3);
    ASSERT_NEAR(p1_rot270.y, p1_norm.y, 1e-3);

    ASSERT_NEAR(p1_rot270.angle(), p1_norm.angle(), 1e-3);
}

TEST(vec2fTests, PointTests)
{
    vec2f p0 = vec2f(-1, 1);
    vec2f p1 = vec2f (0, 1);

    vec2f p1_rot270 = p1.rotate(degToRad(270), p0);
    vec2f p1_norm = p0 + (p1 - p0).rightNormal();

    ASSERT_NEAR(p1_rot270.x, p1_norm.x, 1e-3);
    ASSERT_NEAR(p1_rot270.y, p1_norm.y, 1e-3);

    ASSERT_NEAR(p1_rot270.angle(), p1_norm.angle(), 1e-3);
}

// Signals that all test declarations have been implemented.
TEST(vec2fTests, CompleteSuiteTest)
{
    ASSERT_TRUE(true);
}