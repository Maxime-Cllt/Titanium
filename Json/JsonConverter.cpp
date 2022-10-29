//
// Created by Rahman  Yilmaz on 28/10/2022.
//

#include <QJsonDocument>
#include <QFile>
#include "JsonConverter.h"

JsonConverter::JsonConverter(QObject *parent) : QObject(parent)
{

}

/**
 * @details Fonction qui prend un contact en parametre et crée un json avec tous les attributs du contact.
 * @param contact
 * @return
 */
QJsonObject JsonConverter::contactToJson(const StdContact &contact)
{
    QJsonObject jsonContact;

    jsonContact.insert("nom", QString::fromStdString(contact.getNom()));
    jsonContact.insert("prenom", QString::fromStdString(contact.getPrenom()));
    jsonContact.insert("entreprise", QString::fromStdString(contact.getEntreprise()));
    jsonContact.insert("mail", QString::fromStdString(contact.getMail()));
    jsonContact.insert("telephone", QString::fromStdString(contact.getTelephone()));
    jsonContact.insert("photo", QString::fromStdString(contact.getPhoto()));

    jsonContact.insert("interactions", interactionToJson(*contact.getLstInteraction()));


    QJsonObject json;
    json.insert(QString::number(contact.getDateCreation()), jsonContact);


    qDebug() << QJsonDocument(json).toJson(QJsonDocument::Indented);
    return json;
}

/**
 * @details Fonction qui transforme une liste de contact en un objet json avec les donnés des contact.
 * @param lst
 * @return
 */
QJsonObject JsonConverter::contactToJson(const StdListContact &lst)
{
    QJsonObject json;

    for (const auto &contact: *lst.getLstContact())
    {
        json.insert(QString::number(contact->getDateCreation()),
                    contactToJson(*contact)[QString::number(contact->getDateCreation())]);
    }
    return json;
}

/**
 * @details Renvoie sous forme de QJsonObjet les données d'une interaction.
 * @param interaction
 * @return json
 */
QJsonObject JsonConverter::interactionToJson(const Interaction &interaction)
{
    QJsonObject json;

    json.insert("contenu", QString::fromStdString(interaction.getContenu()));
    json.insert("dateModif", QString::number(interaction.getDateModif()));

    json.insert("taches", tacheToJson(*interaction.getLstTache()));

    return json;
}

/**
 * @details Renvoie sous forme de QJsonObjet les données d'une liste d'interactions.
 * @param lst
 * @return json
 */
QJsonObject JsonConverter::interactionToJson(const ListInteraction &lst)
{
    QJsonObject json;

    for (const auto &interaction: *lst.getListInteraction())
    {
        json.insert(QString::number(interaction->getDateCreation()), interactionToJson(*interaction));
    }
    return json;
}

/**
 * @details Renvoie sous forme de QJsonObjet les données d'une tache.
 * @param tache
 * @return json
 */
QJsonObject JsonConverter::tacheToJson(const Tache &tache)
{
    QJsonObject json;

    json.insert("date", QString::number(tache.getdate()));
    json.insert("contenu", QString::fromStdString(tache.getcontenu()));

    return json;
}

/**
 * @details Renvoie sous forme de QJsonObjet les données d'une liste de taches.
 * @param lst
 * @return json
 */
QJsonObject JsonConverter::tacheToJson(const ListTache &lst)
{
    QJsonObject json;

    int i = 0;
    for (const auto &tache: *lst.getLstTache())
    {
        json.insert(QString::number(i), tacheToJson(*tache));
        i++;
    }
    return json;
}



/**
 * @details Crée un StdContact depuis un fichier json.
 * @param filePath
 * @return
 */
StdListContact *JsonConverter::getContact(const QString &filePath)
{
    auto *lstContact = new StdListContact;

    QFile file(filePath);
    int res = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (res == false)
        return lstContact;

    QByteArray data = file.readAll();


    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson(data, &error);

    if (error.error != 0)
    {
        return lstContact;
    }

    auto contactMap = json.toVariant().toMap();
    for (const auto &key: contactMap.keys())
    {
        auto nom = contactMap.value(key).toMap().value("nom").toString().toStdString();
        auto prenom = contactMap.value(key).toMap().value("prenom").toString().toStdString();
        auto entreprise = contactMap.value(key).toMap().value("entreprise").toString().toStdString();
        auto mail = contactMap.value(key).toMap().value("mail").toString().toStdString();
        auto telephone = contactMap.value(key).toMap().value("telephone").toString().toStdString();
        auto photo = contactMap.value(key).toMap().value("photo").toString().toStdString();
//        auto *contact = new StdContact(contactMap.value(key).toString().toStdString(),)
//        lstContact->addContact()
    }

    return lstContact;
}
