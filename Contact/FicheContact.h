//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef UNTITLED2_FICHECONTACT_H
#define UNTITLED2_FICHECONTACT_H

#include <QDate>
#include "QString"


class FicheContact
{

private:
    QString Nom;
    QString Prenom;
    QString Entreprise;
    QString Mail;
    QString Telephone;
    QString Photo;
    QDateTime DateCreation;
    QList<QString> lstModif;

public:
    const QString &getNom() const;

    void setNom(const QString &nom);

    const QString &getPrenom() const;

    void setPrenom(const QString &prenom);

    const QString &getEntreprise() const;

    void setEntreprise(const QString &entreprise);

    const QString &getMail() const;

    void setMail(const QString &mail);

    const QString &getTelephone() const;

    void setTelephone(const QString &telephone);

    const QString &getPhoto() const;

    void setPhoto(const QString &photo);

    const QDateTime &getDateCreation() const;

    void setDateCreation(const QDateTime &dateCreation);

};


#endif //UNTITLED2_FICHECONTACT_H
