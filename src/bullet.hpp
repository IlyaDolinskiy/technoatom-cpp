#pragma once

#include "gameentity.hpp"

class Bullet : public GameEntity
{
public:
  Bullet() = default;
  Bullet(Point2D origin, Point2D direction)
    : m_origin(origin)
    , m_direction(direction)
  {
    Position();
  }
  Bullet(Bullet const & obj)
    : m_origin(obj.m_origin)
    , m_direction(obj.m_direction)
  {}
  Bullet(Bullet && obj)
  {
    std::swap(m_origin, obj.m_origin);
    std::swap(m_direction, obj.m_direction);
  }
  Bullet & operator = (Bullet && obj)
  {
    std::swap(m_origin, obj.m_origin);
    std::swap(m_direction, obj.m_direction);
    return *this;
  }

  void Update()
  {
    Move();
  }

  void Move() override
  {
    m_position.Move(VectorSpeed());
    Origin();
  }

  friend std::ostream & operator << (std::ostream & os, Bullet const & obj)
  {
    os << "[Bullet]: { " << obj.GetPosition() << " }; Speed=" << obj.GetSpeed() << "; Height=" << obj.GetHeight() << "; Width=" << obj.GetWidth() << "; Origin: { " << obj.GetOrigin() << " }" << "; Direction: { " << obj.GetDirection() << " }" << std::endl;
    return os;
  }

  void SetPosition(Box2D && position)
  {
    m_position = std::move(position);
    Origin();
  }
  void SetOrigin(Point2D && origin)
  {
    m_origin = std::move(origin);
    Position();
  }
  void SetDirection(Point2D && direction) { m_direction = std::move(direction); }
  void SetSpeed(float const & speed) { m_speed = speed; }
  void SetHeight(float const & height)
  {
    try
    {
      if (fabs(height) < 1e-5) throw std::invalid_argument("The height can not be equal to 0");
      m_height = height;
    }
    catch (std::exception const & ex)
    {
      std::cerr << ex.what();
    }
  }
  void SetWidth(float const & width)
  {
    try
    {
      if (fabs(width) < 1e-5) throw std::invalid_argument("The width can not be equal to 0");
      m_width = width;
    }
    catch (std::exception const & ex)
    {
      std::cerr << ex.what();
    }
  }
  Box2D const & GetPosition() const { return m_position; }
  Point2D const & GetOrigin() const { return m_origin; }
  Point2D const & GetDirection() const { return m_direction; }
  float const & GetSpeed() const { return m_speed; }
  float const & GetHeight() const { return m_height; }
  float const & GetWidth() const { return m_width; }

private:

  void Position()
  {
    m_position = {
      (m_origin.x() - m_width / 2.0f),
      (m_origin.y() - m_height / 2.0f),
      (m_origin.x() + m_width / 2.0f),
      (m_origin.y() + m_height / 2.0f) };
  }

  void Origin() { m_origin = m_position.Center(); }

  Point2D VectorSpeed() { return m_direction*m_speed; }

  float m_speed = 1.0f;
  float m_height = 0.4f;
  float m_width = 0.2f;
  Point2D m_origin = { 0.0f, 0.0f };
  Point2D m_direction = { 1.0f, 0.0f };
  Box2D m_position = { 0.0f, 0.0f, 0.2f, 0.4f };

};
