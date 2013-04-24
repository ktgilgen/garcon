/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 24 11:39:48 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *tittle;
    QLabel *logo;
    QLabel *label;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *mainMenu;
    QVBoxLayout *entres;
    QLabel *tittle_2;
    QListWidget *list;
    QPushButton *add;
    QLabel *label_2;
    QGridLayout *Details;
    QTextEdit *Year_Made;
    QLabel *details;
    QLabel *year;
    QLabel *chef;
    QTextEdit *Author_name;
    QTextEdit *Descriptions;
    QLabel *Bash;
    QTextEdit *BashLoc;
    QHBoxLayout *actions;
    QPushButton *run;
    QSplitter *splitter;
    QPushButton *restartVRPN;
    QPushButton *showControls;
    QPushButton *QuitButton;
    QMenuBar *menuBar;
    QMenu *menuGARCON;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(823, 994);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../chameleon_logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 20, 761, 311));
        tittle = new QHBoxLayout(horizontalLayoutWidget);
        tittle->setSpacing(6);
        tittle->setContentsMargins(11, 11, 11, 11);
        tittle->setObjectName(QString::fromUtf8("tittle"));
        tittle->setContentsMargins(0, 0, 0, 0);
        logo = new QLabel(horizontalLayoutWidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../waiter.gif")));

        tittle->addWidget(logo);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Chancery L"));
        font.setPointSize(72);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label->setFont(font);

        tittle->addWidget(label);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(30, 330, 781, 561));
        mainMenu = new QVBoxLayout(verticalLayoutWidget_3);
        mainMenu->setSpacing(6);
        mainMenu->setContentsMargins(11, 11, 11, 11);
        mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        mainMenu->setContentsMargins(0, 0, 0, 0);
        entres = new QVBoxLayout();
        entres->setSpacing(6);
        entres->setObjectName(QString::fromUtf8("entres"));
        tittle_2 = new QLabel(verticalLayoutWidget_3);
        tittle_2->setObjectName(QString::fromUtf8("tittle_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("TeXGyreSchola"));
        font1.setPointSize(28);
        font1.setItalic(true);
        tittle_2->setFont(font1);

        entres->addWidget(tittle_2);

        list = new QListWidget(verticalLayoutWidget_3);
        list->setObjectName(QString::fromUtf8("list"));

        entres->addWidget(list);

        add = new QPushButton(verticalLayoutWidget_3);
        add->setObjectName(QString::fromUtf8("add"));

        entres->addWidget(add);


        mainMenu->addLayout(entres);

        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        mainMenu->addWidget(label_2);

        Details = new QGridLayout();
        Details->setSpacing(6);
        Details->setObjectName(QString::fromUtf8("Details"));
        Year_Made = new QTextEdit(verticalLayoutWidget_3);
        Year_Made->setObjectName(QString::fromUtf8("Year_Made"));

        Details->addWidget(Year_Made, 1, 1, 1, 1);

        details = new QLabel(verticalLayoutWidget_3);
        details->setObjectName(QString::fromUtf8("details"));

        Details->addWidget(details, 2, 0, 1, 1);

        year = new QLabel(verticalLayoutWidget_3);
        year->setObjectName(QString::fromUtf8("year"));

        Details->addWidget(year, 1, 0, 1, 1);

        chef = new QLabel(verticalLayoutWidget_3);
        chef->setObjectName(QString::fromUtf8("chef"));

        Details->addWidget(chef, 0, 0, 1, 1);

        Author_name = new QTextEdit(verticalLayoutWidget_3);
        Author_name->setObjectName(QString::fromUtf8("Author_name"));

        Details->addWidget(Author_name, 0, 1, 1, 1);

        Descriptions = new QTextEdit(verticalLayoutWidget_3);
        Descriptions->setObjectName(QString::fromUtf8("Descriptions"));

        Details->addWidget(Descriptions, 2, 1, 1, 1);

        Bash = new QLabel(verticalLayoutWidget_3);
        Bash->setObjectName(QString::fromUtf8("Bash"));

        Details->addWidget(Bash, 3, 0, 1, 1);

        BashLoc = new QTextEdit(verticalLayoutWidget_3);
        BashLoc->setObjectName(QString::fromUtf8("BashLoc"));

        Details->addWidget(BashLoc, 3, 1, 1, 1);


        mainMenu->addLayout(Details);

        actions = new QHBoxLayout();
        actions->setSpacing(6);
        actions->setObjectName(QString::fromUtf8("actions"));
        run = new QPushButton(verticalLayoutWidget_3);
        run->setObjectName(QString::fromUtf8("run"));

        actions->addWidget(run);


        mainMenu->addLayout(actions);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(30, 900, 309, 27));
        splitter->setOrientation(Qt::Horizontal);
        restartVRPN = new QPushButton(splitter);
        restartVRPN->setObjectName(QString::fromUtf8("restartVRPN"));
        splitter->addWidget(restartVRPN);
        showControls = new QPushButton(splitter);
        showControls->setObjectName(QString::fromUtf8("showControls"));
        splitter->addWidget(showControls);
        QuitButton = new QPushButton(splitter);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));
        splitter->addWidget(QuitButton);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 823, 25));
        menuGARCON = new QMenu(menuBar);
        menuGARCON->setObjectName(QString::fromUtf8("menuGARCON"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGARCON->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        logo->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Gar\303\247on", 0, QApplication::UnicodeUTF8));
        tittle_2->setText(QApplication::translate("MainWindow", "Entr\303\251s", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("MainWindow", "Add One", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "==============================================================================================", 0, QApplication::UnicodeUTF8));
        details->setText(QApplication::translate("MainWindow", "Details : ", 0, QApplication::UnicodeUTF8));
        year->setText(QApplication::translate("MainWindow", "Year : ", 0, QApplication::UnicodeUTF8));
        chef->setText(QApplication::translate("MainWindow", "Chef : ", 0, QApplication::UnicodeUTF8));
        Bash->setText(QApplication::translate("MainWindow", "Recipe : ", 0, QApplication::UnicodeUTF8));
        run->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        restartVRPN->setText(QApplication::translate("MainWindow", "Restart VRPN", 0, QApplication::UnicodeUTF8));
        showControls->setText(QApplication::translate("MainWindow", "Show Controls", 0, QApplication::UnicodeUTF8));
        QuitButton->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        menuGARCON->setTitle(QApplication::translate("MainWindow", "GARCON", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
