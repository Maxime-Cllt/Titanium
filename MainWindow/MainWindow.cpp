//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "MainWindow.h"
#include <QStatusBar>
#include "../ContactDialog/CreationContactDialog.h"
#include "../Menu/MenuBar.h"
#include "../ToolBar/ToolBar.h"

/**
 * @details Constructeur de la classe MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setMinimumHeight(500);
    bd = new BD;
    historique = new ListHistorique;
    historique->loadData("log.txt");

    lstContact = BD::getContactData();
    lstContact->sort(StdListContact::DateDecroissant);
    lstContactTmp = lstContact;

    setMenuBar(new MenuBar(this));


    layoutGauche = new QHBoxLayout;
    layoutDroit = new QHBoxLayout;


    setWindowTitle("Projet");
    auto *central = new QWidget;
    auto *layout = new QHBoxLayout(central);
    setCentralWidget(central);

    layout->addLayout(layoutGauche);
    layout->addLayout(layoutDroit);

    auto *status = new QStatusBar(this);


    nbContactLab = new QLabel("Nombre de contact : " + QString::number(lstContact->getLstContact()->size()));
    nbContactLab->setAlignment(Qt::AlignHCenter);
    status->addWidget(nbContactLab, 1);
    nbInetractionLab = new QLabel("Nombre d'interaction : ");
    status->addWidget(nbInetractionLab, 1);
    nbInetractionLab->setAlignment(Qt::AlignHCenter);

    setStatusBar(status);

    auto *ToolBar = new class ToolBar(this);
    connect(ToolBar, &ToolBar::clearHistoriqueClicked, this, &MainWindow::clearHistorique);
    connect(ToolBar, &ToolBar::resetActionTriggered, this, &MainWindow::resetListContactWidget);
    connect(ToolBar, &ToolBar::addContact, this, &MainWindow::addContact);
    connect(ToolBar, &ToolBar::suppContact, this, [=, this](StdListContact *lst)
    {
        suppContact(lst);
        lstContact->sort(StdListContact::Sort::DateDecroissant);
        listContactWidget->recreateGroupeBoxContact();
    });

    addToolBar(ToolBar);

    lstContact->sort(StdListContact::DateDecroissant);
    listContactWidget = new ListContactWidget(lstContact, this);
    connect(listContactWidget, &ListContactWidget::suppContact, this, [=, this](StdContact *contact){
        suppContact(contact);
    });
    connect(listContactWidget, &ListContactWidget::resetLastConctact, this, &MainWindow::removeListInteractionWidget);
    connect(listContactWidget, &ListContactWidget::interactionWidgetsHidedOrShowed, this, [=,this](bool visible){
        if(!visible)
            setNbInteraction("");
    });

    layoutGauche->addWidget(listContactWidget);

//    for (int i = 0; i < 5; i++)
//    {
//        auto *contact = new StdContact(std::string("fc migrant"), {"tutu"}, "alo", "tdfd", "23442", "/Users/sr-71/Downloads/images.jpeg",
//                                       std::chrono::duration_cast<std::chrono::microseconds>(
//                                               std::chrono::system_clock::now().time_since_epoch()).count(),
//                                       ListInteraction());
//        Interaction it("wesh");
//        it.addTache(Tache("@todo il fait beau"));
//        it.addTache(Tache("@todo il fait mauvais @date 15/06/2023"));
//        contact->addInteraction(Interaction("wesh"));
//        contact->addInteraction(it);
//        addContact(contact);
//    }
}

/**
 * @brief Setter de lstContact qui est la liste de contact utilisé qui stock les contacts de recherche ou tous les contacts.
 * @return lstContact
 */
StdListContact *MainWindow::getLstContact() const
{
    return lstContact;
}

/**
 * @brief Getter de la liste des historiques.
 * @return
 */
ListHistorique *MainWindow::getHistorique() const
{
    return historique;
}

/**
 * @brief Setter de lstContactTmp qui est la liste de contact de base.
 * @return lstContactTmp
 */
StdListContact *MainWindow::getLstContactTmp() const
{
    return lstContactTmp;
}

/**
 * @brief Surcharge de l’événement de fermeture.
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
    delete lstContact;
    delete bd;
    if (lstContactTmp != lstContact)
    {
        lstContactTmp->getLstContact()->clear();
        delete lstContactTmp;
    }
    historique->saveData("log.txt");
    delete historique;
}

/**
 * @details Ajouter un StdContact dans la liste des contacts et dans le Widget des contacts pour l'afficher.
 * @param contact
 */
void MainWindow::addContact(StdContact *contact)
{
    lstContact->addContact(contact);
    if (lstContact != lstContactTmp)
        lstContactTmp->addContact(contact);
    listContactWidget->addContactBox(contact);
    BD::addFullContactAttributesOnBD(*contact);
    historique->addLog(ListHistorique::AjoutContact, *contact);
    updateNbContact();
}

/**
 * @details Supprime un contact.
 * @param contact
 */
void MainWindow::suppContact(StdContact *contact)
{

    BD::supContact(*contact);
    historique->addLog(ListHistorique::SuppressionContact, *contact);
    lstContact->supContact(contact);
    lstContactTmp->removeContact(contact);
    updateNbContact();
}

/**
 * @details Supprime une liste de contact.
 * @param lst
 */
void MainWindow::suppContact(StdListContact *lst)
{
    QString str;
    for (auto contact: *lst->getLstContact())
    {
        str += QString::fromStdString(contact->getNom() + " - " + contact->getPrenom()) + "\n";
        suppContact(contact);
    }
    QMessageBox msgb(QMessageBox::Icon::Information,"Succès","Suppression réalisée avec succès");
    msgb.setDetailedText(str);
    msgb.exec();
}


/**
 * @details Fonction utilisée lors d'une recherche de contacts, qui cache les contacts qui ne correspondent à la recherche.
 * @param lst
 */
void MainWindow::rechercheListContactWidget(StdListContact *lst)
{
    lstContact = lst;
    listContactWidget->cacheGroupeBox(lst);

    updateNbContact();

    removeListInteractionWidget();

    setNbInteraction("");

}

/**
 * @details setter du widget des interactions.
 * @param widget
 */
void MainWindow::setListInteractionWidget(ListInteractionWidget *widget)
{
    removeListInteractionWidget();

    layoutDroit->addWidget(widget);
    listInteractionWidget = widget;


    connect(listInteractionWidget, &ListInteractionWidget::updateNbInteraction, this, &MainWindow::setNbInteraction);
    setNbInteraction(QString::number(listInteractionWidget->getLstInteraction()->size()));
}

/**
 * @details Remet à 0 le Widget qui affiche les contacts, c'est-à-dire supprime l'ancien listContactWidget,
 * recrée une nouvelle listContactWidget avec les contacts dans lstContact, enlève aussi le Widget qui affiche les interactions d'un contact s'il est affiché.
 */
void MainWindow::resetListContactWidget()
{
    lstContact = lstContactTmp;
    lstContact->sort(StdListContact::DateDecroissant);
    reactualise();
}

/**
 * @brief Fonction qui met à jour la valeur de nbContactLab qui indique le nombre de contacts visible.
 */
void MainWindow::updateNbContact()
{
    nbContactLab->setText("Nombre de contact : " + QString::number(lstContact->size()));
}

/**
 * @brief Fonction qui met à jour la valeur de nbInetractionLab qui indique le nombre de d'interaction du contact sélectionné.
 */
void MainWindow::setNbInteraction(const QString &number)
{
    nbInetractionLab->setText("Nombre d'interaction : " + number);
}


/**
 * @details Réactualise l'UI, c’est-à-dire enlève le widget des interactions et affiche tous les contacts.
 */
void MainWindow::reactualise()
{
    removeListInteractionWidget();

    listContactWidget->afficheAllGroupeBox();

    setNbInteraction("");
    updateNbContact();
}

/**
 * @brief Cache le widget des interactions.
 */
void MainWindow::removeListInteractionWidget()
{
    if (listInteractionWidget)
    {
        listInteractionWidget->hide();
        setNbInteraction("");
    }
}

void MainWindow::clearHistorique()
{
    historique->clear();

}
