#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QFile>
#include "student.h"

class DataBase : public QObject
{
    Q_OBJECT
public:
    DataBase();
    QList<Student> AddStud(Student std);
    QList<Student> SearchStud1(QString surname, int group);
    QList<Student> DelStud1(QString surname, int group);
    QList<Student> SearchStud2(QString surname, QString work);
    QList<Student> DelStud2(QString surname, QString work);
    QList<Student> SearchStud3(QString surname, int timemin, int timemax, QString work);
    QList<Student> DelStud3(QString surname, int timemin, int timemax, QString work);
    QList<Student> DelAllStud();

private:

 //   int colDel;
    QList<Student> database;


signals:

    void SendDataBase(QList<Student> database);
    void SaveState(bool ok);
    void UploadState(bool ok);
    void DataBaseIsClear();
    void DelState(int colStd);
    void SrchState(int colStd);
    void SendDataSrch(QList<Student> students);

public slots:

    void ClearDataBase();
    void RecieveDataAdd(Student std);
    void SaveDataBase(QString filename);
    void UploadDataBase(QString filename);
    void RecieveDataDel1(QString fio, int group);
    void RecieveDataDel2(QString surname, QString work);
    void RecieveDataDel3(QString surname, int timemin, int timemax, QString work);
    void RecieveDataSrch1(QString fio, int group);
    void RecieveDataSrch2(QString surname, QString work);
    void RecieveDataSrch3(QString surname, int timemin, int timemax, QString work);
    void GetDataBase();

};

#endif // DATABASE_H
