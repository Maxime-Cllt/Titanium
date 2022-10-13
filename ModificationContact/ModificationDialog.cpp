//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ModificationDialog.h"
#include "GroupeBoxContact.h"
#include <QLabel>
#include <QLineEdit>

ModificationDialog::ModificationDialog(QWidget *parent) : QDialog(parent)
{
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
    scrollArea->setStyleSheet("QScrollArea{border: none;}");
    scrollAreaWidget = new QWidget;
    layScrollArea = new QVBoxLayout(scrollAreaWidget);

    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lay->addWidget(scrollArea);

    StdContact *contact1 = new StdContact;
    contact1->setNom("Alooo");


    for (auto contact: *(qobject_cast<MainWindow *>(parent)->getLstContact())->getLstContact())
    {
        layScrollArea->addWidget(new GroupeBoxContact(contact, this));
    }
    layScrollArea->addWidget(new GroupeBoxContact(contact1,this));
    layScrollArea->addWidget(new GroupeBoxContact(contact1,this));


}
