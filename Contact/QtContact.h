//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef UNTITLED2_QTCONTACT_H
#define UNTITLED2_QTCONTACT_H

#include <QDate>
#include <QString>
#include <QList>
#include "../Interaction/Interaction.h"
#include "../Interaction/ListInteraction.h"

class QtContact
{

private:
    QString Nom;
    QString Prenom;
    QString Entreprise;
    QString Mail;
    QString Telephone;
    QString Photo;
    std::time_t DateCreation{};
    ListInteraction lstInteraction;

public:
    QtContact(const QString &nom, const QString &prenom, const QString &entreprise, const QString &mail,
              const QString &telephone, const QString &photo, const time_t &dateCreation,
              const ListInteraction &lstInteraction);

    const ListInteraction getLstInteraction() const;

    ListInteraction *getLstInteraction();

    void setLstInteraction(const ListInteraction &lstInteraction);

    explicit QtContact();

    ~QtContact();

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

    time_t getDateCreation() const;

    void setDateCreation(time_t dateCreation);
};

#endif //UNTITLED2_QTCONTACT_H
