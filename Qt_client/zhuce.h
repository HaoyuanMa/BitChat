#ifndef ZHUCE_H
#define ZHUCE_H

#include <QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QTcpSocket>
#include <QTextCodec>

namespace Ui {
    class ZhuCe;
}

class ZhuCe : public QDialog {
    Q_OBJECT
public:
    ZhuCe(QWidget *parent = 0);
    ~ZhuCe();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ZhuCe *ui;
    QTcpSocket sock;

private slots:
    void on_pushButton_clicked();
    void handConnected();
    void handData();
    void clean();
};

#endif // ZHUCE_H
