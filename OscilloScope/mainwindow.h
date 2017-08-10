//
// Created by kalistrat on 03.08.2017.
//

#ifndef OSCILLOSCOPE_MAIN_WINDOW_H
#define OSCILLOSCOPE_MAIN_WINDOW_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QDialogButtonBox>
#include "deviceAccessPage.h"
#include "importFilePage.h"
#include "resultsPage.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    //void createFormInterior();
    QPushButton *CheckDeviceAccButton;
    QLabel *AccLabel;
    QListWidget *listWidget;
    QListWidgetItem *itemAccessPage;
    QListWidgetItem *itemExportPage;
    QListWidgetItem *itemResultPage;

    QStackedLayout *stackLay;
    deviceAccessPage *AccessPage;
    importFilePage *impFilePage;
    resultsPage *resPage;
    QPushButton *pbExit;
    QHBoxLayout *buttonBox;

private slots:
    void onAccessItemClicked(QListWidgetItem* item);
};


#endif //OSCILLOSCOPE_MAIN_WINDOW_H
