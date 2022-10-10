//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#ifndef PROJET_QT_INTERACTIONGROUPBOX_H
#define PROJET_QT_INTERACTIONGROUPBOX_H

#include <QGroupBox>
#include "Interaction.h"
#include <QTextEdit>
#include <QPushButton>

class InteractionGroupBox : public QGroupBox
{
Q_OBJECT

public:
    explicit InteractionGroupBox(Interaction *interaction, QWidget *parent = nullptr);

private:
    Interaction *interaction{};
    QPushButton *modifBtn{};
    QTextEdit *textEdit{};


};


#endif //PROJET_QT_INTERACTIONGROUPBOX_H
