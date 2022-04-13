//filename:frilist.h
#ifndef FRILIST_H
#define FRILIST_H


#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QList>
#include <QDebug>
#include <QMainWindow>
#include <login.h>
#include <manage.h>
namespace Ui {
    class FriList;
}
class FriList : public QToolBox
{    Q_OBJECT
public:
    FriList(QWidget *parent=0,Qt::WindowFlags f=0);
    void setLayFri();
    void setLayGro();
    void addOnline(QString username,QString id,QString myid,QTcpSocket *sock,manage* mng);
    void addOffline(QString username,QString id,QString myid,QTcpSocket *sock,manage* mng);
private:
    QToolButton *toolBtn1;
    QList <QToolButton *>online_list;
    QList <QToolButton *>offline_list;
    QGroupBox *onlineBox;
    QGroupBox *offlineBox;
    QVBoxLayout *layout_fri;
    QVBoxLayout *layout_group;
 };
#endif // DRAWER_H
