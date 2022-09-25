//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "CreateFicheWidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

CreateFicheWidget::CreateFicheWidget(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Creation de la fiche contacte");

    setMinimumSize(QSize(500,300));

    layout = new QVBoxLayout(this);
    layoutCenter = new QHBoxLayout;
    layGauche = new QVBoxLayout;
    layDroite = new QVBoxLayout;
    layoutCenter->addLayout(layGauche);
    layoutCenter->addLayout(layDroite);
    layout->addLayout(layoutCenter);
    layout->setSpacing(10);

    auto *lab1 = new QLabel("Nom : ");
    layGauche->addWidget(lab1);
    auto *le1 = new QLineEdit();
    layDroite->addWidget(le1);

    auto *lab2 = new QLabel("Prenom : ");
    layGauche->addWidget(lab2);
    auto *le2 = new QLineEdit();
    layDroite->addWidget(le2);

    auto *lab3 = new QLabel("Entreprise : ");
    layGauche->addWidget(lab3);
    auto *le3 = new QLineEdit();
    layDroite->addWidget(le3);

    auto *lab4 = new QLabel("mail : ");
    layGauche->addWidget(lab4);
    auto *le4 = new QLineEdit();
    layDroite->addWidget(le4);

    auto *lab5 = new QLabel("Téléphone : ");
    layGauche->addWidget(lab5);
    auto *le5 = new QLineEdit();
    layDroite->addWidget(le5);

    auto *lab6 = new QLabel("Photo : ");
    layGauche->addWidget(lab6);
    auto *le6 = new QLineEdit();
    layDroite->addWidget(le6);

    auto *lab7 = new QLabel("Date de creation de l'entreprise : ");
    lab7->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
    lab7->setMaximumWidth(150);
    lab7->setWordWrap(true);
    layGauche->addWidget(lab7);
    auto *le7 = new QLineEdit();
    layDroite->addWidget(le7);

    auto *bt = new QPushButton("Ajouter");

    layout->addWidget(bt);

    connect(bt,&QPushButton::clicked, this, [=](){

    });



}
