//
// Created by rahman on 03/11/22.
//

#include "RechercheTaches.h"
#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>
#include <QStyle>


/**
 * @brief Constructeur de la classe RechercheTaches.
 * @param lst
 * @param parent
 */
RechercheTaches::RechercheTaches(ListInteraction *listInteraction, QWidget *parent) : QDialog(parent),
                                                                                      lstInteraction(listInteraction)
{

    setWindowTitle("Recherche de Todo");

    layout = new QGridLayout(this);


    layout->addWidget(new QLabel("Définissez les champs de recherche", this), 0, 0, 1, 2, Qt::AlignHCenter);

    layout->addWidget(new QLabel("Début : ", this), 1, 0, 1, 1, Qt::AlignHCenter);
    layout->addWidget(new QLabel("Fin : ", this), 1, 1, 1, 1, Qt::AlignHCenter);

    debut = new QDateTimeEdit(this);
    debut->setMaximumDateTime(QDateTime::currentDateTime());

    layout->addWidget(debut, 2, 0, 1, 1);

    fin = new QDateTimeEdit(this);
    fin->setDateTime(QDateTime::currentDateTime());

    layout->addWidget(fin, 2, 1, 1, 1);

    listWidget = new TreeWidget(listInteraction, this);

    layout->addWidget(listWidget, 3, 0, 1, 2);

    listWidget->initDebFin(debut->dateTime(), fin->dateTime());

    listWidget->remplirTextEdit();

    connect(debut, &QDateTimeEdit::dateTimeChanged, listWidget, &TreeWidget::setDeb);
    connect(fin, &QDateTimeEdit::dateTimeChanged, listWidget, &TreeWidget::setFin);


}

/**
 * @brief Constructeur par défaut de TreeWidget.
 * @param listInteraction
 * @param parent
 */
RechercheTaches::TreeWidget::TreeWidget(ListInteraction *listInteraction, QWidget *parent) : lstInteraction(
        listInteraction)
{
    setAlternatingRowColors(true);
    setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
    setHeaderLabels({"Détail", "Date"});
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    setColumnWidth(0,300);
    setMinimumSize(500,300);
}

/**
 * @details Fonction qui est appelée a change fois que la date des QDateTimeEdit change et met à jour le contenu
 * de la QTreeWidget.
 */
void RechercheTaches::TreeWidget::remplirTextEdit()
{

    clear();

    // on récupère la date des QDateTimeEdit, on multiplie par 1000, car la date d'une tache est en microseconde.
    uint64_t dateDebut = deb.toMSecsSinceEpoch() * 1000;
    uint64_t dateFin = fin.toMSecsSinceEpoch() * 1000;
    uint64_t currentTime = QDateTime::currentMSecsSinceEpoch() * 1000;


    ListTache lst;

    for (const auto interaction: *lstInteraction->getListInteraction())
    {
        for (const auto tache: *interaction->getLstTache()->getLstTache())
        {
            // si la date de la tache est compris entre le debut et la fin des QDateTimeEdit
            if (tache->getdate() > dateDebut and tache->getdate() < dateFin)
            {
                // si afficheTachePasse est vrai, on ajoute la tache dans la liste
                if (afficheTachePasse)
                    lst.addTache(*tache);
                    // si afficheTachePasse, on ajoute uniquement les taches à partir de la date de maintenant.
                else
                {
                    if (tache->getdate() > currentTime)
                        lst.addTache(*tache);
                }
            }
        }
    }


    // variable qui stockera tout le contenu des taches.
    QString str;

    QDateTime dateTache;


    if (sort == Sort::Recent)
        lst.sort(ListTache::Recent);
    else
        lst.sort(ListTache::Ancien);

    for (const auto tache: *lst.getLstTache())
    {
        auto *item = new QTreeWidgetItem(this);
        item->setText(0, QString::fromStdString(tache->getContenuWithoutTodo()));
        dateTache.setMSecsSinceEpoch((qint64) tache->getdate() / 1000);
        item->setText(1, dateTache.toString("dd/MM/yyyy hh:mm:ss"));
        addTopLevelItem(item);
    }
}


/**
 * @details Surcharge de l'évènement click de la souris qui déclenche un menu personnalisé.
 * @param event
 */
void RechercheTaches::TreeWidget::mousePressEvent(QMouseEvent *event)
{
    QAbstractItemView::mousePressEvent(event);
    if (event->button() == Qt::MouseButton::RightButton)
    {
        auto *menu = new QMenu;

        auto *recent = new QAction("Tri récent", this);
        if (sort == Sort::Recent)
            recent->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton));

        connect(recent, &QAction::triggered, this, [=, this]()
        {
            setSortMode(Sort::Recent);
            remplirTextEdit();
        });


        auto *ancien = new QAction("Tri ancien", this);
        if (sort == Sort::Ancien)
            ancien->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton));

        connect(ancien, &QAction::triggered, this, [=, this]()
        {
            setSortMode(Sort::Ancien);
            remplirTextEdit();
        });

        menu->addSeparator();

        auto *actionAfficheTachePasse = new QAction("Afficher les taches passées.", this);
        if (afficheTachePasse)
            actionAfficheTachePasse->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogApplyButton));


        connect(actionAfficheTachePasse, &QAction::triggered, this, [=, this]()
        {
            afficheTachePasse = !afficheTachePasse;
            remplirTextEdit();
        });


        menu->addAction(recent);
        menu->addAction(ancien);
        menu->addSeparator();
        menu->addAction(actionAfficheTachePasse);

        menu->exec(event->globalPos());
        delete menu;
    }
}

/**
* @brief Définit le mode de tri des taches.
* @param sortMode
*/
void RechercheTaches::TreeWidget::setSortMode(RechercheTaches::TreeWidget::Sort sortMode)
{
    RechercheTaches::TreeWidget::sort = sortMode;
}

/**
 * @brief Setter de la date du debut qui appelle la fonction remplirTextEdit qui remplie le QTreeWiget avec les taches.
 * @param d
 */
void RechercheTaches::TreeWidget::setDeb(QDateTime d)
{
    TreeWidget::deb = d;
    remplirTextEdit();
}

/**
 * @brief Setter de la date du debut qui appelle la fonction remplirTextEdit qui remplie le QTreeWiget avec les taches.
 * @param d
 */
void RechercheTaches::TreeWidget::setFin(QDateTime d)
{
    TreeWidget::fin = d;
    remplirTextEdit();
}

/**
 * @brief Fonction pour initializer les dates au debut.
 * @param deb, fin
 */
void RechercheTaches::TreeWidget::initDebFin(QDateTime deb, QDateTime fin)
{
    RechercheTaches::TreeWidget::deb = deb;
    RechercheTaches::TreeWidget::fin = fin;
}
