#ifndef MANAGE_H
#define MANAGE_H

#include <QWidget>
#include "chat.h"

class manage : public QWidget
{ Q_OBJECT
public:
    manage(QWidget *parent);
    QString sender;
    QTcpSocket *soc;
    QList<Chat *> win;
    //Chat *win[10];
    QStringList a;
    QList<int> cnct;
    //int cnct[10];
private slots:
    void setflag(Chat*,QString,int);
    void recivemsg(QString);
    void deletewin(QString);
    void reciverec(QString);
signals:
    void account(QString str,QTcpSocket *soc,Chat *);
    void sendtomanage(Chat*,QString,int);
    void transmsg(QString);
    void recmsg(QString);
};

#endif // MANAGE_H
