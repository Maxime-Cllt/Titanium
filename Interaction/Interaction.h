//
// Created by rahman on 09/10/22.
//

#ifndef UNTITLED2_INTERACTION_H
#define UNTITLED2_INTERACTION_H

#include <iostream>
#include <string>
#include <ctime>
#include "../Tache/ListTache.h"

class Interaction
{

public:
    Interaction(const std::string &contenu);

    Interaction(const Interaction &interaction);

    explicit Interaction();

    ~Interaction();

private:
    std::string contenu{};
    uint64_t id{};
    uint64_t dateModif{};
    ListTache *lstTache{};

public:
    ListTache *getLstTache() const;

    void setLstTache(ListTache *lstTache);

    void setLstTache(const ListTache &lstTache);

public:
    friend bool operator<(const Interaction &lhs, const Interaction &rhs);

    friend bool operator>(const Interaction &lhs, const Interaction &rhs);

    friend bool operator<=(const Interaction &lhs, const Interaction &rhs);

    friend bool operator>=(const Interaction &lhs, const Interaction &rhs);

    uint64_t getDateModif() const;

    void setDateModif(uint64_t dateModif);

    uint64_t getId() const;

    void setId(uint64_t id);

    const std::string &getContenu() const;

    void setContenu(const std::string &contenu);

    void modif();

    void addTache(const Tache &tache);

};

#endif //UNTITLED2_INTERACTION_H