#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {

class Controller {
 private:
  Model model = Model::initModel();

 public:
  void parseFile(std::string filename);
  std::vector<double> getVertexes();
  std::vector<polygon_t> getPolygons();
  void moveObject(double x, double y, double z);
  void rotateObject(double x, double y, double z);
  void scaleObject(double n);
};

}  // namespace s21

#endif
