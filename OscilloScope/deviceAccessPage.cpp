//
// Created by kalistrat on 04.08.2017.
//

#include <QtWidgets/QHBoxLayout>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include "deviceAccessPage.h"

deviceAccessPage::deviceAccessPage (QWidget *parent)
        : QWidget (parent)
{
    pageName = new QLabel(trUtf8("Проверка доступности устройства"));

    progressBar = new QProgressBar();
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);

    AccLog = new QTextEdit();

    int PortCount = QSerialPortInfo::availablePorts().length();
    int PortIt = 0;
    int isSuccess = 0;

    AccLog->append("Производится опрашивание доступных портов");

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
    PortIt = PortIt + 1;
    int pBarValue = int((PortIt/PortCount)*100);
    progressBar->setValue(pBarValue);
    AccLog->append("Проверяется порт : " + info.portName() + " : устройство не найдено");
    QSerialPort serial;
    serial.setPort(info);
    if (serial.open(QIODevice::ReadWrite))
    serial.close();
    }

    AccLog->append("Проверка портов завершена");

    checkResultLabel = new QLabel();
    //checkResultIcon = new QLabel();

    QHBoxLayout *checkLay = new QHBoxLayout();
    checkLay->addWidget(checkResultLabel);
    //checkLay->addWidget(checkResultIcon);

    if (isSuccess == 0) {
        checkResultLabel->setText(trUtf8("Устройство не найдено. Подключите его и повторите поиск"));
        //QPixmap pix("search-fail.ico");
        //QPixmap scaledpix = pix.scaled(QSize(20,20),  Qt::KeepAspectRatio);
        //checkResultIcon->setPixmap(scaledpix);
    } else {
        checkResultIcon->setText(" successable");
    }



    QVBoxLayout *deviceAccessLayout = new QVBoxLayout();
    deviceAccessLayout->addWidget(pageName);
    deviceAccessLayout->addWidget(progressBar);
    deviceAccessLayout->addWidget(AccLog);
    deviceAccessLayout->addLayout(checkLay);

    this->setLayout(deviceAccessLayout);
}
