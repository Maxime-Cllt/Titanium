//
// Created by rahman on 03/11/22.
//

#ifndef PROJET_QT_INTERACTIONTEXTEDIT_H
#define PROJET_QT_INTERACTIONTEXTEDIT_H


#include <QTextEdit>
#include "../ListInteraction.h"


class InteractionTextEdit : public QTextEdit
{

Q_OBJECT

public:
    explicit InteractionTextEdit(Interaction * = nullptr, QWidget * = nullptr);


private:
    Interaction *interaction{};

    void parseContenu();

public:
    Interaction *parseTache();

};


#endif //PROJET_QT_INTERACTIONTEXTEDIT_H
