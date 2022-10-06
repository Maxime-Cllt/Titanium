//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef UNTITLED2_WIDGETCONTACT_H
#define UNTITLED2_WIDGETCONTACT_H

#include <QGroupBox>
#include <QGridLayout>
#include "../Contact/FicheContact.h"


class WidgetContact: public QGroupBox
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    WidgetContact(FicheContact contact, QWidget * parent = nullptr);
private:

    FicheContact contact;

    QGridLayout *layout{};


};


#endif //UNTITLED2_WIDGETCONTACT_H
