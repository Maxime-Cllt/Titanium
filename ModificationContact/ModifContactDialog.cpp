//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ModifContactDialog.h"

ModifContactDialog::ModifContactDialog(StdContact *contact, QWidget *parent) : ContactDialog(parent), contact(contact)
{

    setWindowTitle("Modification de la fiche contact");

    QtContact qtContact(TraductionQtStd::StdFicheContacttoQtFicheContact(*contact));

    QDateTime date;
    date.setMSecsSinceEpoch(contact->getDateCreation()*1000);
    QLocale local(QLocale::Language::French);
    labDateCreation->setText(local.toString(date,"dddd, MMMM d yyyy hh:mm:ss"));

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
        QtContact qtContact(getContact(contact->getDateCreation(),*contact->getLstInteraction()));
        *contact = TraductionQtStd::QtFicheContactToStdFicheContact(qtContact);
        int rep = BD::modifyContact(*contact);
        if (rep){
            qobject_cast<GroupeBoxContact *>(parent())->reactualiseDonne();
            close();
        }
    }
}
