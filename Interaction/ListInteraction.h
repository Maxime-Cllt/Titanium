//
// Created by rahman on 15/10/22.
//

#ifndef PROJET_QT_LISTINTERACTION_H
#define PROJET_QT_LISTINTERACTION_H

#include "Interaction.h"
#include <iostream>
#include <list>

/**
 *  @details Classe ListInteraction qui sert à stocker les objets de type Interaction et à réaliser divers operations.
 */
class ListInteraction
{
public:
    ListInteraction(uint64_t id);

    ListInteraction(const ListInteraction &);

    explicit ListInteraction();

    ~ListInteraction();

    friend std::ostream &operator<<(std::ostream &, const ListInteraction &);

    void addInteraction(Interaction *);

    void addInteraction(const Interaction &);

    void supInteraction(Interaction *);

    uint64_t getContactId() const;

    void setContactId(uint64_t contactId);


    void reverse();

    std::list<Interaction *> *getListInteraction() const;

    void setListInteraction(std::list<Interaction *> *lstInteraction);

    int size();

private:
    uint64_t contactId{};
    std::list<Interaction *> *listInteraction{};
};


#endif //PROJET_QT_LISTINTERACTION_H
