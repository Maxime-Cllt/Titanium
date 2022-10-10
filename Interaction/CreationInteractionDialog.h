//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#ifndef PROJET_QT_CREATIONINTERACTIONDIALOG_H
#define PROJET_QT_CREATIONINTERACTIONDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include "../Contact/StdContact.h"

class CreationInteractionDialog : public QDialog
{

Q_OBJECT

public:
    explicit CreationInteractionDialog(StdContact *contact, QWidget *parent = nullptr);

private:
    QTextEdit *text{};
    QPushButton *ajouter{};
    StdContact *contact{};

};


#endif //PROJET_QT_CREATIONINTERACTIONDIALOG_H
