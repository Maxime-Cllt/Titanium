//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#ifndef PROJET_QT_LISTINTERACTIONDIALOG_H
#define PROJET_QT_LISTINTERACTIONDIALOG_H

#include <QDialog>
#include "Interaction.h"
#include <QScrollArea>

class ListInteractionDialog : public QDialog
{
Q_OBJECT

public:
    explicit ListInteractionDialog(std::list<Interaction *> *lstInteraction, QWidget *parent);

private:
    std::list<Interaction *> *lstInteraction{};
    QScrollArea *scrollArea{};

};


#endif //PROJET_QT_LISTINTERACTIONDIALOG_H
