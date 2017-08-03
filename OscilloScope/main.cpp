#include <iostream>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    std::cout << QT_VERSION_STR << std::endl;
    QApplication app(argc, argv);
    MainWindow md;
    md.show();
    return app.exec();
}