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

    itemAccessPage = new QListWidgetItem (trUtf8("Доступность"), listWidget);
    itemExportPage = new QListWidgetItem (trUtf8("Импорт файла частот"), listWidget);

    stackLay = new QStackedLayout;
    stackLay->addWidget(AccessPage);
    stackLay->addWidget(impFilePage);
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

        for( int i = 0; i <100+1; ++i ) {
            AccessPage->progressBar->setValue(i);
            AccessPage->AccLog->append(QString::number(i));
        }
                foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {

                std::cout << info.portName().toUtf8().toStdString() << std::endl;
                std::cout << info.description().toUtf8().toStdString() << std::endl;
                std::cout << info.manufacturer().toUtf8().toStdString() << std::endl;

                QSerialPort serial;
                serial.setPort(info);
                if (serial.open(QIODevice::ReadWrite))
                    serial.close();
            }


    }
}



