//
// Created by kalistrat on 10.08.2017.
//

#include <QtWidgets/QHBoxLayout>
#include "resultsPage.h"

resultsPage::resultsPage (QWidget *parent)
        : QWidget (parent)
{
    pageName = new QLabel(trUtf8("Выполнение исследования"));
    QVBoxLayout *resultsLayout = new QVBoxLayout();
    resultsLayout->addWidget(pageName);
    this->setLayout(resultsLayout);
}