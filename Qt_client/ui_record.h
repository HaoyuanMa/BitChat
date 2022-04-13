/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created: Tue Sep 3 15:47:41 2019
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_record
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QScrollBar *verticalScrollBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *record)
    {
        if (record->objectName().isEmpty())
            record->setObjectName(QString::fromUtf8("record"));
        record->resize(800, 600);
        centralwidget = new QWidget(record);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 30, 761, 511));
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(760, 30, 20, 511));
        verticalScrollBar->setOrientation(Qt::Vertical);
        record->setCentralWidget(centralwidget);
        menubar = new QMenuBar(record);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        record->setMenuBar(menubar);
        statusbar = new QStatusBar(record);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        record->setStatusBar(statusbar);

        retranslateUi(record);

        QMetaObject::connectSlotsByName(record);
    } // setupUi

    void retranslateUi(QMainWindow *record)
    {
        record->setWindowTitle(QApplication::translate("record", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class record: public Ui_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
