#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detected.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    qDebug() << "portas disponiveis: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "tem vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Tem id de produto: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Id de produto: " << serialPortInfo.productIdentifier();
        }
    }
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }
    if(arduino_is_available){
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        QMessageBox::warning(this, "Port Error", "Couldn't find Arduino!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    arduino->close();
}

void MainWindow::on_pushButton_toggled(bool checked)
{
    QByteArray data;
    arduino->readyRead();
    data=arduino->readAll();
        if (data != NULL){
            detected *dtc = new detected(this);
            dtc->setAttribute(Qt::WA_DeleteOnClose);
            dtc->show();
            data = NULL;
            }
}

