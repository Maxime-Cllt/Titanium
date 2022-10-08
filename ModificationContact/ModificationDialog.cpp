//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ModificationDialog.h"
#include "../Contact/QtFicheContact.h"
#include "GroupeBoxContact.h"
#include <QLabel>
#include <QLineEdit>

ModificationDialog::ModificationDialog(QWidget *parent) : QDialog(parent)
{
    lstContact = qobject_cast<MainWindow *>(parent)->getLstContact();

    setModal(true);

    setMinimumSize(QSize(500, 500));

    lay = new QVBoxLayout(this);

    auto *layTop = new QHBoxLayout;

    layTop->addWidget(new QLabel("Rechercher un contact : "));

    auto *lineRecherche = new QLineEdit(this);
    lineRecherche->setPlaceholderText("toto");

    layTop->addWidget(lineRecherche);

    lay->addLayout(layTop);

    scrollArea = new QScrollArea(this);
    scrollAreaWidget = new QWidget();
    layScrollArea = new QVBoxLayout(scrollAreaWidget);

    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lay->addWidget(scrollArea);


    QtFicheContact fich1;
    fich1.setNom("aaaa");
    fich1.setPrenom("bbbbb");
    fich1.setEntreprise("CCCCCC");
    fich1.setMail("CCrvfeerCCCC");
    fich1.setPhoto("/home/rahman/Téléchargements/mw2.jpg");
    layScrollArea->addWidget(
            new GroupeBoxContact(TraductionQtStd::StdFicheContacttoQtFicheContact(*lstContact->takeAt(0))));
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