//
// Created by rahman on 08/10/22.
//

#include "TraductionQtStd.h"

/**
 * @details Traduire de Std vers QT
 * @param StdContact
 * @return Un QtContact
 */
QtContact TraductionQtStd::StdFicheContacttoQtFicheContact(const StdContact &contact)
{
    return QtContact(QString::fromStdString(contact.getNom()), QString::fromStdString(contact.getPrenom()),
                     QString::fromStdString(contact.getEntreprise()), QString::fromStdString(contact.getMail()),
                     QString::fromStdString(contact.getTelephone()), QString::fromStdString(contact.getPhoto()),
                     contact.getDateCreation(), contact.getLstInteraction());
}

/**
 * @details Traduire de QT vers Std
 * @param QtContact
 * @return StdContact
 */
StdContact TraductionQtStd::QtFicheContactToStdFicheContact(const QtContact &contact)
{
    return StdContact(contact.getNom().toStdString(), contact.getPrenom().toStdString(),
                      contact.getEntreprise().toStdString(), contact.getMail().toStdString(),
                      contact.getTelephone().toStdString(), contact.getPhoto().toStdString(), contact.getDateCreation(),
                      contact.getLstInteraction());
}
