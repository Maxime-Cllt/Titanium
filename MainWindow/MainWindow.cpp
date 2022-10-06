//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include "../FicheContactDialog/FicheContactDialog.h"
#include "../ModificationContact/ModificationWidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Projet");
    central = new QWidget();
    layout = new QGridLayout(central);
    setCentralWidget(central);

    auto *bt = new QPushButton("wsh mon gars");
    layout->addWidget(bt, 0, 0);
    connect(bt, &QPushButton::clicked, this, [=]()
    {
        FicheContactDialog fiche;
        fiche.show();
        fiche.exec();
    });

    auto *bt1 = new QPushButton("wsh mon frr");
    layout->addWidget(bt1, 1, 0);
    connect(bt1, &QPushButton::clicked, this, [=]()
    {
        ModificationWidget modificationWidget;
        modificationWidget.show();
        modificationWidget.exec();
    });


}
