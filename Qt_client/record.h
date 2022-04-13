#ifndef RECORD_H
#define RECORD_H

#include <QMainWindow>

namespace Ui {
class record;
}

class record : public QMainWindow
{
    Q_OBJECT

public:
    explicit record(QWidget *parent = 0);
    ~record();

private:
    Ui::record *ui;


private slots:
   void dsb(QString str);

};

#endif // RECORD_

