//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ModificationWidget.h"
#include "../Contact/FicheContact.h"
#include "WidgetContact.h"

ModificationWidget::ModificationWidget(QWidget *parent) : QDialog(parent)
{

    setModal(true);
    lay = new QVBoxLayout(this);

    scrollArea = new QScrollArea(this);
    scrollAreaWidget = new QWidget();
    layScrollArea = new QVBoxLayout(scrollAreaWidget);

    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lay->addWidget(scrollArea);


    FicheContact fich1;
    fich1.setNom("aaaa");
    fich1.setPrenom("bbbbb");
    fich1.setEntreprise("CCCCCC");
    fich1.setMail("CCrvfeerCCCC");
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));
    layScrollArea->addWidget(new WidgetContact(fich1));


}