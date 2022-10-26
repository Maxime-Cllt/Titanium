//
// Created by Rahman  Yilmaz on 26/10/2022.
//

#ifndef PROJET_QT_RECHERCHECONTACTDIALOG_H
#define PROJET_QT_RECHERCHECONTACTDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLayout>
#include "../../Contact/StdListContact.h"

class RechercheContactDialog : public QDialog
{
Q_OBJECT
public:
    explicit RechercheContactDialog(QWidget *parent);

    ~RechercheContactDialog() override;

private:
protected:
    void closeEvent(QCloseEvent *event) override;

private:
    QComboBox *comboBox{};
    QGridLayout *centerLay{};
    QList<QWidget *> lstWidget{};
    StdListContact *lstContact{};

    void rechercheParNom();

    void rechercheParPrenom();

    void rechercheParEntreprise();

    void rechercheParMail();

    void rechercheParTelephone();

    void rechercheParDateAjout();

    QWidget *getMainWindowWidget();

    void clearBottomLayout();

private slots:

    void comboBoxTextChanged(const QString &);


};


#endif //PROJET_QT_RECHERCHECONTACTDIALOG_H
