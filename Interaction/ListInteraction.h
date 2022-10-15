//
// Created by rahman on 15/10/22.
//

#ifndef PROJET_QT_LISTINTERACTION_H
#define PROJET_QT_LISTINTERACTION_H

#include "Interaction.h"
#include <iostream>
#include <list>

class ListInteraction
{
public:
    ListInteraction(std::time_t id);

    explicit ListInteraction();

    ~ListInteraction();

    void addInteraction(Interaction *interaction);

    void supInteraction(Interaction * interaction);

    time_t getContactId() const;

    void setContactId(time_t contactId);

    const std::list<Interaction *> &getListInteraction() const;

    void setListInteraction(const std::list<Interaction *> &listInteraction);

private:
    std::time_t contactId{};
    std::list<Interaction *> listInteraction{};
};


#endif //PROJET_QT_LISTINTERACTION_H
