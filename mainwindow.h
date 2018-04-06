#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Magick++.h"
#include <QtWidgets>

#define MENU_TRANSPARENT 0

using namespace Magick;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_LineEdit_LoadPath();
    void on_pushButton_Convert_clicked();
    void on_LineEdit_SavePath();
    void on_pushButton_Load_clicked();
    void on_pushButton_Save_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
