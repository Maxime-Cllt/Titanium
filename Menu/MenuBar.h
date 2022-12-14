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
    explicit MenuBar(StdListContact *lstContact, QWidget *parent);

private:
    QMenu *menu1{};
    QMenu *menu2{};
    ExportImportMenu *menu3{};

    StdListContact *lstContact{};

private slots:

    void settings();

signals :
    void contactImported();

};


#endif //PROJET_QT_MENUBAR_H
