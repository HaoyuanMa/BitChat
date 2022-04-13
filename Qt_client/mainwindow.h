#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTcpSocket>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include "frilist.h"
#include <QCloseEvent>
#include "manage.h"
#include <QTextCodec>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);
private:
    Ui::MainWindow *ui;
    QTcpSocket sock;
    QString id;
    manage *db;
private slots:
    void revid(QString);
    void searchresult(QString);
    void refresult(QString);
    void handConnect();
   // void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void solvebuf();
signals:
    void passinf(QString str);
    void dmsg(QString str);
    void smsg(QString str);
    void rmsg(QString str);
    void mmsg(QString str);
    void recmsg(QString str);
};

#endif // MAINWINDOW_H
