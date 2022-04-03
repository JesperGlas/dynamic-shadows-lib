#include "gtest/gtest.h"
#include "line2D.hpp"

using namespace ds;

// Tests the overloaded operator==
TEST(line2DTests, LengthTest)
{
    point2D s1 = point2D(0, 0);
    point2D e1 = point2D(0, 4);
    line2D line1 = line2D(s1, e1);
    ASSERT_EQ(length(line1), 4);

    point2D s2 = point2D(0, 0);
    point2D e2 = point2D(-4, 0);
    line2D line2 = line2D(s1, e1);
    ASSERT_EQ(length(line2), 4);
}

TEST(line2DTests, NormalTest)
{
    ASSERT_TRUE(false);
}

TEST(line2DTests, FlipTest)
{
    ASSERT_TRUE(false);
}

// Signals that all test declarations have been implemented.
TEST(line2DTests, CompleteSuiteTest)
{
    ASSERT_TRUE(false);
}