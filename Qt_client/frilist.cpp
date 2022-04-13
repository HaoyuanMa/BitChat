#include "frilist.h"
#include "idtb.h"
#include <QGroupBox>
#include <QVBoxLayout>
FriList::FriList(QWidget *parent,Qt::WindowFlags f)    :QToolBox(parent,f)
{
    onlineBox = new QGroupBox;
    offlineBox = new QGroupBox;
    this->setLayFri();
    this->setLayGro();
}
void FriList::setLayFri()
{
    layout_fri = new QVBoxLayout(onlineBox);
    layout_fri->setMargin(3);
    layout_fri->setAlignment(Qt::AlignTop);
    this->addItem((QWidget*)onlineBox,QString("Online"));
}
void FriList::setLayGro()
{
    layout_group = new QVBoxLayout(offlineBox);
    layout_fri->setMargin(3);
    layout_fri->setAlignment(Qt::AlignTop);
    this->addItem((QWidget*)offlineBox,QString("Offline"));
}
void FriList::addOnline(QString username, QString id,QString myid,QTcpSocket *sock,manage* mng)
{   Idtb *tempButton = new Idtb(username+"|"+myid+"|"+id,sock,mng);
    //QToolButton *tempButton = new QToolButton;
    QString iconpath = QString(":/img/timg.jpg");
    QString text = QString("%1 <%2>").arg(username).arg(id);
    tempButton->setText(text);
    qDebug()<<iconpath;
    tempButton->setIcon(QPixmap(iconpath));
    tempButton->setIconSize(QSize(100,30)); //设置按钮尺寸
    tempButton->setAutoRaise(true);   //当鼠标离开时，按钮恢复为弹起状态
    tempButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //设置按钮文字显示在图标旁边
    online_list.append(tempButton);
    layout_fri->addWidget(online_list.last());
}
void FriList::addOffline( QString username, QString id,QString myid,QTcpSocket *sock,manage* mng)
{   Idtb *tempButton = new Idtb(username+"|"+myid+"|"+id,sock,mng);
    //QToolButton *tempButton = new QToolButton;
    QString iconpath = QString(":/img/timg.jpg");
    QString text = QString("%1 <%2>").arg(username).arg(id);
    tempButton->setText(text);
    qDebug()<<iconpath;
    tempButton->setIcon(QPixmap(iconpath));
    tempButton->setIconSize(QSize(100,30)); //设置按钮尺寸
    tempButton->setAutoRaise(true);   //当鼠标离开时，按钮恢复为弹起状态
    tempButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //设置按钮文字显示在图标旁边
    offline_list.append(tempButton);
    layout_group->addWidget(offline_list.last());
}
