//
// Created by kalistrat on 04.08.2017.
//

#include <QtWidgets/QHBoxLayout>
#include "deviceAccessPage.h"

deviceAccessPage::deviceAccessPage (QWidget *parent)
        : QWidget (parent)
{
    pageName = new QLabel(trUtf8("Проверка доступности устройства"));

    progressBar = new QProgressBar();
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);

    AccLog = new QTextEdit();

    for( int i = 0; i <100+1; ++i ) {
        progressBar->setValue(i);
        AccLog->append(QString::number(i));
    }



    QVBoxLayout *deviceAccessLayout = new QVBoxLayout();
    deviceAccessLayout->addWidget(pageName);
    deviceAccessLayout->addWidget(progressBar);
    deviceAccessLayout->addWidget(AccLog);

    this->setLayout(deviceAccessLayout);
}
