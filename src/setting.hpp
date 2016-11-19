#pragma once

class Setting
{
public:

  int GetAlienHealth() { return m_alienHealth; }
  int GetAlienSpeed() { return m_alienSpeed; }
  int GetGunHealth() { return m_gunHealth; }
  int GetGunAmountBullet() { return m_gunAmountBullet; }
  int GetObstacleHealth() { return m_obstacleHealth; }
  int GetBulletSpeed() { return m_bulletSpeed; }

  void SetAlienHealth(int alienHealth) { m_alienHealth = alienHealth; }
  void SetAlienSpeed(int alienSpeed) { m_alienSpeed = alienSpeed; }
  void SetGunHealth(int gunHealth) { m_gunHealth = gunHealth; }
  void SetGunAmountBullet(int gunAmountBullet) { m_gunAmountBullet = gunAmountBullet; }
  void SetObstacleHealth(int obstacleHealth) { m_obstacleHealth = obstacleHealth; }
  void SetBulletSpeed(int bulletSpeed) { m_bulletSpeed = bulletSpeed; }

private:

  int m_alienHealth = 0;
  int m_alienSpeed = 0;
  int m_gunHealth = 0;
  int m_gunAmountBullet = 0;
  int m_obstacleHealth = 0;
  int m_bulletSpeed = 0;

};
