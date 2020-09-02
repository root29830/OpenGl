#ifndef FIGURE_H
#define FIGURE_H
#include <QtOpenGL>

struct Figure
{
//    Figure(GLfloat X, GLfloat Y, GLfloat Z, GLfloat X2, GLfloat Y2, GLfloat Z2,
//           GLfloat A, GLfloat Width, GLfloat Height, GLfloat Depth,
//           GLfloat H, GLfloat P,
//           GLfloat XRotate, GLfloat YRotate, GLfloat ZRotate,
//           int TypeFig);
    //for all
    GLfloat x, y, z;
    //Line
    GLfloat x2, y2, z2;
    //Cube
    GLfloat a;
    //Parallelepiped
    GLfloat width, height, depth;
    //Piramid
    GLfloat h, p;
    GLfloat r;
    GLfloat xRotate, yRotate, zRotate;
    QColor color;
    int typeFig;//0 нет фигуры
    //1 точка
    //2 прямая
    //3 куб
    //4 параллелепипед
    //5 пирамида
    //6 сфера

};

#endif // FIGURE_H
