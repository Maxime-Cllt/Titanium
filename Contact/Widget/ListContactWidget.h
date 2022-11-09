//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef PROJET_QT_MODIFICATIONDIALOG_H
#define PROJET_QT_MODIFICATIONDIALOG_H

#include <QWidget>
#include <QScrollArea>
#include <QLayout>
#include "ListContactWidget.h"
#include "GroupeBoxContact.h"


class ListContactWidget : public QWidget
{
Q_OBJECT

public:
    explicit ListContactWidget(StdListContact *lst, QWidget *parent);

private:
    QWidgetList lstWidget;


public:
    StdListContact *getLstContact() const;

    void cacheGroupeBox(StdListContact *);

    void afficheAllGroupeBox();

    void addContactBox(StdContact *);

    void setLastConctactselected(GroupeBoxContact *);

    void recreateGroupeBoxContact();

    void resetLastConctactselected();

private:
    QVBoxLayout *lay{};
    QScrollArea *scrollArea{};
    QWidget *scrollAreaWidget{};
    QVBoxLayout *layScrollArea{};
    StdListContact *lstContact{};

    GroupeBoxContact *lastConctactselected{};


    signals:
    void suppContact(StdContact *);


};


#endif //PROJET_QT_MODIFICATIONDIALOG_H
