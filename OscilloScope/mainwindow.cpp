//
// Created by kalistrat on 03.08.2017.
//

#include "mainwindow.h"
#include <QLineEdit>
#include <QtWidgets/QDialogButtonBox>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    QWidget * wgt = new QWidget(this);
    setCentralWidget(wgt);
    setWindowTitle(trUtf8("Генератор сигнала"));
    setWindowIcon(QIcon("icon1.ico"));

    buttonBox = new QHBoxLayout();
    pbExit = new QPushButton (trUtf8("Выход"), this);
    buttonBox->addWidget(pbExit);

    listWidget = new QListWidget (this);

    AccessPage = new deviceAccessPage(this);
    impFilePage = new importFilePage(this);
    resPage = new resultsPage(this);

    itemAccessPage = new QListWidgetItem (trUtf8("Подключение устройства"), listWidget);
    itemAccessPage->setIcon(QIcon("plugin.ico"));
    itemExportPage = new QListWidgetItem (trUtf8("Импорт файла частот"), listWidget);
    itemExportPage->setIcon(QIcon("import.ico"));
    itemResultPage = new QListWidgetItem (trUtf8("Выполнение исследования"), listWidget);
    itemResultPage->setIcon(QIcon("play.ico"));

    stackLay = new QStackedLayout;
    stackLay->addWidget(AccessPage);
    stackLay->addWidget(impFilePage);
    stackLay->addWidget(resPage);
    connect(listWidget, SIGNAL(currentRowChanged(int)),
            stackLay, SLOT(setCurrentIndex(int)));
    listWidget->setCurrentRow(0);

    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onAccessItemClicked(QListWidgetItem*)));



    QHBoxLayout *ContentLay = new QHBoxLayout();
    ContentLay->addWidget(listWidget);
    ContentLay->addLayout(stackLay);
    ContentLay->setStretchFactor(listWidget,1);
    ContentLay->setStretchFactor(stackLay,2);


    QVBoxLayout *mainLay = new QVBoxLayout();
    mainLay->addLayout(ContentLay);
    mainLay->addLayout(buttonBox);
    wgt->setLayout(mainLay);

    //tabViewPoint = new TabViewPoint(this);
}

MainWindow::~MainWindow()
{
}

//void MainWindow::createFormInterior()
//{
//    QWidget * wgt = new QWidget(this);
//    // создаем кнопку
//    CheckDeviceAccButton = new QPushButton;
//    CheckDeviceAccButton->setWindowIcon(QIcon("icon1.ico"));
//    // устанавливаем размер и положение кнопки
//    CheckDeviceAccButton->setGeometry(QRect(QPoint(100, 100),
//                                            QSize(200, 50)));
//
//    connect(CheckDeviceAccButton, SIGNAL (released()), this, SLOT (handleButton()));
//    QGridLayout *MainLayout;
//    MainLayout->addWidget(CheckDeviceAccButton);
//
//    //setCentralWidget(wgt);
//    wgt->setLayout(MainLayout);
//}


void MainWindow::onAccessItemClicked(QListWidgetItem* item)
{
    if (listWidget->item(0) == item) {

        int PortCount = QSerialPortInfo::availablePorts().length();
        int PortIt = 0;
        AccessPage->AccLog->append("Производится опрашивание доступных портов");

                foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
                PortIt = PortIt + 1;
                int pBarValue = int((PortIt/PortCount)*100);
                AccessPage->progressBar->setValue(pBarValue);
                AccessPage->AccLog->append("Проверяется порт : " + info.portName() + " : устройство не найдено");
                QSerialPort serial;
                serial.setPort(info);
                if (serial.open(QIODevice::ReadWrite))
                    serial.close();
            }

        AccessPage->AccLog->append("Проверка портов завершена");


    }
}



