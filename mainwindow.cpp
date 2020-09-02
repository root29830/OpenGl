#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(this, &MainWindow::on_doubleSpinBox_valueChanged,
                     ui->GLwidget, &GLWidget::changeX);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_2_valueChanged,
                     ui->GLwidget, &GLWidget::changeY);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_3_valueChanged,
                     ui->GLwidget, &GLWidget::changeZ);
    QObject::connect(this, &MainWindow::changeMouseFlag,
                     ui->GLwidget, &GLWidget::changeMouseFlag);


    QObject::connect(this, &MainWindow::on_comboBox_currentIndexChanged,
                     this, &MainWindow::comboBoxIndexChanged);


    QObject::connect(this, &MainWindow::on_comboBox_currentIndexChanged,
                     ui->GLwidget, &GLWidget::change1TypeFigure);
    QObject::connect(this, &MainWindow::on_comboBox_4Punkt_currentIndexChanged,
                     ui->GLwidget, &GLWidget::changeColor);

    QObject::connect(this, &MainWindow::on_doubleSpinBox_4_valueChanged,
                     ui->GLwidget, &GLWidget::change2x);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_5_valueChanged,
                     ui->GLwidget, &GLWidget::change2y);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_6_valueChanged,
                     ui->GLwidget, &GLWidget::change2z);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_3P1_valueChanged,
                     ui->GLwidget, &GLWidget::change3a);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_3P2_valueChanged,
                     ui->GLwidget, &GLWidget::change3b);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_3P3_valueChanged,
                     ui->GLwidget, &GLWidget::change3c);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_5p1_valueChanged,
                     ui->GLwidget, &GLWidget::changeXangleRotate);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_5p2_valueChanged,
                     ui->GLwidget, &GLWidget::changeYangleRotate);
    QObject::connect(this, &MainWindow::on_doubleSpinBox_5p3_valueChanged,
                     ui->GLwidget, &GLWidget::changeZangleRotate);

    QObject::connect(this, &MainWindow::on_pushButton_clicked,
                     ui->GLwidget, &GLWidget::change_numFigur);
//    QObject::connect(this, &MainWindow::on_pushButton_clicked,
//                     ui->GLwidget->, &GLWidget::on_comboBox_currentIndexChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 > 0) changeMouseFlag(true);
    if(arg1 == 0) changeMouseFlag(false);
}

void MainWindow::comboBoxIndexChanged(int index)
{
    switch(index)
    {   //0 нет фигуры
        //1 точка
        case 1: ui->label_3Punkt->setVisible(false);
                ui->label_3p1->setVisible(false);
                ui->label_3p2->setVisible(false);
                ui->label_3p3->setVisible(false);
                ui->doubleSpinBox_3P1->setVisible(false);
                ui->doubleSpinBox_3P2->setVisible(false);
                ui->doubleSpinBox_3P3->setVisible(false);

                ui->label_2Punkt->setText("2.Введите координаты точки");
                ui->label_2p1->setText("X");
                ui->label_2p2->setText("Y");
                ui->label_2p3->setText("Z");
                ui->label_4Punkt->setText("3.Выберете цвет фигуры");
                ui->label_5Punkt->setText("4. Введите угол поворота");
            break;
        //2 прямая
        case 2: //setVisible(true);
                ui->label_3Punkt->setVisible(true);
                ui->label_3p1->setVisible(true);
                ui->label_3p2->setVisible(true);
                ui->label_3p3->setVisible(true);
                ui->doubleSpinBox_3P1->setVisible(true);
                ui->doubleSpinBox_3P2->setVisible(true);
                ui->doubleSpinBox_3P3->setVisible(true);

                ui->label_2Punkt->setText("2.Введите координаты\n начальной точки");
                ui->label_2p1->setText("X1");
                ui->label_2p2->setText("Y1");
                ui->label_2p3->setText("Z1");
                ui->label_3Punkt->setText("3.Введите координаты\n конечной точки");
                ui->label_3p1->setText("X2");
                ui->label_3p2->setText("Y2");
                ui->label_3p3->setText("Z2");
                ui->label_4Punkt->setText("4.Выберете цвет фигуры");
                ui->label_5Punkt->setText("5.Введите угол поворота");
            break;
        //3 куб
        case 3:
                ui->label_3Punkt->setVisible(true);
                ui->label_3p1->setVisible(true);
                ui->doubleSpinBox_3P1->setVisible(true);

                ui->label_3p2->setVisible(false);
                ui->label_3p3->setVisible(false);
                ui->doubleSpinBox_3P2->setVisible(false);
                ui->doubleSpinBox_3P3->setVisible(false);

                ui->label_2Punkt->setText("2.Введите координаты\n верхнего левого угла");
                ui->label_3Punkt->setText("3.Введите длину стороны\n куба");
                ui->label_4Punkt->setText("4.Выберете цвет фигуры");
                ui->label_5Punkt->setText("5.Введите угол поворота");

            break;
        //4 параллелепипед
        case 4:
                ui->label_3Punkt->setVisible(true);
                ui->label_3p1->setVisible(true);
                ui->label_3p2->setVisible(true);
                ui->label_3p3->setVisible(true);
                ui->doubleSpinBox_3P1->setVisible(true);
                ui->doubleSpinBox_3P2->setVisible(true);
                ui->doubleSpinBox_3P3->setVisible(true);

                ui->label_2Punkt->setText("2.Введите координаты\n верхнего левого угла");
                ui->label_3Punkt->setText("3.Введите размеры\n параллелепипеда");
                ui->label_4Punkt->setText("4.Выберете цвет фигуры");
                ui->label_5Punkt->setText("5.Введите угол поворота");

                ui->label_3p1->setText("Длина");
                ui->label_3p2->setText("Высота");
                ui->label_3p3->setText("Глубина");

            break;
        //5 пирамида
        case 5:
                ui->label_3Punkt->setVisible(true);
                ui->label_3p1->setVisible(true);
                ui->label_3p2->setVisible(true);
                ui->doubleSpinBox_3P1->setVisible(true);
                ui->doubleSpinBox_3P2->setVisible(true);

                ui->label_3p3->setVisible(false);
                ui->doubleSpinBox_3P3->setVisible(false);

                ui->label_2Punkt->setText("2.Введите координаты\n вершины");
                ui->label_3Punkt->setText("3.Введите размеры\n пирамиды");
                ui->label_4Punkt->setText("4.Выберете цвет фигуры");
                ui->label_5Punkt->setText("5.Введите угол поворота");

                ui->label_3p1->setText("Высота");
                ui->label_3p2->setText("Длина основания");

            break;
        //6 сфера
        case 6:
                ui->label_3Punkt->setVisible(true);
                ui->label_3p1->setVisible(true);
                ui->doubleSpinBox_3P1->setVisible(true);

                ui->label_3p2->setVisible(false);
                ui->label_3p3->setVisible(false);
                ui->doubleSpinBox_3P2->setVisible(false);
                ui->doubleSpinBox_3P3->setVisible(false);

                ui->label_2Punkt->setText("2.Введите координаты\n центра");
                ui->label_3Punkt->setText("3.Введите длину радиуса");
                ui->label_4Punkt->setText("4.Выберете цвет фигуры");
                ui->label_5Punkt->setText("5.Введите угол поворота");

                ui->label_3p1->setText("Радиус");

            break;
        default:qDebug() <<"Фигура не выбрана! ror меню";
            break;
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->GLwidget->change_numFigur();
    ui->GLwidget->change1TypeFigure(ui->comboBox->currentIndex());
}
