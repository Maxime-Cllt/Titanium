//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#ifndef PROJET_QT_LISTINTERACTIONWIDGET_H
#define PROJET_QT_LISTINTERACTIONWIDGET_H

#include <QWidget>
#include "Interaction.h"
#include <QScrollArea>
#include <QPushButton>
#include <QVBoxLayout>
#include "ListInteraction.h"


class ListInteractionWidget : public QWidget
{
Q_OBJECT

public:
    explicit ListInteractionWidget(ListInteraction *lstInteraction, QWidget *parent);

private:
    ListInteraction *lstInteraction{};
    QScrollArea *scrollArea{};
    QVBoxLayout *layoutScroll{};
    QPushButton *ajoutBtn{};
public:
    ListInteraction *getLstInteraction() const;

private slots:

    void ajoutInteraction();

};


#endif //PROJET_QT_LISTINTERACTIONWIDGET_H
