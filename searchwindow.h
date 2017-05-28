#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QErrorMessage>
#include <QMessageBox>
#include <QRegExp>
#include <QTableWidget>
#include "student.h"
#include <QCompleter>

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QDialog
{
    Q_OBJECT
public:
    SearchWindow();
    QStringList actual_works;
    void SetWorks();

private:

    QList<Student> search_result;

    QGroupBox *box1;
    QGroupBox *box2;
    QGroupBox *box3;
    QLabel *lbl11;
    QLabel *lbl12;
    QLineEdit *line11;
    QLineEdit *line12;
    QPushButton *butSrch1;
    QPushButton *butClr1;
    QLabel *lbl21;
    QLabel *lbl22;
    QLineEdit *line21;
    QLineEdit *line22;
    QPushButton *butSrch2;
    QPushButton *butClr2;
    QLabel *lbl31;
    QLabel *lbl32;
    QLabel *lbl33;
    QLabel *lbl34;
    QLineEdit *line31;
    QLineEdit *line32;
    QLineEdit *line33;
    QLineEdit *line34;
    QPushButton *butSrch3;
    QPushButton *butClr3;
    bool checkNum = true;
    bool checkFIO = true;
    bool checkFull = true;
    QRegExp fio = ("[А-ЯЁа-яё]+");

    QPushButton *prevPage;
    QPushButton *nextPage;
    QLabel *page;
    QLabel *lblNumPages;
    QLabel *lblNumOfAllRec;
    QLineEdit *lineNumPages;
    QPushButton *butSetNumPages;
    QPushButton *firstPage;
    QPushButton *lastPage;
    void SetPage(int numRec);
    int maxRec=4;
    int curPage=1;
    int numPages=1;

    int maxCol=12;
    QTableWidget *table;

    void TableClear();

signals:
    void SendDataSrch1(QString surname, int gpoup);
    void SendDataSrch2(QString surname, QString work);
    void SendDataSrch3(QString surname, int timemin, int timemax, QString work);

private slots:

    void PushButtonSrch1();
    void PushButtonClr1();
    void PushButtonSrch2();
    void PushButtonClr2();
    void PushButtonSrch3();
    void PushButtonClr3();
    void SrchState(int colStd);
    void UpdateDataSrch(QList<Student> database);

    void PushButtonNextPage();
    void PushButtonPrevPage();
    void PushButtonFirstPage();
    void PushButtonLastPage();

    void ChangeNumberOfRecords();
};

#endif // SEARCHWINDOW_H
