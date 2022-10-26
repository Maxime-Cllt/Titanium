//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef UNTITLED2_GROUPEBOXCONTACT_H
#define UNTITLED2_GROUPEBOXCONTACT_H

#include <QGroupBox>
#include <QGridLayout>
#include "../Contact/StdListContact.h"
#include "../Interaction/ListInteractionWidget.h"
#include <QMouseEvent>
#include <QMenu>


class GroupeBoxContact : public QGroupBox
{
Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    GroupeBoxContact(StdContact *contact, QWidget *parent = nullptr);

    void reactualiseDonne();

    void cache();

    ListInteractionWidget *getListInteractionWidget();


private:

    void createUi();

private:
    QGridLayout *layout{};

    StdContact *contact{};

    ListInteractionWidget *listInteractionWidget{};

    signals:

    void supBtnClicled(StdContact *contact);


};


#endif //UNTITLED2_GROUPEBOXCONTACT_H
