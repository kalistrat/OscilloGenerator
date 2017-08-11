//
// Created by kalistrat on 04.08.2017.
//

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtCore/QTextStream>
#include "importFilePage.h"
#include <QDebug>

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

    //readFileLog->append("Производится построчное чтение файла");
    readFileLayout->addWidget(pageName);
    readFileLayout->addLayout(fileLayout);
    readFileLayout->addWidget(progressBarFile);
    readFileLayout->addWidget(readFileLog);

    this->setLayout(readFileLayout);

}

void importFilePage::handleButton()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    QString::fromUtf8("Указать файл"),
                                                    QDir::currentPath(),
                                                    "*.csv");
    qDebug()<<fileName;

    QFile file(fileName);


    int nRows = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        nRows = QTextStream(&file).readAll().split('\n').count();
    file.close();
    qDebug() << nRows;

    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "Файл не найден";
    } else {
        // Создаём поток для извлечения данных из файла
        QTextStream in(&file);
        // Считываем данные до конца файла
        int kRow=0;
        while (!in.atEnd())
        {
            kRow = kRow + 1;
            // ... построчно
            QString line = in.readLine();
            readFileLog->append(line);

            int pBarValue = int((kRow/nRows)*100);
            progressBarFile->setValue(pBarValue);
        }
        file.close();
    }
}