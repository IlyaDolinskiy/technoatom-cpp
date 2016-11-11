#include "logger.hpp"
#include "alien.hpp"
#include "bullet.hpp"
#include "gameentity.hpp"
#include "gun.hpp"
#include "obstacle.hpp"
#include "space.hpp"
#include "gtest/gtest.h"

TEST(logger, test1)
{
  std::stringstream ss;
  std::string actionCr = "Create Object: ";
  std::string bullet1 = "[Bullet]: { Box 2D {boxMin Point2D {4.9, 4.8}, boxMax Point2D {5.1, 5.2}} }; Speed=1; Height=0.4; Width=0.2; Origin: { Point2D {5, 5} }; Direction: { Point2D {1, 0} }";
  Bullet b = { Point2D(5.0f, 5.0f), Point2D(1.0f, 0.0f) };
  Logger::Log(ss, GameAction::Create, b);
  EXPECT_EQ(ss.str(), actionCr + bullet1);
}

TEST(logger, test2)
{
  std::stringstream ss;
  std::string actionDam = "Damage Object: ";
  std::string alien1 = "[Alien]: { Box 2D {boxMin Point2D {0, 0}, boxMax Point2D {10, 10}} }; Ammo=100; Health=100; Speed=1; Direction: { Point2D {0, -1} }";
  Alien a = Box2D{ Point2D(0.0f, 0.0f), Point2D(10.0f, 10.0f) };
  Logger::Log(ss, GameAction::Damage, a);
  EXPECT_EQ(ss.str(), actionDam + alien1);
}

TEST(logger, test3)
{
  std::stringstream ss;
  std::string actionDes = "Destruction Object: ";
  std::string gun1 = "[Gun]: { Box 2D {boxMin Point2D {0, 0}, boxMax Point2D {1, 1}} }; Ammo=100; Health=100; Direction: { Point2D {0, 1} }";
  Gun g(100);
  Logger::Log(ss, GameAction::Destruction, g);
  EXPECT_EQ(ss.str(), actionDes + gun1);
}


TEST(logger, test4)
{
  std::stringstream ss;
  std::string actionCr = "Create Object: ";
  std::string gun1 = "[Alien]: { Box 2D {boxMin Point2D {0, 0}, boxMax Point2D {1, 1}}}; Ammo=100; Health=100; Speed=1; Direction: { Point2D {0, -1} }";
  std::string gun2 = "[Alien]: { Box 2D {boxMin Point2D {1, 1}, boxMax Point2D {2, 2}}}; Ammo=100; Health=100; Speed=1; Direction: { Point2D {0, -1} }";
  std::string gun3 = "[Alien]: { Box 2D {boxMin Point2D {2, 2}, boxMax Point2D {3, 3}}}; Ammo=100; Health=100; Speed=1; Direction: { Point2D {0, -1} }";
  std::list<Alien> A{ Box2D{ Point2D(0.0f, 0.0f), Point2D(1.0f, 1.0f) } , Box2D{ Point2D(1.0f, 1.0f), Point2D(2.0f, 2.0f) } , Box2D{ Point2D(2.0f, 2.0f), Point2D(3.0f, 3.0f) } };
  Logger::Log(ss, GameAction::Create, A);
  EXPECT_EQ(ss.str(), actionCr + gun1 + actionCr + gun2 + actionCr + gun3);
}