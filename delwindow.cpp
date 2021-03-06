#include "delwindow.h"

DelWindow::DelWindow()
{
    setModal(true);

    box1 = new QGroupBox("Поиск по фамилии и номеру группы студента");

    butDel1 = new QPushButton("Удалить запись(и)");
    butClr1 = new QPushButton("Очистить поля ввода");

    lbl11 = new QLabel("Фамилия студента");
    lbl12 = new QLabel("Номер группы");

    line11 = new QLineEdit;
    line12 = new QLineEdit;

    QVBoxLayout *lay11 = new QVBoxLayout;
    lay11->addWidget(lbl11);
    lay11->addWidget(lbl12);

    QVBoxLayout *lay12 = new QVBoxLayout;
    lay12->addWidget(line11);
    lay12->addWidget(line12);

    QVBoxLayout *lay13 = new QVBoxLayout;
    lay13->addWidget(butDel1);
    lay13->addWidget(butClr1);

    QHBoxLayout *lay14 = new QHBoxLayout;
    lay14->addLayout(lay11);
    lay14->addLayout(lay12);
    lay14->addLayout(lay13);

    box1->setLayout(lay14);

    box2 = new QGroupBox("Поиск по фамилии и виду общественной работы");

    butDel2 = new QPushButton("Удалить запись(и)");
    butClr2 = new QPushButton("Очистить поля ввода");

    lbl21 = new QLabel("Фамилия студента");
    lbl22 = new QLabel("Вид общественной работы");

    line21 = new QLineEdit;
    line22 = new QLineEdit;

    QVBoxLayout *lay21 = new QVBoxLayout;
    lay21->addWidget(lbl21);
    lay21->addWidget(lbl22);

    QVBoxLayout *lay22 = new QVBoxLayout;
    lay22->addWidget(line21);
    lay22->addWidget(line22);

    QVBoxLayout *lay23 = new QVBoxLayout;
    lay23->addWidget(butDel2);
    lay23->addWidget(butClr2);

    QHBoxLayout *lay24 = new QHBoxLayout;
    lay24->addLayout(lay21);
    lay24->addLayout(lay22);
    lay24->addLayout(lay23);

    box2->setLayout(lay24);

    box3 = new QGroupBox("Поиск по фамилии и количеству часов вида обественной работы");

    butDel3 = new QPushButton("Удалить запись(и)");
    butClr3 = new QPushButton("Очистить поля ввода");

    lbl31 = new QLabel("Фамилия студента");
    lbl32 = new QLabel("Количество часов: от ");
    lbl33 = new QLabel("до");
    lbl34 = new QLabel("Вид общественной работы");

    line31 = new QLineEdit;
    line32 = new QLineEdit;
    line33 = new QLineEdit;
    line34 = new QLineEdit;

    QHBoxLayout *lay31 = new QHBoxLayout;
    lay31->addWidget(lbl32);
    lay31->addWidget(line32);
    lay31->addWidget(lbl33);
    lay31->addWidget(line33);
    lay31->addWidget(butClr3);

    QHBoxLayout *lay32 = new QHBoxLayout;
    lay32->addWidget(lbl31);
    lay32->addWidget(line31);
    lay32->addWidget(butDel3);

    QHBoxLayout *lay33 = new QHBoxLayout;
    lay33->addWidget(lbl34);
    lay33->addWidget(line34);

    QVBoxLayout *lay34 = new QVBoxLayout;
    lay34->addLayout(lay32);
    lay34->addLayout(lay31);
    lay34->addLayout(lay33);

    box3->setLayout(lay34);

    connect(butDel1, SIGNAL(clicked(bool)), this, SLOT(PushButtonDel1()));
    connect(butClr1, SIGNAL(clicked(bool)), this, SLOT(PushButtonClr1()));
    connect(butDel2, SIGNAL(clicked(bool)), this, SLOT(PushButtonDel2()));
    connect(butClr2, SIGNAL(clicked(bool)), this, SLOT(PushButtonClr2()));
    connect(butDel3, SIGNAL(clicked(bool)), this, SLOT(PushButtonDel3()));
    connect(butClr3, SIGNAL(clicked(bool)), this, SLOT(PushButtonClr3()));

    QVBoxLayout *layall = new QVBoxLayout;
    layall->addWidget(box1);
    layall->addWidget(box2);
    layall->addWidget(box3);
    setLayout(layall);
    setWindowTitle("Удаление записи");

}


void DelWindow::PushButtonDel1()
{
    bool ok;
    if (line11->text()==NULL)
        checkFull = false;
    if (line12->text()==NULL)
        checkFull = false;

    checkFIO = fio.exactMatch (line11->text());
    line12->text().toInt(&checkNum, 10);

    if (checkFull==false)
        (new QErrorMessage(this))->showMessage("Введите все данные!");
    else
    if (checkFIO==false)
        (new QErrorMessage(this))->showMessage("В поле <b>Фамилия студента</b> введено некорректное значение!");
    else
    if (checkNum==false)
        (new QErrorMessage(this))->showMessage("В поле <b>Номер группы</b> должно быть введено целое число!");
    else {
        close();
        emit SendDataDel1(line11->text(), line12->text().toInt(&ok, 10));
    }
    checkFull = checkNum = checkFIO = true;
}

void DelWindow::PushButtonDel2()
{
    if (line21->text()==NULL)
        checkFull = false;
    if (line22->text()==NULL)
        checkFull = false;

    checkFIO = fio.exactMatch (line21->text());

    if (checkFull==false)
        (new QErrorMessage(this))->showMessage("Введите все данные!");
    else
    if (checkFIO==false)
        (new QErrorMessage(this))->showMessage("В поле <b>Фамилия студента</b> введено некорректное значение!");
    else {
        close();
        emit SendDataDel2(line21->text(), line22->text());
    }
    checkFull = checkFIO = true;
}

void DelWindow::PushButtonDel3()
{
    bool ok=false;
    checkNum = false;
    if (line31->text()==NULL)
        checkFull = false;
    else
    if (line32->text()==NULL)
        checkFull = false;
    else
    if (line33->text()==NULL)
        checkFull = false;
    else
    if (line34->text()==NULL)
        checkFull = false;

    checkFIO = fio.exactMatch (line31->text());

    line32->text().toInt(&ok, 10);
    if (ok == true){
        line32->text().toInt(&ok, 10);
        if (ok == true){
            checkNum = true;
        }
    }

    if (checkFull==false)
        (new QErrorMessage(this))->showMessage("Введите все данные!");
    else
    if (checkFIO==false)
        (new QErrorMessage(this))->showMessage("В поле <b>Фамилия студента</b> введено некорректное значение!");
    else
    if (checkNum==false)
        (new QErrorMessage(this))->showMessage("В полях, задающих <b>Количество часов</b> должны быть введены целые числа!");
    else {
        close();
        emit SendDataDel3(line31->text(), line32->text().toInt(&ok, 10), line33->text().toInt(&ok, 10), line34->text());
    }
    checkFull = checkNum = checkFIO = true;
}


void DelWindow::PushButtonClr1()
{
    line11->clear();
    line12->clear();
    checkFull = checkNum = checkFIO = true;
}

void DelWindow::PushButtonClr2()
{
    line21->clear();
    line22->clear();
    checkFull = checkFIO = true;
}

void DelWindow::PushButtonClr3()
{
    line31->clear();
    line32->clear();
    line33->clear();
    line34->clear();
    checkFull = checkNum = checkFIO = true;
}

void DelWindow::SetWorks()
{
  QCompleter *completer = new QCompleter(actual_works);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    line22->setCompleter(completer);
    line34->setCompleter(completer);
}
