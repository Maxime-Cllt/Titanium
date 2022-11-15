//
// Created by rahman on 01/11/22.
//

#ifndef PROJET_QT_TOOLBAR_H
#define PROJET_QT_TOOLBAR_H

#include <QToolBar>
#include <QToolButton>
#include "../Contact/StdContact.h"

/**
 * @details Classe ToolBar qui hérite de QToolBar qui servira pour les ajouts de contacts,
 * recherche de contacts, trié les contacts, remettre à zero le Widget des contacts apres une recherche.
 */
class ToolBar : public QToolBar
{
Q_OBJECT

public:
    explicit ToolBar(QWidget *parent);

private:

    QAction *ajouter{};
    QToolButton *chercher{};
    QToolButton *tri{};
    QAction *resetListContactsWidget{};
    QAction *historique{};

    void createFindBtn();

    void createTriBtn();


private slots:

    void ajouterContact();

    void chercherContact();

    void afficheHistorique();

    void chercherTache();

signals:

    void clearHistoriqueClicked();

    void resetActionTriggered();

    void addContact(StdContact *);

};


#endif //PROJET_QT_TOOLBAR_H
