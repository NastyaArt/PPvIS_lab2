#ifndef DELWINDOW_H
#define DELWINDOW_H

#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QErrorMessage>
#include <QRegExp>
#include <QCompleter>

namespace Ui {
class DelWindow;
}

class DelWindow : public QDialog
{
    Q_OBJECT
public:
    DelWindow();
    QStringList actual_works;
    void SetWorks();

private:

    QGroupBox *box1;
    QGroupBox *box2;
    QGroupBox *box3;
    QLabel *lbl11;
    QLabel *lbl12;
    QLineEdit *line11;
    QLineEdit *line12;
    QPushButton *butDel1;
    QPushButton *butClr1;
    QLabel *lbl21;
    QLabel *lbl22;
    QLineEdit *line21;
    QLineEdit *line22;
    QPushButton *butDel2;
    QPushButton *butClr2;
    QLabel *lbl31;
    QLabel *lbl32;
    QLabel *lbl33;
    QLabel *lbl34;
    QLineEdit *line31;
    QLineEdit *line32;
    QLineEdit *line33;
    QLineEdit *line34;
    QPushButton *butDel3;
    QPushButton *butClr3;
    bool checkNum = true;
    bool checkFIO = true;
    bool checkFull = true;
    QRegExp fio = ("[А-ЯЁа-яё]+");

signals:
    void SendDataDel1(QString surname, int gpoup);
    void SendDataDel2(QString surname, QString work);
    void SendDataDel3(QString surname, int timemin, int timemax, QString work);

private slots:

    void PushButtonDel1();
    void PushButtonClr1();
    void PushButtonDel2();
    void PushButtonClr2();
    void PushButtonDel3();
    void PushButtonClr3();
};

#endif // DELWINDOW_H
