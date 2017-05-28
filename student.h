#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student // : public QObject
{
   // Q_OBJECT
public:
    Student();
    Student (QString Sname, QString Name, QString Fname, int gr, QList<QString> wrk, int hrs[]);

//private:

   // QString fio;
    QString surname;
    QString name;
    QString fathername;
    int group;
    QList<QString> works;
    int hours[5];

    friend const bool operator ==(const Student &stud1, const Student &stud2 ); //перегрузка ==

signals:

public slots:

};

#endif // STUDENT_H
