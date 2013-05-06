#include "controls.h"
#include "ui_controls.h"
#include <fstream>
#include <iostream>

Controls::Controls(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Controls)
{
    ui->setupUi(this);
}

Controls::~Controls()
{
    delete ui;
}

void Controls::display(std::string imagePath){
    ui->image->setPixmap(  QPixmap(  imagePath.c_str()  ).scaledToHeight(1275)  );
/*
    no longer necessary because of new check in app manager showImage
    if(imagePath.empty()){
        //if there is no imagePath use captian falcon
        ui->image->setPixmap(QPixmap("/home/demo/Pictures/Captainfalcon.png"));
    }
    else{
        ui->image->setPixmap(QPixmap(imagePath.c_str()));
    }
*/


}
