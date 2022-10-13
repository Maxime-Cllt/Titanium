//
// Created by rahman on 08/10/22.
//

#include "CreationContactDialog.h"

CreationContactDialog::CreationContactDialog(QWidget *parent) : ContactDialog(parent)
{
    setWindowTitle("Creation de la fiche contact");

    QDateTime date;
    date.setMSecsSinceEpoch(time(nullptr)*1000);
    QLocale local(QLocale::Language::French);
    labDateCreation->setText(local.toString(date,"dddd, MMMM d yyyy"));

    btAction->setText("Ajouter");

}

void CreationContactDialog::btActionClicked()
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
        QtContact qtContact(getContact(time(nullptr),{}));
        qobject_cast<MainWindow *>(parent())->getLstContact()->addContact(qtContact);
        BD::addOnBD(TraductionQtStd::QtFicheContactToStdFicheContact(qtContact));
        int rep = QMessageBox::information(this, "Information", "Le contact à été ajouté avec succès.");
        if (rep == QMessageBox::Ok)
        {
            close();
        }
    }
}
