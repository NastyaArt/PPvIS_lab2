#include "searchwindow.h"

SearchWindow::SearchWindow()
{
    setModal(true);

    box1 = new QGroupBox("Поиск по фамилии и номеру группы студента");

    butSrch1 = new QPushButton("Найти запись(и)");
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
    lay13->addWidget(butSrch1);
    lay13->addWidget(butClr1);

    QHBoxLayout *lay14 = new QHBoxLayout;
    lay14->addLayout(lay11);
    lay14->addLayout(lay12);
    lay14->addLayout(lay13);

    box1->setLayout(lay14);

    box2 = new QGroupBox("Поиск по фамилии и виду общественной работы");

    butSrch2 = new QPushButton("Найти запись(и)");
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
    lay23->addWidget(butSrch2);
    lay23->addWidget(butClr2);

    QHBoxLayout *lay24 = new QHBoxLayout;
    lay24->addLayout(lay21);
    lay24->addLayout(lay22);
    lay24->addLayout(lay23);

    box2->setLayout(lay24);

    box3 = new QGroupBox("Поиск по фамилии и количеству часов вида обественной работы");

    butSrch3 = new QPushButton("Найти запись(и)");
    butClr3 = new QPushButton("Очистить поля ввода");

    lbl31 = new QLabel("Фамилия студента");
    lbl32 = new QLabel("Количество часов: от ");
    lbl33 = new QLabel("до");
    lbl34 = new QLabel("Вид общественной работы");

    line31 = new QLineEdit;
    line32 = new QLineEdit;
    line33 = new QLineEdit;
    line34 = new QLineEdit;

    prevPage = new QPushButton();
    prevPage -> setFixedSize(25,25);
    prevPage -> setIcon(QIcon("images/prevpage.png"));
    prevPage -> setIconSize(prevPage->size());
    prevPage -> setToolTip ("Предыдущая страница");
    prevPage-> setEnabled(false);

    nextPage = new QPushButton();
    nextPage -> setFixedSize(25,25);
    nextPage -> setIcon(QIcon("images/nextpage.png"));
    nextPage -> setIconSize(nextPage->size());
    nextPage -> setToolTip ("Следующая страница");
    nextPage-> setEnabled(false);

    firstPage = new QPushButton("Первая страница");
    firstPage-> setEnabled(false);

    lastPage = new QPushButton("Последняя страница");
    lastPage-> setEnabled(false);

    butSetNumPages = new QPushButton("Изменить");
    butSetNumPages ->setEnabled(false);

    lblNumPages = new QLabel("Количество записей на странице");

    lblNumOfAllRec = new QLabel("Количество записей найдено: <b>0</b>");

    lineNumPages = new QLineEdit();
    lineNumPages->setText(QString::number(maxRec));

    page = new QLabel("Страница 1 из 1");

    QHBoxLayout *lay31 = new QHBoxLayout;
    lay31->addWidget(lbl32);
    lay31->addWidget(line32);
    lay31->addWidget(lbl33);
    lay31->addWidget(line33);
    lay31->addWidget(butClr3);

    QHBoxLayout *lay32 = new QHBoxLayout;
    lay32->addWidget(lbl31);
    lay32->addWidget(line31);
    lay32->addWidget(butSrch3);

    QHBoxLayout *lay33 = new QHBoxLayout;
    lay33->addWidget(lbl34);
    lay33->addWidget(line34);

    QVBoxLayout *lay34 = new QVBoxLayout;
    lay34->addLayout(lay32);
    lay34->addLayout(lay31);
    lay34->addLayout(lay33);

    box3->setLayout(lay34);

    table = new QTableWidget(this);

    QHBoxLayout *layPages = new QHBoxLayout;
    layPages->addWidget(firstPage);
    layPages->addWidget(prevPage);
    layPages->addWidget(page);
    layPages->addWidget(nextPage);
    layPages->addWidget(lastPage);
    layPages->addWidget(lblNumOfAllRec);
    layPages->addWidget(lblNumPages);
    layPages->addWidget(lineNumPages);
    layPages->addWidget(butSetNumPages);
    layPages->addStretch(1);

    QVBoxLayout *layall = new QVBoxLayout;
    layall->addWidget(box1);
    layall->addWidget(box2);
    layall->addWidget(box3);
    layall->addWidget(table);
    layall->addLayout(layPages);

    setLayout(layall);
    setWindowTitle("Поиск записи");

    connect(butSrch1, SIGNAL(clicked(bool)), this, SLOT(PushButtonSrch1()));
    connect(butClr1, SIGNAL(clicked(bool)), this, SLOT(PushButtonClr1()));
    connect(butSrch2, SIGNAL(clicked(bool)), this, SLOT(PushButtonSrch2()));
    connect(butClr2, SIGNAL(clicked(bool)), this, SLOT(PushButtonClr2()));
    connect(butSrch3, SIGNAL(clicked(bool)), this, SLOT(PushButtonSrch3()));
    connect(butClr3, SIGNAL(clicked(bool)), this, SLOT(PushButtonClr3()));

    connect (nextPage, SIGNAL(clicked()), this, SLOT(PushButtonNextPage()));
    connect (prevPage, SIGNAL(clicked()), this, SLOT(PushButtonPrevPage()));
    connect (firstPage, SIGNAL(clicked()), this, SLOT(PushButtonFirstPage()));
    connect (lastPage, SIGNAL(clicked()), this, SLOT(PushButtonLastPage()));
    connect (butSetNumPages, SIGNAL(clicked()), this, SLOT(ChangeNumberOfRecords()));
}


void SearchWindow::PushButtonSrch1()
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
        emit SendDataSrch1(line11->text(), line12->text().toInt(&ok, 10));
    }
    checkFull = checkNum = checkFIO = true;
}

void SearchWindow::PushButtonSrch2()
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
        emit SendDataSrch2(line21->text(), line22->text());
    }
    checkFull = checkFIO = true;
}

void SearchWindow::PushButtonSrch3()
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
        emit SendDataSrch3(line31->text(), line32->text().toInt(&ok, 10), line33->text().toInt(&ok, 10), line34->text());
    }
    checkFull = checkNum = checkFIO = true;
}


void SearchWindow::PushButtonClr1()
{
    line11->clear();
    line12->clear();
    checkFull = checkNum = checkFIO = true;
}

void SearchWindow::PushButtonClr2()
{
    line21->clear();
    line22->clear();
    checkFull = checkFIO = true;
}

void SearchWindow::PushButtonClr3()
{
    line31->clear();
    line32->clear();
    line33->clear();
    line34->clear();
    checkFull = checkNum = checkFIO = true;
}

void SearchWindow::SrchState(int colStd)
{
    QMessageBox::information(this, "Поиск записей", "Найдено " + QString::number(colStd) + " записей(и)", QMessageBox::Ok);
}

void SearchWindow::UpdateDataSrch(QList<Student> database)
{
    table->setRowCount(maxRec);
    table->setColumnCount(12);
    butSetNumPages ->setEnabled(true);

    for(int row = 0; row < table->rowCount(); row++)
      for(int column = 0; column < table->columnCount(); column++)
          table->setItem(row, column, new QTableWidgetItem());

    QStringList name_table;
            name_table << "\nФИО студента\n" << "\nГруппа\n" << "1 семестр\n\nВид общественной работы"<< "\n\nКоличество часов"
                          << "2 семестр\n\nВид общественной работы"<< "\n\nКоличество часов"
                          << "3 семестр\n\nВид общественной работы"<< "\n\nКоличество часов"
                          << "4 семестр\n\nВид общественной работы"<< "\n\nКоличество часов"
                          << "5 семестр\n\nВид общественной работы"<< "\n\nКоличество часов";

    table->setHorizontalHeaderLabels(name_table);
    table->resizeColumnsToContents();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setShowGrid(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

   /* for (int st = 0; st < database.length(); st++){
        table->item(st,0)->setText(database.at(st).surname + " " + database.at(st).name + " " + database.at(st).fathername + " ");
        table->item(st,1)->setText(QString::number(database.at(st).group));
        for (int i = 2, j = 0; i < 12; i=i+2, j++)
            table->item(st,i)->setText(database.at(st).works.at(j));
        for (int i = 3, j = 0; i < 12; i=i+2, j++)
            table->item(st,i)->setText(QString::number(database.at(st).hours[j]));
    }*/
    search_result = database;
    QStringList nameRows;
    SetPage(database.length());
    int maxRecOnPage = 0;
    if (database.length()==0)
        maxRecOnPage = 0;
    else{
        if (curPage == numPages)
            maxRecOnPage = database.length()-(numPages-1)*maxRec;
        else  maxRecOnPage = maxRec;
    }

    for (int st = (curPage-1)*maxRec, numRow = 0; st < (curPage-1)*maxRec+maxRecOnPage; st++, numRow++){
        table->item(numRow,0)->setText(database.at(st).surname + " " + database.at(st).name + " " + database.at(st).fathername + " ");
        table->item(numRow,1)->setText(QString::number(database.at(st).group));
        for (int i = 2, j = 0; i < 12; i=i+2, j++)
            table->item(numRow,i)->setText(database.at(st).works.at(j));
        for (int i = 3, j = 0; i < 12; i=i+2, j++)
            table->item(numRow,i)->setText(QString::number(database.at(st).hours[j]));
    }
    lblNumOfAllRec->setText("Количество записей найдено: <b>" + QString::number(database.length()) + "</b>");
    for (int i = (curPage-1)*maxRec; i < curPage*maxRec; i++)
        nameRows << QString::number(i+1);
    table->setVerticalHeaderLabels(nameRows);
}

void SearchWindow::ChangeNumberOfRecords()
{
    bool ok=true;
    lineNumPages->text().toInt(&ok, 10);
    if (ok == false){
        (new QErrorMessage(this))->showMessage("Введено некорректное количество записей!");
        lineNumPages->setText(QString::number(maxRec));
    }
    else if (lineNumPages->text().toInt(&ok, 10)<=0)
    {
        (new QErrorMessage(this))->showMessage("Введено некорректное количество записей!");
        lineNumPages->setText(QString::number(maxRec));
    }
    else
    {
        maxRec = lineNumPages->text().toInt(&ok, 10);
        table->setRowCount(maxRec);

        for(int row = 0; row < table->rowCount(); row++)
          for(int column = 0; column < table->columnCount(); column++)
              table->setItem(row, column, new QTableWidgetItem());
        UpdateDataSrch(search_result);
    }
}

void SearchWindow::SetPage(int numRec)
{
    if (numRec!=0){
        numPages = ceil((double) numRec/maxRec);

        prevPage -> setEnabled(curPage!=1);
        firstPage -> setEnabled(curPage!=1);

        nextPage -> setEnabled(curPage!=numPages);
        lastPage -> setEnabled(curPage!=numPages);
    }
    else
    {
        curPage = numPages = 1;
        prevPage -> setEnabled(false);
        firstPage -> setEnabled(false);
        nextPage -> setEnabled(false);
        lastPage -> setEnabled(false);
    }
    page->setText("Страница " + QString::number(curPage) + " из " + QString::number(numPages) );

}

void  SearchWindow::TableClear()
{
    for(int row = 0; row < maxRec; row++)
        for(int column = 0; column < maxCol; column++)
            table->item(row, column)->setText("");
}

void SearchWindow::PushButtonNextPage()
{
    curPage++;
    UpdateDataSrch(search_result);
}

void SearchWindow::PushButtonPrevPage()
{
    curPage--;
    UpdateDataSrch(search_result);
}

void SearchWindow::PushButtonFirstPage()
{
    curPage = 1;
    UpdateDataSrch(search_result);
}

void SearchWindow::PushButtonLastPage()
{
    curPage = numPages;
    UpdateDataSrch(search_result);
}

void SearchWindow::SetWorks()
{
  QCompleter *completer = new QCompleter(actual_works);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    line22->setCompleter(completer);
    line34->setCompleter(completer);
}
