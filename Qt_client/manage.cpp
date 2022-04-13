#include "manage.h"

manage::manage(QWidget *parent):QWidget(parent)
{
   // for(int i=0;i<10;i++){
   //    win[i]=NULL;
   //    a.append("0");
   //    cnct[i]=0;
   // }
     connect(this,SIGNAL(sendtomanage(Chat*,QString,int)),this,SLOT(setflag(Chat*,QString,int)));
}
void manage::setflag(Chat* w,QString str,int b){
    win.append(w);
    a.append(str);
    cnct.append(b);
}
void manage::deletewin(QString buf){
    QStringList slist=buf.split("|");
    for(int i=0;i<win.length();i++){
        if(slist.at(1)==a.at(i)){
            win.removeAt(i);
            a.removeAt(i);
            cnct.removeAt(i);
        }
    }
}
void manage::reciverec(QString buf){
    QStringList slist=buf.split("|");
    for(int i=0;i<win.length();i++){
        if(slist.at(3)==a.at(i)||slist.at(4)==a.at(i)){
            connect(this,SIGNAL(recmsg(QString)),win.at(i),SLOT(recivrec(QString)));
            emit recmsg(buf);
        }
    }
}

void manage::recivemsg(QString buf){
        QStringList slist=buf.split("|");
        int flag=0;
        for(int i=0;i<win.length();i++){//找到窗口
            if(slist.at(3)==a.at(i)){
                flag=1;
                if(cnct.at(i)==0){
                    connect(this,SIGNAL(transmsg(QString)),win.at(i),SLOT(handData(QString)));
                    emit transmsg(buf);
                    cnct.replace(i,1);;
                }
                else{
                    emit transmsg(buf);
                }
                break;
            }
        }
        if(flag==0){//没找到窗口新建
            Chat *w= new Chat(this);
            w->show();
            connect(this,SIGNAL(account(QString,QTcpSocket*,Chat*)),w,SLOT(revinf(QString,QTcpSocket*,Chat *)));
            emit account(sender+"|"+slist.at(3)+"|"+slist.at(4),soc,w);
            emit sendtomanage(w,slist.at(3),1);
            connect(this,SIGNAL(transmsg(QString)),w,SLOT(handData(QString)));
            emit transmsg(buf);
        }
}
