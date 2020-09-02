   #include "glwidget.h"
#include <QDebug>
#include <QtGui>

GLWidget::GLWidget(QWidget *parent /* = nullptr */): QOpenGLWidget { parent },
    X_Rotete_xyz(0), Y_Rotete_xyz(0), Z_Rotete_xyz(0), scale(0.5),
    mouseFlag(true),
    typeFigure(0),
    mousePosition(0, 0), m_Pos_X(0), m_Pos_Y(0)
{
    numFigure = 0;
    for(int i = 0;i < 50;i++)
    {
        masFigur[i].x = 0;
        masFigur[i].y = 0;
        masFigur[i].z = 0;
        masFigur[i].x2 = 1;
        masFigur[i].y2 = 1;
        masFigur[i].z2 = 1;
        masFigur[i].a = 1;
        masFigur[i].h = 1;
        masFigur[i].p = 1;
        masFigur[i].depth = 1;
        masFigur[i].width = 1;
        masFigur[i].height = 1;
        masFigur[i].color = Qt::white;
        masFigur[i].xRotate = 0;
        masFigur[i].yRotate = 0;
        masFigur[i].zRotate = 0;
        masFigur[i].r = 1;
        masFigur[i].typeFig = 0;
    }
}

//поворот относительно оси(левый нижний спин боксы)
void GLWidget::changeX(double x)
{
    X_Rotete_xyz = (GLfloat)x;
    update();
}

void GLWidget::changeY(double y)
{
    Y_Rotete_xyz = (GLfloat)y;
    update();
}

void GLWidget::changeZ(double z)
{
    Z_Rotete_xyz = (GLfloat)z;
    update();
}

void GLWidget::changeMouseFlag(bool f)
{
    mouseFlag = f;
}

//слоты по передаче параметров фигур
void GLWidget::change1TypeFigure(int t)
{
    masFigur[numFigure].typeFig = t;
    update();
}

void GLWidget::change2x(double x)
{
    masFigur[numFigure].x = x;
    update();
}

void GLWidget::change2y(double y)
{
    masFigur[numFigure].y = y;
    update();
}

void GLWidget::change2z(double z)
{
    masFigur[numFigure].z = z;
    update();
}

void GLWidget::change3a(double a)
{
    onSelectType(masFigur[numFigure].typeFig, 1, a);
    update();
}

void GLWidget::change3b(double b)
{
    onSelectType(masFigur[numFigure].typeFig, 2, b);
    update();
}

void GLWidget::change3c(double c)
{
    onSelectType(masFigur[numFigure].typeFig, 3, c);
    update();
}

void GLWidget::changeColor(int c)
{
    switch(c)
    {
        //порядок цветов:белый красный синий зелёный
        case 1:masFigur[numFigure].color = Qt::white;
            break;
        case 2:masFigur[numFigure].color = Qt::red;
            break;
        case 3:masFigur[numFigure].color = Qt::blue;
            break;
        case 4:masFigur[numFigure].color = Qt::green;
            break;
        //доп пункты
        case 5:
            break;
        case 6:
            break;
    }
    update();
}

void GLWidget::changeXangleRotate(double angle)
{
    masFigur[numFigure].xRotate = angle;
    update();
}

void GLWidget::changeYangleRotate(double angle)
{
    masFigur[numFigure].yRotate = angle;
    update();
}

void GLWidget::changeZangleRotate(double angle)
{
    masFigur[numFigure].zRotate = angle;
    update();
}

void GLWidget::change_numFigur()
{
    if(masFigur[numFigure].typeFig > 0 && numFigure < 50)
        numFigure++;
    if(numFigure > 0 && numFigure < 50)
    {
        switch(masFigur[numFigure].typeFig)
        {
            case 2:
                masFigur[numFigure].x2 = masFigur[numFigure - 1].x2;
                masFigur[numFigure].y2 = masFigur[numFigure - 1].y2;
                masFigur[numFigure].z2 = masFigur[numFigure - 1].z2;
                break;
            case 3:
                masFigur[numFigure].a = masFigur[numFigure - 1].a;
                break;
            case 4:
                masFigur[numFigure].width = masFigur[numFigure - 1].width;
                masFigur[numFigure].height = masFigur[numFigure - 1].height;
                masFigur[numFigure].height = masFigur[numFigure - 1].height;
                break;
            case 5:
                masFigur[numFigure].h = masFigur[numFigure - 1].h;
                masFigur[numFigure].p = masFigur[numFigure - 1].p;
                break;
            case 6:
                masFigur[numFigure].r = masFigur[numFigure - 1].r;
                break;
        }

        masFigur[numFigure].x = masFigur[numFigure - 1].x;
        masFigur[numFigure].y = masFigur[numFigure - 1].y;
        masFigur[numFigure].z = masFigur[numFigure - 1].z;
        masFigur[numFigure].color = masFigur[numFigure - 1].color;
        masFigur[numFigure].xRotate = masFigur[numFigure - 1].xRotate;
        masFigur[numFigure].yRotate = masFigur[numFigure - 1].yRotate;
        masFigur[numFigure].zRotate = masFigur[numFigure - 1].zRotate;
    }
    update();
}


void GLWidget::wheelEvent(QWheelEvent *pe)
{
        if (pe->delta() > 0)
            scale *= (GLfloat)1.1;
        if (pe->delta() < 0)
            scale /= (GLfloat)1.1;
        update();
}

void GLWidget::colorToRGB(QColor color)
{

        if(color == Qt::white){
            RGB[0] = 1.0;
            RGB[1] = 1.0;
            RGB[2] = 1.0;
        }
        if(color == Qt::black){
            RGB[0] = 0.0;
            RGB[1] = 0.0;
            RGB[2] = 0.0;
        }
        if(color == Qt::red){
            RGB[0] = 1.0;
            RGB[1] = 0.0;
            RGB[2] = 0.0;
        }
        if(color == Qt::darkRed){
            RGB[0] = 0.5;
            RGB[1] = 0.0;
            RGB[2] = 0.0;
        }
        if(color == Qt::green){
            RGB[0] = 0.0;
            RGB[1] = 1.0;
            RGB[2] = 0.0;
        }
        if(color == Qt::blue){
            RGB[0] = 0.0;
            RGB[1] = 0.0;
            RGB[2] = 1.0;
        }
        if(color == Qt::darkGreen){
            RGB[0] = 0.0;
            RGB[1] = 0.5;
            RGB[2] = 0.0;
        }
        if(color == Qt::darkBlue){
            RGB[0] = 0.0;
            RGB[1] = 0.0;
            RGB[2] = 0.5;
        }
        if(color == Qt::cyan){
            RGB[0] = 0.0;
            RGB[1] = 1.0;
            RGB[2] = 1.0;
        }
        if(color == Qt::darkCyan){
            RGB[0] = 0.0;
            RGB[1] = 0.5;
            RGB[2] = 0.5;
        }
        if(color == Qt::magenta){
            RGB[0] = 1.0;
            RGB[1] = 0.0;
            RGB[2] = 1.0;
        }
        if(color == Qt::darkMagenta){
            RGB[0] = 0.5;
            RGB[1] = 0.0;
            RGB[2] = 0.5;
        }
        if(color == Qt::yellow){
            RGB[0] = 1.0;
            RGB[1] = 1.0;
            RGB[2] = 0.0;
        }
        if(color == Qt::darkYellow){
            RGB[0] = 0.5;
            RGB[1] = 0.5;
            RGB[2] = 0.0;
        }
        if(color == Qt::gray){
            RGB[0] = 0.625;
            RGB[1] = 0.625;
            RGB[2] = 0.641f;
        }
        if(color == Qt::darkGray){
            RGB[0] = 0.5;
            RGB[1] = 0.5;
            RGB[2] = 0.5;
        }
        if(color == Qt::lightGray){
            RGB[0] = 0.75;
            RGB[1] = 0.75;
            RGB[2] = 0.75;
        }
}

void GLWidget::mousePressEvent(QMouseEvent *pe)
{
    if(mouseFlag)
    {
        mousePosition = pe->pos();
        qDebug() <<mousePosition;
    }
    qDebug() << pe->pos().x() <<pe->pos().y();
}

void GLWidget::mouseMoveEvent(QMouseEvent *pe)
{
    GLfloat w, h;
    w = width();
    h = height();
    if(mouseFlag)
    {
        X_Rotete_xyz = 180*(GLfloat)(pe->y() - mousePosition.y()) /height();
        Y_Rotete_xyz = 180*(GLfloat)(pe->x() - mousePosition.x()) /width();
        update();
    }
    else
    {
        m_Pos_X = 4*(1/scale)*(pe->pos().x() - w/2)/w;
        m_Pos_Y = -4*(1/scale)*(pe->pos().y() - h/2)/h;
        masFigur[numFigure].x = m_Pos_X;
        masFigur[numFigure].y = m_Pos_Y;
        update();
    }
}


void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    //glShadeModel(GL_FLAT);
    glShadeModel(GL_SMOOTH);

//createPoint(1.0f, 1.0f, 1.0f, Qt::cyan);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//сброс просмотра
    //glFrustum(-2.0, 2.0, -2.0, 2.0, 2.0, 6.0);
    glOrtho(-2.0, 2.0, -2.0, 2.0, 2.0, 6.0);
}


//------------------------------------------------------
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);

    glScalef(scale, scale, scale);
    glRotatef(X_Rotete_xyz, 1.0, 0.0, 0.0);
    glRotatef(Y_Rotete_xyz, 0.0, 1.0, 0.0);
    glRotatef(Z_Rotete_xyz, 0.0, 0.0, 1.0);

    glLineWidth(1.0);
    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-20.0, 0.0, 0.0);
        glVertex3f(20.0, 0.0, 0.0);

        glVertex3f(0.0, -20.0, 0.0);
        glVertex3f(0.0, 20.0, 0.0);

        glVertex3f(0.0, 0.0, -20.0);
        glVertex3f(0.0, 0.0, 20.0);
    glEnd();

    createAllFigure();

}

void GLWidget::createPoint(GLfloat x, GLfloat y, GLfloat z, QColor color)
{
    colorToRGB(color);
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glColor3f(RGB[0], RGB[1], RGB[2]);
        glVertex3f(x, y, z);
    glEnd();
}

void GLWidget::createLine(GLfloat x1, GLfloat y1, GLfloat z1,
                          GLfloat x2, GLfloat y2, GLfloat z2, QColor color)
{
    colorToRGB(color);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(RGB[0], RGB[1], RGB[2]);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
    glEnd();
}


void GLWidget::create_kube(GLfloat x, GLfloat y, GLfloat z,
                          GLfloat a, QColor color)
{
    colorToRGB(color);
    glLineWidth(1.0);
    glBegin(GL_QUADS);
        glColor3f(RGB[0], RGB[1], RGB[2]);
        //3 плоскости с центром  в т. x, y, z
        glVertex3f(x, y, z);
        glVertex3f(x + a, y, z);
        glVertex3f(x + a, y - a, z);
        glVertex3f(x, y - a, z);

        //glColor3f(1.0, 0.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(x + a, y, z);
        glVertex3f(x + a, y, z - a);
        glVertex3f(x, y, z - a);

        //glColor3f(0.0, 1.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(x, y, z - a);
        glVertex3f(x, y - a, z - a);
        glVertex3f(x, y - a, z);
        //

        //3 плоскости с центром в т x+a,y-a,z-a
        //glColor3f(0.0, 1.0, 0.0);
        glVertex3f(x + a, y - a, z - a);
        glVertex3f(x + a, y, z - a);
        glVertex3f(x + a, y, z);
        glVertex3f(x + a, y - a, z);

        //glColor3f(0.0, 1.0, 1.0);
        glVertex3f(x + a, y - a, z - a);
        glVertex3f(x + a, y, z - a);
        glVertex3f(x, y, z - a);
        glVertex3f(x, y - a, z - a);

        //glColor3f(1.0, 0.0, 0.0);
        glVertex3f(x + a, y - a, z - a);
        glVertex3f(x, y - a, z - a);
        glVertex3f(x, y - a, z);
        glVertex3f(x + a, y - a, z);
        glEnd();
}

void GLWidget::createParallelepiped(GLfloat x, GLfloat y, GLfloat z,
                                    GLfloat width, GLfloat height, GLfloat depth, QColor color)
{
    colorToRGB(color);
    glLineWidth(1.0);
    glBegin(GL_QUADS);
        glColor3f(RGB[0], RGB[1], RGB[2]);
        //3 плоскости с центром  в т. x, y, z
        glVertex3f(x, y, z);
        glVertex3f(x + width, y, z);
        glVertex3f(x + width, y - height, z);
        glVertex3f(x, y - height, z);

        //glColor3f(1.0, 0.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(x + width, y, z);
        glVertex3f(x + width, y, z - depth);
        glVertex3f(x, y, z - depth);

        //glColor3f(0.0, 1.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(x, y, z - depth);
        glVertex3f(x, y - height, z - depth);
        glVertex3f(x, y - height, z);
        //

        //3 плоскости с центром в т x+a,y-a,z-a
        //glColor3f(0.0, 1.0, 0.0);
        glVertex3f(x + width, y - height, z - depth);
        glVertex3f(x + width, y, z - depth);
        glVertex3f(x + width, y, z);
        glVertex3f(x + width, y - height, z);

        //glColor3f(0.0, 1.0, 1.0);
        glVertex3f(x + width, y - height, z - depth);
        glVertex3f(x + width, y, z - depth);
        glVertex3f(x, y, z - depth);
        glVertex3f(x, y - height, z - depth);

        //glColor3f(1.0, 0.0, 0.0);
        glVertex3f(x + width, y - height, z - depth);
        glVertex3f(x, y - height, z - depth);
        glVertex3f(x, y - height, z);
        glVertex3f(x + width, y - height, z);
        glEnd();
}

void GLWidget::createSphere(GLfloat x, GLfloat y, GLfloat z,
                            GLfloat r, int numDz, int numDx, QColor color)
{
    colorToRGB(color);
    int i, j;
    for(i = 0; i <= numDz; i++)
    {
        GLfloat alfa1 = M_PI * (-0.5 + (GLfloat) (i - 1) / numDz);
        GLfloat zsin0  = sin(alfa1);
        GLfloat zcos0 = cos(alfa1);

        GLfloat alfa2 = M_PI * (-0.5 + (GLfloat) i / numDz);
        GLfloat zsin1 = sin(alfa2);
        GLfloat zcos1 = cos(alfa2);

        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= numDx; j++)
        {
            GLfloat betha = 2 * M_PI * (GLfloat) (j - 1) / numDx;
            GLfloat xcos = cos(betha);
            GLfloat ysin = sin(betha);

            glColor3f(RGB[0], RGB[1], RGB[2]);
            glVertex3f(x + r * xcos * zcos0, y + r * ysin * zcos0, z + r * zsin0);
            glVertex3f(x + r * xcos * zcos1, y + r * ysin * zcos1, z + r * zsin1);
        }
        glEnd();
    }
}


void GLWidget::createPyramid(GLfloat x, GLfloat y, GLfloat z,
                               GLfloat h, GLfloat p, QColor color)
{
    colorToRGB(color);
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(RGB[0], RGB[1], RGB[2], 1.0f);
        glVertex3f(x, y, z);
        glVertex3f(x - p/2, y - h, z - p/2);
        glVertex3f(x + p/2, y - h, z - p/2);

        //glColor4f(RGB[0], RGB[1], RGB[2], 1.0f);
        glVertex3f(x + p/2, y - h, z + p/2);

        //glColor4f(RGB[0], RGB[1], RGB[2], 1.0f);
        glVertex3f(x - p/2, y - h, z + p/2);

        //glColor4f(RGB[0], RGB[1], RGB[2], 1.0f);
        glVertex3f(x - p/2, y - h, z - p/2);
        glEnd();

        glBegin(GL_QUADS);
            glColor4f(RGB[0], RGB[1], RGB[2], 1.0f);
            glVertex3f(x - p/2, y - h, z - p/2);
            glVertex3f(x + p/2, y - h, z - p/2);
            glVertex3f(x + p/2, y - h, z + p/2);
            glVertex3f(x - p/2, y - h, z + p/2);
     glEnd();
}

void GLWidget::createAllFigure()
{
    int max = 0;
    if (numFigure > 50)
        max = 50;
    else
        max = numFigure + 1;
    for(int i = 0;i < max;i++)
    {
        switch(masFigur[i].typeFig)
        {
            case 0:qDebug() <<"Фигура не выбрана!\nError";
                break;
            case 1:
            rotateFigure(i);
            createPoint(masFigur[i].x, masFigur[i].y, masFigur[i].z,
                        masFigur[i].color);
            deRotateFigure(i);
                break;
            case 2:
            rotateFigure(i);
            createLine(masFigur[i].x, masFigur[i].y, masFigur[i].z,
                       masFigur[i].x2, masFigur[i].y2, masFigur[i].z2,
                       masFigur[i].color);
            //deRotateFigure(i);
                break;
            case 3:
            rotateFigure(i);
            create_kube(masFigur[i].x, masFigur[i].y, masFigur[i].z,
                       masFigur[i].a, masFigur[i].color);
            deRotateFigure(i);
                break;
            case 4:
            rotateFigure(i);
            createParallelepiped(masFigur[i].x, masFigur[i].y, masFigur[i].z,
                                 masFigur[i].width, masFigur[i].height, masFigur[i].depth,
                                 masFigur[i].color);
            deRotateFigure(i);
                break;
            case 5:
            rotateFigure(i);
            createPyramid(masFigur[i].x, masFigur[i].y, masFigur[i].z,
                          masFigur[i].h, masFigur[i].p, masFigur[i].color);
            deRotateFigure(i);
                break;
            case 6:
            rotateFigure(i);
            createSphere(masFigur[i].x, masFigur[i].y, masFigur[i].z,
                         masFigur[i].r, 20, 20, masFigur[i].color);
            deRotateFigure(i);
                break;
            default:qDebug() <<"Фигура не выбрана! Неизвестная ошибка \nError";
                break;
        }
    }
}

void GLWidget::onSelectType(int type, int number, double znachenie)
{
    switch(type)
    {
    case 2:qDebug() <<number;
        switch(number)
        {
        case 1:masFigur[numFigure].x2 = znachenie;
                break;
        case 2:masFigur[numFigure].y2 = znachenie;
            break;
        case 3:masFigur[numFigure].z2 = znachenie;
            break;
        }
        break;

    case 3:
        masFigur[numFigure].a = znachenie;
        break;
    case 4:
        switch(number)
        {
        case 1:masFigur[numFigure].width = znachenie;
                break;
        case 2:masFigur[numFigure].height = znachenie;
            break;
        case 3:masFigur[numFigure].depth = znachenie;
            break;
        }
        break;
    case 5:
        switch(number)
        {
        case 1:masFigur[numFigure].h = znachenie;
                break;
        case 2:

            masFigur[numFigure].p = znachenie;
            break;
        }
        break;
    case 6:masFigur[numFigure].r = znachenie;
        break;
    }
}

void GLWidget::rotateFigure(int number)
{
//    glTranslatef(masFigur[number].x, masFigur[number].y, masFigur[number].z);
    glRotatef(masFigur[number].xRotate, 1.0, 0.0, 0.0);
    glRotatef(masFigur[number].yRotate, 0.0, 1.0, 0.0);
    glRotatef(masFigur[number].zRotate, 0.0, 0.0, 1.0);
}

void GLWidget::deRotateFigure(int number)
{
    glRotatef(-masFigur[number].zRotate, 0.0, 0.0, 1.0);
    glRotatef(-masFigur[number].yRotate, 0.0, 1.0, 0.0);
    glRotatef(-masFigur[number].xRotate, 1.0, 0.0, 0.0);
//    glTranslatef(-masFigur[number].x, -masFigur[number].y, -masFigur[number].z);
}
