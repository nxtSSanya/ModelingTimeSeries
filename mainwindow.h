#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <qvector.h>
#include <QVector>
#include <fstream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    double xBegin, xEnd, h, X;
    QVector<double> x,y;
    double sumT4 = 0, sumY = 0, sumT2 = 0, sumYT2 = 0, sumT = 0, sumYT = 0, sumT3=0;
    double sumLN = 0, sumLN2 = 0, sumYLNT = 0;
    double sumYX =0, sumX1=0, sumX1_2=0;
    double averageY = 0;
};

#endif // MAINWINDOW_H
