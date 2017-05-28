#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CreateActions();
    CreateMenus();

    QList<QToolBar *> toolbars = this->findChildren<QToolBar *>();
    for (int i = 0; i < toolbars.length(); i++)
        toolbars.at(i)->hide();

    addWind = new AddWindow;
    delWind = new DelWindow;
    srchWind = new SearchWindow;

    butAdd = new QPushButton();
    butAdd ->setFixedSize(50,50);
    butAdd ->setIcon(QIcon("images/add.png"));
    butAdd ->setIconSize(butAdd->size());
    butAdd ->setToolTip ("Добавить запись");

    butSrch = new QPushButton();
    butSrch ->setFixedSize(50,50);
    butSrch ->setIcon(QIcon("images/search.png"));
    butSrch ->setIconSize(butSrch->size());
    butSrch ->setToolTip ("Найти запись");

    butDel = new QPushButton();
    butDel ->setFixedSize(50,50);
    butDel ->setIcon(QIcon("images/delete.png"));
    butDel ->setIconSize(butDel->size());
    butDel ->setToolTip ("Удалить запись");

    butClr = new QPushButton();
    butClr ->setFixedSize(50,50);
    butClr ->setIcon(QIcon("images/clean.png"));
    butClr ->setIconSize(butClr->size());
    butClr ->setToolTip ("Очистить таблицу");

    butSave = new QPushButton();
    butSave ->setFixedSize(50,50);
    butSave ->setIcon(QIcon("images/save.png"));
    butSave ->setIconSize(butSave->size());
    butSave ->setToolTip ("Сохранить в файл");

    butUpld = new QPushButton();
    butUpld -> setFixedSize(50,50);
    butUpld -> setIcon(QIcon("images/upload.png"));
    butUpld -> setIconSize(butUpld->size());
    butUpld -> setToolTip ("Загрузить из файла");

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

    QVBoxLayout *lay1 = new QVBoxLayout;
    lay1->addWidget(butAdd);
    lay1->addWidget(butSrch);
    lay1->addWidget(butDel);
    lay1->addWidget(butClr);
    lay1->addWidget(butSave);
    lay1->addWidget(butUpld);

    QHBoxLayout *lay2 = new QHBoxLayout;
    lay2->addWidget(firstPage);
    lay2->addWidget(prevPage);
    lay2->addWidget(page);
    lay2->addWidget(nextPage);
    lay2->addWidget(lastPage);
    lay2->addWidget(lblNumOfAllRec);
    lay2->addWidget(lblNumPages);
    lay2->addWidget(lineNumPages);
    lay2->addWidget(butSetNumPages);
    lay2->addStretch(1);

    QVBoxLayout *lay3 = new QVBoxLayout;
    lay3->addWidget(table);
    lay3->addLayout(lay2);

    QHBoxLayout *lay4 = new QHBoxLayout;
    lay4->addLayout(lay1);
    lay4->addLayout(lay3);

    group->setLayout(lay4);

    setCentralWidget(group);

    connect (butAdd, SIGNAL(clicked()), addWind, SLOT(show()));
    connect (butSrch, SIGNAL(clicked()), srchWind, SLOT(show()));
    connect (butDel, SIGNAL(clicked()), delWind, SLOT(show()));
    connect (butSave, SIGNAL(clicked()), this, SLOT(PushButtonSave()));
    connect (butUpld, SIGNAL(clicked()), this, SLOT(PushButtonUpld()));
    connect (butClr, SIGNAL(clicked()), this, SLOT(PushButtonClear()));
    connect (nextPage, SIGNAL(clicked()), this, SLOT(PushButtonNextPage()));
    connect (prevPage, SIGNAL(clicked()), this, SLOT(PushButtonPrevPage()));
    connect (firstPage, SIGNAL(clicked()), this, SLOT(PushButtonFirstPage()));
    connect (lastPage, SIGNAL(clicked()), this, SLOT(PushButtonLastPage()));
    connect (butSetNumPages, SIGNAL(clicked()), this, SLOT(ChangeNumberOfRecords()));

}

void MainWindow::PushButtonSave()
{

    QString filename = QFileDialog::getOpenFileName(this, tr("Сохранить данные в Xml-файл"), ".", tr("Xml files (*.xml)"));

    if(filename != "") emit SaveDataBase(filename);

}

void MainWindow::SaveState(bool ok)
{
    if (ok == true)
        QMessageBox::information(this, "Сохранение файла", "Сохранено успешно!", QMessageBox::Ok);
    else
        QMessageBox::warning(this, "Сохранение файла", "Ошибка сохранения!", QMessageBox::Ok);

}

void MainWindow::UploadState(bool ok)
{
    if (ok == true)
        QMessageBox::information(this, "Загрузка файла", "Загружено успешно!", QMessageBox::Ok);
    else
        QMessageBox::warning(this, "Загрузка файла", "Ошибка загрузки!", QMessageBox::Ok);

}

void MainWindow::DelState(int colStd)
{
    QMessageBox::information(this, "Удаление записей", "Удалено " + QString::number(colStd) + " записей(и)", QMessageBox::Ok);
}

void MainWindow::DataBaseIsClear()
{
    QMessageBox::information(this, "Очистка базы данных", "Очищено успешно!", QMessageBox::Ok);
}

void MainWindow::PushButtonUpld()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Загрузить данные из Xml-файла"), ".", tr("Xml files (*.xml)"));
    if(filename != "") emit UploadDataBase(filename);

}

void  MainWindow::TableClear()
{
    for(int row = 0; row < maxRec; row++)
        for(int column = 0; column < maxCol; column++)
            table->item(row, column)->setText("");
}

void MainWindow::UpdateData(QList<Student> database)
{
    TableClear();
    actual_base=database;
    SetActualWorks();
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
    lblNumOfAllRec->setText("Количество записей в базе: <b>" + QString::number(database.length()) + "</b>");
    for (int i = (curPage-1)*maxRec; i < curPage*maxRec; i++)
        nameRows << QString::number(i+1);
    table->setVerticalHeaderLabels(nameRows);
}

void MainWindow::SetPage(int numRec)
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

void MainWindow::PushButtonNextPage()
{
    curPage++;
    UpdateData(actual_base);
 //   UpdateData(actual_base);
    //emit GetDataBase();
}

void MainWindow::PushButtonPrevPage()
{
    curPage--;
    UpdateData(actual_base);
    //emit GetDataBase();
}

void MainWindow::PushButtonFirstPage()
{
    curPage = 1;
    UpdateData(actual_base);
    //emit GetDataBase();
}

void MainWindow::PushButtonLastPage()
{
    curPage = numPages;
    UpdateData(actual_base);
    //emit GetDataBase();
}

void MainWindow::PushButtonClear()
{
    emit ClearDataBase();
}

void MainWindow::ChangeNumberOfRecords()
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
        //emit GetDataBase();
        UpdateData(actual_base);
    }
}

void MainWindow::AddStudent()
{
    addWind->show();
}

void MainWindow::DelStudent()
{
    delWind->show();
}

void MainWindow::SrchStudent()
{
    srchWind->show();
}

void MainWindow::CreateActions()
{
    uplAct = new QAction(tr("Загрузить из файла"), this);
    connect(uplAct, &QAction::triggered, this, &MainWindow::PushButtonUpld);
    saveAct = new QAction(tr("Сохранить в файл"), this);
    connect(saveAct, &QAction::triggered, this, &MainWindow::PushButtonSave);
    clrAct = new QAction(tr("Очистить таблицу"), this);
    connect(clrAct, &QAction::triggered, this, &MainWindow::PushButtonClear);

    addAct = new QAction(tr("Добавить запись"), this);
    connect(addAct, &QAction::triggered, this, &MainWindow::AddStudent);
    delAct = new QAction(tr("Удалить запись"), this);
    connect(delAct, &QAction::triggered, this, &MainWindow::DelStudent);
    srchAct = new QAction(tr("Найти запись"), this);
    connect(srchAct, &QAction::triggered, this, &MainWindow::SrchStudent);
}

void MainWindow::CreateMenus()
{

    QMenu *fileMenu = new QMenu("Файл");
    fileMenu->addAction(uplAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(clrAct);
    QMenu *editMenu = new QMenu("Изменить");
    editMenu->addAction(addAct);
    editMenu->addAction(delAct);
    editMenu->addAction(srchAct);
    ui->menuBar->addMenu(fileMenu);
    ui->menuBar->addMenu(editMenu);
}

void MainWindow::SetActualWorks()
{
    QStringList works;
    srchWind->actual_works.clear();
    for (int i = 0; i< actual_base.length(); i++)
            for (int j = 0; j< actual_base.at(i).works.length(); j++)
                if (works.contains(actual_base.at(i).works.at(j))==false)
                    works << actual_base.at(i).works.at(j);

    srchWind->actual_works = works;
    srchWind->SetWorks();
    delWind->actual_works = works;
    delWind->SetWorks();
}

MainWindow::~MainWindow()
{

    delete ui;
}
