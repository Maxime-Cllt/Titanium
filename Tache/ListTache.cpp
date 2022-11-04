//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "ListTache.h"
#include <algorithm>

/**
 * @details Constructeur par défaut.
 */
ListTache::ListTache()
{
    lstTache = new std::list<Tache *>();

}

/**
 * @details Constructeur avec l'id de l'interaction en paramètre.
 */
ListTache::ListTache(uint64_t idInteraction) : idInteraction(idInteraction)
{
    lstTache = new std::list<Tache *>();
}

/**
 * @details Getter de lstTache.
 * @return lstTache
 */
std::list<Tache *> *ListTache::getLstTache() const
{
    return lstTache;
}

/**
 * @details Setter de lstTache.
 * @param lstTache
 */
void ListTache::setLstTache(std::list<Tache *> *lstTache)
{
    ListTache::lstTache = lstTache;
}

/**
 * @details Getter de idInteraction.
 * @return idInteraction
 */
uint64_t ListTache::getIdInteraction() const
{
    return idInteraction;
}

/**
 * @details Setter de idInteraction.
 * @param idInteraction
 */
void ListTache::setIdInteraction(uint64_t idInteraction)
{
    ListTache::idInteraction = idInteraction;
}


/**
 * @details Ajoute la tache en paramètre à la liste des taches en recréant un nouveau pointeur
 * qui pointe sur une nouvelle tache avec les attributs de memes valeur que la tache en paramètre.
 * @param tache
 */
void ListTache::addTache(const Tache &tache)
{
    lstTache->push_back(new Tache(tache));
}

/**
 * @details Ajoute la tache en paramètre à la liste des taches.
 * @param tache
 */
void ListTache::addTache(Tache *tache)
{
    lstTache->push_back(tache);
}

/**
 * @details Supprime la tache de la liste des taches et le delete.
 * @param tache
 */
void ListTache::suppTache(Tache *tache)
{
    lstTache->remove(tache);
    delete tache;

}

/**
 * @details Supprime la tache de la liste. des taches
 * @param tache
 */
void ListTache::removeTache(Tache *tache)
{
    lstTache->remove(tache);
}

/**
 * @brief Retourn la taille de la liste.
 * @return
 */
int ListTache::size()
{
    return lstTache->size();
}

/**
 * @details Constructeur par copie .
 * @param lst
 */
ListTache::ListTache(const ListTache &listTache)
{
    lstTache = new std::list<Tache *>();
    for (auto tache: *listTache.lstTache)
    {
        addTache(*tache);
    }
}

/**
 * @details Destructeur.
 */
ListTache::~ListTache()
{
    for (auto tache: *lstTache)
        delete tache;
    delete lstTache;
}

/**
 * @details Surcharge de l'opérateur d'affichage ostream <<. Affiche un à un les tache de la liste.
 * @param os
 * @param lstTache
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const ListTache &lstTache)
{
    os << "ListTache" << std::endl << "{" << std::endl << "\tidInteraction : " << lstTache.getIdInteraction()
       << std::endl;
    int i = 1;
    for (auto tache: *lstTache.getLstTache())
    {
        os << "\tTache n°" << i << " { " << *tache << " }" << std::endl;
        i++;
    }
    os << "}" << std::endl;
    return os;
}

/**
 * @brief Tri la liste dans l'ordre croissant des dates des taches.
 */
void ListTache::sortRecent()
{
    lstTache->sort([=, this](Tache *t1, Tache *t2)
                   {
                       return *t1 < *t2;
                   });
}

/**
 * @brief Tri la liste dans l'ordre croissant des dates des taches.
 */
void ListTache::sortAncien()
{
    lstTache->sort([=, this](Tache *t1, Tache *t2)
                   {
                       return *t1 > *t2;
                   });
}

