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

    [[nodiscard]] const QString &getNom() const;

    void setNom(const QString &nom);

    [[nodiscard]] const QString &getPrenom() const;

    void setPrenom(const QString &prenom);

    [[nodiscard]] const QString &getEntreprise() const;

    void setEntreprise(const QString &entreprise);

    [[nodiscard]] const QString &getMail() const;

    void setMail(const QString &mail);

    [[nodiscard]] const QString &getTelephone() const;

    void setTelephone(const QString &telephone);

    [[nodiscard]] const QString &getPhoto() const;

    void setPhoto(const QString &photo);

    [[nodiscard]] uint64_t getDateCreation() const;

    void setDateCreation(uint64_t dateCreation);
};

#endif //PROJET_QT_QTCONTACT_H
