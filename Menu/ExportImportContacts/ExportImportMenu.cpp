//
// Created by rahman on 30/10/22.
//

#include "ExportImportMenu.h"
#include <QFileDialog>
#include <QMessageBox>
#include "../../Json/JsonConverter.h"
#include "../../Utility/Utility.h"
#include "../../MainWindow/MainWindow.h"

ExportImportMenu::ExportImportMenu(QWidget *parent) : QMenu(parent)
{

    setTitle("&Json");

    exportAction = new QAction("Exporter");
    connect(exportAction, &QAction::triggered, this, &ExportImportMenu::exportActionTriggered);

    importAction = new QAction("Importer");
    connect(importAction, &QAction::triggered, this, &ExportImportMenu::importActionTriggered);

    addAction(exportAction);

    addAction(importAction);
}

/**
 * @details Export dans un fichier json la liste des contacts.
 */
void ExportImportMenu::exportActionTriggered()
{
    lstContact = qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact();

    QFile file(QFileDialog::getSaveFileName(this, "Enregistrez-sous", QDir::homePath(), "json (*.json)"));

    if (!file.fileName().isEmpty())
    {

        QFileInfo fileInfo(file);

        if (fileInfo.suffix().isEmpty() || fileInfo.suffix() != "json")
        {
            file.setFileName(file.fileName() + ".json");
        }

        if (file.open(QIODevice::ReadWrite))
        {
            QJsonDocument json(JsonConverter::contactToJson(*lstContact));
            file.write(json.toJson());
            file.close();
            QMessageBox::information(this, "Succès", "L'export a été réalisé avec succès !");
        }
    }

}

/**
 * @details Importe depuis un fichier json la liste des contacts.
 */
void ExportImportMenu::importActionTriggered()
{
    lstContact = qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact();

    QFile file(QFileDialog::getOpenFileName(this, "Import json", QDir::homePath(), "json (*.json)"));
    auto *lst = JsonConverter::getContact(file.fileName());

    if (lst->size() == 0)
    {
        QMessageBox::warning(nullptr, "Erreur", "Le fichier n’est pas bon ou mal formaté.");
        return;
    }

    QString str;
    int i = 1;
    for (auto contact: *lst->getLstContact())
    {
        if (lstContact->contains(*contact))
        {
            str += QString::number(i) + " : Le Contact : " + QString::fromStdString(contact->getNom()) + " " +
                   QString::fromStdString(contact->getPrenom()) + " est deja present dans la liste.\n";
            i++;
        } else
            qobject_cast<MainWindow *>(Utility::getMainWindow(this))->addContact(contact);
    }
    if (str.isEmpty())
    {
        QMessageBox::information(nullptr, "Succès", "L'importation a été réalisée avec succès.");
    } else
    {
        QMessageBox msb(QMessageBox::Icon::Warning, "Informations", "Erreur sur l’importation des contacts",
                        QMessageBox::StandardButton::Ok);
        msb.setDetailedText(str);
        msb.exec();
    }
    lst->getLstContact()->clear();
    delete lst;

    lstContact->sort(StdListContact::Date);
    qobject_cast<MainWindow *>(
            Utility::getMainWindow(this))->findChildren<ListContactWidget *>().first()->recreateGroupeBoxContact();
}
