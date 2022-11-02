//
// Created by rahman on 31/10/22.
//

#include "Utility.h"

Utility::Utility() = default;


/**
 * @details Traduire de Std vers QT
 * @param StdContact
 * @return Un QtContact
 */
QtContact Utility::StdFicheContacttoQtFicheContact(const StdContact &contact)
{
    return QtContact(QString::fromStdString(contact.getNom()), QString::fromStdString(contact.getPrenom()),
                     QString::fromStdString(contact.getEntreprise()), QString::fromStdString(contact.getMail()),
                     QString::fromStdString(contact.getTelephone()), QString::fromStdString(contact.getPhoto()),
                     contact.getDateCreation());
}

/**
 * @details Traduire de QT vers Std
 * @param QtContact
 * @return StdContact
 */
StdContact Utility::QtFicheContactToStdFicheContact(const QtContact &contact)
{
    return StdContact(contact.getNom().toStdString(), contact.getPrenom().toStdString(),
                      contact.getEntreprise().toStdString(), contact.getMail().toStdString(),
                      contact.getTelephone().toStdString(), contact.getPhoto().toStdString(), contact.getDateCreation(),
                      ListInteraction());
}


/**
* @details Fonction qui retourne le widget MainWindow.
* @param widgetDepart
* @return MainWindow.
*/
QWidget *Utility::getMainWindow(QWidget *widgetDepart)
{
    QWidget *mainWindow = widgetDepart;
    while (mainWindow->parentWidget())
    {
        mainWindow = mainWindow->parentWidget();
        if (strcmp(mainWindow->metaObject()->className(), "MainWindow") == 0)
            break;
    }
    return mainWindow;
}

/**
* @details Fonction qui retourne le widget du nom de className.
* @param widgetDepart,className
* @return MainWindow.
*/
QWidget *Utility::getWidget(QWidget *widgetDepart, char *className)
{
    auto *widget = widgetDepart;
    while (widget->parentWidget())
    {
        widget = widget->parentWidget();
        if (strcmp(widget->metaObject()->className(), className) == 0)
            break;
    }
    return widget;
}
