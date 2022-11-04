//
// Created by rahman on 04/11/22.
//

#include "ListHistorique.h"
#include <fstream>
#include <algorithm>
#include <string>


/**
 * @brief Constructeur par défaut.
 */
ListHistorique::ListHistorique() = default;

/**
 * @brief Ajoute un log à la liste en fonction du type de log.
 * @param type
 * @param contact
 */
void ListHistorique::addLog(ListHistorique::Contact type, const StdContact &contact)
{

    if (type == Contact::AjoutContact)
        push_back(getDateNow() + " > Contact {" + contact.getNom() + " - " + contact.getPrenom() + "} ajouté");
    if (type == Contact::ModificationContact)
        push_back(getDateNow() + " > Contact {" + contact.getNom() + " - " + contact.getPrenom() + "} modifié");
    if (type == Contact::SuppressionContact)
        push_back(getDateNow() + " > Contact {" + contact.getNom() + " - " + contact.getPrenom() + "} supprimé");
}

/**
 * @brief Ajoute un log à la liste en fonction du type de log.
 * @param type
 * @param contact
 */
void ListHistorique::addLog(ListHistorique::Interaction type, const ::Interaction &interaction)
{

    if (type == Interaction::AjoutInteraction)
        push_back(getDateNow() + " > interaction {" + interaction.getContenu() + "} ajouté");
    if (type == Interaction::ModificationInteraction)
        push_back(getDateNow() + " > interaction {" + interaction.getContenu() + "} modifié");
    if (type == Interaction::SuppressionInteraction)
        push_back(getDateNow() + " > interaction {" + interaction.getContenu() + "} supprimé");
}


/**
 * @brief Fonction qui retourne la date de maintenant sous forme de string.
 * @return La date de maintenant.
 */
std::string ListHistorique::getDateNow()
{
    char str[100];

    auto t = time(nullptr);
    auto *tm = localtime(&t);

    strftime(str, 50, "%x %X", tm);

    return {str};
}

/**
 * @details Surcharge operator d'affichage.
 * @param os
 * @param historique
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const ListHistorique &historique)
{
    int i = 1;
    for (const auto &str: historique)
    {
        os << i << " : " << str << std::endl;
        i++;
    }
    return os;
}

/**
 * @details Retourne sous un string tout l’historique.
 * @return
 */
std::string ListHistorique::affiche()
{
    std::string all;
    for (auto &str: *this)
    {
        int i = 0;
        // on remplace tous les retours chariots par des | pour stocker un log par ligne.
        while (i != str.length() - 1)
        {
            if (str[i] == '\n')
                str.replace(i, 1, " | ");
            else
                i++;
        }
        all += str + "\n";
    }
    return all;
}

/**
 * @details Enregistre les données de la liste dans le fichier en paramètre.
 * @param path
 */
void ListHistorique::saveData(const std::string &path)
{
    std::ofstream file(path, std::ios::out);
    if (file.is_open())
    {
        file << affiche();
        file.close();
    }
}

/**
 * @details Charge les données du fichier en paramètre dans la liste.
 * @param path
 */
void ListHistorique::loadData(const std::string &path)
{
    std::ifstream file(path, std::ios::in);
    if (file.is_open())
    {
        std::string str;
        while (getline(file, str))
        {

            int i = 0;
            // on remplace toute les occurrences de | par des retours chariots.
            while (i != str.length() - 1)
            {
                if (str[i] == '|')
                    str.replace(i - 1, 3, "\n");
                else
                    i++;
            }
            push_back(str);
        }
        file.close();
    }
}

