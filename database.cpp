#include "database.h"

DataBase::DataBase()
{

}


QList<Student> DataBase::AddStud(Student std)
{
    database.append(std);
    return database;
}

QList<Student> DataBase::SearchStud1(QString surname, int group)
{
    QList<Student> students;
    for (int st = 0; st < database.length(); st++){
        if (database.at(st).surname==surname && database.at(st).group==group)
        {
            students << database.at(st);
        }
    }
    return students;
}

QList<Student> DataBase::SearchStud2(QString surname, QString work)
{
    QList<Student> students;
    for (int st = 0; st < database.length(); st++){
        if (database.at(st).surname==surname)
        {
            for (int i = 0; i < 5; i++)
                if (database.at(st).works.at(i)==work){
                    students << database.at(st);
                    break;
                }
        }
    }
    return students;
}

QList<Student> DataBase::SearchStud3(QString surname, int timemin, int timemax, QString work)
{
    QList<Student> students;
    for (int st = 0; st < database.length(); st++){
        if (database.at(st).surname==surname)
        {
            for (int i = 0; i < 5; i++)
                if (database.at(st).works.at(i)==work){
                    if (database.at(st).hours[i]>=timemin && database.at(st).hours[i]<=timemax){
                        students << database.at(st);
                        break;
                    }
                }
        }
    }
    return students;
}
QList<Student> DataBase::DelStud1(QString surname, int group)
{
    QList<Student> students;
    students = SearchStud1(surname, group);
    for (int i = 0; i < students.length(); i++)
        database.removeAll(students.at(i));
    return database;
}

QList<Student> DataBase::DelStud2(QString surname, QString work)
{
    QList<Student> students;
    students = SearchStud2(surname, work);
    for (int i = 0; i < students.length(); i++)
        database.removeAll(students.at(i));
    return database;
}

QList<Student> DataBase::DelStud3(QString surname, int timemin, int timemax, QString work)
{
    QList<Student> students;
    students = SearchStud3(surname, timemin, timemax, work);
    for (int i = 0; i < students.length(); i++)
        database.removeAll(students.at(i));
    return database;
}

void DataBase::RecieveDataDel1(QString surname, int group)
{
    int colStd = database.length();
    database = DelStud1(surname, group);
    colStd = colStd - database.length();
    emit DelState(colStd);
    emit SendDataBase(database);
}

void DataBase::RecieveDataDel2(QString surname, QString work)
{
    int colStd = database.length();
    database = DelStud2(surname, work);
    colStd = colStd - database.length();
    emit DelState(colStd);
    emit SendDataBase(database);
}

void DataBase::RecieveDataDel3(QString surname, int timemin, int timemax, QString work)
{
    int colStd = database.length();
    database = DelStud3(surname, timemin, timemax, work);
    colStd = colStd - database.length();
    emit DelState(colStd);
    emit SendDataBase(database);
}

void DataBase::RecieveDataSrch1(QString surname, int group)
{
    QList<Student> students;
    students = SearchStud1(surname, group);
    emit SrchState(students.length());
    emit SendDataSrch(students);
}

void DataBase::RecieveDataSrch2(QString surname, QString work)
{
    QList<Student> students;
    students = SearchStud2(surname, work);
    emit SrchState(students.length());
    emit SendDataSrch(students);
}

void DataBase::RecieveDataSrch3(QString surname, int timemin, int timemax, QString work)
{
    QList<Student> students;
    students = SearchStud3(surname, timemin, timemax, work);
    emit SrchState(students.length());
    emit SendDataSrch(students);
}

QList<Student> DataBase::DelAllStud()
{
    database.clear();
    return database;
}

void DataBase::GetDataBase()
{
    emit SendDataBase(database);
}

void DataBase::ClearDataBase()
{
    database = DelAllStud();
    emit SendDataBase(database);
    emit DataBaseIsClear();
}

void DataBase::RecieveDataAdd(Student std)
{
    database = AddStud(std);
    emit SendDataBase(database);
}

void DataBase::SaveDataBase(QString filename)
{
    bool ok = true;

    /* Открываем файл для Записи */
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
        ok = false;
    else {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("students");

        for (int st = 0; st < database.length(); st++){
            xmlWriter.writeStartElement("student");

            xmlWriter.writeStartElement("surname");
            xmlWriter.writeCharacters(database.at(st).surname);
            xmlWriter.writeEndElement();

            xmlWriter.writeStartElement("name");
            xmlWriter.writeCharacters(database.at(st).name);
            xmlWriter.writeEndElement();

            xmlWriter.writeStartElement("fathername");
            xmlWriter.writeCharacters(database.at(st).fathername);
            xmlWriter.writeEndElement();

            xmlWriter.writeStartElement("group");
            xmlWriter.writeCharacters(QString::number(database.at(st).group));
            xmlWriter.writeEndElement();

            for (int n = 0; n < 5; n++){
                xmlWriter.writeStartElement("work");
                xmlWriter.writeAttribute("semestr", QString::number(n+1));
                xmlWriter.writeStartElement("workName");
                xmlWriter.writeCharacters(database.at(st).works.at(n));
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("time");
                xmlWriter.writeCharacters(QString::number(database.at(st).hours[n]));
                xmlWriter.writeEndElement();
                xmlWriter.writeEndElement();
            }

            xmlWriter.writeEndElement();
        }

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
        file.close();
    }
    emit SaveState(ok);
}

void DataBase::UploadDataBase(QString filename)
{
    bool ok = true;
    bool intOk = true;
    int num_semestr = 0;
    QString surname, name, fathername;
    int group;
    QList<QString> work;
    int time[5];
    database = DelAllStud();
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        ok = false;
    else {
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();

        while(!xmlReader.atEnd())
        {
           if(xmlReader.isStartElement())
           {
                if (xmlReader.name() == "student"){
                    surname = ("");
                    name = ("");
                    fathername = ("");
                    group = 0;
                    work.clear();
                    for (int i = 0; i < 5; i++)
                        time[i]=0;
                }
                else if (xmlReader.name() == "surname")
                    surname=xmlReader.readElementText();
                else if (xmlReader.name() == "name")
                    name=xmlReader.readElementText();
                else if (xmlReader.name() == "fathername")
                    fathername=xmlReader.readElementText();
                else if (xmlReader.name() == "group")
                    group=xmlReader.readElementText().toInt(&intOk, 10);
                else if (xmlReader.name() == "work"){
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if (attr.name().toString() == "semestr")
                            num_semestr = attr.value().toInt();
                    }
                }
                else if (xmlReader.name() == "workName")
                    work << xmlReader.readElementText();
                else if (xmlReader.name() == "time"){
                    time[num_semestr-1]=xmlReader.readElementText().toInt(&intOk, 10);
                    if (num_semestr == 5){
                        Student std(surname, name, fathername, group, work, time);
                        database = AddStud(std);
                    }
                }
           }
           xmlReader.readNext();
        }
        file.close();
    }
    emit SendDataBase(database);
    emit UploadState(ok);
}
