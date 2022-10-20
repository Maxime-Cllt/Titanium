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
    Tache(std::string tag, std::string contenu);

private:
    std::string tag;
    std::string contenu;
public:
    const std::string &getTag() const;

    void setTag(const std::string &tag);

    const std::string &getContenu() const;

    void setContenu(const std::string &contenu);

};


#endif //PROJET_QT_TACHE_H
