//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "ListInteractionWidget.h"
#include "GroupBoxInteraction.h"
#include "../../BaseDeDonne/BD.h"
#include "../../MainWindow/MainWindow.h"
#include "../../Utility/Utility.h"


/**
 * @details Constructeur de la classe ListInteractionWidget
 * @param lstInteraction
 * @param parent
 */
ListInteractionWidget::ListInteractionWidget(ListInteraction *lstInteraction, QWidget *parent) : lstInteraction(
        lstInteraction), QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    ajoutBtn = new QPushButton("Ajouter", this);
    setMinimumWidth(500);
    ajoutBtn->setDefault(true);

    connect(ajoutBtn, &QPushButton::clicked, this, &ListInteractionWidget::addInteraction);

    layout->addWidget(ajoutBtn);

    scrollArea = new QScrollArea(this);
    auto *scrollWidget = new QWidget;
    scrollArea->setWidget(scrollWidget);

    layoutScroll = new QVBoxLayout(scrollWidget);
    layoutScroll->setSpacing(30);

    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setObjectName("scrollArea");
    scrollArea->setStyleSheet("QScrollArea#scrollArea{border: none;}");
    scrollArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);

    layout->addWidget(scrollArea);

    createUi();

}

/**
 * @details Ajoute une interaction dans la base de données
 */
void ListInteractionWidget::addInteraction()
{
    auto *interaction = new Interaction;
    addInteraction1(interaction);

}

/**
 *
 * @return lstInteraction
 */
ListInteraction *ListInteractionWidget::getLstInteraction() const
{
    return lstInteraction;
}

/**
 * @details Réactualise le widget qui contient les groupebox des interaction a chaque fois qu'une nouvelle interaction est ajouté.
 */
void ListInteractionWidget::reactualiseUi()
{
    for (auto *widget: scrollArea->findChildren<GroupBoxInteraction *>())
    {
        widget->close();
    }
    createUi();
}

/**
 * @brief Fonction qui crée le Ui design
 */
void ListInteractionWidget::createUi()
{
    lstInteraction->reverse();
    for (auto interaction: *lstInteraction->getListInteraction())
    {
        auto *box = new GroupBoxInteraction(interaction, scrollArea);

        // quand le boutton supprimé d'une interaction est clické.
        connect(box, &GroupBoxInteraction::supBtnClicked, this, [this](Interaction *interaction)
        {
            // on supprime l'interaction de la base de donné
            BD::supInteraction(*interaction);

            // on supprime l'interaction de la liste des interactions
            this->lstInteraction->supInteraction(interaction);

            // on emet un signal pour modifier le label qui indique le nombre d'interaction dans la statusbar.
            emit updateNbInteraction(QString::number(lstInteraction->size()));

        });

        // quand le boutton modifié d'une interaction est clické.
        connect(box, &GroupBoxInteraction::modifBtnClicked, this, &ListInteractionWidget::reactualiseUi);

        layoutScroll->addWidget(box);
    }
}


/**
 * @brief Fonction qui cahce le widget.
 */
void ListInteractionWidget::cache()
{
    hide();
    emit updateNbInteraction(QString::number(lstInteraction->size()));
}

void ListInteractionWidget::addInteraction1(Interaction *interaction)
{
    lstInteraction->addInteraction(interaction);

    auto *box = new GroupBoxInteraction(interaction, scrollArea);
    layoutScroll->insertWidget(0, box);

    connect(box, &GroupBoxInteraction::supBtnClicked, this, [this](Interaction *interaction)
    {
        BD::supInteraction(*interaction);
        this->lstInteraction->supInteraction(interaction);
        emit updateNbInteraction(QString::number(lstInteraction->size()));
    });
    BD::addInteraction(lstInteraction->getidContact(), *interaction);
    emit updateNbInteraction(QString::number(lstInteraction->size()));
}

