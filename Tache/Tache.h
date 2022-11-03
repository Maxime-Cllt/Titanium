//
// Created by Rahman  Yilmaz on 20/10/2022.
//


#ifndef PROJET_QT_TACHE_H
#define PROJET_QT_TACHE_H

#include <iostream>

/**
 * @details Classe qui modelise une tache. Il comporte 2 attributs,
 * un attribut contenu qui stock le contenu d'une tache
 * et un attribut date date qui indique la date de la tache.
 */
class Tache
{
public:
    explicit Tache();

    explicit Tache(std::string contenu);

    ~Tache();

private:
    std::string contenu{};
    uint64_t date{};

public:
    friend std::ostream &operator<<(std::ostream &, const Tache &);

    bool operator<(const Tache &) const;

    bool operator>(const Tache &) const;

    bool operator<=(const Tache &) const;

    bool operator>=(const Tache &) const;

    [[nodiscard]] const std::string &getcontenu() const;

    void setcontenu(const std::string &);

    [[nodiscard]] uint64_t getdate() const;

    void setdate(uint64_t);
};


#endif //PROJET_QT_TACHE_H
