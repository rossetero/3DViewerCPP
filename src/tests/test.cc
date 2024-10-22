#include <gtest/gtest.h>

#include "../controller/controller.h"

TEST(VIEVER, test_1) {
  s21::Controller controller;

  std::string str1 = "ERROR: The file doesn't exist!";
  try {
    controller.parseFile("./objects/no.obj");
  } catch (std::string error_message) {
    ASSERT_EQ(str1, error_message);
  }

  std::string str2 = "ERROR: The file has a wrong format";
  try {
    controller.parseFile("./Makefile");
  } catch (std::string error_message) {
    ASSERT_EQ(str2, error_message);
  }
}

TEST(VIEWER, test_2) {
  s21::Controller controller;
  controller.parseFile("./objects/tetraedr.obj");
  std::vector<double> vec = controller.getVertexes();
  ASSERT_EQ(vec[0], -0.5);
  ASSERT_EQ(vec[1], -0.435);
  ASSERT_EQ(vec[2], -0.405);
  ASSERT_EQ(vec[3], 0.5);
  ASSERT_EQ(vec[4], -0.435);
  ASSERT_EQ(vec[5], -0.405);
  ASSERT_EQ(vec[6], 0);
  ASSERT_EQ(vec[7], 0.435);
  ASSERT_EQ(vec[8], -0.405);
  ASSERT_EQ(vec.size(), 12);
  std::vector<s21::polygon_t> vec2 = controller.getPolygons();
  ASSERT_EQ(vec2.size(), 4);
}

TEST(VIEWER, test_3) {
  s21::Controller controller;
  controller.parseFile("./objects/tetraedr.obj");
  controller.scaleObject(2);
  std::vector<double> vec = controller.getVertexes();
  ASSERT_EQ(vec[0], -1);
  ASSERT_EQ(vec[1], -0.87);
  ASSERT_EQ(vec[2], -0.81);
  ASSERT_EQ(vec[3], 1);
  ASSERT_EQ(vec[4], -0.87);
  ASSERT_EQ(vec[5], -0.81);
  ASSERT_EQ(vec[6], 0);
  ASSERT_EQ(vec[7], 0.87);
  ASSERT_EQ(vec[8], -0.81);
  ASSERT_NEAR(vec[10], -0.29, 1e-6);
  ASSERT_EQ(vec.size(), 12);
  std::vector<s21::polygon_t> vec2 = controller.getPolygons();
  ASSERT_EQ(vec2.size(), 4);
}

TEST(VIEWER, test_4) {
  s21::Controller controller;
  controller.parseFile("./objects/tetraedr.obj");
  controller.scaleObject(2);

  controller.moveObject(0.5, 0.5, 0.5);
  std::vector<double> vec = controller.getVertexes();

  ASSERT_EQ(vec[0], -0.5);
  ASSERT_EQ(vec[1], -0.37);
  ASSERT_NEAR(vec[8], -0.31, 1e-6);
  ASSERT_EQ(vec[3], 1.5);
  ASSERT_EQ(vec[4], -0.37);
  ASSERT_NEAR(vec[8], -0.31, 1e-6);
  ASSERT_EQ(vec[6], 0.5);
  ASSERT_EQ(vec[7], 1.37);
  ASSERT_NEAR(vec[8], -0.31, 1e-6);
  ASSERT_EQ(vec.size(), 12);
  std::vector<s21::polygon_t> vec2 = controller.getPolygons();
  ASSERT_EQ(vec2.size(), 4);
}

TEST(VIEWER, test_5) {
  s21::Controller controller;
  controller.parseFile("./objects/tetraedr.obj");

  controller.rotateObject(360, 360, 360);
  std::vector<double> vec = controller.getVertexes();

  ASSERT_EQ(vec[0], -0.5);
  ASSERT_EQ(vec[1], -0.435);
  ASSERT_EQ(vec[2], -0.405);
  ASSERT_EQ(vec[3], 0.5);
  ASSERT_NEAR(vec[4], -0.435, 1e-6);
  ASSERT_NEAR(vec[5], -0.4049999999, 1e-6);
  ASSERT_NEAR(vec[6], 0, 1e-6);
  ASSERT_NEAR(vec[7], 0.435, 1e-6);
  ASSERT_NEAR(vec[8], -0.4049999999, 1e-6);
  ASSERT_EQ(vec.size(), 12);
  std::vector<s21::polygon_t> vec2 = controller.getPolygons();
  ASSERT_EQ(vec2.size(), 4);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}