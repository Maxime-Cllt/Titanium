//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "GroupeBoxContact.h"

#include <QLabel>
#include "ModifContactDialog.h"

GroupeBoxContact::GroupeBoxContact(StdContact *contact, QWidget *parent) : QGroupBox(parent), contact(contact)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    QtContact qtContact(TraductionQtStd::StdFicheContacttoQtFicheContact(*contact));

    layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->setSpacing(30);

    QPixmap im(qtContact.getPhoto());
    auto *labIm = new QLabel(this);
    labIm->setPixmap(im.scaled(50, 50, Qt::KeepAspectRatio));
    layout->addWidget(labIm);
    layout->addWidget(new QLabel("Nom Prénom : " + qtContact.getNom() + " " + qtContact.getPrenom(), this), 0, 1);
    layout->addWidget(new QLabel("Entreprise : " + qtContact.getEntreprise(), this), 0, 2);
    layout->addWidget(new QLabel("Mail : " + qtContact.getMail(), this), 1, 1);
    layout->addWidget(new QLabel("Téléphone : " + qtContact.getTelephone(), this), 1, 2);

    for (auto lab: findChildren<QLabel *>())
    {
        lab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    }

}


void GroupeBoxContact::mousePressEvent(QMouseEvent *event)
{
    QGroupBox::mousePressEvent(event);
    setStyleSheet("QGroupBox{background-color: gray;border-radius: 5px; color: white;}");
    if (event->button() == Qt::RightButton)
    {
        auto *menu = new QMenu(this);

        auto *action1 = new QAction("Ajouter une interaction");

        auto *action2 = new QAction("Liste des interactions");

        menu->addAction(action1);
        menu->addAction(action2);

        menu->exec(event->globalPosition().toPoint());

        setStyleSheet("");

    }
}


void GroupeBoxContact::mouseReleaseEvent(QMouseEvent *event)
{
    QGroupBox::mouseReleaseEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        setStyleSheet("");

        ModifContactDialog modif(this->contact, this);
        modif.setModal(true);
        modif.exec();
    }

}

