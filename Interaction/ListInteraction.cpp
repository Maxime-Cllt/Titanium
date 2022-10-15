//
// Created by rahman on 15/10/22.
//

#include "ListInteraction.h"

ListInteraction::ListInteraction(std::time_t id) : contactId(id)
{

}

void ListInteraction::addInteraction(Interaction *interaction)
{
    listInteraction.push_back(interaction);
}

void ListInteraction::supInteraction(Interaction *interaction)
{
    listInteraction.remove(interaction);
}

time_t ListInteraction::getContactId() const
{
    return contactId;
}

void ListInteraction::setContactId(time_t contactId)
{
    ListInteraction::contactId = contactId;
}

const std::list<Interaction *> &ListInteraction::getListInteraction() const
{
    return listInteraction;
}

void ListInteraction::setListInteraction(const std::list<Interaction *> &listInteraction)
{
    ListInteraction::listInteraction = listInteraction;
}

ListInteraction::~ListInteraction()
{

    for (auto interaction : listInteraction )
    {
        delete interaction;
    }
}

ListInteraction::ListInteraction()
{

}
