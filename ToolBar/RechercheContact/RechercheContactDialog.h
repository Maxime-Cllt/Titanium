//
// Created by rahman on 01/11/22.
//

#ifndef PROJET_QT_RECHERCHECONTACTDIALOG_H
#define PROJET_QT_RECHERCHECONTACTDIALOG_H


#include <QDialog>
#include <QComboBox>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "../../Contact/StdListContact.h"

/**
 * @details Classe RechercheContactDialog qui hérite de QDialog,
 * cette classe va gérer les entrés de l’utilisateur et rechercher des contacts en fonction de leurs attributs,
 * puis demandera à la mainWindow d’afficher la liste des contacts recherchée.
 */
class RechercheContactDialog : public QDialog
{
Q_OBJECT
public:
    explicit RechercheContactDialog(StdListContact *lstContact, QWidget *parent);

    ~RechercheContactDialog() override;

private:
    QLabel *label;
    QLineEdit *allRecherche;
    QVBoxLayout *layout{};
    QPushButton *buttonAvance{};
    bool avance;
    QWidgetList lstWidget{};

    StdListContact *lstContact{};
    StdListContact *lstContactReference{};

    QLineEdit *lineNom{};
    QLineEdit *linePrenom{};
    QLineEdit *lineEntreprise{};
    QLineEdit *lineMail{};
    QLineEdit *lineTel{};
    QDateTimeEdit *lineDateDeb{};
    QDateTimeEdit *lineDateFin{};


    void createAvanceUi();

    void cacheUiAvance();

    void afficheUiAvance();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:

    void btnAvanceClicked();

    void allRechercheLineTextChanged();

    void rechercheAvance();

signals:

    void closeDialog();

    /**
     * @brief signal quand un contact est recherché.
     */
    void contactSought(StdListContact *lst);

};


#endif //PROJET_QT_RECHERCHECONTACTDIALOG_H
