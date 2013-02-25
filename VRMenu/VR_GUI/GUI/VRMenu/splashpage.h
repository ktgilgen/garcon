#ifndef SPLASHPAGE_H
#define SPLASHPAGE_H

#include <QDialog>
#include<QSplashScreen>

namespace Ui {
class SplashPage;
}

class SplashPage : public QDialog
{
    Q_OBJECT
    
public:
    explicit SplashPage(QWidget *parent = 0);
    ~SplashPage();
    
private:
    Ui::SplashPage *ui;
};

#endif // SPLASHPAGE_H
