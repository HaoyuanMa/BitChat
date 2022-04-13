/********************************************************************************
** Form generated from reading UI file 'liaotian.ui'
**
** Created: Sat Aug 31 20:41:07 2019
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIAOTIAN_H
#define UI_LIAOTIAN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LiaoTian
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QScrollBar *verticalScrollBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LiaoTian)
    {
        if (LiaoTian->objectName().isEmpty())
            LiaoTian->setObjectName(QString::fromUtf8("LiaoTian"));
        LiaoTian->resize(800, 600);
        centralwidget = new QWidget(LiaoTian);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 0, 60, 17));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 250, 441, 27));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 290, 88, 27));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 30, 441, 192));
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(470, 30, 20, 191));
        verticalScrollBar->setOrientation(Qt::Vertical);
        LiaoTian->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LiaoTian);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        LiaoTian->setMenuBar(menubar);
        statusbar = new QStatusBar(LiaoTian);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LiaoTian->setStatusBar(statusbar);

        retranslateUi(LiaoTian);

        QMetaObject::connectSlotsByName(LiaoTian);
    } // setupUi

    void retranslateUi(QMainWindow *LiaoTian)
    {
        LiaoTian->setWindowTitle(QApplication::translate("LiaoTian", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LiaoTian", "\345\245\275\346\234\213\345\217\213", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LiaoTian", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LiaoTian: public Ui_LiaoTian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIAOTIAN_H
