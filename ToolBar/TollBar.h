//
// Created by rahman on 01/11/22.
//

#ifndef PROJET_QT_TOLLBAR_H
#define PROJET_QT_TOLLBAR_H

#include <QToolBar>

/**
 * @details Classe TollBar qui hérite de QToolBar qui servira pour les ajouts de contacts,
 * recherche de contacts, trié les contacts, remettre à zero le widget des contacts apres une recherche.
 */
class TollBar : public QToolBar
{
Q_OBJECT

public:
    explicit TollBar(QWidget *);

private:

    QAction *ajouter{};
    QAction *chercher{};
    QAction *tri{};
    QAction *resetListContactsWidget{};


private slots:

    void ajouterContact();

    void chercherContact();

    void triContacts();

    void resetActionTriggered();

};


#endif //PROJET_QT_TOLLBAR_H
