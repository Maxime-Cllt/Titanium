//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include "../CreationContact/CreationContactDialog.h"
#include "../MenuBar/MenuBar.h"

/**
 * Constructeur de la classe MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    setMinimumHeight(500);

    bd = new BD;
    modificationMap = new ModificationMap;

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
}

/**
 *
 * @return modificationMap
 */
ModificationMap *MainWindow::getModificationMap() const
{
    return modificationMap;
}

/**
 * Ajouter un StdContact dans la liste
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
void MainWindow::setListInteractionWidget(QWidget *widget)
{
    layout->addWidget(widget);
}
