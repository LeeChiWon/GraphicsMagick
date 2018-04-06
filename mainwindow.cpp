#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit_LoadPath,SIGNAL(clicked()),this,SLOT(on_LineEdit_LoadPath()));
    connect(ui->lineEdit_SavePath,SIGNAL(clicked()),this,SLOT(on_LineEdit_SavePath()));
    InitializeMagick("GraphicsMagick");
    ui->comboBox_SelectMenu->addItems(QStringList()<<"Transparent");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LineEdit_LoadPath()
{
    QString FilePath=ui->lineEdit_LoadPath->text();
    if(!FilePath.isEmpty())
    {
        QDesktopServices::openUrl(QUrl(FilePath.prepend("file:///")));
    }
}

void MainWindow::on_LineEdit_SavePath()
{
    QString FilePath=ui->lineEdit_SavePath->text();
    if(!FilePath.isEmpty())
    {
        QDesktopServices::openUrl(QUrl(FilePath.prepend("file:///")));
    }
}


void MainWindow::on_pushButton_Convert_clicked()
{
    if(!ui->lineEdit_LoadPath->text().isEmpty() && !ui->lineEdit_SavePath->text().isEmpty())
    {
        switch (ui->comboBox_SelectMenu->currentIndex())
        {
        case MENU_TRANSPARENT:
            Image testImage;
            testImage.read(ui->lineEdit_LoadPath->text().toStdString());
            testImage.colorFuzz(2);
            testImage.transparent(Color("rgb(65535,65535,65535"));
            testImage.write(ui->lineEdit_SavePath->text().toStdString());
            break;
        }
        QMessageBox::information(this,"Infomation","Image converted.");
    }
}

void MainWindow::on_pushButton_Load_clicked()
{
    ui->lineEdit_LoadPath->setText(QFileDialog::getOpenFileName(this,"Load Image",NULL,"Image(*.jpg *.png *.bmp)"));
}

void MainWindow::on_pushButton_Save_clicked()
{
    ui->lineEdit_SavePath->setText(QFileDialog::getSaveFileName(this,"Save Image",NULL,"Image(*.jpg);;Image(*.png);;Image(*.bmp)"));
}
