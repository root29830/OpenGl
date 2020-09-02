#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QColor>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QtGui>
#include <QGLWidget>

#include "figure.h"


class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent = nullptr);
public slots:
    void  changeX(double x);
    void  changeY(double y);
    void  changeZ(double z);
    void  changeMouseFlag(bool f);

    //передаём параметры фигуры из формы
    void change1TypeFigure(int t);
    void change2x(double x);
    void change2y(double y);
    void change2z(double z);
    void change3a(double a);
    void change3b(double b);
    void change3c(double c);
    void changeColor(int c);

    void changeXangleRotate(double angle);
    void changeYangleRotate(double angle);
    void changeZangleRotate(double angle);

    void change_numFigur();

protected:
    virtual void paintGL();
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);

    virtual void   mousePressEvent(QMouseEvent* pe);
    virtual void   mouseMoveEvent(QMouseEvent* pe);

    //Колёсико мыши - отвечает за приближение
    virtual void wheelEvent(QWheelEvent *pe);
    void colorToRGB(QColor color);
    void createPoint(GLfloat x, GLfloat y, GLfloat z, QColor color);
    void createLine(GLfloat x1, GLfloat y1, GLfloat z1,
                    GLfloat x2, GLfloat y2, GLfloat z2, QColor color);
    void create_kube(GLfloat x, GLfloat y, GLfloat z, GLfloat a, QColor color);
    void createParallelepiped(GLfloat x, GLfloat y, GLfloat z,
                              GLfloat width, GLfloat height, GLfloat depth, QColor color);
    void createPyramid(GLfloat x, GLfloat y, GLfloat z,
                         GLfloat h, GLfloat p, QColor color);
    void createSphere(GLfloat x, GLfloat y, GLfloat z,
                    GLfloat r, int numDz, int numDx, QColor color);
    void createAllFigure();

    void onSelectType(int type, int number, double znachenie);
    void rotateFigure(int number);
    void deRotateFigure(int number);
private:

    int typeFigure; //0 нет фигуры
                    //1 точка
                    //2 прямая
                    //3 куб
                    //4 параллелепипед
                    //5 пирамида
                    //6 сфера
    GLuint Point[10], Pyramid; //видимо какой то тип OpenGL
    QPoint  mousePosition;
    GLfloat X_Rotete_xyz;
    GLfloat Y_Rotete_xyz;
    GLfloat Z_Rotete_xyz;
    GLfloat scale; //масштабироваине
    GLfloat m_Pos_X;
    GLfloat m_Pos_Y;
    GLfloat RGB[3];

    bool mouseFlag;

    int numFigure; //колличество фигур в целом
    Figure masFigur[50];
};


#endif // GLWIDGET_H
