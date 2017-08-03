//
// Created by kalistrat on 03.08.2017.
//

#ifndef OSCILLOSCOPE_MAIN_WINDOW_H
#define OSCILLOSCOPE_MAIN_WINDOW_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

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

private slots:
    void handleButton();
};


#endif //OSCILLOSCOPE_MAIN_WINDOW_H
