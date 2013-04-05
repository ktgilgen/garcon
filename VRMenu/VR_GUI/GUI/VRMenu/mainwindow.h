#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<QCloseEvent>
#include<vector>
#include "../../garcon/src/AppManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    
  public:
     explicit MainWindow(QWidget *parent = 0);
     ~MainWindow();    

  private slots:
     void on_list_clicked();
     void on_run_clicked();
     //void on_Remove_clicked();
     void on_QuitButton_clicked();
     //void on_edit_clicked();
     void update();


     void on_add_clicked();

     void on_pushButton_clicked();

private:
    void updateAppList(); //update the app list
    void disableButtons();

     Ui::MainWindow *ui;
     AppManager *manager;
     vector<string> appList;
     string NO_IMAGE_PATH;
};

#endif // MAINWINDOW_H
