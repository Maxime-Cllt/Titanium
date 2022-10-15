//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#ifndef PROJET_QT_GROUPBOXINTERACTION_H
#define PROJET_QT_GROUPBOXINTERACTION_H

#include <QGroupBox>
#include "Interaction.h"
#include <QTextEdit>
#include <QPushButton>

class GroupBoxInteraction : public QGroupBox
{
Q_OBJECT

public:
    explicit GroupBoxInteraction(Interaction *interaction, QWidget *parent);

private:
    Interaction *interaction{};
    QPushButton *modifBtn{};
    QPushButton *supBtn{};
    QTextEdit *textEdit{};


};


#endif //PROJET_QT_GROUPBOXINTERACTION_H
