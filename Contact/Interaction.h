//
// Created by rahman on 09/10/22.
//

#ifndef UNTITLED2_INTERACTION_H
#define UNTITLED2_INTERACTION_H

#include <iostream>
#include <string>
#include "../date.h"


class Interaction
{

public:
    Interaction(const std::string &note);

    explicit Interaction();

private:
    std::time_t date{};
    std::string note{};

public:
    const std::time_t &getDate() const;

    const std::string &getNote() const;

    void setNote(const std::string &note);

};


#endif //UNTITLED2_INTERACTION_H
