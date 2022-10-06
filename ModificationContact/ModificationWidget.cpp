//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ModificationWidget.h"
#include "../Contact/FicheContact.h"
#include "GroupeBoxContact.h"
#include <QLabel>
#include <QLineEdit>

ModificationWidget::ModificationWidget(QWidget *parent) : QDialog(parent)
{

    setModal(true);

    setMinimumSize(QSize(500,500));

    lay = new QVBoxLayout(this);

    auto * layTop = new QHBoxLayout;

    layTop->addWidget(new QLabel("Rechercher un contact : "));

    auto* lineRecherche = new QLineEdit(this);

    layTop->addWidget(lineRecherche);

    lay->addLayout(layTop);

    scrollArea = new QScrollArea(this);
    scrollAreaWidget = new QWidget();
    layScrollArea = new QVBoxLayout(scrollAreaWidget);

    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    lay->addWidget(scrollArea);


    FicheContact fich1;
    fich1.setNom("aaaa");
    fich1.setPrenom("bbbbb");
    fich1.setEntreprise("CCCCCC");
    fich1.setMail("CCrvfeerCCCC");
    fich1.setPhoto("/Users/sr-71/Downloads/images.jpeg");
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));
    layScrollArea->addWidget(new GroupeBoxContact(fich1));


}