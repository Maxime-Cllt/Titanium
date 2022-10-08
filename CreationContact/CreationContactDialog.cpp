//
// Created by rahman on 08/10/22.
//

#include "CreationContactDialog.h"


CreationContactDialog::CreationContactDialog(QWidget *parent) : FicheContactDialog(parent)
{

}

void CreationContactDialog::btAddClicked()
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
        QtFicheContact qtFicheContact(line1->text(), line2->text(), line3->text(), line4->text(), line5->text(),
                                      line6->text(), dateTime, {});
        qobject_cast<MainWindow *>(parent())->addContact(
                new StdFicheContact(TraductionQtStd::QtFicheContactToStdFicheContact(qtFicheContact)));

        int rep = QMessageBox::information(this, "Information", "Le contact à été ajouté avec succès.");
        if (rep == QMessageBox::Ok)
        {
            close();
        }
    }
}