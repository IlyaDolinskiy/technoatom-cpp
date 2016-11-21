#include <QPainter>
#include <QPaintEngine>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QCoreApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QGuiApplication>
#include <cmath>

#include <iostream>

#include "mainwindow.h"
#include "gl_widget.h"

GLWidget::GLWidget(MainWindow * mw, QColor const & background)
  : m_mainWindow(mw)
  , m_background(background)
{
  setMinimumSize(1024, 768);
  setFocusPolicy(Qt::StrongFocus);
}

GLWidget::~GLWidget()
{
  makeCurrent();
  delete m_texture;
  delete m_texturedRect;
  doneCurrent();
}

void GLWidget::initializeGL()
{
  initializeOpenGLFunctions();

  m_texturedRect = new TexturedRect();

  m_texturedRect->Initialize(this);

  m_texture = new QOpenGLTexture(QImage("data/star.png")); //*

  m_time.start();

  m_time2.start();

  float m_xScale = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  float m_yScale = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  int m_size = 1 + std::rand() % 10;
  int m_timeStart = 100 + std::rand() % 700;
  float m_time3 = (100.0f + std::rand() % 500);
}

void GLWidget::paintGL()
{
  int const elapsed = m_time.elapsed();
  Update(elapsed / 1000.0f);

  QPainter painter;
  painter.begin(this);
  painter.beginNativePainting();

  glClearColor(m_background.redF(), m_background.greenF(), m_background.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glFrontFace(GL_CW);
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Render();

  glDisable(GL_CULL_FACE);
  glDisable(GL_BLEND);

  painter.endNativePainting();

  if (elapsed != 0)
  {
    QString framesPerSecond;
    framesPerSecond.setNum(m_frames / (elapsed / 1000.0), 'f', 2);
    painter.setPen(Qt::white);
    painter.drawText(20, 40, framesPerSecond + " fps");
  }
  painter.end();

  if (!(m_frames % 100))
  {
    m_time.start();
    m_frames = 0;
  }
  ++m_frames;
  update();
}

void GLWidget::resizeGL(int w, int h)
{
  m_screenSize.setWidth(w);
  m_screenSize.setHeight(h);
}

void GLWidget::Update(float elapsedSeconds)
{
}

void GLWidget::Render()
{
  for(int i = 1; i < 50; ++i)
  {
    int m_size = m_size * sin( (m_time2.elapsed()) / m_time3 );
    m_texturedRect->Render(m_texture, QVector2D(m_xScale * m_screenSize.width(),m_yScale * m_screenSize.height()),QSize(m_size, m_size), m_screenSize);
  }
}
