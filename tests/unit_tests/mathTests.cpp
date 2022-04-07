#include "gtest/gtest.h"
#include "math.hpp"

using namespace ds;

TEST(mathTests, DegToRadBaseCaseTest)
{
    ASSERT_FLOAT_EQ(ds::degToRad(0.f), 0.f);
    ASSERT_FLOAT_EQ(ds::degToRad(45.f), 0.25*ds::PI);
    ASSERT_FLOAT_EQ(ds::degToRad(180.f), ds::PI);
    ASSERT_FLOAT_EQ(ds::degToRad(360.f), 2*ds::PI);
}

TEST(mathTests, DegToRadNegativeCaseTest)
{
    ASSERT_FLOAT_EQ(ds::degToRad(-0.f), 0.f);
    ASSERT_FLOAT_EQ(ds::degToRad(-45.f), -0.25*ds::PI);
}

TEST(mathTests, RadToDegBaseCaseTest)
{
    ASSERT_FLOAT_EQ(ds::radToDeg(0), 0.f);
    ASSERT_FLOAT_EQ(ds::radToDeg(0.25*ds::PI), 45.f);
    ASSERT_FLOAT_EQ(ds::radToDeg(ds::PI), 180.f);
    ASSERT_FLOAT_EQ(ds::radToDeg(2*ds::PI), 360.f);
}

TEST(mathTests, RadToDegNegativeCaseTest)
{
    ASSERT_FLOAT_EQ(ds::radToDeg(-0.f), 0.f);
    ASSERT_FLOAT_EQ(ds::radToDeg(-ds::PI), -180.f);
}

// Signals that all test declarations have been implemented.
TEST(mathTests, CompleteSuiteTest)
{
    ASSERT_TRUE(true);
}