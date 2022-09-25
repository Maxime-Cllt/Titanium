//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QPushButton>
#include "../Contact/CreateFicheWidget.h"

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
        CreateFicheWidget fiche;
        fiche.show();
        fiche.exec();
    });


}
