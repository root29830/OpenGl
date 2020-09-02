#include "mainwindow.h"
#include <QApplication>
#include <QGLWidget>
#include <QDebug>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow w;

    qDebug() <<"qewr" ;
    w.show();
    return a.exec();
}
