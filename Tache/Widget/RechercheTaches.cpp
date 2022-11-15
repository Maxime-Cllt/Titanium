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

    textEdit = new QTextEdit(this);
    textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    textEdit->setReadOnly(true);
    textEdit->setWordWrapMode(QTextOption::NoWrap);

    textEdit->setContextMenuPolicy(Qt::CustomContextMenu);

    layout->addWidget(textEdit, 3, 0, 1, 2);

    remplirTextEdit();

    connect(debut, &QDateTimeEdit::dateTimeChanged, this, &RechercheTaches::remplirTextEdit);
    connect(fin, &QDateTimeEdit::dateTimeChanged, this, &RechercheTaches::remplirTextEdit);


}

/**
 * @details Fonction qui est appelée a change fois que la date des QDateTimeEdit change et met à jour le contenu
 * de la QTextEdit.
 */
void RechercheTaches::remplirTextEdit()
{
    // on récupère la date des QDateTimeEdit, on multiplie par 1000, car la date d'une tache est en microseconde.
    uint64_t dateDebut = debut->dateTime().toMSecsSinceEpoch() * 1000;
    uint64_t dateFin = fin->dateTime().toMSecsSinceEpoch() * 1000;
    uint64_t currentTime = QDateTime::currentMSecsSinceEpoch() * 1000;

    textEdit->clear();


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

    int i = 1;

    // variable qui stockera tout le contenu des taches.
    QString str;

    QDateTime dateTache;


    if (sort == Sort::Recent)
        lst.sort(ListTache::Recent);
    else
        lst.sort(ListTache::Ancien);

    for (const auto tache: *lst.getLstTache())
    {

        dateTache.setMSecsSinceEpoch((qint64) tache->getdate() / 1000);

        str += QString::number(i) + " : ";

        // une fois sur deux la couleur de la tache ajoutée change pour plus de lisibilité.
        if (i % 2)
            str += "<font color=red>";
        else
            str += "<font color=blue>";
        str += QString::fromStdString(tache->getcontenu()) + " -> [" +
               dateTache.toString("dd/MM/yyyy hh:mm:ss") + " ]</font><br>";
        i++;
    }

    textEdit->insertHtml(str);
}

/**
 * @brief Definit le mode de tri des taches.
 * @param sortMode
 */
void RechercheTaches::setSortMode(RechercheTaches::Sort sortMode)
{
    RechercheTaches::sort = sortMode;
}

/**
 * @details Surcharge de l'évènement click de la souris qui déclenche un menu personnalisé.
 * @param event
 */
void RechercheTaches::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::RightButton)
    {
        auto *menu = textEdit->createStandardContextMenu();

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