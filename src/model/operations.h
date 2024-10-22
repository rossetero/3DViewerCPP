#ifndef TRANSFORM
#define TRANSFORM

#include <memory>
#include <vector>

#define PI 3.141592653589793238462643383279502884L

namespace s21 {

class Transformation {
 public:
  virtual void transform(std::vector<double>& vertexes, double x = 0,
                         double y = 0, double z = 0) = 0;
  virtual ~Transformation() {}
};

class MoveObject : public Transformation {
 public:
  void transform(std::vector<double>& vertexes, double x, double y,
                 double z) override;
};

class RotateObject : public Transformation {
 public:
  void transform(std::vector<double>& vertexes, double x, double y,
                 double z) override;
};

}  // namespace s21

#endif