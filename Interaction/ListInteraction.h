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
    ListInteraction(uint64_t id);

    ListInteraction(const ListInteraction &);

    explicit ListInteraction();

    ~ListInteraction();

    void addInteraction(Interaction *interaction);

    void addInteraction(const Interaction &interaction);

    void supInteraction(Interaction *interaction);

    uint64_t getContactId() const;

    void setContactId(uint64_t contactId);


    void reverse();

    std::list<Interaction *> *getListInteraction() const;

    void setListInteraction(std::list<Interaction *> *listInteraction);

private:
    uint64_t contactId{};
    std::list<Interaction *> *listInteraction{};
};


#endif //PROJET_QT_LISTINTERACTION_H
