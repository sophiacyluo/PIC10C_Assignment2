#include "mainwindow.h"
#include "ui_mainwindow.h"

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
