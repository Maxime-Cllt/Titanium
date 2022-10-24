//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "ListTache.h"


/**
 * @details Constructeur par défaut.
 */
ListTache::ListTache()
{
    lstTache = new std::list<Tache *>();

}

/**
 * @details constructeur avec l'id de l'intercation en parametre.
 */
ListTache::ListTache(uint64_t idInteraction)
{
    lstTache = new std::list<Tache *>();
    idInteraction = idInteraction;
}

/**
 * @details Destructeur qui supprime tous les pointeurs de Tache contenu dans lstTache.
 */
ListTache::~ListTache()
{
    for (auto tache: *lstTache)
    {
        delete tache;
    }
    delete lstTache;
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
 * @details Ajoute la tache en paramètre à la liste des taches en recréant un nouveau pointeur
 * qui pointe sur une nouvelle tache avec les attributs de memes valeur que la tache en paramètre.
 * @param tache
 */
void ListTache::addTache(Tache *tache)
{
    addTache(*tache);
}

/**
 * @details Supprime la tache de la liste.
 * @param tache
 */
void ListTache::suppTache(Tache *tache)
{
    lstTache->remove(tache);
    delete tache;

}


/**
 * @details destruteur qui détruit tous les pointeurs de tache contenu dans la liste des taches.
 * @param lst
 */
ListTache::ListTache(const ListTache &lst)
{
    lstTache = new std::list<Tache *>();
    for (auto tache: *lst.lstTache)
    {
        addTache(tache);
    }
}

/**
 * @details Surcharge de l'opérateur d'affichage ostream <<. Affiche un à un les tache de la liste.
 * @param os
 * @param lstTache
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const ListTache &lstTache)
{
    os << "ListTache" << std::endl << "{" << std::endl;
    int i = 1;
    for (auto tache: *lstTache.getLstTache())
    {
        os << "\tTache n°" << i << " { " << *tache << " }" << std::endl;
        i++;
    }
    os << "}" << std::endl;
    return os;
}
