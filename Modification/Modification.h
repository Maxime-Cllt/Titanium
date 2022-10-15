//
// Created by Rahman  Yilmaz on 14/10/2022.
//

#ifndef PROJET_QT_MODIFICATION_H
#define PROJET_QT_MODIFICATION_H
#include <iostream>

class Modification
{
public:
    explicit Modification(const std::time_t &dateCreationContact,std::string contenuModif);

private:
    std::string contenuModif;
    std::time_t dateCreationContact;
public:

    const std::string &getContenuModif() const;

    void setContenuModif(const std::string &contenuModif);

    time_t getDateCreationContact() const;

    void setDateCreationContact(time_t dateCreationContact);
};


#endif //PROJET_QT_MODIFICATION_H
