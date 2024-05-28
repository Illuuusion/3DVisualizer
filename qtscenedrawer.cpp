#include <QtGui>
#include <math.h>
#include "qtscenedrawer.h"
#include "QDebug"


QtSceneDrawer::QtSceneDrawer(QWidget* parent) : QGLWidget(parent)
{
   xRot=-90;
   yRot=0;
   zRot=0;
   zTra=0;
   nSca=0.25;
}

void QtSceneDrawer::initializeGL()
{
   qglClearColor(Qt::white);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
   glEnable(GL_CULL_FACE);
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);
}

void QtSceneDrawer::resizeGL(int nWidth, int nHeight)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth;
   if (nWidth>=nHeight)
      glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0);
   else
      glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);
   glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void QtSceneDrawer::paintGL()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glScalef(nSca, nSca, nSca);
   glTranslatef(0.0f, zTra, 0.0f);
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 1.0f, 0.0f);
   glRotatef(zRot, 0.0f, 0.0f, 1.0f);
   drawAxis();
   drawFigure();
}

void QtSceneDrawer::mousePressEvent(QMouseEvent* pe)
{
   ptrMousePosition = pe->pos();
}

void QtSceneDrawer::mouseMoveEvent(QMouseEvent* pe)
{
   xRot += 180/nSca*(GLfloat)(pe->y()-ptrMousePosition.y())/height();
   zRot += 180/nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width();
   ptrMousePosition = pe->pos();
   updateGL();
}
void QtSceneDrawer::wheelEvent(QWheelEvent* pe)
{
   if ((pe->delta())>0)
       scale_plus();
   else if ((pe->delta())<0)
       scale_minus();
   updateGL();
}


void QtSceneDrawer::scale_plus()
{
   nSca = nSca*1.1;
}

void QtSceneDrawer::scale_minus()
{
   nSca = nSca/1.1;
}

void QtSceneDrawer::rotate_up()
{
   xRot += 1.0;
}

void QtSceneDrawer::rotate_down()
{
   xRot -= 1.0;
}

void QtSceneDrawer::rotate_left()
{
   zRot += 1.0;
}

void QtSceneDrawer::rotate_right()
{
   zRot -= 1.0;
}

void QtSceneDrawer::translate_down()
{
   zTra -= 0.05;
}

void QtSceneDrawer::translate_up()
{
   zTra += 0.05;
}

void QtSceneDrawer::defaultScene()
{
   xRot=-90; yRot=0; zRot=0; zTra=0; nSca=0.25;
}

void QtSceneDrawer::drawAxis()
{
    glLineWidth(3.0f);
    glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
    glBegin(GL_LINES);
       glVertex3f( 10.0f,  0.0f,  0.0f);
       glVertex3f(-10.0f,  0.0f,  0.0f);
    glEnd();
    QColor halfGreen(0, 128, 0, 255);
    qglColor(halfGreen);
    glBegin(GL_LINES);
       glVertex3f( 0.0f,  10.0f,  0.0f);
       glVertex3f( 0.0f, -10.0f,  0.0f);
       glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
       glVertex3f( 0.0f,  0.0f,  10.0f);
       glVertex3f( 0.0f,  0.0f, -10.0f);
    glEnd();
}

void QtSceneDrawer::drawFigure(){
    glLineWidth(25.0f);
    GLfloat x, y, z;
    std::vector<Edge> edges;
    glBegin(GL_LINES);
    glColor3f(139, 0, 255);
    for (int i = 0; i < figures.size(); ++i){
        edges = figures[i].getEdges();
        for (auto& it : edges){
            x = it.getBegin().getVertex().x;
            y = it.getBegin().getVertex().y;
            z = it.getBegin().getVertex().z;
            glVertex3f(x, y, z);
            x = it.getEnd().getVertex().x;
            y = it.getEnd().getVertex().y;
            z = it.getEnd().getVertex().z;
            glVertex3f(x, y, z);
        }
    }
    glEnd();
}
