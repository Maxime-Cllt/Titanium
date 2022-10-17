//
// Created by rahman on 15/10/22.
//

#include "ListInteraction.h"
#include <list>


/**
 * @details Constructeur de la classe ListInteraction
 * @param id
 */
ListInteraction::ListInteraction(uint64_t id) : contactId(id)
{

}

/**
 * Ajouter une interaction
 * @param interaction
 */
void ListInteraction::addInteraction(Interaction *interaction)
{
    listInteraction.push_back(interaction);
}

/**
 * Supprimer une interaction
 * @param interaction
 */
void ListInteraction::supInteraction(Interaction *interaction)
{
    listInteraction.remove(interaction);
}

/**
 *
 * @return contactId
 */
uint64_t ListInteraction::getContactId() const
{
    return contactId;
}

/**
 *
 * @param contactId
 */
void ListInteraction::setContactId(uint64_t contactId)
{
    ListInteraction::contactId = contactId;
}

/**
 *
 * @return listInteraction
 */
const std::list<Interaction *> &ListInteraction::getListInteraction() const
{
    return listInteraction;
}

/**
 *
 * @param listInteraction
 */
void ListInteraction::setListInteraction(const std::list<Interaction *> &listInteraction)
{
    ListInteraction::listInteraction = listInteraction;
}

/**
 * @param Destructeur de la classe ListInteraction
 */
ListInteraction::~ListInteraction()
{
    for (auto interaction: listInteraction)
    {
        delete interaction;
    }
}

/**
 * @return Constructeur de la classe ListInteraction
 */
ListInteraction::ListInteraction()
{

}

/**
 * Ajouter une interaction
 * @param interaction
 */
void ListInteraction::addInteraction(const Interaction &interaction)
{
    listInteraction.push_back(new Interaction(interaction));

}

/**
 *
 * @param lst
 */
ListInteraction::ListInteraction(const ListInteraction &lst)
{
    for (auto inter: lst.getListInteraction())
    {
        addInteraction(*inter);
    }
    contactId = lst.getContactId();
}

void ListInteraction::reverse()
{
    listInteraction.sort([](Interaction *interaction, Interaction *interaction1)
                         {
                             return *interaction > *interaction1;
                         });
}
