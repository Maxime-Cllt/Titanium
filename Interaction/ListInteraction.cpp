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
 * @details Ajoute l'interaction en paramètre à la liste des interactions en recréant un nouveau pointeur
 * qui pointe sur une nouvelle interaction avec les attributs de memes valeur que l'interaction en paramètre.
 * @param interaction
 */
void ListInteraction::addInteraction(Interaction *interaction)
{
    addInteraction(*interaction);
}

/**
 * @details Ajoute l'interaction en paramètre à la liste des interactions en recréant un nouveau pointeur
 * qui pointe sur une nouvelle interaction avec les attributs de memes valeur que l'interaction en paramètre.
 * @param interaction
 */
void ListInteraction::addInteraction(const Interaction &interaction)
{
    listInteraction->push_back(new Interaction(interaction));
}

/**
 * @details Supprime l'interaction en paramètre de la liste et le delete.
 * @param interaction
 */
void ListInteraction::supInteraction(Interaction *interaction)
{
    listInteraction->remove(interaction);
    delete interaction;
}

/**
 * @details Getter de contactId.
 * @return contactId
 */
uint64_t ListInteraction::getContactId() const
{
    return contactId;
}

/**
 * @details Setter de contactId.
 * @param contactId
 */
void ListInteraction::setContactId(uint64_t contactId)
{
    ListInteraction::contactId = contactId;
}

/**
 * @details Getter de listInteraction.
 * @return La liste des interactions.
 */
std::list<Interaction *> *ListInteraction::getListInteraction() const
{
    return listInteraction;
}

/**
 * @details Setter de listInteraction
 * @param listInteraction
 */
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
 * @details Constructeur de copie.
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
 * @details Fonction qui applique un trie décroissant sur la liste des interactions.
 */
void ListInteraction::reverse()
{
    listInteraction->sort([](Interaction *interaction1, Interaction *interaction2)
                          {
                              return *interaction1 > *interaction2;
                          });
}

/**
 * @details Surcharge de l'opérateur d'affichage ostream <<. Affiche l'id du contact et la liste des interactions.
 * @param os
 * @param interaction
 * @return
 */
std::ostream &operator<<(std::ostream &os, const ListInteraction &lstInteraction)
{
    os << "ListInteraction" << std::endl << "{" << std::endl << "\tcontactId: " << lstInteraction.contactId
       << std::endl;
    int i = 1;
    for (const auto interaction: *lstInteraction.getListInteraction())
    {
        os << "\tInteraction n°" << i << " { " << *interaction << " }" << std::endl;
        i++;
    }
    os << "}" << std::endl;
    return os;
}
