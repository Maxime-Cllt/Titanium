//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef PROJET_QT_MODIFCONTACTDIALOG_H
#define PROJET_QT_MODIFCONTACTDIALOG_H

#include <QDialog>
#include "ContactDialog.h"
#include "../Contact/Widget/GroupeBoxContact.h"

class ModifContactDialog : public ContactDialog
{
Q_OBJECT

public:
    explicit ModifContactDialog(StdContact *contact, QWidget *parent);

    virtual void btActionClicked();

private:
    StdContact *contact{};

    signals:
    void dataModified();
};


#endif //PROJET_QT_MODIFCONTACTDIALOG_H
