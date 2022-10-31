//
// Created by rahman on 31/10/22.
//

#include "Utility.h"

Utility::Utility() = default;


/**
* @details Fonction qui retourne le widget MainWindow.
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

QWidget *Utility::getLstInteractionWidget(QWidget *widgetDepart)
{
    auto *lstInteractionWidget = widgetDepart;
    while (lstInteractionWidget->parentWidget())
    {
        lstInteractionWidget = lstInteractionWidget->parentWidget();
        if (strcmp(lstInteractionWidget->metaObject()->className(), "ListInteractionWidget") == 0)
            break;
    }
    return lstInteractionWidget;
}
