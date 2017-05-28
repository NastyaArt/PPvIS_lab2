#include "addwindow.h"


AddWindow::AddWindow()
{

       setModal(true);
       butAdd = new QPushButton("Добавить");
       butClr = new QPushButton("Очистить");
       int sem = 1;

       lbls = new QList<QLabel*>;
       QVBoxLayout *lay1 = new QVBoxLayout;

       for (int i = 0; i < maxLines; ++i) {
                       QLabel* lbl = new QLabel();
                       if (i==0) lbl->setText(QString::number(i+1) + ") Фамилия студента");
                       else
                       if (i==1) lbl->setText(QString::number(i+1) + ") Имя студента");
                       else
                       if (i==2) lbl->setText(QString::number(i+1) + ") Отчество студента");
                       else
                       if (i==3) lbl->setText(QString::number(i+1) + ") Группа");
                       else
                       if (i%2==0) lbl->setText("<b>Семестр " + QString::number(sem++) + "</b>  " + QString::number(i+1) + ") Вид общественной работы");
                       else
                       if (i%2==1) lbl->setText(QString::number(i+1) + ") Количество часов");

                       lbls->append(lbl);
                       lay1->addWidget(lbls->at(i));
   }

       QVBoxLayout *lay2 = new QVBoxLayout;
       lines = new QList<QLineEdit*>;

       for (int i = 0; i < maxLines; ++i) {
                       QLineEdit* line = new QLineEdit();
                       lines->append(line);
                       lay2->addWidget(lines->at(i));
       }

       lay1->addWidget(butAdd);
       lay2->addWidget(butClr);

       QHBoxLayout *lay3 = new QHBoxLayout;
       lay3->addLayout(lay1);
       lay3->addLayout(lay2);

       connect(butAdd, SIGNAL(clicked(bool)), this, SLOT(PushButtonAdd()));
       connect(butClr, SIGNAL(clicked(bool)), this, SLOT(PushButtonClr()));


       setLayout(lay3);
       setWindowTitle("Добавление записи");
   }


   void AddWindow::PushButtonAdd()
   {
       bool ok = true;
       for (int i = 0; i < maxLines; i++) {
               if (lines->at(i)->text()==NULL)
                   checkFull = false;
               if (i>2 && i%2==1){
                   lines->at(i)->text().toInt(&ok, 10);
                   if (ok == false)
                       checkNum = false;
               }
               else
               if (i<3 && fio.exactMatch (lines->at(i)->text())==false)
                   checkFIO = false;
       }

     //  checkFIO = fio.exactMatch (lines->at(0)->text());

       if (checkFull==false)
           (new QErrorMessage(this))->showMessage("Введите все данные!");
       else
       if (checkFIO==false)
           (new QErrorMessage(this))->showMessage("В полях <b>Фамилия/Имя/Отчество студента</b> введены некорректные данные!");
       else
       if (checkNum==false)
           (new QErrorMessage(this))->showMessage("В полях <b>Группа</b> и <b>Количество часов</b> должны быть введены целые числа!");
       else {
           close();
           QList<QString> work;
           int time[5];
           time[0] = lines->at(5)->text().toInt(&ok, 10);
           time[1] = lines->at(7)->text().toInt(&ok, 10);
           time[2] = lines->at(9)->text().toInt(&ok, 10);
           time[3] = lines->at(11)->text().toInt(&ok, 10);
           time[4] = lines->at(13)->text().toInt(&ok, 10);

          // work.append(lines->at(3)->text());
           work << lines->at(4)->text() << lines->at(6)->text() << lines->at(8)->text() << lines->at(10)->text() << lines->at(12)->text();
           Student std(lines->at(0)->text(), lines->at(1)->text(), lines->at(2)->text(), lines->at(3)->text().toInt(&ok, 10), work, time);
           emit SendDataAdd(std);
           QMessageBox::information(this, "Добавление данных", "Добавлено успешно!", QMessageBox::Ok);
       }
       checkFull = checkNum = checkFIO = true;
   }


   void AddWindow::PushButtonClr()
   {
       for (int i = 0; i < maxLines; i++) {
               lines->at(i)->clear();
       }
       checkFull = checkNum = checkFIO = true;
   }
