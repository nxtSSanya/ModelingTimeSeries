#define CRT_SECURE_NO_WARNINGS
#include "mainwindow.h"
#include "ui_mainwindow.h"

static int isPressed=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile aFile("C:/Users/SanyaBooster/Documents/Trend/Input.txt");
    QTextStream qwqe(&aFile);
    QString time = "", values ="";
    x.resize(50);
    aFile.open(QIODevice::ReadOnly);
    for(int i =0;i<50;++i) { qwqe>>x[i]; }
    for(int i =0;i<50;++i) {y.push_back(i+1); time+=QString::number(y[i]) + "\t"; }
    for(int i =0 ;i< 50;++i){
        sumY+=x[i];
        sumT+=i+1;
        sumT2+=(i+1)*(i+1);
        sumT4+=std::pow(y[i], 4.);
        sumT3+=std::pow(y[i], 3.);
        sumYT2+=y[i]*y[i]*x[i];
        sumYT+=x[i]*(i+1);
        sumLN+=log(y[i]);
        sumYLNT+=x[i]*log(y[i]);
        sumLN2+=log(y[i])*log(y[i]);
        sumYX+=x[i]/y[i];
        sumX1+=1/y[i];
        sumX1_2+=1/(y[i]*y[i]);
    }
    averageY += sumY / 50.;   
    for(auto&i:x){
        values+=QString::number(i) + "\t";
    }
    ui->textBrowser_2->setText("Time serie:\n" + time + "\n\n\n" + "Values:\n" + values);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->addGraph();
    ui->widget->graph(isPressed)->addData(y, x);
    ui->widget->rescaleAxes();
    ui->widget->replot();
    isPressed++;
}

void MainWindow::on_pushButton_2_clicked()
{
    double detMatrix = (50 * sumT2 * sumT4) - (50 * sumT3 * sumT3) - (sumT * sumT * sumT4) + (sumT * sumT3 * sumT2) + (sumT2 * sumT * sumT3) - (sumT2 * sumT2 * sumT2);
    double detMatrix1 = (sumY * sumT2 * sumT4) - (sumY * sumT3 * sumT3) - (sumT * sumYT *sumT4) + (sumT * sumT3 * sumYT2) + (sumT2 * sumYT * sumT3) - (sumT2 * sumT2 * sumYT2);
    double detMatrix2 = (50 * sumYT * sumT4) - (50 * sumT3 * sumYT2) - (sumY * sumT * sumT4) + (sumY * sumT3 * sumT2) + (sumT2 * sumT * sumYT2) - (sumT2 * sumYT * sumT2);
    double detMatrix3 = (50 * sumT2 * sumYT2) - (50 * sumYT * sumT3) - (sumT * sumT * sumYT2) + (sumT * sumYT * sumT2) + (sumY * sumT * sumT3) - (sumY * sumT2 * sumT2);
    QVector<double> approx;
    double sumYPR = 0, sumDIF_Y = 0;
    for(int i =0;i<50;++i){
        approx.push_back((detMatrix1 / detMatrix) + (detMatrix2 / detMatrix)* y[i] + (detMatrix3 / detMatrix)*std::pow(y[i],2));
    }
     for(const auto&i :approx){
         sumYPR+= std::pow((i - averageY), 2);
    }
     for(const auto&i: x){
         sumDIF_Y += std::pow((i - averageY), 2);
     }
    ui->widget->addGraph();
    ui->widget->graph()->setPen(QPen(QColor("#00FF00")));
    ui->widget->graph(isPressed)->addData(y, approx);
    ui->widget->replot();
    QString text_b0 = QString::number((detMatrix1 / detMatrix), 'g', 4);
    QString text_b1 = QString::number((detMatrix2 / detMatrix), 'g', 4);
    QString text_b2 = QString::number((detMatrix3 / detMatrix), 'g', 4);
    ui->textBrowser->setText("y^2(t) = " + text_b0 + " + " + text_b1+"*t "+text_b2+"*t^2\n" + "Determination coefficient: " + QString::number((sumYPR/sumDIF_Y), 'g', 4));
    isPressed++;
}

void MainWindow::on_pushButton_3_clicked()
{
    double a0 = (50*sumYX-sumX1*sumY)/(50*sumX1_2-sumX1*sumX1);
    double a1 = (1/50.)*sumY-(1/50.)*a0*sumX1;
    QVector<double> linear_approx;
    double sumYPR = 0, sumDIF_Y = 0;
    for(int i =0;i<50;++i){
        linear_approx.push_back(a1 + a0/(i+1));
    }
    for(const auto&i :linear_approx){
        sumYPR+= std::pow((i - averageY), 2);
   }
    for(const auto&i: x){
        sumDIF_Y += std::pow((i - averageY), 2);
    }
    ui->widget->addGraph();
    ui->widget->graph()->setPen(QPen(QColor("#FF1493")));
    ui->widget->graph(isPressed)->addData(y, linear_approx);
    ui->widget->replot();
    QString text_a0 = QString::number(a0, 'g', 4);
    QString text_a1 = QString::number(a1, 'g', 4);
    ui->textBrowser->setText("y(t) = " + text_a0 + " + " + text_a1+"/t\n" + "Determination coefficient: " + QString::number((sumYPR/sumDIF_Y), 'g', 4));
    isPressed++;
}

void MainWindow::on_pushButton_4_clicked()
{
    double a = (sumY*sumLN2 - sumYLNT*sumLN)/(50*sumLN2 - sumLN*sumLN);
    double b = (50*sumYLNT-sumY*sumLN) / (50*sumLN2 - sumLN*sumLN);
    double sumYPR = 0, sumDIF_Y = 0;
    QVector<double> log_approx;
    for(int i =1;i<50;++i){
        log_approx.push_back(a+b*log(i));
    }
    for(const auto&i :log_approx){
        sumYPR+= std::pow((i - averageY), 2);
   }
    for(const auto&i: x){
        sumDIF_Y += std::pow((i - averageY), 2);
    }
    ui->widget->addGraph();
    ui->widget->graph()->setPen(QPen(QColor("red")));
    ui->widget->graph(isPressed)->addData(y, log_approx);
    ui->widget->replot();
    QString text_a = QString::number(a, 'g', 4);
    QString text_b = QString::number(b, 'g', 4);
    ui->textBrowser->setText("y(t) = " + text_a + " + " + text_b+"*ln(t)\n" + "Determination coefficient: " + QString::number((sumYPR/sumDIF_Y), 'g', 4));
    isPressed++;
}
