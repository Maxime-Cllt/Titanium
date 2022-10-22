//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef UNTITLED2_MODIFCONTACTDIALOG_H
#define UNTITLED2_MODIFCONTACTDIALOG_H

#include <QDialog>
#include "ContactDialog.h"
#include "../ListContactWidget/GroupeBoxContact.h"

class ModifContactDialog : public ContactDialog
{
Q_OBJECT

public:
    explicit ModifContactDialog(StdContact *contact, QWidget *parent);

    virtual void btActionClicked();

private:
    StdContact *contact{};


};


#endif //UNTITLED2_MODIFCONTACTDIALOG_H
