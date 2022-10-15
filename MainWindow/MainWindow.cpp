//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include "../CreationContact/CreationContactDialog.h"
#include "../ListContact/ListContactWidget.h"
#include "../MenuBar/MenuBar.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    bd = new BD;
    modificationMap = new ModificationMap;

    setMenuBar(new MenuBar(this));

    lstContact = new StdListContact(BD::getData());
    setWindowTitle("Projet");
    auto *central = new QWidget();
    auto *layout = new QHBoxLayout(central);
    setCentralWidget(central);

    layout->addWidget(new ListContactWidget(this));


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
