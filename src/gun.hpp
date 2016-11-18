#pragma once

#include "gameentity.hpp"
#include "bullet.hpp"

class Gun : public GameEntity
{
public:

  Gun() = default;
  Gun(int ammo) : m_ammo(ammo) {}
  Gun(Box2D && position) : m_position(std::move(position)) {}
  Gun(Gun const & obj) : m_ammo(obj.m_ammo) {}
  Gun(Gun && obj) { std::swap(m_ammo, obj.m_ammo); }
  Gun & operator = (Gun && obj)
  {
    std::swap(m_ammo, obj.m_ammo);
    return *this;
  }
  Gun & operator = (Gun const & obj)
  {
    if (this == &obj) return *this;
    m_ammo = obj.GetAmmo();
    return *this;
  }
  bool operator == (Gun const & obj) const { return m_ammo == obj.m_ammo; }

  Bullet Shot()
  {
    try
    {
      if (m_ammo == 0) throw std::invalid_argument("Ammo run out");
      m_ammo--;
      return Bullet(m_position.Center(), m_direction);
    }
    catch (std::exception const & ex)
    {
      std::cerr << ex.what();
    }
  }

  void Damage(float const & damage)
  {
    if (m_health - damage > 0)
      m_health -= damage;
    else
      m_health = 0;
  }

  void Move() override {}

  friend std::ostream & operator << (std::ostream & os, Gun const & obj)
  {
    os << "[Gun]: { " << obj.GetPosition() << " }; Ammo=" << obj.GetAmmo() << "; Health=" << obj.GetHealth() << "; Direction: { " << obj.GetDirection() << " }" << std::endl;
    return os;
  }

  void SetHealth(float health) { m_health = health; }
  void SetAmmo(unsigned int ammo) { m_ammo = ammo; }
  void SetDirection(Point2D && direction) { m_direction = std::move(direction); }
  void SetPosition(Box2D && position) { m_position = std::move(position); }
  float const GetHealth() const { return m_health; }
  unsigned int GetAmmo() const { return m_ammo; }
  Point2D GetDirection() const { return m_direction; }
  Box2D GetPosition() const { return m_position; }

private:

  unsigned int m_ammo = 10;
  float m_health = 100.0f;
  Point2D m_direction = { 0.0f, 1.0f };
  Box2D m_position = { 0.0f, 0.0f, 1.0f, 1.0f };

};
