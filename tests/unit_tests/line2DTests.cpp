#include "gtest/gtest.h"
#include "line2D.hpp"

using namespace ds;

// Tests the overloaded operator==

/**
 * @brief Tests the accessor vector of the line2D class.
 * 
 */
TEST(line2DTests, AccVectorTest)
{
    // Base case
    auto l1 = line2D(
        point2D(0, 0),
        point2D(1, 1)
    ); 
    ASSERT_EQ(l1.vector(), vec2f(1, 1));
}


TEST(line2DTests, AccLengthTest)
{
    // Base case
    point2D s1 = point2D(0, 0);
    point2D e1 = point2D(0, 4);
    line2D l1 = line2D(s1, e1);
    ASSERT_EQ(l1.length(), 4);

    point2D s2 = point2D(0, 0);
    point2D e2 = point2D(-4, 0);
    line2D l2 = line2D(s1, e1);
    ASSERT_EQ(l2.length(), 4);
}

TEST(line2DTests, AccDirectionTest)
{
    // Base case
    ASSERT_TRUE(false);
}

TEST(line2DTests, NormalTest)
{
    ASSERT_TRUE(false);
}

TEST(line2DTests, FlipTest)
{
    // Subtest 2 [2 -4] -> [-3 0] TF()=> [2 -4] -> [5 4]
    auto s1 = point2D(2, -4);
    auto e1 = point2D(-3, 0);
    auto li1 = line2D(s1, e1);

    ASSERT_EQ(li1, line2D(
        point2D(2, -4),
        point2D(-3, 0)
    ));

    line2D new_li1 = flip(li1); 

    // Original unchanged
    ASSERT_EQ(li1, line2D(
        point2D(2, -4),
        point2D(-3, 0)
    ));

    // New line
    ASSERT_EQ(new_li1, line2D(
        point2D(2, -4),
        point2D(7, -8)
    ));
}

TEST(line2DTests, TransformFlipTest)
{
    /*
     * Subtest 1:
     * [0 0] -> [1 1] TF()=> [0 0] -> [-1 -1] 
     * [0 0] -> [-1 -1] TFX()=> [0 0] -> [1 -1]
     * [0 0] -> [1 -1] TFX()=> [0 0] -> [1 1]
    */
    auto s1 = point2D(0, 0);
    auto e1 = point2D(1, 1);
    auto li1 = line2D(s1, e1);

    ASSERT_EQ(li1, line2D(
        point2D(0, 0),
        point2D(1, 1)
    ));

    li1.transformFlip();

    ASSERT_EQ(li1, line2D(
        point2D(0, 0),
        point2D(-1, -1)
    ));

    li1.transformFlipX();
    li1.transformFlipY();

    ASSERT_EQ(li1, line2D(s1, e1));
    ASSERT_EQ(li1, line2D(
        point2D(0, 0),
        point2D(1, 1)
    ));

    // Subtest 2 [2 -4] -> [-3 0] TF()=> [2 -4] -> [5 4]
    auto s2 = point2D(2, -4);
    auto e2 = point2D(-3, 0);
    auto li2 = line2D(s2, e2);

    ASSERT_EQ(li2, line2D(
        point2D(2, -4),
        point2D(-3, 0)
    ));

    li2.transformFlip();

    ASSERT_EQ(li2, line2D(
        point2D(2, -4),
        point2D(7, -8)
    ));
}

// Signals that all test declarations have been implemented.
TEST(line2DTests, CompleteSuiteTest)
{
    ASSERT_TRUE(false);
}