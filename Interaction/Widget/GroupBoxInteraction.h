//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#ifndef PROJET_QT_GROUPBOXINTERACTION_H
#define PROJET_QT_GROUPBOXINTERACTION_H

#include <QGroupBox>
#include "../Interaction.h"
#include "InteractionTextEdit.h"
#include <QPushButton>
#include <QLabel>

class GroupBoxInteraction : public QGroupBox
{
Q_OBJECT

public:
    explicit GroupBoxInteraction(Interaction *interaction, QWidget *parent);

private:
    Interaction *interaction{};
    QLabel *labDateModif{};
    QPushButton *modifBtn{};
    QPushButton *supBtn{};
    InteractionTextEdit *textEdit{};

signals:

    void *supBtnClicked(Interaction *interaction);

    void *modifBtnClicked();
};


#endif //PROJET_QT_GROUPBOXINTERACTION_H
