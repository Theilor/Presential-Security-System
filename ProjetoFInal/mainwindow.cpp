#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detected.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
QSerialPort *serialPort;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serialPort = new QSerialPort(this);
    serialPort->setPortName("com1");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setDataTerminalReady(true);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->open(QIODevice::ReadWrite);
}

MainWindow::~MainWindow()
{
    delete ui;
    serialPort->close();
}


void MainWindow::on_pushButton_toggled(bool checked)
{
    QByteArray data;
    serialPort->readyRead();
    data=serialPort->readAll();
        if (data != NULL){
            detected *dtc = new detected(this);
            dtc->setAttribute(Qt::WA_DeleteOnClose);
            dtc->show();
            data = NULL;
            }
}

