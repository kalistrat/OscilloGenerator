//
// Created by kalistrat on 04.08.2017.
//

#ifndef OSCILLOSCOPE_DEVICEACCESSPAGE_H
#define OSCILLOSCOPE_DEVICEACCESSPAGE_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>

class deviceAccessPage : public QWidget {
    Q_OBJECT

public:
    deviceAccessPage (QWidget *parent = 0);
    QProgressBar *progressBar;
    QTextEdit *AccLog;
    QLabel *checkResultLabel;
    QLabel *checkResultIcon;


private:
    QLabel *pageName;


//private slots:
//    void slotRefresh();
//    void slotDeleteObject();
//    void slotAddObject();
//
//signals:
//    void signalRefresh();
};


#endif //OSCILLOSCOPE_DEVICEACCESSPAGE_H
