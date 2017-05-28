#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include "addwindow.h"
#include "delwindow.h"
#include "searchwindow.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    AddWindow *addWind;    
    DelWindow *delWind;
    SearchWindow *srchWind;

private:
    Ui::MainWindow *ui;

    QList<Student> actual_base;    

    QPushButton *butAdd;
    QPushButton *butSrch;
    QPushButton *butDel;
    QPushButton *butClr;
    QPushButton *butSave;
    QPushButton *butUpld;
    QPushButton *prevPage;
    QPushButton *nextPage;

    int maxRec=15;
    int numPages=1;
    int curPage=1;
    int maxCol=12;

    QTableWidget *table;
    QGroupBox *group;
    void  TableClear();

    QLabel *page;
    QLabel *lblNumPages;
    QLabel *lblNumOfAllRec;
    QLineEdit *lineNumPages;
    QPushButton *butSetNumPages;
    QPushButton *firstPage;
    QPushButton *lastPage;

    void SetPage(int numRec);
    void CreateActions();
    void CreateMenus();
    void SetActualWorks();

    QMenu *fileMenu;
    QMenu *editMenu;
    QAction *uplAct;
    QAction *saveAct;
    QAction *clrAct;
    QAction *exitAct;
    QAction *addAct;
    QAction *srchAct;
    QAction *delAct;

signals:

    void SaveDataBase(QString filename);
    void UploadDataBase(QString filename);
    void GetDataBase();
    void ClearDataBase();

private slots:

    void UpdateData(QList<Student> database);

    void PushButtonSave();
    void SaveState(bool ok);
    void UploadState(bool ok);

    void DelState(int colStd);

    void DataBaseIsClear();
    void PushButtonUpld();
    void PushButtonClear();

    void PushButtonNextPage();
    void PushButtonPrevPage();
    void PushButtonFirstPage();
    void PushButtonLastPage();

    void ChangeNumberOfRecords();

    void AddStudent();
    void DelStudent();
    void SrchStudent();

};



#endif // MAINWINDOW_H
