//
// Created by Rahman  Yilmaz on 15/10/2022.
//

#include "MenuBar.h"
#include "../ContactDialog/CreationContactDialog.h"
#include <QMessageBox>

/**
 * @details Constructeur de la classe MenuBar
 * @param parent
 */
MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
    menu1 = new QMenu(tr("&Ajouter"), this);

    auto *addContactAction = new QAction("Nouveau contact", this);

    addContactAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));

    menu1->addAction(addContactAction);

    connect(addContactAction, &QAction::triggered, this, [this]()
    {
        CreationContactDialog dialog(this);
        dialog.exec();
    });

    auto *menu2 = new QMenu(tr("&À propos"), this);

    auto *actionAbout = new QAction("&Qt", this);
    connect(actionAbout, &QAction::triggered, this, [this]()
    {
        QMessageBox::aboutQt(this);
    });
    menu2->addAction(actionAbout);
    addMenu(menu1);

    addMenu(menu2);


}
