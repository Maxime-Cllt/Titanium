//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ModifContactDialog.h"
#include "../BaseDeDonne/BD.h"
#include "../MainWindow/MainWindow.h"

/**
 * @details Constructeur de la classe ModifContactDialog
 * @param contact
 * @param parent
 */
ModifContactDialog::ModifContactDialog(StdContact *contact, QWidget *parent) : ContactDialog(parent), contact(contact)
{

    setWindowTitle("Modification de la fiche contact");

    QtContact qtContact(Utility::StdFicheContacttoQtFicheContact(*contact));

    QDateTime date;
    date.setMSecsSinceEpoch(this->contact->getDateCreation() / 1000);
    QLocale local(QLocale::Language::French);
    labDateCreation->setText(local.toString(date, "dddd, d MMMM yyyy hh:mm:ss"));

    QPixmap im(qtContact.getPhoto());
    labIm->setPixmap(im.scaled(100, 100, Qt::KeepAspectRatio));

    line1->setText(qtContact.getNom());
    line2->setText(qtContact.getPrenom());
    line3->setText(qtContact.getEntreprise());
    line4->setText(qtContact.getMail());
    line5->setText(qtContact.getTelephone());
    line6->setText(qtContact.getPhoto());

    btAction->setText("Modifier");


}

/**
 * @details Fonction de vérification des champs saisis lors de l'ajout du contact
 */
void ModifContactDialog::btActionClicked()
{
    QString mess("Des champs sont vides !!\n");
    bool pass = true;
    int autreQueLettreOuNombre = 0;
    for (auto *line: findChildren<QLineEdit *>())
    {
        if (line->text().isEmpty())
        {
            pass = false;
            break;
        } else
        {
            if (line->objectName() == "tel")
            {
                for (auto c: line->text())
                {
                    if (!c.isDigit())
                    {
                        mess += "Le Telephone doit contenir uniquement des chiffres !!";
                        pass = false;
                        break;
                    }
                }
            } else
            {
                for (auto c: line->text())
                {
                    if (!c.isDigit() && !c.isLetter())
                        autreQueLettreOuNombre++;
                }
            }
        }

        if (autreQueLettreOuNombre == line->text().size() && !line->text().isEmpty())
            pass = false;
        autreQueLettreOuNombre = 0;
    }
    if (!pass)
    {
        QMessageBox::critical(this, "Erreur", mess);
    } else
    {
        QtContact qtContact(getContact());
        qtContact.setDateCreation(contact->getDateCreation());
        auto *lst = contact->getLstInteraction();
        *contact = Utility::QtFicheContactToStdFicheContact(qtContact);
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getHistorique()->addLog(
                ListHistorique::ModificationContact, *contact);
        contact->setlstInteraction(lst);
        int rep = BD::modifyContact(*contact);
        if (rep)
        {
            emit dataModified();
            close();
        }
    }
}
