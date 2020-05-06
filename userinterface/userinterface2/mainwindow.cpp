#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>


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

void MainWindow::enableStyring()
{
    ui->groupBox->setEnabled(true);
    ui->lblstatus->setText("");
}

void MainWindow::on_btnFrem_pressed()
{
    std::cout<<"nåede så langt"<<std::endl;
    ui->lblstatus->setText("Kører fremad");
    socket.socketwrite('1');
    std::cout<<"nåede til efter write-metode"<<std::endl;
}

void MainWindow::on_btnFrem_released()
{
    ui->lblstatus->setText("");
    socket.socketwrite('0');
}

void MainWindow::on_btnVenstre_pressed()
{
    ui->lblstatus->setText("Drejer til venstre");
    socket.socketwrite('3');
}

void MainWindow::on_btnVenstre_released()
{
    ui->lblstatus->setText("");
    socket.socketwrite('0');
}

void MainWindow::on_btnHojre_pressed()
{
    ui->lblstatus->setText("Drejer til højre");
    socket.socketwrite('4');
}

void MainWindow::on_btnHojre_released()
{
    ui->lblstatus->setText("");
    socket.socketwrite('0');
}

void MainWindow::on_btnTilbage_pressed()
{
    ui->lblstatus->setText("Kører bagud");
    socket.socketwrite('2');
}

void MainWindow::on_btnTilbage_released()
{
    ui->lblstatus->setText("");
    socket.socketwrite('0');
}

void MainWindow::on_btnLoeft_clicked()
{
    ui->lblstatus->setText("Løfter objekt");
    ui->groupBox->setEnabled(false);
    QTimer::singleShot(3000,this, SLOT(enableStyring()));
    socket.socketwrite('8');
}

void MainWindow::on_btnSaenk_clicked()
{
    ui->lblstatus->setText("Sænker objekt");
    ui->groupBox->setEnabled(false);
    QTimer::singleShot(3000,this, SLOT(enableStyring()));
    socket.socketwrite('9');

}
