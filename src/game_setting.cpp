#include "game_setting.hpp"

GameSetting::GameSetting(QWidget * parent) : QMainWindow(parent)
{

  setWindowTitle("Настройки игры");

  this->resize(400, 600);
  this->setMinimumSize(400, 600);
  this->setMaximumSize(500, 750);

  m_centralWidget = new QWidget(this);
  setCentralWidget(m_centralWidget);

  m_alienBox = new QGroupBox("[ Пришелец ]", this);
  m_gumBox = new QGroupBox("[ Игрок ]", this);
  m_obstacleBox = new QGroupBox("[ Препятствие ]", this);
  m_bulletBox = new QGroupBox("[ Пуля ]", this);

  m_gameDifficulty = new QLabel("Сложность:");
  m_alienHealth = new QLabel("Здоровье:", m_alienBox);
  m_alienSpeed = new QLabel("Скорость:", m_alienBox);
  m_gunHealth = new QLabel("Здоровье:", m_gumBox);
  m_gunAmountBullet = new QLabel("Количество пуль:", m_gumBox);
  m_obstacleHealth = new QLabel("Здоровье:", m_obstacleBox);
  m_bulletSpeed = new QLabel("Скорость:", m_bulletBox);
  m_save = new QPushButton("&Сохранить");
  m_cancel = new QPushButton("&Отмена");
  m_exit = new QPushButton("&Выход");

  // game difficulty
  QComboBox * m_gameDifficultyCB = new QComboBox;
  m_gameDifficultyCB->addItem("Easy");
  m_gameDifficultyCB->addItem("Normal");
  m_gameDifficultyCB->addItem("Hard");

  // alien health
  m_alienHealthSB = new QSpinBox;
  m_alienHealthSL = new QSlider(Qt::Horizontal);
  m_alienHealthSB->setMaximum(100);
  m_alienHealthSL->setMaximum(100);
  QObject::connect(m_alienHealthSB,SIGNAL(valueChanged(int)),m_alienHealthSL,SLOT(setValue(int)));
  QObject::connect(m_alienHealthSL,SIGNAL(valueChanged(int)),m_alienHealthSB,SLOT(setValue(int)));
  // alien speed
  m_alienSpeedSB = new QSpinBox;
  m_alienSpeedSL = new QSlider(Qt::Horizontal);
  m_alienSpeedSB->setMaximum(10);
  m_alienSpeedSL->setMaximum(10);
  QObject::connect(m_alienSpeedSB,SIGNAL(valueChanged(int)),m_alienSpeedSL,SLOT(setValue(int)));
  QObject::connect(m_alienSpeedSL,SIGNAL(valueChanged(int)),m_alienSpeedSB,SLOT(setValue(int)));
  // alien layout
  m_alienLayout = new QGridLayout(m_alienBox);
  m_alienLayout->addWidget(m_alienHealth, 0, 0);
  m_alienLayout->addWidget(m_alienSpeed, 1, 0);
  m_alienLayout->addWidget(m_alienHealthSB, 0, 1);
  m_alienLayout->addWidget(m_alienHealthSL, 0, 2);
  m_alienLayout->addWidget(m_alienSpeedSB, 1, 1);
  m_alienLayout->addWidget(m_alienSpeedSL, 1, 2);

  // gun health
  m_gunHealthSB = new QSpinBox;
  m_gunHealthSL = new QSlider(Qt::Horizontal);
  m_gunHealthSB->setMaximum(100);
  m_gunHealthSL->setMaximum(100);
  QObject::connect(m_gunHealthSB,SIGNAL(valueChanged(int)),m_gunHealthSL,SLOT(setValue(int)));
  QObject::connect(m_gunHealthSL,SIGNAL(valueChanged(int)),m_gunHealthSB,SLOT(setValue(int)));
  // gun amount bullet
  m_gumAmountBulletSB = new QSpinBox;
  m_gumAmountBulletSL = new QSlider(Qt::Horizontal);
  m_gumAmountBulletSB->setMaximum(1000);
  m_gumAmountBulletSL->setMaximum(1000);
  QObject::connect(m_gumAmountBulletSB,SIGNAL(valueChanged(int)),m_gumAmountBulletSL,SLOT(setValue(int)));
  QObject::connect(m_gumAmountBulletSL,SIGNAL(valueChanged(int)),m_gumAmountBulletSB,SLOT(setValue(int)));
  // gun layout
  m_gunLayout = new QGridLayout(m_gumBox);
  m_gunLayout->addWidget(m_gunHealth, 0, 0);
  m_gunLayout->addWidget(m_gunAmountBullet, 1, 0);
  m_gunLayout->addWidget(m_gunHealthSB, 0, 1);
  m_gunLayout->addWidget(m_gunHealthSL, 0, 2);
  m_gunLayout->addWidget(m_gumAmountBulletSB, 1, 1);
  m_gunLayout->addWidget(m_gumAmountBulletSL, 1, 2);

  // obstacle health
  m_obstacleHealthSB = new QSpinBox;
  m_obstacleHealthSL = new QSlider(Qt::Horizontal);
  m_obstacleHealthSB->setMaximum(100);
  m_obstacleHealthSL->setMaximum(100);
  QObject::connect(m_obstacleHealthSB,SIGNAL(valueChanged(int)),m_obstacleHealthSL,SLOT(setValue(int)));
  QObject::connect(m_obstacleHealthSL,SIGNAL(valueChanged(int)),m_obstacleHealthSB,SLOT(setValue(int)));
  // obstacle layout
  m_obstacleLayout = new QGridLayout(m_obstacleBox);
  m_obstacleLayout->addWidget(m_obstacleHealth, 0, 0);
  m_obstacleLayout->addWidget(m_obstacleHealthSB, 0, 1);
  m_obstacleLayout->addWidget(m_obstacleHealthSL, 0, 2);

  // bullet speed
  m_bulletSpeedSB = new QSpinBox;
  m_bulletleSpeedSL = new QSlider(Qt::Horizontal);
  m_bulletSpeedSB->setMaximum(10);
  m_bulletleSpeedSL->setMaximum(10);
  QObject::connect(m_bulletSpeedSB,SIGNAL(valueChanged(int)),m_bulletleSpeedSL,SLOT(setValue(int)));
  QObject::connect(m_bulletleSpeedSL,SIGNAL(valueChanged(int)),m_bulletSpeedSB,SLOT(setValue(int)));
  // bullet layout
  m_bulletLayout = new QGridLayout(m_bulletBox);
  m_bulletLayout->addWidget(m_bulletSpeed, 0, 0);
  m_bulletLayout->addWidget(m_bulletSpeedSB, 0, 1);
  m_bulletLayout->addWidget(m_bulletleSpeedSL, 0, 2);

  m_layout = new QGridLayout(m_centralWidget);
  m_layout->addWidget(m_gameDifficulty, 0, 4);
  m_layout->addWidget(m_gameDifficultyCB, 0, 5);
  m_layout->addWidget(m_alienBox, 1, 0, 3, 6);
  m_layout->addWidget(m_gumBox, 4, 0, 3, 6);
  m_layout->addWidget(m_obstacleBox, 7, 0, 2, 6);
  m_layout->addWidget(m_bulletBox, 9, 0, 2, 6);
  m_layout->addWidget(m_save, 11, 3);
  m_layout->addWidget(m_cancel, 11, 4);
  m_layout->addWidget(m_exit, 11, 5);

}
