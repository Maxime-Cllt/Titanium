//
// Created by Rahman  Yilmaz on 15/10/2022.
//

#include "MenuBar.h"
#include "../ContactDialog/CreationContactDialog.h"
#include <QMessageBox>
#include <QFontDialog>
#include <QApplication>
#include "../Utility/Utility.h"

/**
 * @details Constructeur de la classe Menu
 * @param parent
 */
MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
    menu1 = new QMenu(tr("&Paramètre"), this);


    auto actionSettings = new QAction("Settings", this);
    connect(actionSettings, &QAction::triggered, this, &MenuBar::settingsClicked);

    menu1->addAction(actionSettings);


    menu2 = new QMenu(tr("&À propos"), this);

    auto *actionAbout = new QAction("&Qt", this);
    connect(actionAbout, &QAction::triggered, this, [this]()
    {
        QMessageBox::aboutQt(this);
    });
    menu2->addAction(actionAbout);


    menu4 = new ExportImportMenu(this);


    addMenu(menu1);

    addMenu(menu2);

    addMenu(menu4);
}

void MenuBar::settingsClicked()
{
    QDialog dialog;

    auto *layout = new QGridLayout(&dialog);

    QPushButton btn("Changer de Font");
    connect(&btn, &QPushButton::clicked, this, [=, this]()
    {
        QFontDialog diag;
        diag.exec();
        qApp->setFont(diag.selectedFont());
        for (auto *widget: QApplication::allWidgets())
        {
            widget->setFont(QApplication::font());
            widget->update();
        }
    });

    layout->addWidget(&btn);


    dialog.exec();

}
