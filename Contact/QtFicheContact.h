//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef UNTITLED2_QTFICHECONTACT_H
#define UNTITLED2_QTFICHECONTACT_H

#include <QDate>
#include <QString>
#include <QList>


class QtFicheContact
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
    QtFicheContact(const QString &nom, const QString &prenom, const QString &entreprise, const QString &mail,
                   const QString &telephone, const QString &photo, const QDateTime &dateCreation,
                   const QList<QString> &lstModif);

    const QList<QString> &getLstModif() const;

    void setLstModif(const QList<QString> &lstModif);

    explicit QtFicheContact();


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


#endif //UNTITLED2_QTFICHECONTACT_H
