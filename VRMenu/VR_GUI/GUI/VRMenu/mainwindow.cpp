#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include"editApp.h"
#include<stdlib.h>

#include<iostream>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMinimizeButtonHint); //get rid of 'X' from the window

    manager = AppManager::getInstance();
    updateAppList(); //update the app list

    //make the details texts as read only
    ui->Author_name->setReadOnly(true);
    ui->Descriptions->setReadOnly(true);
    ui->Year_Made->setReadOnly(true);
    ui->BashLoc->setReadOnly(true);

    NO_IMAGE_PATH = "../no-image.png";
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateAppList(){
    ui->list->clear();
    appList.clear();

    manager->getAppList(appList);
    for(auto i : appList) {
        ui->list->addItem( QString(i.c_str()) );
    }
}

void MainWindow::on_list_clicked() { //when an app is selected
    int selectedApp = ui->list->currentRow(); //determine which app is selected from the list
    AppInfo app_temp = manager->getAppInfo(appList[selectedApp]); //get the app info from manager

    //set the details based on the selected app//if not, start it
    ui->Author_name->setText( QString(app_temp.getAuthor().c_str()) );
    ui->Year_Made->setText(QString(app_temp.getYearBuilt().c_str()));
    ui->Descriptions->setText(QString(app_temp.getDescription().c_str()));
    ui->BashLoc->setText(QString(app_temp.getPathToBash().c_str()));
}

void MainWindow::on_run_clicked() { //run an app
    int selectedApp = ui->list->currentRow();

    if(selectedApp >= 0 && selectedApp < appList.size()) {
         disableButtons();
        if(!manager->runApp(appList[selectedApp])) {
            QMessageBox::information(this, "ERROR", "APP COULD NOT RUN");
        }
        this->update();
    }
}
/*
void MainWindow::on_Remove_clicked() { //remove an app
    int selectedApp = ui->list->currentRow();

    if(selectedApp >= 0 && selectedApp < appList.size()) {
        manager->removeApp(appList[selectedApp]);
    }

    //update list
      this->updateAppList();
}
*/


void MainWindow::on_QuitButton_clicked() { //Quit
    manager->quit();
    QCoreApplication::quit();
}
/*
void MainWindow::on_edit_clicked() { //edit info
    //get the app that is selected


    if(ui->list->currentRow() >= 0 && ui->list->currentRow() < appList.size()) {
        disableButtons();
        AppInfo changedApp = manager->getAppInfo(appList[ui->list->currentRow()]);

       //create editWindow and set the app//if not, start it
        EditApp *editInfo = new EditApp();
        editInfo->setApp(changedApp);

       //connect
        connect(editInfo, SIGNAL(destroyed()), this, SLOT(update()) );

       //run it
         editInfo->show();
    }


}
*/
void MainWindow::on_add_clicked() {
     disableButtons();
    //get the app that is selected
    AppInfo changedApp;

    //testing the directory explore//if not, start it
    Dialog *dirBox = new Dialog();
    //dirBox->setApp(changedApp);

    connect( dirBox, SIGNAL(destroyed()), this, SLOT(update()) );
    dirBox->show();
}


void MainWindow::update() {
    ui->run->setEnabled(true); //disable run
    //ui->edit->setEnabled(true); //disable edit info
    ui->QuitButton->setEnabled(true);
    //ui->Remove->setEnabled(true);
    ui->add->setEnabled(true);

    this->updateAppList();
}

void MainWindow::disableButtons() {
    ui->run->setDisabled(true); //disable run
    //ui->edit->setDisabled(true); //disable edit info
    ui->QuitButton->setDisabled(true);
    //ui->Remove->setDisabled(true);
    ui->add->setDisabled(true);
}

void MainWindow::on_pushButton_clicked() //the retsart vrpn button
{
    manager->restartVRPN();
}
