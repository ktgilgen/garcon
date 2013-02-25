#ifndef EDITAPP_H
#define EDITAPP_H

#include <QDialog>
#include"mainwindow.h"
#include"../../garcon/src/AppManager.h"
#include "../../garcon/src/AppInfo.h"

namespace Ui {
class EditApp;
}

class EditApp : public QDialog {
    Q_OBJECT
    
  public:

    explicit EditApp(QWidget *parent = 0);
    ~EditApp();

    void setApp(AppInfo selectedApp);
    
private slots:
    void on_Done_clicked();

    void on_Cancel_clicked();

private:
    Ui::EditApp *ui;
    AppInfo app;
    AppManager *manager;
};

#endif // EDITAPP_H
