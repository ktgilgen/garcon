/********************************************************************************
** Form generated from reading UI file 'controls.ui'
**
** Created: Tue Apr 23 16:52:11 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLS_H
#define UI_CONTROLS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Controls
{
public:
    QLabel *image;

    void setupUi(QDialog *Controls)
    {
        if (Controls->objectName().isEmpty())
            Controls->setObjectName(QString::fromUtf8("Controls"));
        Controls->resize(583, 478);
        image = new QLabel(Controls);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(0, 0, 581, 471));

        retranslateUi(Controls);

        QMetaObject::connectSlotsByName(Controls);
    } // setupUi

    void retranslateUi(QDialog *Controls)
    {
        Controls->setWindowTitle(QApplication::translate("Controls", "Dialog", 0, QApplication::UnicodeUTF8));
        image->setText(QApplication::translate("Controls", "                                                                     image path invalid", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Controls: public Ui_Controls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLS_H
