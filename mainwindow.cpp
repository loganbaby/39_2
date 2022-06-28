#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    exp = new QRegularExpression("^(\\+)(\\d{11})$");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_textEdited(const QString &newText)
{
    if(exp->match(newText).hasMatch()) {
        ui->label->setText("OK");
        ui->label->setStyleSheet("QLabel { color: green; }");
    } else {
        ui->label->setText("NOT OK");
        ui->label->setStyleSheet("QLabel { color: red; }");
    }
}

