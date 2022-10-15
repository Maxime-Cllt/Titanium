//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef UNTITLED2_GROUPEBOXCONTACT_H
#define UNTITLED2_GROUPEBOXCONTACT_H

#include <QGroupBox>
#include <QGridLayout>
#include "../Contact/StdListContact.h"
#include "ListContactWidget.h"
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


private:

    void createUi();

    QGridLayout *layout{};

    StdContact *contact{};


};


#endif //UNTITLED2_GROUPEBOXCONTACT_H