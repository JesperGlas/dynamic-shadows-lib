#include "gtest/gtest.h"
#include "vec2f.hpp"

TEST(vec2fTests, vec2ValueTest) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}