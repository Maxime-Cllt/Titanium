//
// Created by rahman on 04/11/22.
//

#ifndef PROJET_QT_LISTHISTORIQUE_H
#define PROJET_QT_LISTHISTORIQUE_H

#include <iostream>
#include <list>
#include "../Contact/StdContact.h"
#include "../Interaction/Interaction.h"

/**
 * @details Classe qui stock tout l’historique de l’application.
 */
class ListHistorique : public std::list<std::string>
{
public:
    explicit ListHistorique();

    enum Contact { AjoutContact, ModificationContact, SuppressionContact };
    enum Interaction { AjoutInteraction, ModificationInteraction, SuppressionInteraction };

    void addLog(ListHistorique::Contact type, const StdContact &);

    void addLog(ListHistorique::Interaction type, const ::Interaction &);

    [[nodiscard]] std::string affiche();

    void saveData(const std::string &path);

    void loadData(const std::string &path);

    friend std::ostream &operator<<(std::ostream &os, const ListHistorique &historique);

private:
    [[nodiscard]] static std::string getDateNow();


};


#endif //PROJET_QT_LISTHISTORIQUE_H
