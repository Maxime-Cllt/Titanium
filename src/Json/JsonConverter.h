//
// Created by Rahman  Yilmaz on 28/10/2022.
//

#ifndef PROJET_QT_JSONCONVERTER_H
#define PROJET_QT_JSONCONVERTER_H

#include <QJsonObject>
#include <QJsonDocument>
#include "../Contact/StdListContact.h"

class JsonConverter : public QObject
{
Q_OBJECT

public:
    explicit JsonConverter(QObject * = nullptr);

    [[nodiscard]] static QJsonObject contactToJson(const StdContact &);

    [[nodiscard]] static QJsonObject contactToJson(const StdListContact &);

    [[nodiscard]] static StdListContact *getContact(const QString &);


private:

    [[nodiscard]] static QJsonObject interactionToJson(const Interaction &);

    [[nodiscard]] static QJsonObject interactionToJson(const ListInteraction &);

    [[nodiscard]] static QJsonObject tacheToJson(const Tache &);

    [[nodiscard]] static QJsonObject tacheToJson(const ListTache &);


    [[nodiscard]] static ListInteraction *getListInteraction(const QJsonObject &);

    [[nodiscard]] static ListTache *getListTache(const QJsonObject &);


};


#endif //PROJET_QT_JSONCONVERTER_H
