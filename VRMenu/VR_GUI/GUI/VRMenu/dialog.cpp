#include "dialog.h"
#include "ui_dialog.h"
#include <string>
#include <QtDebug>
#include <iostream>
#include <fstream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model = new QDirModel(this);
    model->setReadOnly(true); //makes ths file system able to eb altered... make true for file select

    ui->treeView->setModel(model);

    QModelIndex index = model->index("/home");
    ui->treeView->setRootIndex(index);
    ui->treeView->resizeColumnToContents(0);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);


    //get instance of the app manager
    manager = AppManager::getInstance();

}
Dialog::~Dialog()
{
    delete ui;
}


//Select button
void Dialog::on_pushButton_clicked()
{
    char buffer = ' ';

    //select file
    QModelIndex index  = ui->treeView->currentIndex();
    QString selectedFile = (model->filePath(index) );
    std::string fileString = selectedFile.toStdString().c_str();

    // set up file reader
    std::ifstream fin;
    fin.clear();
    fin.open(fileString);


    // Check if file exists
    if(fin.good())
    {
    // If yes, get the file from the selected folder
        AppInfo newApp; //create temp app
        manager->getApp(fin, newApp); // get the app from the file
        newApp.setPathToGarcon(fileString);
        manager->addApp(newApp);  //put the app in the menu
    }
    // If no, don't do anything and print error message
    else
        QMessageBox::information(this, "ERROR", "INVALID FILE FORMAT");

    fin.close();

    //close window
    this->~Dialog();
}


//Cancel button
void Dialog::on_pushButton_2_clicked()
{
    //delete
    this->~Dialog();
}
