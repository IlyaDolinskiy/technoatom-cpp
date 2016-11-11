#pragma once

#include "logger.hpp"
#include "gameentity.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <memory>

class Space
{
public:

  Space() = default;
  Box2D const & GetPosition() const { return m_position; }
    
private:

  Box2D m_position = { 0.0f, 0.0f, 100.0f, 100.0f };

  //std::list<std::shared_ptr<Alien>> m_alien;
  //std::list<std::shared_ptr<Bullet>> m_bullet;
  //std::list<std::shared_ptr<Obstacle>> m_obstacle;
};
