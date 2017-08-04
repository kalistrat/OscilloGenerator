//
// Created by kalistrat on 04.08.2017.
//

#ifndef OSCILLOSCOPE_EXPORTFILE_H
#define OSCILLOSCOPE_EXPORTFILE_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

class importFilePage : public QWidget {
    Q_OBJECT

public:
    importFilePage (QWidget *parent = 0);

private:
    QLabel *pageName;
};


#endif //OSCILLOSCOPE_EXPORTFILE_H
