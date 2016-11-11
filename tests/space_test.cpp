#include "space.hpp"

#include "gtest/gtest.h"

TEST(space_test, test_constructor)
{
  Space space;
  EXPECT_EQ(space.GetPosition(), Box2D(Point2D(0.0f, 0.0f), Point2D(100.0f, 100.0f)));
}
