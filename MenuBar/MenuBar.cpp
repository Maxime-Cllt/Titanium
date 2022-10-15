//
// Created by Rahman  Yilmaz on 15/10/2022.
//

#include "MenuBar.h"
#include "../CreationContact/CreationContactDialog.h"

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
    menu1  = new QMenu(tr("&Ajouter"),this);

    auto * addContactAction = new QAction("Nouveau contact", this);

    addContactAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));

    menu1->addAction(addContactAction);

    connect(addContactAction,&QAction::triggered, this, [this](){
        CreationContactDialog dialog(this);
        dialog.exec();
    });


    addMenu(menu1);



}
