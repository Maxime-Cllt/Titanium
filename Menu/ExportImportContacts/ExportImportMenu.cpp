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
    lstContact->append(*lst);
    delete lst;

    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->resetListContactWidget();
}
