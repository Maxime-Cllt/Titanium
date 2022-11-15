//
// Created by rahman on 15/11/22.
//

#ifndef PROJET_QT_TREEWIDGET_H
#define PROJET_QT_TREEWIDGET_H

#include <QTreeWidget>
#include "../../Contact/StdListContact.h"

class TreeWidget : public QTreeWidget
{
Q_OBJECT

public:
    explicit TreeWidget(StdListContact *lst, QWidget *parent = nullptr);

private:
    class TreeItemContact : public QTreeWidgetItem
    {
    public:
        explicit TreeItemContact(StdContact *contact, QTreeWidget *parent = nullptr);

    private:
        StdContact *contact;
    public:
        StdContact *getContact() const;
    };

private:
    StdListContact *listContact{};

    void addOnTree();
protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:

    void suppClicked(StdListContact *lst);
};

#endif //PROJET_QT_TREEWIDGET_H
