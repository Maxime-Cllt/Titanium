//
// Created by Rahman  Yilmaz on 15/10/2022.
//

#include "MenuBar.h"
#include "../ContactDialog/CreationContactDialog.h"
#include "RechercheContact/RechercheContactDialog.h"
#include <QMessageBox>
#include <QFileDialog>

/**
 * @details Constructeur de la classe Menu
 * @param parent
 */
MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
    menu1 = new QMenu(tr("&Ajouter"), this);

    auto *addContactAction = new QAction("&Nouveau contact", this);

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

    auto *menu3 = new QMenu("&Recherche", this);

    auto *actionRecherche = new QAction("Rechercher un contact", this);
    connect(actionRecherche, &QAction::triggered, this, [this]()
    {
        auto *dialog = new RechercheContactDialog(this);
        dialog->setModal(false);
        dialog->show();
    });

    menu3->addAction(actionRecherche);


    auto *menu4 = new QMenu("&Json", this);

    auto *actionImportJson = new QAction("Exporter", this);
    connect(actionImportJson, &QAction::triggered, this, [=]()
    {
        auto *fileDiag = new QFileDialog;
        fileDiag->setDirectory(QDir::homePath());
        fileDiag->setModal(true);
        QFile file(fileDiag->getSaveFileName());
        QFileInfo fileInfo(file);
        if(fileInfo.suffix().isEmpty() || fileInfo.suffix()!= "json"){
            file.setFileName(file.fileName()+".json");
        }
        file.open(QFile::WriteOnly);
        file.write("aa");
        file.close();
        delete fileDiag;
    });
    menu4->addAction(actionImportJson);


    addMenu(menu1);

    addMenu(menu2);

    addMenu(menu3);

    addMenu(menu4);
}
