//
// Created by rahman on 08/10/22.
//

#ifndef UNTITLED2_CREATIONCONTACTDIALOG_H
#define UNTITLED2_CREATIONCONTACTDIALOG_H

#include "../ContactDialog/ContactDialog.h"
#include "../MainWindow/MainWindow.h"

class CreationContactDialog : public ContactDialog
{
Q_OBJECT

public:
    explicit CreationContactDialog(QWidget *parent);

public:
    virtual void btActionClicked();
};


#endif //UNTITLED2_CREATIONCONTACTDIALOG_H
