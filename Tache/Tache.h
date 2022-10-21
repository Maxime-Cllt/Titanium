//
// Created by Rahman  Yilmaz on 20/10/2022.
//
/************************************************
 *  Classe qui reprensente une tache, une tache est composé d'un tag et de son contenu
 ***********************************************/

#ifndef PROJET_QT_TACHE_H
#define PROJET_QT_TACHE_H

#include <iostream>

class Tache
{
public:
    explicit Tache();

    Tache(std::string contenu);

private:
    std::string contenu{};
    uint64_t dateTag{};

public:

    const std::string &getcontenu() const;

    void setcontenu(const std::string &contenu);

    uint64_t getdateTag() const;

    void setdateTag(uint64_t dateTag);

};


#endif //PROJET_QT_TACHE_H
