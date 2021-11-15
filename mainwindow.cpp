#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gamepad()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_apply_clicked()
{
    std::string str = "";
    QString button = ui->button_analogic->currentText();
    str += button.toStdString();
    button = ui->button_up->currentText();
    str += button.toStdString();
    button = ui->button_left->currentText();
    str += button.toStdString();
    button = ui->button_right->currentText();
    str += button.toStdString();
    button = ui->button_down->currentText();
    str += button.toStdString();
    gamepad.apply(str);
    gamepad.send();
}

