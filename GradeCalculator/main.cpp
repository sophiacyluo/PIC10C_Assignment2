#include "dialog.h"
#include <QApplication>

#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

void Write(QString Filename)
{
    QFile mFile(Filename);

    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "could not open file for writing";
        return;
    }

    QTextStream out(&mFile);
    out << "It worked!!";

    mFile.flush();
    mFile.close();
}

void Read(QString Filename)
{
    QFile mFile(Filename);

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "could not open file for reading";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;

    mFile.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    QString filename = "/Users/sophialuo/test.txt";
    Write(filename);

    return a.exec();
}
