#include "gtest/gtest.h"
#include "vec2f.hpp"

using namespace ds;

// Tests the overloaded operator==
TEST(vec2fTests, EqualOperatorTest)
{
    vec2f v1 = vec2f(1, 2);
    vec2f v2 = vec2f(1, 2);
    vec2f v3 = vec2f(2, 1);

    ASSERT_TRUE(v1 == v1);
    ASSERT_TRUE(v1 == v2);
    ASSERT_FALSE(v1 == v3);

    ASSERT_EQ(v1, v2);
}

// Tests the overloaded operator+
TEST(vec2fTests, AdditionTest)
{
    vec2f v1 = vec2f(1, 2);
    vec2f v2 = vec2f(-2, 5);

    ASSERT_EQ(v1 + v2, vec2f(-1, 7));
}

// Tests the overloaded operator-
TEST(vec2fTests, SubtractionTest)
{
    vec2f v1 = vec2f(8, 2);
    vec2f v2 = vec2f(4, -1);
    vec2f v3 = vec2f(7, 4);

    ASSERT_EQ(v1 - v2, vec2f(4, 3));
}

// Tests the overloaded operator* (Scalar multiplilcation)
TEST(vec2fTests, ScalarMultiplicationTest)
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
TEST(vec2fTests, ScalarDivisionTest)
{
    vec2f v1 = vec2f(4, 3);
    vec2f v2 = vec2f(8, -4);

    ASSERT_EQ(v1 / 2, vec2f(2, 1.5));
    ASSERT_EQ(v2 / 4, vec2f(2, -1));
    ASSERT_EQ(v2 / -4, vec2f(-2, 1));
}

// Tests the dot function
TEST(vec2fTests, DotProductTest)
{
    vec2f v1 = vec2f(4, 3);
    vec2f v2 = vec2f(2, 5);

    ASSERT_EQ(dot(v1, v2), 23);
}

TEST(vec2fTests, DistanceTest)
{
    point2D ori = point2D(0, 0);
    point2D p1 = point2D(1, 1);
    point2D p2 = point2D(4, 9);
    point2D p3 = point2D (-3, 5);

    // Subtest 1 [0 0] -> [1 1] ~= 1.41
    float ori_p1 = sqrtf(pow(1, 2) + pow(1, 2));
    ASSERT_FLOAT_EQ(dist(ori, p1), ori_p1);
    ASSERT_FLOAT_EQ(dist(p1, ori), ori_p1);

    // Subtest 2 [0 0] -> [-3 5] ~= 5.83
    float ori_p3 = sqrtf(
        pow(abs(p3.x - ori.x), 2) +
        pow(abs(p3.y - ori.y), 2)
    );
    ASSERT_FLOAT_EQ(dist(ori, p3), ori_p3);
    ASSERT_FLOAT_EQ(dist(p3, ori), ori_p3);

    // Subtest 3 [4 9] -> [-3 5] ~= 8.06
    float p2_p3 = sqrtf(
        pow(abs(p3.x - p2.x), 2) +
        pow(abs(p3.y - p2.y), 2)
    );
    ASSERT_FLOAT_EQ(dist(p2, p3), p2_p3);
    ASSERT_FLOAT_EQ(dist(p3, p2), p2_p3);
}