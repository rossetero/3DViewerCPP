#include "controller.h"

using namespace s21;

void Controller::parseFile(std::string filename) { model.parseFile(filename); }

std::vector<double> Controller::getVertexes() { return model.getVertexes(); }

std::vector<polygon_t> Controller::getPolygons() { return model.getPolygons(); }

void Controller::moveObject(double x, double y, double z) {
  model.moveObject(x, y, z);
}

void Controller::rotateObject(double x, double y, double z) {
  model.rotateFigure(x, y, z);
}

void Controller::scaleObject(double n) { model.scaleObject(n); }
