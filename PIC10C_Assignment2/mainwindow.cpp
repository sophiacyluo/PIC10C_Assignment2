#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grade.h"

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
    Course course(ui->course_name->text());
    Scheme s(ui->course_name->text() + '1');
}
