//
// Created by rahman on 15/11/22.
//

#include "SuppressionDialog.h"


/**
 * @details Constructeur par défaut.
 * @param lst
 * @param parent
 */
SuppressionDialog::SuppressionDialog(StdListContact *lst, QWidget *parent) : QDialog(parent), listContact(lst)
{
    setWindowTitle("Suppression");
    lay = new QGridLayout(this);

    tree = new TreeWidget(lst);

    connect(tree, &TreeWidget::suppClicked, this, [=, this](StdListContact *lst)
    {
        emit contactSupprimer(lst);
    });

    lay->addWidget(tree);
}

