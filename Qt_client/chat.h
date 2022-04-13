#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include<QDebug>
#include<QMessageBox>
#include<QTcpSocket>
#include <qdatetime.h>
#include <record.h>
#include <QCloseEvent>
#include <QTextCodec>
namespace Ui {
    class Chat;
}

class Chat : public QMainWindow {
    Q_OBJECT
public:
    Chat(QWidget *parent = 0);
    ~Chat();
    QTcpSocket *soc;
protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);
private:
    Ui::Chat *ui;
    QString text;
    QString sendid;
    QString recvid;
    QString recvname;
    QString talker;
//signals:
 //   void sendmsg(QString str);

private slots:

    void handData(QString str2);
    //void stringToHtmlFilter(QString &str);
    //void stringToHtml(QString &str,QColor crl);
    void on_pushButton_clicked();//发送
    void on_pushButton_2_clicked();//关闭
    void clean();
    void on_pushButton_3_clicked();
    void recivrec(QString);
    void revinf(QString str,QTcpSocket *soc,Chat *);//接受信号
signals:
    void account(QString);
};


#endif // CHAT_H
