//
// Created by Rahman  Yilmaz on 20/10/2022.
//

#include "Tache.h"

#include <utility>
#include <chrono>

/**
 * @details Constructeur de Tache.
 * @param contenu
 */
Tache::Tache(const std::string &contenu)
{
    setcontenu(contenu);
}

/**
 * @details Constructeur par défaut.
 */
Tache::Tache()
{
    date = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
};

/**
 * @details Getter de contenu.
 * @return
 */
const std::string &Tache::getcontenu() const
{
    return contenu;
}

/**
 * @details Setter de contenu.
 * @param contenu
 */
void Tache::setcontenu(const std::string &contenu)
{
    if (contenu.find("@date") != std::string::npos)
    {
        int pos = contenu.find("@date") + 6;

        int day, month, year;

        try
        {
            day = std::stoi(contenu.substr(pos, pos + 2));
            month = std::stoi(contenu.substr(pos + 3, pos + 5));
            year = std::stoi(contenu.substr(pos + 6, pos + 9));
            tm tm = {0};
            tm.tm_year = year - 1900;
            tm.tm_mon = month - 1;
            tm.tm_mday = day;
            setdate((uint64_t) mktime(&tm) * 1000000);
        } catch (std::invalid_argument)
        {
            std::cout << "probleme convertion tache date" << std::endl;
            setdate(std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count());
        }



        // Compatible uniquement systeme unix.
//        strptime(contenu.substr(pos, pos + 9).c_str(), "%d/%m/%Y", &d);
    } else
    {
        date = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
    }
    Tache::contenu = contenu;
}

/**
 * @details Getter de date.
 * @return date
 */
uint64_t Tache::getdate() const
{
    return date;
}

/**
 * @details Setter de date.
 * @param date
 */
void Tache::setdate(uint64_t date)
{
    Tache::date = date;
}

/**
 * @details Surcharge de l'opérateur d'affichage ostream <<. Affiche le contenu de la tache et la date de la tache.
 * @param os
 * @param tache
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const Tache &tache)
{
    os << "contenu: " << tache.contenu << " date: " << tache.date;
    return os;
}

/**
 * @details Surcharge de l'opérateur <
 * @param rhs
 * @return
 */
bool Tache::operator<(const Tache &rhs) const
{
    return date < rhs.date;
}

/**
 * @details Surcharge de l'opérateur >
 * @param rhs
 * @return
 */
bool Tache::operator>(const Tache &rhs) const
{
    return rhs < *this;
}

/**
 * @details Surcharge de l'opérateur <=
 * @param rhs
 * @return
 */
bool Tache::operator<=(const Tache &rhs) const
{
    return !(rhs < *this);
}

/**
 * @details Surcharge de l'opérateur >=
 * @param rhs
 * @return
 */
bool Tache::operator>=(const Tache &rhs) const
{
    return !(*this < rhs);
}

/**
 * @details Fonction qui retourne le contenu sans les todos.
 * @return string sans les todos.
 */
std::string Tache::getContenuWithoutTodo()
{
    std::string tmp = contenu;
    tmp.erase(0, 5);
    if (tmp.find("@date") != std::string::npos)
    {
        int pos = tmp.find("@date");
        int longueur = 0;
        int compteur = 0;
        for (int i = pos; i < tmp.length() - 1; i++)
        {
            if (tmp[i] == '/')
            {
                compteur++;
                if (compteur == 2)
                {
                    longueur = i + 5 - pos;
                    break;
                }
            }
        }
        tmp.erase(pos, longueur);
    }
    return tmp;
}


/**
 * @details Destructeur.
 */
Tache::~Tache()
= default;
