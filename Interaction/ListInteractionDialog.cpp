//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "ListInteractionDialog.h"
#include <QLabel>
#include <QVBoxLayout>
#include "InteractionGroupBox.h"

ListInteractionDialog::ListInteractionDialog(std::list<Interaction *> *lstInteraction, QWidget *parent)
        : lstInteraction(
        lstInteraction),
          QDialog(parent)
{
    setStyleSheet("QDialog{border : none;}");
    auto *layout = new QVBoxLayout(this);

    if (lstInteraction->size() == 0)
    {
        layout->addWidget(new QLabel("Il n'y a pas d'interaction."));
    } else
    {

        scrollArea = new QScrollArea(this);
        auto *scrollWidget = new QWidget;
        scrollArea->setWidget(scrollWidget);

        auto *layoutScroll = new QVBoxLayout(scrollWidget);

        scrollArea->setWidgetResizable(true);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        layout->addWidget(scrollArea);


        for (auto interaction: *lstInteraction)
        {
            layoutScroll->addWidget(new InteractionGroupBox(interaction, this));
        }
    }
}