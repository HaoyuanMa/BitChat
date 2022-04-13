/********************************************************************************
** Form generated from reading UI file 'zhuce.ui'
**
** Created: Sun Sep 1 22:25:06 2019
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUCE_H
#define UI_ZHUCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ZhuCe
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *ZhuCe)
    {
        if (ZhuCe->objectName().isEmpty())
            ZhuCe->setObjectName(QString::fromUtf8("ZhuCe"));
        ZhuCe->resize(400, 300);
        label = new QLabel(ZhuCe);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 60, 17));
        label_2 = new QLabel(ZhuCe);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 60, 17));
        label_3 = new QLabel(ZhuCe);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 120, 60, 17));
        lineEdit = new QLineEdit(ZhuCe);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 50, 113, 27));
        lineEdit_2 = new QLineEdit(ZhuCe);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 80, 113, 27));
        lineEdit_3 = new QLineEdit(ZhuCe);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 110, 113, 27));
        pushButton = new QPushButton(ZhuCe);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(230, 220, 88, 27));
        label_4 = new QLabel(ZhuCe);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 180, 60, 17));
        lineEdit_4 = new QLineEdit(ZhuCe);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 140, 113, 27));
        label_5 = new QLabel(ZhuCe);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 150, 60, 17));
        lineEdit_5 = new QLineEdit(ZhuCe);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(110, 170, 113, 27));

        retranslateUi(ZhuCe);

        QMetaObject::connectSlotsByName(ZhuCe);
    } // setupUi

    void retranslateUi(QDialog *ZhuCe)
    {
        ZhuCe->setWindowTitle(QApplication::translate("ZhuCe", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ZhuCe", "\346\226\260\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ZhuCe", "\346\226\260\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ZhuCe", "\345\257\206\347\240\201\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ZhuCe", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ZhuCe", "\347\255\224\346\241\210", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ZhuCe", "\345\257\206\344\277\235\351\227\256\351\242\230", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZhuCe: public Ui_ZhuCe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCE_H
