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
    listInteraction = new std::list<Interaction *>();
}

/**
 * Ajouter une interaction
 * @param interaction
 */
void ListInteraction::addInteraction(Interaction *interaction)
{
    addInteraction(*interaction);
}

/**
 * Supprimer une interaction
 * @param interaction
 */
void ListInteraction::supInteraction(Interaction *interaction)
{
    listInteraction->remove(interaction);
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

std::list<Interaction *> *ListInteraction::getListInteraction() const
{
    return listInteraction;
}

void ListInteraction::setListInteraction(std::list<Interaction *> *listInteraction)
{
    for (auto interaction: *listInteraction)
    {
        addInteraction(interaction);
    }
}


/**
 * @details Destructeur de la classe ListInteraction qui delete tous les pointeurs D'interaction contenu dans listInteraction.
 */
ListInteraction::~ListInteraction()
{
    for (auto interaction: *listInteraction)
    {
        delete interaction;
    }
    delete listInteraction;
}

/**
 * @details Constructeur par defaut.
 */
ListInteraction::ListInteraction()
{
    listInteraction = new std::list<Interaction *>();
};

/**
 * Ajouter une interaction
 * @param interaction
 */
void ListInteraction::addInteraction(const Interaction &interaction)
{
    listInteraction->push_back(new Interaction(interaction));
}

/**
 * Constructeur de copie, qui cree de nouveaux pointeurs d'interaction.
 * @param lst
 */
ListInteraction::ListInteraction(const ListInteraction &lst)
{
    listInteraction = new std::list<Interaction *>();
    for (auto inter: *lst.getListInteraction())
    {
        addInteraction(*inter);
    }
    contactId = lst.getContactId();
}

/**
 * @details Fonction qui applique un trie decroissant sur la liste des interactions.
 */
void ListInteraction::reverse()
{
    listInteraction->sort([](Interaction *interaction1, Interaction *interaction2)
                          {
                              return *interaction1 > *interaction2;
                          });
}
