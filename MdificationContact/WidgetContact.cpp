//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "WidgetContact.h"

#include <QLabel>

WidgetContact::WidgetContact(FicheContact contact, QWidget *parent ) : QGroupBox(parent), contact(contact)
{

    layout = new QGridLayout(this);

    layout->addWidget(new QLabel(contact.getNom() + " " + contact.getPrenom()),0,0);
    layout->addWidget(new QLabel(contact.getEntreprise()),0,1);
    layout->addWidget(new QLabel(contact.getMail()),1,0);
    layout->addWidget(new QLabel(contact.getTelephone()),1,1);



}


void WidgetContact::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    setStyleSheet("QGroupBox{background-color: gray;border-radius: 5px;}");
}


void WidgetContact::mouseReleaseEvent(QMouseEvent *event)
{
    QGroupBox::mouseReleaseEvent(event);
    setStyleSheet("");

}
