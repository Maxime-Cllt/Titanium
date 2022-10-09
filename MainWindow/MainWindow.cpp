//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include "../CreationContact/CreationContactDialog.h"
#include "../ModificationContact/ModificationDialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    lstContact = new StdListContact;
    setWindowTitle("Projet");
    central = new QWidget();
    layout = new QGridLayout(central);
    setCentralWidget(central);

    auto *bt = new QPushButton("wsh mon gars");
    layout->addWidget(bt, 0, 0);
    connect(bt, &QPushButton::clicked, this, [=]()
    {
        CreationContactDialog fiche(this);
        fiche.show();
        fiche.exec();
    });

    auto *bt1 = new QPushButton("wsh mon frr");
    layout->addWidget(bt1, 1, 0);
    connect(bt1, &QPushButton::clicked, this, [=]()
    {
        ModificationDialog modificationWidget(this);
        modificationWidget.show();
        modificationWidget.exec();

    });


}

StdListContact *MainWindow::getLstContact()
{
    return lstContact;
}
