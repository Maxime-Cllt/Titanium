//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include "../CreationContact/CreationContactDialog.h"
#include "../MenuBar/MenuBar.h"

/**
 * @details Constructeur de la classe MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    setBaseSize(500, 450);
    setMinimumHeight(450);
    bd = new BD;
    listModification = new ListModification;

    setMenuBar(new MenuBar(this));

    lstContact = new StdListContact(BD::getContactData());

    setWindowTitle("Projet");
    auto *central = new QWidget();
    layout = new QHBoxLayout(central);
    setCentralWidget(central);


    listContactWidget = new ListContactWidget(this);
    layout->addWidget(listContactWidget);
}

/**
 *
 * @return lstContact
 */
StdListContact *MainWindow::getLstContact()
{
    return lstContact;
}

/**
 *
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
    delete lstContact;
    delete listModification;
    delete bd;
}

/**
 * Ajouter un StdContact dans la liste des contact et dans le widget des contacts pour l'afficher.
 * @param contact
 */
void MainWindow::addContact(const StdContact &contact)
{
    auto *c = new StdContact(contact);
    lstContact->addContact(c);
    listContactWidget->addContactBox(c);

}

/**
 * Ajoute un widget avec la liste d'interaction
 * @param widget
 */
void MainWindow::setListInteractionWidget(ListInteractionWidget *widget)
{
    if (listInteractionWidget)
        layout->removeWidget(listInteractionWidget);
    layout->addWidget(widget);
    listInteractionWidget = widget;
}
