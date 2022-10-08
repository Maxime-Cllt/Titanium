//
// Created by Rahman  Yilmaz on 07/10/2022.
//

#include "StdFicheContact.h"
#include "QtFicheContact.h"


StdFicheContact::StdFicheContact(const std::string &nom, const std::string &prenom, const std::string &entreprise,
                                 const std::string &mail, const std::string &telephone, const std::string &photo,
                                 const date::year_month_day &dateCreation, const std::list<std::string> &lstModif)
        : Nom(nom), Prenom(prenom), Entreprise(entreprise), Mail(mail), Telephone(telephone), Photo(photo),
          DateCreation(dateCreation), lstModif(lstModif) {}

StdFicheContact::StdFicheContact() {}

QtFicheContact StdFicheContact::toQtFicheContact()
{
    QDate date(static_cast<int>(DateCreation.year()), static_cast<unsigned >(DateCreation.month()),
               static_cast<unsigned>(DateCreation.day()));
    QDateTime dateTime;
    dateTime.setDate(date);

    QList<QString> list;

    for (std::string &s: lstModif)
    {
        list.push_back(QString::fromStdString(s));
    }

    return QtFicheContact(QString::fromStdString(Nom), QString::fromStdString(Prenom),
                          QString::fromStdString(Entreprise), QString::fromStdString(Mail),
                          QString::fromStdString(Telephone),
                          QString::fromStdString(Photo), dateTime, list);
}
