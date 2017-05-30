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

    group = new QGroupBox();

    tableData = new TableDatadase;

    QVBoxLayout *lay1 = new QVBoxLayout;
    lay1->addWidget(butAdd);
    lay1->addWidget(butSrch);
    lay1->addWidget(butDel);
    lay1->addWidget(butClr);
    lay1->addWidget(butSave);
    lay1->addWidget(butUpld);

    QVBoxLayout *lay3 = new QVBoxLayout;
    lay3->addWidget(tableData);

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

void MainWindow::UpdateData(QList<Student> database)
{

    tableData->UpdateData(database);
    SetActualWorks(database);

}

void MainWindow::PushButtonClear()
{
    tableData->ClearTable();
    emit ClearDataBase();
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

void MainWindow::SetActualWorks(QList<Student> actual_base)
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
