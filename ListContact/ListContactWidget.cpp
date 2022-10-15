//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ListContactWidget.h"
#include "GroupeBoxContact.h"
#include <QLabel>
#include <QLineEdit>

ListContactWidget::ListContactWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(QSize(500, 500));

    setContentsMargins(0,0,0,0);

    lay = new QVBoxLayout(this);

    scrollArea = new QScrollArea(this);
    scrollArea->setStyleSheet("QScrollArea{border: none;}");
    scrollAreaWidget = new QWidget;
    layScrollArea = new QVBoxLayout(scrollAreaWidget);

    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lay->addWidget(scrollArea);


    for (auto contact: *(qobject_cast<MainWindow *>(parent)->getLstContact())->getLstContact())
    {
        layScrollArea->addWidget(new GroupeBoxContact(contact, this));
    }
}
