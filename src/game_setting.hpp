#pragma once

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

#include <QGridLayout>
#include <QGroupBox>
#include <QSpinBox>
#include <QSlider>
#include <QMainWindow>
#include <QComboBox>

class GameSetting : public QMainWindow
{
  Q_OBJECT

public:
  GameSetting(QWidget * parent = 0);

private:

  QWidget * m_centralWidget = nullptr;
  QGroupBox * m_alienBox = nullptr;
  QGroupBox * m_gumBox = nullptr;
  QGroupBox * m_obstacleBox = nullptr;
  QGroupBox * m_bulletBox = nullptr;
  QLabel * m_gameDifficulty = nullptr;
  QLabel * m_alienAmount = nullptr;
  QLabel * m_alienHealth = nullptr;
  QLabel * m_alienSpeed = nullptr;
  QLabel * m_gunHealth = nullptr;
  QLabel * m_gunAmountBullet = nullptr;
  QLabel * m_obstacleHealth = nullptr;
  QLabel * m_bulletSpeed = nullptr;
  QPushButton * m_save = nullptr;
  QPushButton * m_cancel = nullptr;
  QPushButton * m_exit = nullptr;
  QSpinBox * m_alienHealthSB = nullptr;
  QSlider * m_alienHealthSL = nullptr;
  QSpinBox * m_alienSpeedSB = nullptr;
  QSlider * m_alienSpeedSL = nullptr;
  QGridLayout * m_alienLayout = nullptr;
  QSpinBox * m_gunHealthSB = nullptr;
  QSlider * m_gunHealthSL = nullptr;
  QSpinBox * m_gumAmountBulletSB = nullptr;
  QSlider * m_gumAmountBulletSL = nullptr;
  QGridLayout * m_gunLayout = nullptr;
  QSpinBox * m_obstacleHealthSB = nullptr;
  QSlider * m_obstacleHealthSL = nullptr;
  QGridLayout * m_obstacleLayout = nullptr;
  QSpinBox * m_bulletSpeedSB = nullptr;
  QSlider * m_bulletleSpeedSL = nullptr;
  QGridLayout * m_bulletLayout = nullptr;
  QGridLayout * m_layout = nullptr;
};