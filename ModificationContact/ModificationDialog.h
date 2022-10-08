//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef UNTITLED2_MODIFICATIONDIALOG_H
#define UNTITLED2_MODIFICATIONDIALOG_H

#include <QDialog>
#include <QScrollArea>
#include <QLayout>
#include "../Contact/StdFicheContact.h"
#include "../MainWindow/MainWindow.h"
#include "../Contact/TraductionQtStd.h"


class ModificationDialog : public QDialog
{
Q_OBJECT

public:
    explicit ModificationDialog(QWidget *parent);

private:
    QList<StdFicheContact *> *lstContact{};
    QVBoxLayout *lay{};
    QScrollArea *scrollArea{};
    QWidget *scrollAreaWidget{};
    QVBoxLayout *layScrollArea{};


};


#endif //UNTITLED2_MODIFICATIONDIALOG_H
