//
// Created by rahman on 08/10/22.
//

#include "TraductionQtStd.h"


QtContact TraductionQtStd::StdFicheContacttoQtFicheContact(const StdContact &contact)
{

    QList<Interaction *> list;
    for (auto i: contact.getLstInteraction())
    {
        list.push_back(i);
    }

    return QtContact(QString::fromStdString(contact.getNom()), QString::fromStdString(contact.getPrenom()),
                     QString::fromStdString(contact.getEntreprise()), QString::fromStdString(contact.getMail()),
                     QString::fromStdString(contact.getTelephone()), QString::fromStdString(contact.getPhoto()),
                     contact.getDateCreation(), {});
}

StdContact TraductionQtStd::QtFicheContactToStdFicheContact(const QtContact &contact)
{
    std::list<Interaction *> lst;
    for (const auto i: contact.getLstInteraction())
    {
        lst.push_back(i);
    }

    return StdContact(contact.getNom().toStdString(), contact.getPrenom().toStdString(),
                      contact.getEntreprise().toStdString(), contact.getMail().toStdString(),
                      contact.getTelephone().toStdString(), contact.getPhoto().toStdString(),
                      contact.getDateCreation(), lst);
}
