/********************************************************************************
** Form generated from reading UI file 'editApp.ui'
**
** Created: Wed Apr 24 11:39:48 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITAPP_H
#define UI_EDITAPP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditApp
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *AppForm;
    QTextEdit *newName;
    QLabel *name;
    QLabel *YearBuilt;
    QTextEdit *bashPath;
    QTextEdit *newDescription;
    QLabel *PathToBash;
    QTextEdit *author;
    QLabel *label;
    QLabel *Chef;
    QTextEdit *newYear;
    QLabel *logo;
    QPushButton *Done;
    QPushButton *Cancel;

    void setupUi(QDialog *EditApp)
    {
        if (EditApp->objectName().isEmpty())
            EditApp->setObjectName(QString::fromUtf8("EditApp"));
        EditApp->resize(641, 559);
        gridLayoutWidget = new QWidget(EditApp);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 315, 561, 191));
        AppForm = new QGridLayout(gridLayoutWidget);
        AppForm->setObjectName(QString::fromUtf8("AppForm"));
        AppForm->setContentsMargins(0, 0, 0, 0);
        newName = new QTextEdit(gridLayoutWidget);
        newName->setObjectName(QString::fromUtf8("newName"));

        AppForm->addWidget(newName, 0, 1, 1, 1);

        name = new QLabel(gridLayoutWidget);
        name->setObjectName(QString::fromUtf8("name"));

        AppForm->addWidget(name, 0, 0, 1, 1);

        YearBuilt = new QLabel(gridLayoutWidget);
        YearBuilt->setObjectName(QString::fromUtf8("YearBuilt"));

        AppForm->addWidget(YearBuilt, 2, 0, 1, 1);

        bashPath = new QTextEdit(gridLayoutWidget);
        bashPath->setObjectName(QString::fromUtf8("bashPath"));

        AppForm->addWidget(bashPath, 4, 1, 1, 1);

        newDescription = new QTextEdit(gridLayoutWidget);
        newDescription->setObjectName(QString::fromUtf8("newDescription"));

        AppForm->addWidget(newDescription, 3, 1, 1, 1);

        PathToBash = new QLabel(gridLayoutWidget);
        PathToBash->setObjectName(QString::fromUtf8("PathToBash"));

        AppForm->addWidget(PathToBash, 4, 0, 1, 1);

        author = new QTextEdit(gridLayoutWidget);
        author->setObjectName(QString::fromUtf8("author"));

        AppForm->addWidget(author, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        AppForm->addWidget(label, 3, 0, 1, 1);

        Chef = new QLabel(gridLayoutWidget);
        Chef->setObjectName(QString::fromUtf8("Chef"));

        AppForm->addWidget(Chef, 1, 0, 1, 1);

        newYear = new QTextEdit(gridLayoutWidget);
        newYear->setObjectName(QString::fromUtf8("newYear"));

        AppForm->addWidget(newYear, 2, 1, 1, 1);

        logo = new QLabel(EditApp);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(150, 10, 331, 301));
        logo->setPixmap(QPixmap(QString::fromUtf8("../waiter.gif")));
        Done = new QPushButton(EditApp);
        Done->setObjectName(QString::fromUtf8("Done"));
        Done->setGeometry(QRect(490, 510, 98, 27));
        Cancel = new QPushButton(EditApp);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(380, 510, 98, 27));

        retranslateUi(EditApp);

        QMetaObject::connectSlotsByName(EditApp);
    } // setupUi

    void retranslateUi(QDialog *EditApp)
    {
        EditApp->setWindowTitle(QApplication::translate("EditApp", "Dialog", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("EditApp", "Name : ", 0, QApplication::UnicodeUTF8));
        YearBuilt->setText(QApplication::translate("EditApp", "Year Built : ", 0, QApplication::UnicodeUTF8));
        PathToBash->setText(QApplication::translate("EditApp", "Path To Bash : ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EditApp", "Description", 0, QApplication::UnicodeUTF8));
        Chef->setText(QApplication::translate("EditApp", "Chef : ", 0, QApplication::UnicodeUTF8));
        logo->setText(QString());
        Done->setText(QApplication::translate("EditApp", "Done", 0, QApplication::UnicodeUTF8));
        Cancel->setText(QApplication::translate("EditApp", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditApp: public Ui_EditApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITAPP_H
