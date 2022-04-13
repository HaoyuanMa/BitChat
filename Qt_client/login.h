#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTcpSocket>
#include <mainwindow.h>
#include <zhuce.h>
#include <QTextCodec>

namespace Ui {
    class login;
}

class login : public QDialog {
    Q_OBJECT
public:
    login(QWidget *parent = 0);
    ~login();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::login *ui;
    QTcpSocket sock;
    QString uName,pWord;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void handConnect();
    void handData();
signals:
    void account(QString str);
};

#endif // LOGIN_H
