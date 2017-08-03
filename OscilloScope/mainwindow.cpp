//
// Created by kalistrat on 03.08.2017.
//

#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtWidgets/QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    QWidget * wgt = new QWidget(this);
    setCentralWidget(wgt);
    setWindowTitle(tr("Генератор сигнала"));
    setWindowIcon(QIcon("icon1.ico"));

    QPixmap bimg("icon1.ico");
    CheckDeviceAccButton = new QPushButton();
    CheckDeviceAccButton->setIcon(bimg);
    CheckDeviceAccButton->setWindowIcon(QIcon("icon1.ico"));

    AccLabel = new QLabel("Проверить доступность генератора : ");
    // устанавливаем размер и положение кнопки

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(AccLabel);
    mainLayout->addWidget(CheckDeviceAccButton);
    wgt->setLayout(mainLayout);

//    connect(CheckDeviceAccButton, SIGNAL (released()), this, SLOT (handleButton()));

    //createFormInterior();
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

void MainWindow::handleButton()
{
    // меняем текст
    CheckDeviceAccButton->setText("Example");
    // изменяем размер кнопки
    CheckDeviceAccButton->resize(100,100);
}