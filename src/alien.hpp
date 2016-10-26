#pragma once

#include "gameentity.hpp"
#include "bullet.hpp"

class Alien : public GameEntity
{
public:

  Alien() = default;

  Alien(Box2D && position) : m_position(std::move(position)) {}

  Alien(Alien const & obj) : m_position(obj.m_position) {}

  Alien(Alien && obj) { std::swap(m_position, obj.m_position); }

  Alien & operator = (Alien && obj)
  {
    std::swap(m_position, obj.m_position);
    return *this;
  }

  Alien & operator = (Alien const & obj)
  {
    if (this == &obj) return *this;
    m_position = obj.GetPosition();
    return *this;
  }

  bool operator == (Alien const & obj) const { return m_position == obj.m_position; }


  void Damage(float const & damage)
  {
    if (m_health - damage > 0)
      m_health -= damage;
    else
      m_health = 0;
  }

  void Move() override {}
  
  Bullet Shot()
  {
    try
    {
      if (m_ammo == 0) throw std::invalid_argument("Ammo run out");
      m_ammo--;
      return Bullet(m_position.Center(), m_direction);
    }
    catch (const std::exception const & ex)
    {
      std::cerr << ex.what();
    }
  }

  void SetAmmo(unsigned int ammo) { m_ammo = ammo; }
  void SetHealth(float health) { m_health = health; }
  void SetSpeed(float speed) { m_speed = speed; }
  void SetPosition(Box2D && position) { m_position = std::move(position); }
  void SetDirection(Point2D && direction) { m_direction = std::move(direction); }

  unsigned int GetAmmo() const { return m_ammo; }
  float const GetHealth() const { return m_health; }
  float const GetSpeed() const { return m_speed; }
  Box2D const GetPosition() const { return m_position; }
  Point2D const GetDirection() const { return  m_direction; }

private:

  unsigned int m_ammo = 100;
  float m_health = 100.0f;
  float m_speed = 1.0f;
  Box2D m_position = { 0.0f, 0.0f, 1.0f, 1.0f };
  Point2D m_direction = { 0.0f, -1.0f };
};
