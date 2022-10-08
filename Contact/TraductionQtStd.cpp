//
// Created by rahman on 08/10/22.
//

#include "TraductionQtStd.h"


QtFicheContact TraductionQtStd::StdFicheContacttoQtFicheContact(const StdFicheContact &contact)
{
    QDate date(static_cast<int>(contact.getDateCreation().year()),
               static_cast<unsigned >(contact.getDateCreation().month()),
               static_cast<unsigned>(contact.getDateCreation().day()));
    QDateTime dateTime;
    dateTime.setDate(date);

    QList<QString> list;

    for (const std::string &s: contact.getLstModif())
    {
        list.push_back(QString::fromStdString(s));
    }

    return QtFicheContact(QString::fromStdString(contact.getNom()), QString::fromStdString(contact.getPrenom()),
                          QString::fromStdString(contact.getEntreprise()), QString::fromStdString(contact.getMail()),
                          QString::fromStdString(contact.getTelephone()), QString::fromStdString(contact.getPhoto()),
                          dateTime, list);
}

StdFicheContact TraductionQtStd::QtFicheContactToStdFicheContact(const QtFicheContact &contact)
{

    date::year_month_day d(date::year(contact.getDateCreation().date().year()),
                           date::month(contact.getDateCreation().date().month()),
                           date::day(contact.getDateCreation().date().day()));

    std::list<std::string> lst;
    for (const auto &s: contact.getLstModif())
    {
        lst.push_back(s.toStdString());
    }

    return StdFicheContact(contact.getNom().toStdString(), contact.getPrenom().toStdString(),
                           contact.getEntreprise().toStdString(), contact.getMail().toStdString(),
                           contact.getTelephone().toStdString(), contact.getPhoto().toStdString(), d, lst);


}
