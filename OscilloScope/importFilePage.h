//
// Created by kalistrat on 04.08.2017.
//

#ifndef OSCILLOSCOPE_EXPORTFILE_H
#define OSCILLOSCOPE_EXPORTFILE_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>

class importFilePage : public QWidget {
    Q_OBJECT

public:
    importFilePage (QWidget *parent = 0);
    QProgressBar *progressBarFile;
    QTextEdit *readFileLog;
    QPushButton *pointFileButton;
    QLabel *fileNameLabel;

private:
    QLabel *pageName;

private slots:
    void handleButton();
};


#endif //OSCILLOSCOPE_EXPORTFILE_H
