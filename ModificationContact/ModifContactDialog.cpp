//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ModifContactDialog.h"

ModifContactDialog::ModifContactDialog(StdContact *contact, QWidget *parent) : ContactDialog(parent), contact(contact)
{
    QtContact qtContact(TraductionQtStd::StdFicheContacttoQtFicheContact(*contact));

    QPixmap im(qtContact.getPhoto());
    labIm->setPixmap(im.scaled(100, 100, Qt::KeepAspectRatio));

    line1->setText(qtContact.getNom());
    line2->setText(qtContact.getPrenom());
    line3->setText(qtContact.getEntreprise());
    line4->setText(qtContact.getMail());
    line5->setText(qtContact.getTelephone());
    line6->setText(qtContact.getPhoto());
    line7->setText(qtContact.getDateCreation().toString());

    btAction->setText("Modifier");
}


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
        auto *ancien = contact;
        contact = new StdContact(TraductionQtStd::QtFicheContactToStdFicheContact(getContact()));
        qDebug() << "ici";
        delete ancien;
        qDebug() << "ici";

        int rep = QMessageBox::information(this, "Information", "Le contact à été modifié avec succès.");
        if (rep == QMessageBox::Ok)
        {
            close();
            qobject_cast<ModificationDialog *>(
                    qobject_cast<GroupeBoxContact *>(parent())->parent())->createContactGroupBox();
            qDebug() << "ici";
        }
    }
}
