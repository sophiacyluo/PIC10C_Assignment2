#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <algorithm>
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_next1_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_next2_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    double homework1 = ui->lineEdit_1->text().toDouble();
    double homework2 = ui->lineEdit_2->text().toDouble();
    double homework3 = ui->lineEdit_3->text().toDouble();
    double homework4 = ui->lineEdit_4->text().toDouble();
    double homework5 = ui->lineEdit_5->text().toDouble();
    double homework6 = ui->lineEdit_6->text().toDouble();
    double homework7 = ui->lineEdit_7->text().toDouble();

    vector<double> homeworks = {homework1, homework2, homework3, homework4, homework5, homework6, homework7};

    if(ui->lineEdit_8->text() != "N/A")
    {
        double homework8 = ui->lineEdit_8->text().toDouble();
        homeworks.push_back(homework8);
    }

    sort(homeworks.begin(), homeworks.end());

    double sum = 0;

    for(int i = 1; i < homeworks.size(); ++i)
    {
        sum = sum + homeworks[i];
    }

    double homework_grade = (sum / (homeworks.size() - 1)) * 0.25;

    double midterm1 = ui->lineEdit_9->text().toDouble();
    double midterm2 = ui->lineEdit_10->text().toDouble();
    double final = ui->lineEdit_11->text().toDouble();

    double midterm1_grade1 = midterm1 * 0.2;
    double midterm2_grade1 = midterm2 * 0.2;
    double final_grade1 = final * 0.35;

    double midterm_grade2 = 0;

    if(midterm1 > midterm2)
        midterm_grade2 = midterm1 * 0.3;
    else
        midterm_grade2 = midterm2 * 0.3;

    double final_grade2 = final * 0.44;

    double scheme1 = homework_grade + midterm1_grade1 + midterm2_grade1 + final_grade1;
    double scheme2 = homework_grade + midterm_grade2 + final_grade2;

    double overall = 0;

    if(scheme1 > scheme2)
        overall = scheme1;
    else
        overall = scheme2;

    QString overall1 = QString::number(scheme1);
    QString overall2 = QString::number(scheme2);
    QString overall3 = QString::number(overall);

    ui->lineEdit_12->setText(overall1);
    ui->lineEdit_13->setText(overall2);
    ui->lineEdit_14->setText(overall3);
}
