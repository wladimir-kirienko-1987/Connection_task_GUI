#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Load Image"), "",
            tr("Address Book (*.png);;All Files (*)"));

    if (myImage.load(fileName)){
      QPixmap img(fileName);
      ui->label->setPixmap(img);
      QBuffer buffer(&ba);
      buffer.open(QIODevice::WriteOnly);
      myImage.save(&buffer, "PNG"); // writes image into ba in PNG format
    }
    else{
       ui->label->setText("Image load fail");
    }
}

void MainWindow::on_pushButton_2_clicked()
{

    client.SetImageData(&ba);
    client.start("127.0.0.1", 8888);
}
