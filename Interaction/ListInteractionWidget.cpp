//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "ListInteractionWidget.h"
#include <QLabel>
#include "GroupBoxInteraction.h"
#include "../BaseDeDonne/BD.h"


/**
 * Constructeur de ListInteractionWidget
 * @param lstInteraction
 * @param parent
 */
ListInteractionWidget::ListInteractionWidget(ListInteraction *lstInteraction, QWidget *parent) : lstInteraction(
        lstInteraction), QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    ajoutBtn = new QPushButton("Ajouter", this);
    setMinimumWidth(350);
    ajoutBtn->setDefault(true);

    connect(ajoutBtn, &QPushButton::clicked, this, &ListInteractionWidget::ajoutInteraction);

    layout->addWidget(ajoutBtn);

    scrollArea = new QScrollArea(this);
    auto *scrollWidget = new QWidget;
    scrollArea->setWidget(scrollWidget);

    layoutScroll = new QVBoxLayout(scrollWidget);

    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setObjectName("scrollArea");
    scrollArea->setStyleSheet("QScrollArea#scrollArea{border: none;}");

    layout->addWidget(scrollArea);


    for (auto interaction: lstInteraction->getListInteraction())
    {
        layoutScroll->addWidget(new GroupBoxInteraction(interaction, this));
    }
}

/**
 * @details Ajoute une interaction dans la base de données
 */
void ListInteractionWidget::ajoutInteraction()
{
    auto *interaction = new Interaction;
    lstInteraction->addInteraction(interaction);
    layoutScroll->addWidget(new GroupBoxInteraction(interaction, this));
    BD::addInteraction(lstInteraction->getContactId(), *interaction);
}

/**
 *
 * @return lstInteraction
 */
ListInteraction *ListInteractionWidget::getLstInteraction() const
{
    return lstInteraction;
}
