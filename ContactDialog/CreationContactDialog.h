//
// Created by rahman on 08/10/22.
//

#ifndef PROJET_QT_CREATIONCONTACTDIALOG_H
#define PROJET_QT_CREATIONCONTACTDIALOG_H

#include "ContactDialog.h"
#include "../MainWindow/MainWindow.h"

class CreationContactDialog : public ContactDialog
{
Q_OBJECT

public:
    explicit CreationContactDialog(QWidget *parent);

public:
    virtual void btActionClicked();

signals:

    void btnActionClicked(StdContact *);
};


#endif //PROJET_QT_CREATIONCONTACTDIALOG_H
