//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QStatusBar>
#include "../ContactDialog/CreationContactDialog.h"
#include "../Menu/MenuBar.h"

/**
 * @details Constructeur de la classe MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setMinimumHeight(500);
    bd = new BD;
    listModification = new ListModification;

    setMenuBar(new MenuBar(this));

    lstContact = new StdListContact(BD::getContactData());
    lstContact->sortDateCreation();

    layoutGauche = new QHBoxLayout;
    layoutDroit = new QHBoxLayout;


    setWindowTitle("Projet");
    auto *central = new QWidget();
    auto *layout = new QHBoxLayout(central);
    setCentralWidget(central);

    layout->addLayout(layoutGauche);
    layout->addLayout(layoutDroit);

    setListContactWidgetDefault();

    auto *status = new QStatusBar(this);

    nbContactLab = new QLabel("Nombre de contact : " + QString::number(lstContact->getLstContact()->size()));
    nbContactLab->setAlignment(Qt::AlignHCenter);
    status->addWidget(nbContactLab, 1);
    nbInetractionLab = new QLabel("Nombre d'interaction : ");
    status->addWidget(nbInetractionLab, 1);
    nbInetractionLab->setAlignment(Qt::AlignHCenter);

    setStatusBar(status);

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
    nbContactLab->setText("Nombre de contact : " + QString::number(lstContact->getLstContact()->size()));
}

void MainWindow::rechercheListContactWidget(StdListContact *lst)
{
    listContactWidget->close();
    if (listContactWidget)
    {
        delete listContactWidget;
        listContactWidget = new ListContactWidget(lst, this);
        layoutGauche->addWidget(listContactWidget);
        nbContactLab->setText("Nombre de contact : " + QString::number(lst->getLstContact()->size()));
        if (listInteractionWidget)
            layoutDroit->removeWidget(listInteractionWidget);
        nbInetractionLab->setText("Nombre d'interaction : ");
    }
}

/**
 * Ajoute un widget avec la liste d'interaction
 * @param widget
 */
void MainWindow::setListInteractionWidget(ListInteractionWidget *widget)
{
    if (listInteractionWidget)
        layoutDroit->removeWidget(listInteractionWidget);
    layoutDroit->addWidget(widget);
    listInteractionWidget = widget;
    connect(listInteractionWidget, &ListInteractionWidget::updateNbInteraction, this, [this](int nbInteractions)
    {
        nbInetractionLab->setText("Nombre d'interaction : " + QString::number(nbInteractions));
    });
    nbInetractionLab->setText(
            "Nombre d'interaction : " + QString::number(listInteractionWidget->getLstInteraction()->size()));
}

void MainWindow::setListContactWidgetDefault()
{
    if (listInteractionWidget)
    {
        layoutDroit->removeWidget(listInteractionWidget);
        nbInetractionLab->setText("Nombre d'interaction : ");
    }
    if (listContactWidget)
    {
        nbContactLab->setText("Nombre de contact : " + QString::number(lstContact->getLstContact()->size()));
        listContactWidget->close();
    }
    listContactWidget = new ListContactWidget(lstContact, this);
    layoutGauche->addWidget(listContactWidget);
}

void MainWindow::updateNbContact()
{
    nbContactLab->setText("Nombre de contact : " + QString::number(listContactWidget->getLstContact()->getLstContact()->size()));
}
