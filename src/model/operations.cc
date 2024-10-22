#include "operations.h"

#include "model.h"
namespace s21 {

void Model::centerObject() {
  double x_max = vertexes[0];
  double x_min = vertexes[0];
  double y_max = vertexes[1];
  double y_min = vertexes[1];
  double z_max = vertexes[2];
  double z_min = vertexes[2];
  for (size_t i = 0; i < vertexes.size(); ++i) {
    switch (i % 3) {
      case 0:
        if (vertexes[i] > x_max) x_max = vertexes[i];
        if (vertexes[i] < x_min) x_min = vertexes[i];
        break;
      case 1:
        if (vertexes[i] > y_max) y_max = vertexes[i];
        if (vertexes[i] < y_min) y_min = vertexes[i];
        break;
      case 2:
        if (vertexes[i] > z_max) z_max = vertexes[i];
        if (vertexes[i] < z_min) z_min = vertexes[i];
        break;
    }
  }

  double center_x = (x_max + x_min) / 2;
  double center_y = (y_max + y_min) / 2;
  double center_z = (z_max + z_min) / 2;
  for (size_t i = 0; i < vertexes.size(); ++i) {
    switch (i % 3) {
      case 0:
        vertexes[i] -= center_x;
        break;
      case 1:
        vertexes[i] -= center_y;
        break;
      case 2:
        vertexes[i] -= center_z;
        break;
    }
  }
}

void Model::scaleObject(double n) {
  for (auto it = vertexes.begin(); it != vertexes.end(); it++) {
    *it *= n;
  }
}

void RotateObject::transform(std::vector<double>& vertexes, double x, double y,
                             double z) {
  x = x / 180 * PI;
  y = y / 180 * PI;
  z = z / 180 * PI;
  for (auto it = vertexes.begin(); it != vertexes.end(); it = it + 3) {
    if (x != 0) {
      double tmp = *(it + 1);
      *(it + 1) = *(it + 1) * cos(x) - *(it + 2) * sin(x);
      *(it + 2) = tmp * sin(x) + *(it + 2) * cos(x);
    }
    if (y != 0) {
      double tmp = *it;
      *it = *it * cos(y) + *(it + 2) * sin(y);
      *(it + 2) = tmp * (-sin(y)) + *(it + 2) * cos(y);
    }
    if (z != 0) {
      double tmp = *it;
      *it = *it * cos(z) + *(it + 1) * (-sin(z));
      *(it + 1) = tmp * sin(z) + *(it + 1) * cos(z);
    }
  }
}

void MoveObject::transform(std::vector<double>& vertexes, double x, double y,
                           double z) {
  for (auto it = vertexes.begin(); it != vertexes.end();) {
    *it += x;
    it++;
    *it += y;
    it++;
    *it += z;
    it++;
  }
}
}  // namespace s21