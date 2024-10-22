#ifndef VIEWER_H
#define VIEWER_H

#include <GL/glut.h>
#include <QColorDialog>
#include <QFileDialog>
#include <QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QMovie>
#include <QSettings>
#include <iostream>
#include "../controller/controller.h"
#include "myopenglwidget.h"
#include "qgifimage/gifimage/qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
  class Viewer;
}
QT_END_NAMESPACE

namespace s21
{
  class Viewer : public QMainWindow
  {
    Q_OBJECT
  public:
    Viewer(QWidget *parent = nullptr);
    ~Viewer();
    void clean();
    void set_settings();

  private slots:
    void set_figure_color();
    void set_background_color();
    int set_color(struct color *color, QString *str);
    void set_button_color(struct color color, QString *str);
    void on_radioButton_central_pressed();
    void on_radioButton_parallel_pressed();
    void on_radioButton_solid_pressed();
    void on_radioButton_dashed_pressed();
    void on_radioButton_none_pressed();
    void on_radioButton_circle_pressed();
    void on_radioButton_square_pressed();
    void on_pushButton_open_choose_file_clicked();
    void on_pushButton_clear_changes_clicked();
    void on_doubleSpinBox_thikness_valueChanged(double arg1);
    void on_pushButton_bmp_clicked();
    void on_pushButton_jpeg_clicked();
    void on_pushButton_gif_clicked();
    void change_settings();
    void gifSelect();
    void on_doubleSpinBox_move_x_valueChanged(double value);
    void on_doubleSpinBox_move_y_valueChanged(double value);
    void on_doubleSpinBox_move_z_valueChanged(double value);
    void on_doubleSpinBox_rotate_x_valueChanged(double value);
    void on_doubleSpinBox_rotate_y_valueChanged(double value);
    void on_doubleSpinBox_rotate_z_valueChanged(double value);
    void on_doubleSpinBox_scale_valueChanged(double value);

  private:
    Ui::Viewer *ui;
    Controller m_controller;

    QTimer *timerGif;
    QGifImage *gif;
    int fps = 0;
    double m_previousMoveX = 0.0;
    double m_previousMoveY = 0.0;
    double m_previousMoveZ = 0.0;
    double m_previousRotateX = 0.0;
    double m_previousRotateY = 0.0;
    double m_previousRotateZ = 0.0;
    double m_previousScale = 0.0;
    double m_initialMoveX = 0.0;
    double m_initialMoveY = 0.0;
    double m_initialMoveZ = 0.0;
    double m_initialRotateX = 0.0;
    double m_initialRotateY = 0.0;
    double m_initialRotateZ = 0.0;
    double m_initialScale = 1.0; 
    bool fileLoadedSuccessfully = false;
  };

} // namespace s21
#endif // VIEWER_H
