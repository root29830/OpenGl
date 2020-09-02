#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figure.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_doubleSpinBox_2_valueChanged(double arg1);
    void on_doubleSpinBox_3_valueChanged(double arg1);
    void on_doubleSpinBox_4_valueChanged(double arg1);
    void on_doubleSpinBox_5_valueChanged(double arg1);
    void on_doubleSpinBox_6_valueChanged(double arg1);
    void on_doubleSpinBox_3P1_valueChanged(double arg1);
    void on_doubleSpinBox_3P2_valueChanged(double arg1);
    void on_doubleSpinBox_3P3_valueChanged(double arg1);   
    void on_doubleSpinBox_5p1_valueChanged(double arg1);
    void on_doubleSpinBox_5p2_valueChanged(double arg1);
    void on_doubleSpinBox_5p3_valueChanged(double arg1);

    void on_comboBox_currentIndexChanged(int index);
    void on_comboBox_4Punkt_currentIndexChanged(int index);

    void changeMouseFlag(bool f);

private slots:
    void on_checkBox_stateChanged(int arg1);
    void comboBoxIndexChanged(int index);

void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
