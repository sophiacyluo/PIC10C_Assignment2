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

void MainWindow::on_confirmButton_clicked()
{

}

void MainWindow::on_course_name_textEdited(const QString &arg1)
{
    QString course_name = arg1;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    int schemes = arg1;
}
