#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    int homework1 = ui->lineEdit_1->text().toDouble();
    int homework2 = ui->lineEdit_2->text().toDouble();
    int homework3 = ui->lineEdit->text().toDouble();
    int homework4 = ui->lineEdit_4->text().toDouble();
    int homework5 = ui->lineEdit_5->text().toDouble();
    int homework6 = ui->lineEdit_6->text().toDouble();
    int homework7 = ui->lineEdit_7->text().toDouble();

    vector<int> homeworks = {homework1, homework2, homework3, homework4, homework5, homework6, homework7};

    if(ui->lineEdit_8->text() != "N/A")
    {
        int homework8 = ui->lineEdit_8->text().toDouble();
        homeworks.push_back(homework8);
    }
}
