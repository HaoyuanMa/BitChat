/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created: Tue Sep 3 14:30:37 2019
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QScrollBar *verticalScrollBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(800, 600);
        centralwidget = new QWidget(Chat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 20, 761, 301));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(690, 340, 88, 27));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(710, 510, 71, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(620, 510, 71, 32));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 380, 761, 111));
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(760, 20, 20, 301));
        verticalScrollBar->setOrientation(Qt::Vertical);
        Chat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Chat);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Chat->setMenuBar(menubar);
        statusbar = new QStatusBar(Chat);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chat->setStatusBar(statusbar);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QMainWindow *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Chat", "\350\201\212\345\244\251\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Chat", "close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
