//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "GroupeBoxContact.h"
#include "ListContactWidget.h"
#include "../MainWindow/MainWindow.h"

#include <QLabel>
#include <QLineEdit>


/**
 *  Constructeur de ListContactWidget
 * @param parent
 */
ListContactWidget::ListContactWidget(QWidget *parent) : QWidget(parent)
{

    lay = new QVBoxLayout(this);

    scrollArea = new QScrollArea(this);
    scrollArea->setStyleSheet("QScrollArea{border: none;}");
    scrollAreaWidget = new QWidget;
    layScrollArea = new QVBoxLayout(scrollAreaWidget);

    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lay->addWidget(scrollArea);


    for (auto contact: *(qobject_cast<MainWindow *>(parent)->getLstContact())->getLstContact())
    {
        layScrollArea->addWidget(new GroupeBoxContact(contact, this));
    }

}

/**
 * @param contact
 */
void ListContactWidget::addContactBox(StdContact *contact)
{
    layScrollArea->addWidget(new GroupeBoxContact(contact, scrollArea));
}

/**
 *
 * @param lastConctactselected
 */
void ListContactWidget::setLastConctactselected(GroupeBoxContact *lastConctactselected)
{
    if (this->lastConctactselected != lastConctactselected)
    {
        if (this->lastConctactselected)
        {
            this->lastConctactselected->cache();
        }
        qobject_cast<MainWindow *>(parentWidget()->parentWidget())->setListInteractionWidget(
                lastConctactselected->getListInteractionWidget());
        this->lastConctactselected = lastConctactselected;
    }
}
