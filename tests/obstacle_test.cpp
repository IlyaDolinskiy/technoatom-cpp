#include "obstacle.hpp"

#include "gtest/gtest.h"

TEST(obstacle_test, test_construction)
{
  Obstacle obstacle1;

  EXPECT_EQ(obstacle1.GetPosition(), Box2D(Point2D(0.0f, 0.0f), Point2D(1.0f, 1.0f)));
  EXPECT_EQ(obstacle1.GetHealth(), 50.0f);
}

TEST(obstacle_test, test_set)
{
  Obstacle obstacle;

  obstacle.SetHealth(30.0);
  EXPECT_EQ(obstacle.GetHealth(), 30.0);

  obstacle.SetPosition(Box2D(Point2D(50.0, 30.0), Point2D(100.0, 150.0)));
  EXPECT_EQ(obstacle.GetPosition(), Box2D(Point2D(50.0, 30.0), Point2D(100.0, 150.0)));
}
