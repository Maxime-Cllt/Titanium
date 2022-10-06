//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "GroupeBoxContact.h"

#include <QLabel>
#include "ModifContactDialog.h"

GroupeBoxContact::GroupeBoxContact(FicheContact contact, QWidget *parent ) : QGroupBox(parent), contact(contact)
{

    layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->setSpacing(30);

    QPixmap im(contact.getPhoto());
    auto *labIm = new QLabel(this);
    labIm->setPixmap(im.scaled(50,50, Qt::KeepAspectRatio));
    layout->addWidget(labIm);
    layout->addWidget(new QLabel("Nom Prénom : " + contact.getNom() + " " + contact.getPrenom(),this),0,1);
    layout->addWidget(new QLabel("Entreprise : " + contact.getEntreprise(),this),0,2);
    layout->addWidget(new QLabel("Mail : " + contact.getMail(),this),1,1);
    layout->addWidget(new QLabel("Téléphone : " + contact.getTelephone(),this),1,2);

    for (auto lab : findChildren<QLabel *>())
    {
        lab->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    }

}


void GroupeBoxContact::mousePressEvent(QMouseEvent *event)
{
    QGroupBox::mousePressEvent(event);
    setStyleSheet("QGroupBox{background-color: gray;border-radius: 5px; color: white;}");
}


void GroupeBoxContact::mouseReleaseEvent(QMouseEvent *event)
{
    QGroupBox::mouseReleaseEvent(event);
    setStyleSheet("");
    ModifContactDialog modif(contact, this);
    modif.setModal(true);
    modif.exec();

}
