#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>
#include <QLabel>
#include <QErrorMessage>
#include <QMessageBox>
#include "student.h"

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT
public:
    AddWindow();

private:

    QList<QLineEdit*> *lines;
    QList<QLabel*> *lbls;
    bool checkNum=true;
    int maxLines = 14;
    bool checkFull=true;
    QPushButton *butAdd;
    QPushButton *butClr;
    bool checkFIO = true;
   // QRegExp fio = ("[А-ЯЁа-яё]+\\s[А-ЯЁ]\\.[А-ЯЁ]\\.");
    QRegExp fio = ("[А-ЯЁа-яё]+");

signals:

    void SendDataAdd(Student std);

private slots:

    void PushButtonAdd();
    void PushButtonClr();
};

#endif // ADDWINDOW_H
