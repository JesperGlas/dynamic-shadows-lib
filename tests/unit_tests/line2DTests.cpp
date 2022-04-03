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

TEST(line2DTests, TransformFlipTest)
{
    /*
     * Subtest 1:
     * [0 0] -> [1 1] TF()=> [0 0] -> [-1 -1] 
     * [0 0] -> [-1 -1] TFX()=> [0 0] -> [1 -1]
     * [0 0] -> [1 -1] TFX()=> [0 0] -> [1 1]
    */
    auto s1 = ds::point2D(0, 0);
    auto e1 = ds::point2D(1, 1);
    auto li1 = ds::line2D(s1, e1);

    ASSERT_EQ(li1, ds::line2D(
        ds::point2D(0, 0),
        ds::point2D(1, 1)
    ));

    li1.transformFlip();

    ASSERT_EQ(li1, ds::line2D(
        ds::point2D(0, 0),
        ds::point2D(-1, -1)
    ));

    li1.transformFlipX();
    li1.transformFlipY();

    ASSERT_EQ(li1, ds::line2D(s1, e1));
    ASSERT_EQ(li1, ds::line2D(
        point2D(0, 0),
        point2D(1, 1)
    ));

    // Subtest 2 [2 -4] -> [-3 0] TF()=> [2 -4] -> [5 4]
    auto s2 = ds::point2D(2, -4);
    auto e2 = ds::point2D(-3, 0);
    auto li2 = ds::line2D(s2, e2);

    ASSERT_EQ(li2, ds::line2D(
        ds::point2D(2, -4),
        ds::point2D(-3, 0)
    ));

    li2.transformFlip();

    ASSERT_EQ(li2, ds::line2D(
        ds::point2D(2, -4),
        ds::point2D(7, -8)
    ));
}

// Signals that all test declarations have been implemented.
TEST(line2DTests, CompleteSuiteTest)
{
    ASSERT_TRUE(false);
}