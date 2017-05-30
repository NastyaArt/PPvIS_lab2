#ifndef TABLEDATADASE_H
#define TABLEDATADASE_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QErrorMessage>
#include "student.h"

namespace Ui
{
    class TableDatadase;
}

class TableDatadase : public QWidget
{
    Q_OBJECT
public:
    explicit TableDatadase(QWidget *parent = 0);

    void UpdateData(QList<Student> database);
    void ClearTable();

private:

    QList<Student> actual_base;

    QTableWidget *table;
    QGroupBox *group;

    int maxRec=15;
    int numPages=1;
    int curPage=1;
    int maxCol=12;

    QLabel *page;
    QLabel *lblNumPages;
    QLabel *lblNumOfAllRec;
    QPushButton *prevPage;
    QPushButton *nextPage;
    QLineEdit *lineNumPages;
    QPushButton *butSetNumPages;
    QPushButton *firstPage;
    QPushButton *lastPage;


    void SetPage(int numRec);

signals:

public slots:

    void PushButtonNextPage();
    void PushButtonPrevPage();
    void PushButtonFirstPage();
    void PushButtonLastPage();

    void ChangeNumberOfRecords();
};

#endif // TABLEDATADASE_H
