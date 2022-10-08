//
// Created by rahman on 08/10/22.
//

#ifndef UNTITLED2_CREATIONCONTACTDIALOG_H
#define UNTITLED2_CREATIONCONTACTDIALOG_H

#include "../FicheContactDialog/FicheContactDialog.h"
#include "../Contact/TraductionQtStd.h"
#include "../MainWindow/MainWindow.h"

class CreationContactDialog : public FicheContactDialog
{
Q_OBJECT

public:
    explicit CreationContactDialog(QWidget *parent);

private:
    QList<StdFicheContact> *lstContact{};
public:
    virtual void btAddClicked();
};


#endif //UNTITLED2_CREATIONCONTACTDIALOG_H
