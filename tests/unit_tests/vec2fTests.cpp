#include "gtest/gtest.h"
#include "vec2f.hpp"

using namespace ds;

// Tests the overloaded operator==
TEST(vec2fTests, EqualOperatorBaseCase)
{
    vec2f v1 = vec2f(1, 2);
    vec2f v2 = vec2f(1, 2);
    vec2f v3 = vec2f(2, 1);

    ASSERT_TRUE(v1 == v1);
    ASSERT_TRUE(v1 == v2);
    ASSERT_FALSE(v1 == v3);

    ASSERT_EQ(v1, v1);
    ASSERT_EQ(v1, v2);
}

// Tests the overloaded operator+
TEST(vec2fTests, AdditionBaseCase)
{
    vec2f v1 = vec2f(1, 2);
    vec2f v2 = vec2f(-2, 5);

    ASSERT_EQ(v1 + v2, vec2f(-1, 7));
}

// Tests the overloaded operator-
TEST(vec2fTests, SubtractionBaseCase)
{
    vec2f v1 = vec2f(8, 2);
    vec2f v2 = vec2f(4, -1);
    vec2f v3 = vec2f(7, 4);

    ASSERT_EQ(v1 - v2, vec2f(4, 3));
}

// Tests the overloaded operator* (Scalar multiplilcation)
TEST(vec2fTests, ScalarMultiplicationBaseCase)
{
    vec2f v1 = vec2f(4, 3);
    vec2f v2 = vec2f(-2, 5);

    ASSERT_EQ(v1 * 2, vec2f(8, 6));
    ASSERT_EQ(v2 * 4, vec2f(-8, 20));
    ASSERT_EQ(v2 *-4, vec2f(8, -20));

    ASSERT_EQ(2 * v1, vec2f(8, 6));
    ASSERT_EQ(4 * v2, vec2f(-8, 20));
    ASSERT_EQ(-4 * v2, vec2f(8, -20));
}

// Tests the overloaded operator/ (Scalar division)
TEST(vec2fTests, ScalarDivisionBaseCase)
{
    vec2f v1 = vec2f(4, 3);
    vec2f v2 = vec2f(8, -4);

    ASSERT_EQ(v1 / 2, vec2f(2, 1.5));
    ASSERT_EQ(v2 / 4, vec2f(2, -1));
    ASSERT_EQ(v2 / -4, vec2f(-2, 1));
    ASSERT_THROW(v2 / 0, std::runtime_error);
}

// Tests the dot function
TEST(vec2fTests, DotProductBaseCase)
{
    vec2f v1 = vec2f(4, 3);
    vec2f v2 = vec2f(2, 5);

    ASSERT_EQ(dot(v1, v2), 23);
}

TEST(vec2fTests, MagnitudeBaseCase)
{
    vec2f v1 = vec2f(4, 3);
    vec2f v2 = vec2f(-2, 1);    
    /*
    Magnitude of vector in 2D space in Pythogoras theorem.
    Hence sqrt(x^2, y^2) = sqrt(x*x + y*y)
    */
   ASSERT_FLOAT_EQ(
       magnitude(v1),
       sqrtf(v1.x*v1.x + v1.y*v1.y)
    );

    ASSERT_FLOAT_EQ(
        magnitude(v2),
        sqrtf(v2.x*v2.x + v2.y*v2.y)
    );
}

TEST(vec2fTests, NormalBaseCase)
{
    vec2f v1 = vec2f(1, 1);
    vec2f v2 = vec2f(-8, 3);

    ASSERT_EQ(normal(v1), vec2f(-1, 1));
    ASSERT_EQ(normal(v2), vec2f(-3, -8));
}

TEST(vec2fTests, UnitVectorBaseCase)
{
    vec2f v1 = vec2f(1, 1);
    vec2f v1_unit = unitVector(v1);
    ASSERT_NEAR(v1_unit.x, 0.7071, 1e-3);
    ASSERT_NEAR(v1_unit.y, 0.7071, 1e-3);
}

TEST(vec2fTests, UnitVectorAdvancedCase)
{
    vec2f v2 = vec2f(-8, 3);
    vec2f v2_unit = unitVector(v2);
    ASSERT_NEAR(v2_unit.x, -0.9363, 1e-3);
    ASSERT_NEAR(v2_unit.y, 0.3511, 1e-3);
}

TEST(vec2fTests, FlipVec2fBaseCase)
{
    vec2f v1 = vec2f(1, 1);
    ASSERT_EQ(flipY(v1), vec2f(1, -1));
    ASSERT_EQ(flipX(v1), vec2f(-1, 1));
    ASSERT_EQ(flip(v1), vec2f(-1, -1));
}

TEST(vec2fTests, FlipVec2fAdvancedCase)
{
    vec2f v2 = vec2f(0, -8);
    ASSERT_EQ(flipY(v2), vec2f(0, 8));
    ASSERT_EQ(flipX(v2), vec2f(0, -8));
    ASSERT_EQ(flip(v2), vec2f(0, 8));
}

TEST(vec2fTests, DistanceBaseCase)
{
    point2D ori = point2D(0, 0);
    point2D p1 = point2D(1, 1);
    point2D p2 = point2D (-3, 5);

    // Subtest 1 [0 0] -> [1 1] ~= 1.41
    float ori_p1 = sqrtf(pow(1, 2) + pow(1, 2));
    ASSERT_FLOAT_EQ(distance(ori, p1), ori_p1);
    ASSERT_FLOAT_EQ(distance(p1, ori), ori_p1);

    // Subtest 2 [0 0] -> [-3 5] ~= 5.83
    float ori_p2 = sqrtf(
        pow(abs(p2.x - ori.x), 2) +
        pow(abs(p2.y - ori.y), 2)
    );
    ASSERT_FLOAT_EQ(distance(ori, p2), ori_p2);
    ASSERT_FLOAT_EQ(distance(p2, ori), ori_p2);
}

TEST(vec2fTests, DistanceAdvCase)
{
    point2D p1 = point2D(4, 9);
    point2D p2 = point2D (-3, 5);

    // Subtest 3 [4 9] -> [-3 5] ~= 8.06
    float p1_p2 = sqrtf(
        pow(abs(p2.x - p1.x), 2) +
        pow(abs(p2.y - p1.y), 2)
    );
    ASSERT_FLOAT_EQ(distance(p1, p2), p1_p2);
    ASSERT_FLOAT_EQ(distance(p2, p1), p1_p2);
}

TEST(vec2fTests, FlipPoint2DBaseCase)
{
    auto ori = point2D(0, 0);
    auto p1 = point2D(1, 1);
    auto p2 = point2D(2, 2);
    auto p3 = point2D(-3, 7);

    ASSERT_EQ(flipX(p1, p2), point2D(0, 2));
    ASSERT_EQ(flipY(p1, p2), point2D(2, 0));
    ASSERT_EQ(flip(p1, p2), point2D(0, 0));

    ASSERT_EQ(flipX(p2, p3), point2D(7, 7));
    ASSERT_EQ(flipY(p2, p3), point2D(-3, -3));
    ASSERT_EQ(flip(p2, p3), point2D(7, -3));
}

// Signals that all test declarations have been implemented.
TEST(vec2fTests, CompleteSuiteTest)
{
    ASSERT_TRUE(true);
}