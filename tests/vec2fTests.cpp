#include "gtest/gtest.h"
#include "vec2f.hpp"

using namespace ds;

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

TEST(vec2fTests, AdditionOperatorTest)
{
    vec2f v1 = vec2f(1, 2);
    vec2f v2 = vec2f(-2, 5);

    ASSERT_EQ(v1 + v2, vec2f(-1, 7));
}

TEST(vec2fTests, SubtractionOperationTest)
{
    vec2f v1 = vec2f(8, 2);
    vec2f v2 = vec2f(4, -1);
    vec2f v3 = vec2f(7, 4);

    ASSERT_EQ(v1 - v2, vec2f(4, 3));
}

TEST(vec2fTests, ScalarMultiplicationOperationTest)
{
    vec2f v1 = vec2f(4, 3);
    vec2f v2 = vec2f(-2, 5);

    ASSERT_EQ(v1 * 2, vec2f(8, 6));
    ASSERT_EQ(v2 * 4, vec2f(-8, 20));
    ASSERT_EQ(v2 *-4, vec2f(8, -20));
}