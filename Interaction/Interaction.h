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
    std::time_t date{};
    std::string contenu{};

public:
    const std::string &getContenu() const;

    void setContenu(const std::string &contenu);

    const std::time_t &getDate() const;

    void setDate(time_t date);

};


#endif //UNTITLED2_INTERACTION_H
