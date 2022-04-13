#ifndef IDTB_H
#define IDTB_H

#include <QToolButton>
#include "mainwindow.h"
#include "chat.h"
namespace Ui {
    class Idtb;
}
class Idtb : public QToolButton
{   Q_OBJECT
public:
    Idtb(QString str,QTcpSocket *soc,manage* mng);
    QString sender,reciver,recivername;
    QTcpSocket *soc;
    manage *center;
private slots:
    void openwin();
signals:
    void account(QString str,QTcpSocket *soc,Chat *);
    void sendtomanage(Chat*,QString,int);
};

#endif // IDTB_H
