//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include "../CreationContact/CreationContactDialog.h"
#include "../MenuBar/MenuBar.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    setMinimumHeight(500);

    bd = new BD;
    modificationMap = new ModificationMap;

    setMenuBar(new MenuBar(this));

    lstContact = new StdListContact(BD::getData());
    setWindowTitle("Projet");
    auto *central = new QWidget();
    layout = new QHBoxLayout(central);
    setCentralWidget(central);



    listContactWidget = new ListContactWidget(this);
    layout->addWidget(listContactWidget);
}

StdListContact *MainWindow::getLstContact()
{
    return lstContact;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
    delete lstContact;
}

ModificationMap *MainWindow::getModificationMap() const
{
    return modificationMap;
}

void MainWindow::addContact(const StdContact &contact)
{
    auto *c = new StdContact(contact);
    lstContact->addContact(c);
    listContactWidget->addContactBox(c);

}

void MainWindow::setListInteractionWidget(QWidget *widget)
{
    layout->addWidget(widget);
}
