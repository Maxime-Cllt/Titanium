//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#ifndef PROJET_QT_CREATIONINTERACTIONDIALOG_H
#define PROJET_QT_CREATIONINTERACTIONDIALOG_H

#include "InteractionTextEdit.h"
#include <QDialog>
#include <QPushButton>
#include "../../Contact/StdContact.h"

class CreationInteractionDialog : public QDialog
{

Q_OBJECT

public:
    explicit CreationInteractionDialog(QWidget *parent = nullptr);

private:
    InteractionTextEdit *text{};
    QPushButton *ajouter{};

signals:

    void addInteractionClicked(Interaction *);

};


#endif //PROJET_QT_CREATIONINTERACTIONDIALOG_H
