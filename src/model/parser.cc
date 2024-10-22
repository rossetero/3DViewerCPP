#include "model.h"

namespace s21 {

void Model::parseFile(std::string filename) {
  vertexes.clear();
  polygons.clear();
  if (filename.find(".obj") == std::string::npos)
    throw std::string{"ERROR: The file has a wrong format"};
  std::string b;
  std::ifstream in(filename);
  if (in.is_open()) {
    while (std::getline(in, b)) {
      if (b.size() > 2) {
        if (b[0] == 'f' && b[1] == ' ') polygonParsing(b);
        if (b[0] == 'v' && b[1] == ' ') vertexParsing(b);
      }
    }
    in.close();
  } else
    throw std::string{"ERROR: The file doesn't exist!"};
  centerObject();
}

void Model::vertexParsing(std::string b) {
  double x, y, z;
  std::string ch;
  std::istringstream iss(b);
  iss >> ch >> x >> y >> z;
  vertexes.push_back(x);
  vertexes.push_back(y);
  vertexes.push_back(z);
}

void Model::polygonParsing(std::string b) {
  polygon_t tmp{};
  while (b.size()) {
    while (b.size() && !(isdigit(b[0])) && b[0] != '-') b.erase(0, 1);
    if (b.size()) {
      int value = stod(b);
      if (value < 0) value = vertexes.size() / 3 + value + 1;
      (tmp.polygon_vertexes).push_back(value);
    }
    while (b.size() && b[0] != ' ') b.erase(0, 1);
  }
  polygons.push_back(tmp);
}

}  // namespace s21