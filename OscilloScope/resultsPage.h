//
// Created by kalistrat on 10.08.2017.
//

#ifndef OSCILLOSCOPE_RESULTSPAGE_H
#define OSCILLOSCOPE_RESULTSPAGE_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>

class resultsPage : public QWidget  {
    Q_OBJECT

public:
    resultsPage (QWidget *parent = 0);

private:
    QLabel *pageName;

};


#endif //OSCILLOSCOPE_RESULTSPAGE_H
