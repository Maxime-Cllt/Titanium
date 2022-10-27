//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef PROJET_QT_QTCONTACT_H
#define PROJET_QT_QTCONTACT_H

#include <QDate>
#include <QString>
#include <QList>
#include "../Interaction/Interaction.h"
#include "../Interaction/ListInteraction.h"

/**
* @details  Classe QtContact : Modélise un contact avec les primitives de Qt.
*/
class QtContact
{
public:
    QtContact(QString nom, QString prenom, QString entreprise, QString mail,
              QString telephone, QString photo, const uint64_t &dateCreation);

    explicit QtContact();

    QtContact(const QtContact &);

    ~QtContact();

private:
    QString nom;
    QString prenom;
    QString entreprise;
    QString mail;
    QString telephone;
    QString photo;
    std::uint64_t dateCreation{};

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

    uint64_t getDateCreation() const;

    void setDateCreation(uint64_t dateCreation);
};

#endif //PROJET_QT_QTCONTACT_H
