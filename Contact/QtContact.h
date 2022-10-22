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

/**
* @details  Classe QtContact : Modélise un contact avec les primitives de Qt.
*/
class QtContact
{

private:
    QString Nom;
    QString Prenom;
    QString Entreprise;
    QString Mail;
    QString Telephone;
    QString Photo;
    std::uint64_t DateCreation{};
    ListInteraction *lstInteraction{};

public:
    QtContact(const QString &nom, const QString &prenom, const QString &entreprise, const QString &mail,
              const QString &telephone, const QString &photo, const uint64_t &dateCreation,
              const ListInteraction &lstInteraction);

    const ListInteraction getLstInteraction() const;

    ListInteraction *getLstInteraction();

    void setLstInteraction(const ListInteraction &lstInteraction);

    explicit QtContact();

    QtContact(const QtContact &qtContact);

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

    uint64_t getDateCreation() const;

    void setDateCreation(uint64_t dateCreation);
};

#endif //UNTITLED2_QTCONTACT_H
