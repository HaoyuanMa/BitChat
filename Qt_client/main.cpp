#include <QtGui/QApplication>
#include <QTextCodec>
#include "login.h"
#include "zhuce.h"
#include "chat.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login w;
    w.show();

    return a.exec();
}
