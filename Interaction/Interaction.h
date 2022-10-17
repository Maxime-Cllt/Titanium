//
// Created by rahman on 09/10/22.
//

#ifndef UNTITLED2_INTERACTION_H
#define UNTITLED2_INTERACTION_H

#include <iostream>
#include <string>
#include <ctime>

class Interaction
{

public:
    Interaction(const std::string &contenu);

    explicit Interaction();

private:
    std::string contenu{};
    uint64_t id{};
    uint64_t dateModif{};

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
};

#endif //UNTITLED2_INTERACTION_H