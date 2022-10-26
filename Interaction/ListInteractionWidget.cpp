//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "ListInteractionWidget.h"
#include <QLabel>
#include "GroupBoxInteraction.h"
#include "../BaseDeDonne/BD.h"


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

    connect(ajoutBtn, &QPushButton::clicked, this, &ListInteractionWidget::ajoutInteraction);

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
void ListInteractionWidget::ajoutInteraction()
{
    auto *interaction = new Interaction;
    lstInteraction->addInteraction(interaction);
    layoutScroll->insertWidget(0, new GroupBoxInteraction(interaction, scrollArea));
    BD::addInteraction(lstInteraction->getContactId(), *interaction);
    emit updateNbInteraction(lstInteraction->size());
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

void ListInteractionWidget::createUi()
{
    lstInteraction->reverse();
    for (auto interaction: *lstInteraction->getListInteraction())
    {
        auto *box = new GroupBoxInteraction(interaction, scrollArea);
        connect(box, &GroupBoxInteraction::supBtnClicked, this, [this](Interaction *interaction)
        {
            BD::supInteraction(*interaction);
            this->lstInteraction->supInteraction(interaction);
            emit updateNbInteraction(lstInteraction->size());
        });
        connect(box, &GroupBoxInteraction::modifBtnClicked, this, &ListInteractionWidget::reactualiseUi);
        layoutScroll->addWidget(box);
    }
}
