#include "student.h"

Student::Student()
{
   // fio = new QString("");
    surname = ("");
    name = ("");
    fathername = ("");
    group = 0;

    for (int i = 0; i < 5; i++) {
        QString str;
        str = ("");
        works.append(str);
    }
    for (int i = 0; i < 5; i++)
        hours[i]=0;
}


Student::Student(QString Sname, QString Name, QString Fname, int gr, QList<QString> wrk, int hrs[])
{
  //  fio = FIO;
    surname = Sname;
    name = Name;
    fathername = Fname;
    group = gr;

    for (int i = 0; i < 5; i++) {
      //  QString str;
      //  str = wrk.at(i);
        works.append(wrk.at(i));
    }
    for (int i = 0; i < 5; i++)
        hours[i]=hrs[i];
}

const bool operator == (const Student &stud1, const Student &stud2)
{
    if(stud1.surname==stud2.surname)
    {
        if(stud1.name==stud2.name)
        {
            if(stud1.fathername==stud2.fathername)
            {
                if(stud1.group==stud2.group)
                {
                    for (int i = 0; i < 5; i++){
                        if(stud1.hours[i]!=stud2.hours[i] && stud1.works[i]!=stud2.works[i])
                        {
                           return false;
                        }
                        if(i=4) return true;
                    }

                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
