//
// Created by rahman on 15/11/22.
//

#ifndef PROJET_QT_SUPPRESSIONDIALOG_H
#define PROJET_QT_SUPPRESSIONDIALOG_H

#include <QDialog>
#include <QTreeWidget>
#include <QLayout>
#include "TreeWidget.h"

/**
 * @details Classe SuppressionDialog qui crée une fenêtre de dialogue avec un widget TreeWidget qui gere la suppression multiple.
 */
class SuppressionDialog : public QDialog
{
Q_OBJECT
public:
    explicit SuppressionDialog(StdListContact *lst, QWidget *parent = nullptr);


private:
    QGridLayout *lay{};

    StdListContact *listContact{};

    TreeWidget *tree{};

signals:

    void contactSupprimer(StdListContact *lst);

};


#endif //PROJET_QT_SUPPRESSIONDIALOG_H
