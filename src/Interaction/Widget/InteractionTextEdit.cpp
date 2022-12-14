//
// Created by rahman on 03/11/22.
//

#include <QDate>
#include "InteractionTextEdit.h"

InteractionTextEdit::InteractionTextEdit(Interaction *interaction, QWidget *parent) : QTextEdit(parent),
                                                                                      interaction(interaction)
{


    // si une interaction est passée au moment d’instancié l’objet, on insère le contenu de celui-ci dans le textEdit
    if (this->interaction)
    {
        parseContenu();
    }
}


/**
 * @details Fonction pour trier les tâches qui contiennent des TO-DO et récupérer cette tâche et voir si elle contient le tag @date
 * @param str
 */
Interaction *InteractionTextEdit::parseTache()
{
    // si l’objet InteractionTextEdit a été instancié sans lui passer en paramètre une interaction, on la crée.
    if (!interaction)
        interaction = new Interaction;

    QStringList lst(document()->toPlainText().split("\n"));


    auto *lstTache = new ListTache;


    for (const auto &line: lst)
    {
        QStringList lstWord(line.split(" "));
        Tache tache;
        if (lstWord.contains("@todo"))
        {
            tache.setcontenu(line.toStdString());
            lstTache->addTache(tache);
        }
    }
    interaction->setLstTache(lstTache);

    QString str = document()->toPlainText();
    for (auto tache: *lstTache->getLstTache())
        str.remove(QString::fromStdString(tache->getcontenu()));
    QString contenu;
    for (const auto &line: str.split("\n"))
    {
        if (!line.isEmpty())
            contenu += line + "\n";
    }
    interaction->setContenu(contenu.toStdString());

    parseContenu();

    return interaction;
}

/**
 * @details Parse le contenu de l'interaction, colories les todos en rouge.
 */
void InteractionTextEdit::parseContenu()
{
    clear();

    // on récupère le contenu de l’interaction et on remplace les retours à la ligne par des <br> car nous travaillons en html.
    QString contenu = QString::fromStdString(interaction->getContenu());
    contenu.replace("\n", "<br>");

    QString str("<font color=red>");
    for (auto tache: *interaction->getLstTache()->getLstTache())
        str += QString::fromStdString(tache->getcontenu()) + "<br>";
    str += "</font";
    insertHtml(contenu + str);
}
