#include "tabledatadase.h"

TableDatadase::TableDatadase(QWidget *parent) : QWidget(parent)
{
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

    lblNumPages = new QLabel("Количество записей на странице");

    lblNumOfAllRec = new QLabel("Количество записей в базе: <b>0</b>");

    lineNumPages = new QLineEdit();
    lineNumPages->setText(QString::number(maxRec));

    page = new QLabel("Страница 1 из 1");

    group = new QGroupBox();

    table = new QTableWidget(this);
    table->setRowCount(maxRec);
    table->setColumnCount(maxCol);

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

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(firstPage);
    lay1->addWidget(prevPage);
    lay1->addWidget(page);
    lay1->addWidget(nextPage);
    lay1->addWidget(lastPage);
    lay1->addWidget(lblNumOfAllRec);
    lay1->addWidget(lblNumPages);
    lay1->addWidget(lineNumPages);
    lay1->addWidget(butSetNumPages);
    lay1->addStretch(1);

    QVBoxLayout *lay2 = new QVBoxLayout;
    lay2->addWidget(table);
    lay2->addLayout(lay1);

    setLayout(lay2);

    connect (nextPage, SIGNAL(clicked()), this, SLOT(PushButtonNextPage()));
    connect (prevPage, SIGNAL(clicked()), this, SLOT(PushButtonPrevPage()));
    connect (firstPage, SIGNAL(clicked()), this, SLOT(PushButtonFirstPage()));
    connect (lastPage, SIGNAL(clicked()), this, SLOT(PushButtonLastPage()));
    connect (butSetNumPages, SIGNAL(clicked()), this, SLOT(ChangeNumberOfRecords()));
}

void TableDatadase::SetPage(int numRec)
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

void TableDatadase::PushButtonNextPage()
{
    curPage++;
    UpdateData(actual_base);
}

void TableDatadase::PushButtonPrevPage()
{
    curPage--;
    UpdateData(actual_base);

}

void TableDatadase::PushButtonFirstPage()
{
    curPage = 1;
    UpdateData(actual_base);

}

void TableDatadase::PushButtonLastPage()
{
    curPage = numPages;
    UpdateData(actual_base);

}

void TableDatadase::ChangeNumberOfRecords()
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
        UpdateData(actual_base);
    }
}

void TableDatadase::ClearTable()
{
    for(int row = 0; row < maxRec; row++)
        for(int column = 0; column < maxCol; column++)
            table->item(row, column)->setText("");
}


void TableDatadase::UpdateData(QList<Student> database)
{
    actual_base=database;

    ClearTable();
    SetPage(database.length());

    QStringList nameRows;
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

    lblNumOfAllRec->setText("Количество записей в базе: <b>" + QString::number(database.length()) + "</b>");
    for (int i = (curPage-1)*maxRec; i < curPage*maxRec; i++)
        nameRows << QString::number(i+1);
    table->setVerticalHeaderLabels(nameRows);
}

