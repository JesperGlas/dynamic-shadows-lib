#include "gtest/gtest.h"
#include "math.hpp"

using namespace ds;

TEST(mathTests, DegToRadTest)
{
    ASSERT_FLOAT_EQ(ds::degToRad(0), 0);
    ASSERT_FLOAT_EQ(ds::degToRad(180), ds::PI);
    ASSERT_FLOAT_EQ(ds::degToRad(360), 2*ds::PI);
}

TEST(mathTests, RadToDegTest)
{
    ASSERT_FLOAT_EQ(ds::radToDeg(0), 0.f);
    ASSERT_FLOAT_EQ(ds::radToDeg(ds::PI), 180.f);
    ASSERT_FLOAT_EQ(ds::radToDeg(2*ds::PI), 360.f);
}

// Signals that all test declarations have been implemented.
TEST(mathTests, CompleteSuiteTest)
{
    ASSERT_TRUE(false);
}