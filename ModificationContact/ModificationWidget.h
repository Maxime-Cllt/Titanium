//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef UNTITLED2_MODIFICATIONWIDGET_H
#define UNTITLED2_MODIFICATIONWIDGET_H

#include <QDialog>
#include <QScrollArea>
#include <QLayout>

class ModificationWidget : public QDialog
{
Q_OBJECT

public:
    explicit ModificationWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *lay{};
    QScrollArea * scrollArea{};
    QWidget* scrollAreaWidget{};
    QVBoxLayout *layScrollArea{};


};


#endif //UNTITLED2_MODIFICATIONWIDGET_H
