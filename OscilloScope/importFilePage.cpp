//
// Created by kalistrat on 04.08.2017.
//

#include <QtWidgets/QHBoxLayout>
#include "importFilePage.h"

importFilePage::importFilePage (QWidget *parent)
        : QWidget (parent)
{
    pageName = new QLabel(trUtf8("Импорт файла с исследуемыми частотами"));
    QHBoxLayout *exportFileLayout = new QHBoxLayout();
    exportFileLayout->addWidget(pageName);
    this->setLayout(exportFileLayout);
}