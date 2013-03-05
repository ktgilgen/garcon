#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include<string>
#include <QtGui>
#include"../../garcon/src/AppManager.h"
#include "../../garcon/src/AppInfo.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QDirModel *model;
    QString selectedFile;
    AppManager *manager;
};

#endif // DIALOG_H
