#include "idtb.h"
#include "chat.h"
Idtb::Idtb(QString str,QTcpSocket *sock,manage* mng)
{   QStringList slist = str.split("|");
    recivername=slist.at(0);
    sender=slist.at(1);
    reciver=slist.at(2);
    soc=sock;
    center=mng;
    connect(this,SIGNAL(clicked()),this,SLOT(openwin()));
}

void Idtb::openwin(){

    Chat *w= new Chat(this);
    w->show();
    connect(this,SIGNAL(account(QString,QTcpSocket*,Chat *)),w,SLOT(revinf(QString,QTcpSocket*,Chat *)));
    emit account(sender+"|"+reciver+"|"+recivername,soc,w);
    connect(this,SIGNAL(sendtomanage(Chat*,QString,int)),center,SLOT(setflag(Chat*,QString,int)));
    emit sendtomanage(w,reciver,0);
}
