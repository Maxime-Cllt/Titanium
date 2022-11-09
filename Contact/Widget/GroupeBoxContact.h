//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef PROJET_QT_GROUPEBOXCONTACT_H
#define PROJET_QT_GROUPEBOXCONTACT_H

#include <QGroupBox>
#include <QGridLayout>
#include "../StdListContact.h"
#include "../../Interaction/Widget/ListInteractionWidget.h"
#include <QMouseEvent>
#include <QMenu>
#include <QLabel>


class GroupeBoxContact : public QGroupBox
{
Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *) override;

    void mouseReleaseEvent(QMouseEvent *) override;

public:
    explicit GroupeBoxContact(StdContact *contact, QWidget *parent = nullptr);

    void cacheOuAfficheInteractions();

    void cacheInteractions();

    void afficheInteractions();

    void resetStyleSheet();

    ListInteractionWidget *getListInteractionWidget();


private:

    void createUi();

public:
    [[nodiscard]] StdContact *getContact() const;

private:
    QGridLayout *layout{};

    StdContact *contact{};

    ListInteractionWidget *listInteractionWidget{};

    QLabel *labImage{};
    QLabel *labNomPrenom{};
    QLabel *labEntreprise{};
    QLabel *labMail{};
    QLabel *labTel{};

signals:

    void supBtnClicled(StdContact *);

private slots:

    void menu1Triggered();

    void menu3Triggered();

    void reactualiseDonne();

};


#endif //PROJET_QT_GROUPEBOXCONTACT_H
