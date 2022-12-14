//
// Created by Rahman  Yilmaz on 15/10/2022.
//

#include "../ContactDialog/CreationContactDialog.h"
#include <QMessageBox>
#include <QFontDialog>
#include <QApplication>

/**
 * @details Constructeur de la classe Menu
 * @param parent
 */
MenuBar::MenuBar(StdListContact *lstContact, QWidget *parent) : lstContact(lstContact), QMenuBar(parent)
{
    menu1 = new QMenu(tr("&Paramètre"), this);


    auto actionSettings = new QAction("réglages", this);
    connect(actionSettings, &QAction::triggered, this, &MenuBar::settings);

    menu1->addAction(actionSettings);


    menu2 = new QMenu(tr("&À propos"), this);

    auto *actionAbout = new QAction("&Qt", this);
    connect(actionAbout, &QAction::triggered, this, [this]()
    { QMessageBox::aboutQt(this); });
    menu2->addAction(actionAbout);


    menu3 = new ExportImportMenu(MenuBar::lstContact, this);

    connect(menu3, &ExportImportMenu::contactImported, this, [=, this]()
    { emit contactImported(); });


    addMenu(menu1);

    addMenu(menu2);

    addMenu(menu3);
}

/**
 * @details Fonction qui affiche une fenêtre de settings pour changer les paramètres le l'app.
 */
void MenuBar::settings()
{
    QDialog dialog;
    dialog.setWindowTitle("réglages");

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
