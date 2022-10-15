//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef UNTITLED2_MODIFICATIONDIALOG_H
#define UNTITLED2_MODIFICATIONDIALOG_H

#include <QWidget>
#include <QScrollArea>
#include <QLayout>
#include "../MainWindow/MainWindow.h"
#include "../Contact/TraductionQtStd.h"


class ListContactWidget : public QWidget
{
Q_OBJECT

public:
    explicit ListContactWidget(QWidget *parent);

private:
    QVBoxLayout *lay{};
    QScrollArea *scrollArea{};
    QWidget *scrollAreaWidget{};
    QVBoxLayout *layScrollArea{};


};


#endif //UNTITLED2_MODIFICATIONDIALOG_H
