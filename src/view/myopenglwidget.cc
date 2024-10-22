#include "myopenglwidget.h"

using namespace s21;

void openglView::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor((double)222 / 1, (double)221 / 1, (double)218 / 1, 1);
  glColor3d(53 / 1, (double)131 / 1, (double)228 / 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void openglView::paintGL() {
  glClearColor((double)background_color.red / 255,
               (double)background_color.green / 255,
               (double)background_color.blue / 255, 255);
  glColor3d((double)figure_color.red / 255, (double)figure_color.green / 255,
            (double)figure_color.blue / 255);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLineWidth(thickness);
  if (edges == 0) {
    glDisable(GL_LINE_STIPPLE);
  } else if (edges == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  }
  for (auto it = polygons.begin(); it != polygons.end(); it++) {
    glBegin(GL_LINE_LOOP);
    for (auto it2 = (*it).polygon_vertexes.begin();
         it2 != (*it).polygon_vertexes.end(); it2++) {
      if (projection == 1) {
        glVertex3d(vertexes_[*it2 * 3 - 3], vertexes_[*it2 * 3 - 2],
                   vertexes_[*it2 * 3 - 1]);
      } else if (projection == 0) {
        glVertex4d(vertexes_[*it2 * 3 - 3], vertexes_[*it2 * 3 - 2], 0,
                   1 + vertexes_[*it2 * 3 - 1]);
      }
    }
    glEnd();
  }
  if (vertexes == 0) {
    glDisable(GL_POINT_SMOOTH);
    glPointSize(1);
  } else if (vertexes == 1) {
    glEnable(GL_POINT_SMOOTH);
    glPointSize(10);
  } else if (vertexes == 2) {
    glDisable(GL_POINT_SMOOTH);
    glPointSize(10);
  }
  glBegin(GL_POINTS);
  for (auto it = vertexes_.begin(); it != vertexes_.end(); it = it + 3) {
    if (projection == 1) {
      glVertex3d(*it, *(it + 1), *(it + 2));
    } else if (projection == 0) {
      glVertex4d(*it, *(it + 1), 0, 1 + *(it + 2));
    }
  }
  glEnd();
}
