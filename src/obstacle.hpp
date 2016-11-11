#pragma once

#include "gameentity.hpp"

class Obstacle : public GameEntity
{
public:

  Obstacle() = default;
  Obstacle(Box2D && position) : m_position(std::move(position)) {}
  Obstacle(Obstacle const & obj) : m_position(obj.m_position) {}
  Obstacle(Obstacle && obj) { std::swap(m_position, obj.m_position); }
  Obstacle & operator = (Obstacle && obj)
  {
    std::swap(m_position, obj.m_position);
    return *this;
  }
  Obstacle & operator = (Obstacle const & obj)
  {
    if (this == &obj) return *this;
    m_position = obj.GetPosition();
    return *this;
  }
  bool operator == (Obstacle const & obj) const { return m_position == obj.m_position; }

  void Damage(float const & damage)
  {
    if (m_health - damage > 0)
      m_health -= damage;
    else
      m_health = 0;
  }

  friend std::ostream & operator << (std::ostream & os, Obstacle const & obj)
  {
    os << "[Obstacle]: { " << obj.GetPosition() << " }; Health=" << obj.GetHealth() << std::endl;
    return os;
  }

  void Move() override {}

  void SetPosition(Box2D && position) { m_position = std::move(position); }
  void SetHealth(float health) { m_health = health; }
  Box2D const GetPosition() const { return m_position; }
  float const GetHealth() const { return m_health; }

private:

  Box2D m_position = { 0.0f, 0.0f, 1.0f, 1.0f };
  float m_health = 50.0f;

};
