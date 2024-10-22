#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/glut.h>

#include <QColorDialog>
#include <QFileDialog>
#include <QOpenGLWidget>
#include <QtOpenGL>
#include <iostream>

#include "../controller/controller.h"
#include "mainwindow.h"

using namespace s21;

namespace s21 {

typedef struct color {
  int red;
  int green;
  int blue;
} color;

class openglView : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  explicit openglView(QWidget *parent) : QOpenGLWidget(parent) {}

  openglView();
  std::string filename{};
  std::vector<double> vertexes_;
  std::vector<polygon_t> polygons;
  color figure_color;
  color background_color;
  int projection;
  int edges;
  int vertexes;
  double thickness;

 protected:
  void initializeGL() override;
  void paintGL() override;
};

}  // namespace s21

#endif  // MAINWINDOW_H
