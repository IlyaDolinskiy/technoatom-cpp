#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTime>
#include "textured_rect.h"

#include <array>

class MainWindow;

QT_FORWARD_DECLARE_CLASS(QOpenGLTexture)
QT_FORWARD_DECLARE_CLASS(QOpenGLShader)
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
  Q_OBJECT
public:
  GLWidget(MainWindow * mw, QColor const & background);
  ~GLWidget();

protected:
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void initializeGL() override;

  void Update(float elapsedSeconds);
  void Render();

private:
  int L2D(int px) const { return px * devicePixelRatio(); }

  MainWindow * m_mainWindow;

  unsigned int m_frames = 0;
  QTime m_time;
  QTime m_time2;
  float m_time3;
  QColor m_background;
  QSize m_screenSize;
  float m_xScale;
  float m_yScale;
  int m_size;
  int m_timeStart;



  QOpenGLTexture * m_texture = nullptr;
  TexturedRect * m_texturedRect = nullptr;

  QVector2D m_position = QVector2D(200, 200);
  std::array<bool, 4> m_directions = {{ false, false, false, false }};
};
