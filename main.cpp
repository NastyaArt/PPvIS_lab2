#include "mainwindow.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    DataBase base;


    QObject::connect(w.addWind, SIGNAL(SendDataAdd(Student)), &base, SLOT(RecieveDataAdd(Student)));
    QObject::connect(&base, SIGNAL(SendDataBase(QList<Student>)), &w, SLOT(UpdateData(QList<Student>)));

    QObject::connect(&w, SIGNAL(SaveDataBase(QString)), &base, SLOT(SaveDataBase(QString)));
    QObject::connect(&base, SIGNAL(SaveState(bool)), &w, SLOT(SaveState(bool)));

    QObject::connect(&w, SIGNAL(UploadDataBase(QString)), &base, SLOT(UploadDataBase(QString)));
    QObject::connect(&base, SIGNAL(UploadState(bool)), &w, SLOT(UploadState(bool)));

    QObject::connect(&w, SIGNAL(ClearDataBase()), &base, SLOT(ClearDataBase()));
    QObject::connect(&base, SIGNAL(DataBaseIsClear()), &w, SLOT(DataBaseIsClear()));

    QObject::connect(w.delWind, SIGNAL(SendDataDel1(QString, int)), &base, SLOT(RecieveDataDel1(QString, int)));
    QObject::connect(w.delWind, SIGNAL(SendDataDel2(QString, QString)), &base, SLOT(RecieveDataDel2(QString, QString)));
    QObject::connect(w.delWind, SIGNAL(SendDataDel3(QString, int, int, QString)), &base, SLOT(RecieveDataDel3(QString, int, int, QString)));
    QObject::connect(&base, SIGNAL(DelState(int)), &w, SLOT(DelState(int)));

    QObject::connect(w.srchWind, SIGNAL(SendDataSrch1(QString, int)), &base, SLOT(RecieveDataSrch1(QString, int)));
    QObject::connect(w.srchWind, SIGNAL(SendDataSrch2(QString, QString)), &base, SLOT(RecieveDataSrch2(QString, QString)));
    QObject::connect(w.srchWind, SIGNAL(SendDataSrch3(QString, int, int, QString)), &base, SLOT(RecieveDataSrch3(QString, int, int, QString)));
    QObject::connect(&base, SIGNAL(SrchState(int)), w.srchWind, SLOT(SrchState(int)));
    QObject::connect(&base, SIGNAL(SendDataSrch(QList<Student>)), w.srchWind, SLOT(UpdateDataSrch(QList<Student>)));

    QObject::connect(&w, SIGNAL(GetDataBase()), &base, SLOT(GetDataBase()));

    w.showMaximized();
    w.setWindowTitle("Общественная работа");

    return a.exec();
}
