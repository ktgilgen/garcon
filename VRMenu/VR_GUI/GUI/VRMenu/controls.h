#ifndef CONTROLS_H
#define CONTROLS_H

#include <QDialog>
#include <string>


namespace Ui {
class Controls;
}

class Controls : public QDialog
{
    Q_OBJECT
    
public:
    explicit Controls(QWidget *parent = 0);
    ~Controls();
    void display(std::string imagePath);
    
private:
    Ui::Controls *ui;
};

#endif // CONTROLS_H
