#include "gtest/gtest.h"
#include "bullet.hpp"
#include <sstream>
#include <unordered_set>

TEST(bullet_test, bullet_construction)
{
  Bullet bullet1;
  EXPECT_EQ(bullet1.GetPosition(), Box2D(Point2D{ 0.0f, 0.0f }, Point2D{ 0.1f, 0.1f }));
  EXPECT_EQ(bullet1.GetOrigin(), Point2D(0.0f, 0.0f));
  EXPECT_EQ(bullet1.GetDirection(), Point2D(1.0f, 0.0f));

  Bullet bullet2 = { Point2D(5.0f, 5.0f), Point2D(1.0f, 0.0f) };
  EXPECT_EQ(bullet2.GetPosition(), Box2D(Point2D{ 4.9f, 4.8f }, Point2D{ 5.1f, 5.2f }));
  EXPECT_EQ(bullet2.GetOrigin(), Point2D(5.0f, 5.0f));
  EXPECT_EQ(bullet2.GetDirection(), Point2D(1.0f, 0.0f));
}

TEST(bullet_test, bullet_set_get)
{
  Bullet bullet1;
  bullet1.SetPosition(Box2D{ 1.0f, 1.0f, 2.0f, 2.0f });
  EXPECT_EQ(bullet1.GetPosition(), Box2D(Point2D{ 1.0f, 1.0f }, Point2D{ 2.0f, 2.0f }));
  bullet1.SetOrigin(Point2D{ 1.0f, 1.0f });
  EXPECT_EQ(bullet1.GetOrigin(), Point2D(1.0f, 1.0f));
  bullet1.SetDirection(Point2D{ 1.0f, 0.0f });
  EXPECT_EQ(bullet1.GetDirection(), Point2D(1.0f, 0.0f));
  bullet1.SetSpeed(1.0f);
  EXPECT_EQ(bullet1.GetSpeed(), 1.0f);
  bullet1.SetLength(5.0f);
  EXPECT_EQ(bullet1.GetLength(), 5.0f);
  bullet1.SetWidth(10.0f);
  EXPECT_EQ(bullet1.GetWidth(), 10.0f);
}

TEST(bullet_test, bullet_move)
{
  Bullet bullet1 = { Point2D(5.0f, 5.0f), Point2D(1.0f, 0.0f) };
  bullet1.Move();
  EXPECT_EQ(bullet1.GetPosition(), Box2D(Point2D{ 5.9f, 4.8f }, Point2D{ 6.1f, 5.2f }));
  EXPECT_EQ(bullet1.GetOrigin(), Point2D(6.0f, 5.0f));
  EXPECT_EQ(bullet1.GetDirection(), Point2D(1.0f, 0.0f));
}