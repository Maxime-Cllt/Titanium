//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "ListInteractionWidget.h"
#include <QLabel>
#include "GroupBoxInteraction.h"
#include "../BaseDeDonne/BD.h"

ListInteractionWidget::ListInteractionWidget(ListInteraction *lstInteraction, QWidget *parent) : lstInteraction(
        lstInteraction), QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    ajoutBtn = new QPushButton("Ajouter", this);
    ajoutBtn->setMinimumWidth(400);
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

    layout->addWidget(scrollArea);


    lstInteraction->reverse();
    for (auto interaction: lstInteraction->getListInteraction())
    {
        layoutScroll->addWidget(new GroupBoxInteraction(interaction, scrollArea));
    }
}

void ListInteractionWidget::ajoutInteraction()
{
    auto *interaction = new Interaction;
    lstInteraction->addInteraction(interaction);
    reactualiseUi();
    BD::addInteraction(lstInteraction->getContactId(), *interaction);
}

ListInteraction *ListInteractionWidget::getLstInteraction() const
{
    return lstInteraction;
}

void ListInteractionWidget::reactualiseUi()
{
    lstInteraction->reverse();
    for (auto *widget: scrollArea->findChildren<GroupBoxInteraction *>())
    {
        widget->close();
    }
    for (auto interaction: lstInteraction->getListInteraction())
    {
        layoutScroll->addWidget(new GroupBoxInteraction(interaction, scrollArea));
    }
}
