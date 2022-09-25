//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef UNTITLED2_CREATEFICHEWIDGET_H
#define UNTITLED2_CREATEFICHEWIDGET_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CreateFicheWidget : public QDialog
{
Q_OBJECT
public:
    explicit CreateFicheWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout{};
    QHBoxLayout *layoutCenter{};
    QVBoxLayout *layGauche{};
    QVBoxLayout *layDroite{};


};


#endif //UNTITLED2_CREATEFICHEWIDGET_H
