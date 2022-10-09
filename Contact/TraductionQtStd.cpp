//
// Created by rahman on 08/10/22.
//

#include "TraductionQtStd.h"


QtContact TraductionQtStd::StdFicheContacttoQtFicheContact(const StdContact &contact)
{
    QDate date(static_cast<int>(contact.getDateCreation().year()),
               static_cast<unsigned >(contact.getDateCreation().month()),
               static_cast<unsigned>(contact.getDateCreation().day()));
    QDateTime dateTime;
    dateTime.setDate(date);

    QList<Interaction> list;
    for (const auto &i: contact.getLstInteraction())
    {
        list.push_back(i);
    }

    return QtContact(QString::fromStdString(contact.getNom()), QString::fromStdString(contact.getPrenom()),
                     QString::fromStdString(contact.getEntreprise()), QString::fromStdString(contact.getMail()),
                     QString::fromStdString(contact.getTelephone()), QString::fromStdString(contact.getPhoto()),
                     dateTime, {});
}

StdContact TraductionQtStd::QtFicheContactToStdFicheContact(const QtContact &contact)
{

    date::year_month_day d(date::year(contact.getDateCreation().date().year()),
                           date::month(contact.getDateCreation().date().month()),
                           date::day(contact.getDateCreation().date().day()));

    std::list<Interaction> lst;
    for (const auto &i: contact.getLstInteraction())
    {
        lst.push_back(i);
    }

    return StdContact(contact.getNom().toStdString(), contact.getPrenom().toStdString(),
                      contact.getEntreprise().toStdString(), contact.getMail().toStdString(),
                      contact.getTelephone().toStdString(), contact.getPhoto().toStdString(), d, lst);


}
