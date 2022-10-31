//
// Created by rahman on 09/10/22.
//

#include "StdListContact.h"

/**
 *  @details Constructeur par defaut de la classe StdListContact
 */
StdListContact::StdListContact()
{
    lstContact = new std::list<StdContact *>();
};

/**
 * @details Ajoute le contact en paramètre à la liste des contacts en recréant un nouveau pointeur
 * qui pointe sur un nouveau StdContact avec les attributs de meme valeur que le contact en paramètre.
 * @param StdContact
 */
void StdListContact::addContact(const StdContact &contact)
{
    addLog(0, contact);
    lstContact->push_back(new StdContact(contact));
}

/**
 * @details Ajoute le contact en paramètre à la liste des contacts.
 * @param contact
 */
void StdListContact::addContact(StdContact *contact)
{
    addLog(0, *contact);
    lstContact->push_back(contact);
}

/**
 * @details Getter de lstContact
 * @return lstContact de la classe StdContact
 */
std::list<StdContact *> *StdListContact::getLstContact() const
{
    return lstContact;
}


/**
 * @details Surcharge de l'operator << d'affichage.
 * @param os
 * @param lst
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const StdListContact &lst)
{
    os << "StdListContact" << std::endl << "{" << std::endl;
    int i = 1;
    for (const auto contact: *lst.lstContact)
    {
        os << "\tContact n°" << i << " { " << *contact << " }" << std::endl;
        i++;
    }
    i = 1;
    for (const auto &log: lst.getLstLog())
    {
        os << "\tlog n°" << i << " { " << log << " }" << std::endl;
        i++;
    }
    os << "}" << std::endl;
    return os;
}

/**
 * @details Retire le StdContact en paramètre de la liste des contacts et le delete juste apres.
 * @param StdContact
 */
void StdListContact::supContact(StdContact *contact)
{
    addLog(2, *contact);
    lstContact->remove(contact);
    delete contact;
}

/**
 * @details Retire le StdContact en paramètre de la liste des contacts.
 * @param StdContact
 */
void StdListContact::removeContact(StdContact *contact)
{
    lstContact->remove(contact);
}


/**
 *  @details Destructeur de la classe StdListContact
 */
StdListContact::~StdListContact()
{
    for (auto contact: *lstContact)
    {
        delete contact;
    }
}

/**
 * @details Constructeur par copie.
 * @param lst
 */
StdListContact::StdListContact(const StdListContact &lst)
{
    lstContact = new std::list<StdContact *>();
    for (auto contact: *lst.lstContact)
    {
        addContact(*contact);
    }
    lstLog = lst.getLstLog();
}

/**
 * @details Trie la liste des contacts dans l'ordre décroissant en fonction de la date de creation du contact.
 */
void StdListContact::reverseDateCreation()
{
    lstContact->sort([](StdContact *contact1, StdContact *contact2)
                     {
                         return *contact1 > *contact2;
                     });
}


/**
 * @details Trie la liste des contacts dans l'ordre croissant en fonction du nom du contact.
 */
void StdListContact::sortNom()
{
    lstContact->sort([](StdContact *contact1, StdContact *contact2)
                     {
                         return contact1->getNom() < contact2->getNom();
                     });
}

/**
 * @details Getter de la liste des logs.
 * @return lstlog
 */
const std::list<std::string> &StdListContact::getLstLog() const
{
    return lstLog;
}

/**
 * @details Setter de la liste des logs.
 * @param lstLog
 */
void StdListContact::setLstLog(const std::list<std::string> &lstLog)
{
    StdListContact::lstLog = lstLog;
}


/**
 * @details Renvoie sous chaine de caractère la date de maintenant.
 */
std::string StdListContact::getDateNow()
{
    char str[100];

    auto t = time(nullptr);
    auto *tm = localtime(&t);

    strftime(str, 50, "%d/%m/%Y %H:%OM", tm);

    return {str};
}

/**
 * @details Ajoute un log dans la liste des logs en fonction du type de log,
 * 0 correspond à un ajout,
 * 1 à une modification,
 * 2 à une suppression.
 * @param type
 */
void StdListContact::addLog(int type, const StdContact &contact)
{
    if (type == 0)
    {
        lstLog.push_back(getDateNow() + " > Contact " + contact.getNom() + " " + contact.getPrenom() + " ajouté");
        return;
    }
    if (type == 1)
    {
        lstLog.push_back(getDateNow() + " > Contact " + contact.getNom() + " " + contact.getPrenom() + " modifié");
        return;
    }
    if (type == 2)
    {
        lstLog.push_back(getDateNow() + " > Contact " + contact.getNom() + " " + contact.getPrenom() + " supprimé");
        return;
    }
}

/**
 * @details Retourne la taille de la liste des contacts.
 */
int StdListContact::size()
{
    return lstContact->size();
}

/**
 * @details Setter de lstContact.
 * @param lstContact
 */
void StdListContact::setLstContact(std::list<StdContact *> *lstContact)
{
    StdListContact::lstContact = lstContact;
}

void StdListContact::append(const StdListContact &lst)
{
    lstContact->splice(lstContact->end(), *lst.getLstContact());
}
