/********************************************************************************
** Form generated from reading UI file 'splashpage.ui'
**
** Created: Fri Oct 19 10:23:33 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHPAGE_H
#define UI_SPLASHPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SplashPage
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *SplashPage)
    {
        if (SplashPage->objectName().isEmpty())
            SplashPage->setObjectName(QString::fromUtf8("SplashPage"));
        SplashPage->resize(680, 856);
        label = new QLabel(SplashPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 140, 601, 671));
        label->setPixmap(QPixmap(QString::fromUtf8("../scaledharris.jpg")));
        label_2 = new QLabel(SplashPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 0, 281, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("TeXGyreBonum"));
        font.setPointSize(48);
        font.setItalic(true);
        label_2->setFont(font);
        label_3 = new QLabel(SplashPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 70, 181, 51));

        retranslateUi(SplashPage);

        QMetaObject::connectSlotsByName(SplashPage);
    } // setupUi

    void retranslateUi(QDialog *SplashPage)
    {
        SplashPage->setWindowTitle(QApplication::translate("SplashPage", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("SplashPage", "HPCVIS", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SplashPage", "(Pronounced \"HPC - VIZ\") ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SplashPage: public Ui_SplashPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHPAGE_H
