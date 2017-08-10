//
// Created by kalistrat on 04.08.2017.
//

#include <QtWidgets/QHBoxLayout>
#include "importFilePage.h"

importFilePage::importFilePage (QWidget *parent)
        : QWidget (parent)
{
    pageName = new QLabel(trUtf8("Импорт файла с исследуемыми частотами"));
    QVBoxLayout *readFileLayout = new QVBoxLayout();


    progressBarFile = new QProgressBar();
    progressBarFile->setMinimum(0);
    progressBarFile->setMaximum(100);

    readFileLog = new QTextEdit();
    pointFileButton = new QPushButton(trUtf8("Указать файл"),this);

    fileNameLabel = new QLabel();

    QHBoxLayout *fileLayout = new QHBoxLayout();
    fileLayout->addWidget(pointFileButton);
    fileLayout->addWidget(fileNameLabel);

    connect(pointFileButton, SIGNAL (released()), this, SLOT (handleButton()));

    readFileLog->append("Производится построчное чтение файла");
    readFileLayout->addWidget(pageName);
    readFileLayout->addLayout(fileLayout);
    readFileLayout->addWidget(progressBarFile);
    readFileLayout->addWidget(readFileLog);

    this->setLayout(readFileLayout);

}

void importFilePage::handleButton()
{

}