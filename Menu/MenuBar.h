//
// Created by Rahman  Yilmaz on 15/10/2022.
//

#ifndef PROJET_QT_MENUBAR_H
#define PROJET_QT_MENUBAR_H

#include <QMenuBar>
#include "../Contact/StdListContact.h"
#include "ExportImportContacts/ExportImportMenu.h"

class MenuBar : public QMenuBar
{
Q_OBJECT

public:
    explicit MenuBar(StdListContact *,QWidget * = nullptr);

private:
    QMenu *menu1{};
    QMenu *menu2{};
    QMenu *menu3{};
    ExportImportMenu *menu4{};

    StdListContact *lstContact{};

};


#endif //PROJET_QT_MENUBAR_H