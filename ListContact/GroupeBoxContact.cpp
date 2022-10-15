//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "GroupeBoxContact.h"

#include <QLabel>
#include "ModifContactDialog.h"
#include "../Interaction/CreationInteractionDialog.h"
#include "../Interaction/ListInteractionDialog.h"

GroupeBoxContact::GroupeBoxContact(StdContact *contact, QWidget *parent) : QGroupBox(parent), contact(contact)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    setMaximumHeight(200);

    setObjectName("GroupBoxContact");

    layout = new QGridLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->setSpacing(30);

    createUi();

    for (auto lab: findChildren<QLabel *>())
    {
        lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    }

}


void GroupeBoxContact::mousePressEvent(QMouseEvent *event)
{
    QGroupBox::mousePressEvent(event);
    setStyleSheet("QGroupBox#GroupBoxContact{background-color: gray;border-radius: 10px; color: white;}");
    if (event->button() == Qt::RightButton)
    {
        auto *menu = new QMenu(this);

        auto *action1 = new QAction("Ajouter une interaction");

        auto *action2 = new QAction("Liste des interactions");

        auto *action3 = new QAction("Supprimer");

        menu->addAction(action1);
        menu->addAction(action2);
        menu->addAction(action3);

        connect(action1, &QAction::triggered, this, [=]()
        {
            CreationInteractionDialog diag(contact, this);
            diag.exec();
        });

        connect(action2, &QAction::triggered, this, [=]()
        {
            ListInteractionDialog diag(contact->getLstInteraction(), this);
            diag.exec();
        });

        connect(action3, &QAction::triggered, this, [=]()
        {
            BD::supContact(*contact);
            auto *mainWindow = new QObject(this);
            while (mainWindow->parent()) { mainWindow = mainWindow->parent(); }
            qobject_cast<MainWindow *>(mainWindow)->getLstContact()->supContact(contact);
            close();
            delete contact;
        });

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

void GroupeBoxContact::reactualiseDonne()
{
    QtContact qtContact(TraductionQtStd::StdFicheContacttoQtFicheContact(*contact));

    QPixmap im(qtContact.getPhoto());
    findChildren<QLabel *>()[0]->setPixmap(im.scaled(50, 50, Qt::KeepAspectRatio));
    findChildren<QLabel *>()[1]->setText("Nom Prénom : " + qtContact.getNom() + " " + qtContact.getPrenom());
    findChildren<QLabel *>()[2]->setText("Entreprise : " + qtContact.getEntreprise());
    findChildren<QLabel *>()[3]->setText("Mail : " + qtContact.getMail());
    findChildren<QLabel *>()[4]->setText("Téléphone : " + qtContact.getTelephone());

}

void GroupeBoxContact::createUi()
{
    QtContact qtContact(TraductionQtStd::StdFicheContacttoQtFicheContact(*contact));

    QPixmap im(qtContact.getPhoto());
    auto *labIm = new QLabel(this);
    labIm->setPixmap(im.scaled(50, 50, Qt::KeepAspectRatio));
    layout->addWidget(labIm);
    layout->addWidget(new QLabel("Nom Prénom : " + qtContact.getNom() + " " + qtContact.getPrenom(), this), 0, 1);
    layout->addWidget(new QLabel("Entreprise : " + qtContact.getEntreprise(), this), 0, 2);
    layout->addWidget(new QLabel("Mail : " + qtContact.getMail(), this), 1, 1);
    layout->addWidget(new QLabel("Téléphone : " + qtContact.getTelephone(), this), 1, 2);

}

