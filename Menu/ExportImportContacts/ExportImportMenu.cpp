//
// Created by rahman on 30/10/22.
//

#include "ExportImportMenu.h"
#include <QFileDialog>
#include <QMessageBox>
#include "../../Json/JsonConverter.h"
#include "../../Utility/Utility.h"
#include "../../MainWindow/MainWindow.h"

ExportImportMenu::ExportImportMenu(StdListContact *lst, QWidget *parent) : QMenu(parent), lstContact(lst)
{
    setTitle("&Json");

    exportAction = new QAction("Exporter");
    connect(exportAction, &QAction::triggered, this,&ExportImportMenu::exportActionTriggered);

    importAction = new QAction("Importer");
    connect(importAction, &QAction::triggered, this,&ExportImportMenu::importActionTriggered);

    addAction(exportAction);

    addAction(importAction);
}

/**
 * @details Export dans un fichier json la liste des contacts.
 */
void ExportImportMenu::exportActionTriggered()
{
    QFile file(QFileDialog::getSaveFileName(nullptr, "Enregistrez-sous", QDir::homePath(), "json (*.json)"));

    if(!file.fileName().isEmpty()){

        QFileInfo fileInfo(file);

        if(fileInfo.suffix().isEmpty() || fileInfo.suffix()!= "json")
        {
            file.setFileName(file.fileName() + ".json");
        }

        if(file.open(QIODevice::ReadWrite)){
            QJsonDocument json(JsonConverter::contactToJson(*lstContact));
            file.write(json.toJson());
            file.close();
            QMessageBox::information(this,"Succès", "L'export a été réalisé avec succès !");
        }
    }

}

/**
 * @details Importe depuis un fichier json la liste des contacts.
 */
void ExportImportMenu::importActionTriggered()
{
    QFile file(QFileDialog::getOpenFileName(nullptr, "Ouvrir", QDir::homePath(), "json (*.json)"));
    auto *lst = JsonConverter::getContact(file.fileName());
    lstContact->append(*lst);
    delete lst;

    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->resetListContactWidget();
}
