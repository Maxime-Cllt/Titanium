//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ModifContactDialog.h"

ModifContactDialog::ModifContactDialog(QtFicheContact contact, QWidget *parent) : FicheContactDialog(parent)
{
    QPixmap im(contact.getPhoto());
    labIm->setPixmap(im.scaled(100, 100, Qt::KeepAspectRatio));

    line1->setText(contact.getNom());
    line2->setText(contact.getPrenom());
    line3->setText(contact.getEntreprise());
    line4->setText(contact.getMail());
    line5->setText(contact.getTelephone());
    line6->setText(contact.getPhoto());
    line7->setText(contact.getDateCreation().toString());

    btAdd->setText("Modifier");

}

void ModifContactDialog::btAddClicked()
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
                        mess +=  "Le Telephone doit contenir uniquement des chiffres !!";
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
        int rep = QMessageBox::information(this, "Information", "Le contact à été modifié avec succès.");
        if (rep == QMessageBox::Ok)
        {
            close();
        }
    }
}
