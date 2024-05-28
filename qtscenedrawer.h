#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H

#include <QGLWidget>
#include <QtOpenGL>
#include <QtGui>
#include "appcontext.h"


class QtSceneDrawer : public QGLWidget
{
private:
    GLfloat xRot;
    GLfloat yRot;
    GLfloat zRot;
    GLfloat zTra;
    GLfloat nSca;
    QPoint ptrMousePosition;
    void scale_plus();
    void scale_minus();
    void rotate_up();
    void rotate_down();
    void rotate_left();
    void rotate_right();
    void translate_down();
    void translate_up();
    void defaultScene();
    void drawAxis();
    void drawFigure();
protected:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void mousePressEvent(QMouseEvent* pe);
    void mouseMoveEvent(QMouseEvent* pe);
    void wheelEvent(QWheelEvent* pe);
public:
      QtSceneDrawer(QWidget* parent);
      std::vector<Figure> figures;
};

#endif // QTSCENEDRAWER_H
