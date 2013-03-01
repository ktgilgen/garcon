#include "dialog.h"
#include "ui_dialog.h"
#include <string>
#include <QtDebug>
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model = new QDirModel(this);
    model->setReadOnly(true); //makes ths file system able to eb altered... make true for file select

    ui->treeView->setModel(model);

    QModelIndex index = model->index("/home");
    /*ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);*/
    ui->treeView->setRootIndex(index);
}
Dialog::~Dialog()
{
    delete ui;
}


//Select button
void Dialog::on_pushButton_clicked()
{
    //select directory
    QModelIndex index  = ui->treeView->currentIndex();
    //get the name of the selected file
    //std::string pathSelected;
    Dialog::selectedPath = (model->filePath(index) );
    qDebug() << (selectedPath);

    //get the app info using path


}


//Cancel button
void Dialog::on_pushButton_2_clicked()
{
    //delete
    this->~Dialog();
}
