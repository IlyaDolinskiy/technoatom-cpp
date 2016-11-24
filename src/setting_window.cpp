#include "setting_window.hpp"
#include "setting.hpp"

#include <json/json.h>
#include <json/writer.h>
#include <fstream>
#include <iostream>

GameSetting::GameSetting(QWidget * parent) : QMainWindow(parent)
{

  setWindowTitle("Настройки");

  this->resize(400, 600);
  this->setMinimumSize(400, 600);
  this->setMaximumSize(500, 750);

  m_centralWidget = new QWidget(this);
  setCentralWidget(m_centralWidget);

  m_alienBox = new QGroupBox("[ Пришелец ]", this);
  m_gunBox = new QGroupBox("[ Игрок ]", this);
  m_obstacleBox = new QGroupBox("[ Препятствие ]", this);
  m_bulletBox = new QGroupBox("[ Пуля ]", this);

  m_gameDifficulty = new QLabel("Сложность:");
  m_alienHealth = new QLabel("Здоровье:", m_alienBox);
  m_alienSpeed = new QLabel("Скорость:", m_alienBox);
  m_gunHealth = new QLabel("Здоровье:", m_gunBox);
  m_gunAmountBullet = new QLabel("Количество пуль:", m_gunBox);
  m_obstacleHealth = new QLabel("Здоровье:", m_obstacleBox);
  m_bulletSpeed = new QLabel("Скорость:", m_bulletBox);
  m_save = new QPushButton("&Сохранить");
  m_cancel = new QPushButton("&Отмена");

  // game difficulty
  m_gameDifficultyCB = new QComboBox;
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
  m_gunAmountBulletSB = new QSpinBox;
  m_gunAmountBulletSL = new QSlider(Qt::Horizontal);
  m_gunAmountBulletSB->setMaximum(1000);
  m_gunAmountBulletSL->setMaximum(1000);
  QObject::connect(m_gunAmountBulletSB,SIGNAL(valueChanged(int)),m_gunAmountBulletSL,SLOT(setValue(int)));
  QObject::connect(m_gunAmountBulletSL,SIGNAL(valueChanged(int)),m_gunAmountBulletSB,SLOT(setValue(int)));
  // gun layout
  m_gunLayout = new QGridLayout(m_gunBox);
  m_gunLayout->addWidget(m_gunHealth, 0, 0);
  m_gunLayout->addWidget(m_gunAmountBullet, 1, 0);
  m_gunLayout->addWidget(m_gunHealthSB, 0, 1);
  m_gunLayout->addWidget(m_gunHealthSL, 0, 2);
  m_gunLayout->addWidget(m_gunAmountBulletSB, 1, 1);
  m_gunLayout->addWidget(m_gunAmountBulletSL, 1, 2);

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
  m_bulletSpeedSL = new QSlider(Qt::Horizontal);
  m_bulletSpeedSB->setMaximum(10);
  m_bulletSpeedSL->setMaximum(10);
  QObject::connect(m_bulletSpeedSB,SIGNAL(valueChanged(int)),m_bulletSpeedSL,SLOT(setValue(int)));
  QObject::connect(m_bulletSpeedSL,SIGNAL(valueChanged(int)),m_bulletSpeedSB,SLOT(setValue(int)));
  // bullet layout
  m_bulletLayout = new QGridLayout(m_bulletBox);
  m_bulletLayout->addWidget(m_bulletSpeed, 0, 0);
  m_bulletLayout->addWidget(m_bulletSpeedSB, 0, 1);
  m_bulletLayout->addWidget(m_bulletSpeedSL, 0, 2);

  // difficulty layout
  m_difficultyLayout = new QGridLayout();
  m_difficultyLayout->addWidget(m_gameDifficulty, 0, 0);
  m_difficultyLayout->addWidget(m_gameDifficultyCB, 0, 1);

  // main layout
  m_mainLayout = new QGridLayout(m_centralWidget);
  m_mainLayout->addLayout(m_difficultyLayout, 0, 4, 1, 2);
  m_mainLayout->addWidget(m_alienBox, 1, 0, 3, 6);
  m_mainLayout->addWidget(m_gunBox, 4, 0, 3, 6);
  m_mainLayout->addWidget(m_obstacleBox, 7, 0, 2, 6);
  m_mainLayout->addWidget(m_bulletBox, 9, 0, 2, 6);
  m_mainLayout->addWidget(m_save, 11, 4);
  m_mainLayout->addWidget(m_cancel, 11, 5);

  m_save->setDefault(true);
  connect(m_save, SIGNAL(clicked()), this, SLOT(SaveSetting()));
  connect(m_cancel, SIGNAL(clicked()), this, SLOT(close()));
  connect(m_gameDifficultyCB, SIGNAL(currentIndexChanged(int)), this, SLOT(DifficultyChanged(int)));

}

void GameSetting::DifficultyChanged(int index)
{
  switch (index)
    {
    case 0:
      m_alienHealthSB->setValue(10);
      m_alienSpeedSB->setValue(3);
      m_bulletSpeedSB->setValue(5);
      m_gunAmountBulletSB->setValue(1000);
      m_gunHealthSB->setValue(100);
      m_obstacleHealthSB->setValue(100);
      break;
    case 1:
      m_alienHealthSB->setValue(50);
      m_alienSpeedSB->setValue(5);
      m_bulletSpeedSB->setValue(7);
      m_gunAmountBulletSB->setValue(500);
      m_gunHealthSB->setValue(50);
      m_obstacleHealthSB->setValue(50);
      break;
    case 2:
      m_alienHealthSB->setValue(100);
      m_alienSpeedSB->setValue(10);
      m_bulletSpeedSB->setValue(10);
      m_gunAmountBulletSB->setValue(50);
      m_gunHealthSB->setValue(10);
      m_obstacleHealthSB->setValue(10);
      break;
    }
}

void GameSetting::SaveSetting()
{
  Setting * m_setting = new Setting;
  m_setting->SetAlienHealth(m_alienHealthSB->value());
  m_setting->SetAlienSpeed(m_alienSpeedSB->value());
  m_setting->SetBulletSpeed(m_bulletSpeedSB->value());
  m_setting->SetGunAmountBullet(m_gunAmountBulletSB->value());
  m_setting->SetGunHealth(m_gunHealthSB->value());
  m_setting->SetObstacleHealth(m_obstacleHealthSB->value());
  WriteJson();
  this->close();
}

void GameSetting::WriteJson()
{
  Json::Value settings;
  auto & root = settings["settings"];

  root["entities"]["alien"]["health"] = m_alienHealthSB->value();
  root["entities"]["alien"]["speed"] = m_alienSpeedSB->value();
  root["entities"]["gun"]["health"] = m_gunHealthSB->value();
  root["entities"]["gun"]["bulletsCount"] = m_gunAmountBulletSB->value();
  root["entities"]["obstacle"]["health"] = m_obstacleHealthSB->value();
  root["entities"]["bullet"]["speed"] = m_bulletSpeedSB->value();

  std::ofstream settingsFile;
  settingsFile.open("settings.json");
  if (settingsFile.is_open())
  {
    Json::StyledWriter styledWriter;
    settingsFile << styledWriter.write(settings);
    settingsFile.close();
  }
}

void GameSetting::ReadJson()
{
  Json::Value settings;
  std::ifstream file("settings.json");
  if (file.is_open())
  {
    file >> settings;
    file.close();
  }

  Json::Value & entities = settings["settings"]["entities"];
  std::cout << entities["alien"]["health"].asInt() << std::endl;
  std::cout << entities["alien"]["speed"].asInt() << std::endl;
  std::cout << entities["gun"]["health"].asInt() << std::endl;
  std::cout << entities["gun"]["bulletsCount"].asInt() << std::endl;
  std::cout << entities["obstacle"]["health"].asInt() << std::endl;
  std::cout << entities["bullet"]["speed"].asInt() << std::endl;
}


