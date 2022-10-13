//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include "../CreationContact/CreationContactDialog.h"
#include "../ModificationContact/ModificationDialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    bd = new BD;

    lstContact = new StdListContact(bd->getData());
    setWindowTitle("Projet");
    central = new QWidget();
    layout = new QGridLayout(central);
    setCentralWidget(central);

    auto *bt = new QPushButton("ajout contact");
    layout->addWidget(bt, 0, 0);
    connect(bt, &QPushButton::clicked, this, [=]()
    {
        CreationContactDialog fiche(this);
        fiche.show();
        fiche.exec();
    });

    auto *bt1 = new QPushButton("liste des contact");
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

void MainWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
    qDebug()<< "cic";
    bd->addOnBD(*lstContact);
}
