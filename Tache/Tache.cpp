//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "Tache.h"

#include <utility>

const std::string &Tache::getTag() const
{
    return tag;
}

void Tache::setTag(const std::string &tag)
{
    Tache::tag = tag;
}

const std::string &Tache::getContenu() const
{
    return contenu;
}

void Tache::setContenu(const std::string &contenu)
{
    Tache::contenu = contenu;
}

Tache::Tache(std::string tag, std::string contenu) : tag(std::move(tag)), contenu(std::move(contenu)) {}
