#include "splashpage.h"
#include "ui_splashpage.h"

SplashPage::SplashPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashPage)
{
    ui->setupUi(this);
}

SplashPage::~SplashPage()
{
    delete ui;
}
