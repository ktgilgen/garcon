#include "controls.h"
#include "ui_controls.h"
#include <fstream>

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
    //check to make sure image file is good
    std::ifstream fin(imagePath.c_str());

    if(fin != 0){
        fin.close();
        ui->image->setPixmap(QPixmap(imagePath.c_str()));
    }
    else{
        //otherwise have captian falcon
        ui->image->setPixmap(QPixmap("/home/henry/Pictures/CaptainFalcon.png"));
        fin.close();
    }


}
