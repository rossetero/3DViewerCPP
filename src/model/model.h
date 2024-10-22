#ifndef MODEL_H_
#define MODEL_H_

#include <cmath>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "operations.h"
namespace s21 {

typedef struct polygon {
  std::vector<int> polygon_vertexes;
} polygon_t;

class Model {
 public:
  static Model& initModel() {
    static Model theModelObject;
    return theModelObject;
  }
  // parsers
  void parseFile(std::string filename);
  void vertexParsing(std::string buffer);
  void polygonParsing(std::string buffer);
  // getters
  std::vector<double> getVertexes() { return vertexes; }
  std::vector<polygon_t> getPolygons() { return polygons; }

  // operations
  void centerObject();
  void scaleObject(double n);
  void setTransformation(std::shared_ptr<Transformation> t) {
    currentTransformation = t;
  }
  void applyTransformation(double x = 0, double y = 0, double z = 0) {
    if (currentTransformation) {
      currentTransformation->transform(vertexes, x, y, z);
    }
  }
  void moveObject(double x, double y, double z) {
    setTransformation(std::make_shared<MoveObject>());
    applyTransformation(x, y, z);
  };
  void rotateFigure(double x, double y, double z) {
    setTransformation(std::make_shared<RotateObject>());
    applyTransformation(x, y, z);
  }

 private:
  std::shared_ptr<Transformation> currentTransformation;
  std::vector<polygon_t> polygons;
  std::vector<double> vertexes;
};
}  // namespace s21

#endif
