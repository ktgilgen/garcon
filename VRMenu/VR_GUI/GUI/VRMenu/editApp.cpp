
#include "editApp.h"
#include "ui_editApp.h"

EditApp::EditApp(QWidget *parent) : QDialog(parent), ui(new Ui::EditApp) {
    ui->setupUi(this);
     setWindowFlags(Qt::WindowMinimizeButtonHint);
    manager = AppManager::getInstance();
}

//copy the app that needs to be edited
void EditApp::setApp(AppInfo selectedApp) {
  app = selectedApp;
  //first remove the app
  manager->removeApp(app.getName()); //remove the app that is selected

  //set current values
  ui->author->setText( QString(app.getAuthor().c_str()) );
  ui->newName->setText( QString(app.getName().c_str()) );
  ui->bashPath->setText( QString(app.getPathToWorkingDirectory().c_str()) );
  ui->newDescription->setText( QString(app.getDescription().c_str()) );
  ui->newYear->setText( QString(app.getYearBuilt().c_str()) );

}


EditApp::~EditApp() {
    delete ui;
}

//when done is selected, copy all of the info into the app object
void EditApp::on_Done_clicked() {
    app.setAuthor((ui->author->toPlainText()).toStdString());
    app.setName(ui->newName->toPlainText().toStdString());
    app.setDescription(ui->newDescription->toPlainText().toStdString());
    app.setPathToWorkingDirectory(ui->bashPath->toPlainText().toStdString());
    app.setYearBuilt(ui->newYear->toPlainText().toStdString());

    manager->addApp(app);
    this->~EditApp();
}

void EditApp::on_Cancel_clicked() {
    manager->addApp(app);
    this->~EditApp();
}
