//
// Created by rahman on 03/11/22.
//

#include <QDate>
#include <QDebug>

#include "InteractionTextEdit.h"

InteractionTextEdit::InteractionTextEdit(Interaction *interaction, QWidget *parent) : QTextEdit(parent),
                                                                                      interaction(interaction)
{


    // si une interaction est passée au moment d’instancié l’objet, on insère le contenu de celui-ci dans le textEdit
    if (this->interaction)
    {
        // on récupère le contenu de l’interaction et on remplace les retours à la ligne par des <br> car nous travaillons en html.
        QString contenu= QString::fromStdString(interaction->getContenu());
        contenu.replace("\n", "<br>");

        QString str("<br><font color=red>");
        for (auto tache: *interaction->getLstTache()->getLstTache())
            str += QString::fromStdString(tache->getcontenu()) ;
        str += "</font";
        insertHtml(contenu + str);
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
            int i = lstWord.indexOf("@todo");

            for (int o = i + 2; o < lstWord.size(); o++)
            {
                if (lstWord[o] == "@date")
                {
                    QDate date(lstWord[o + 1].split("/")[2].toInt(), lstWord[o + 1].split("/")[1].toInt(),
                               lstWord[o + 1].split("/")[0].toInt());
                    QDateTime dateTime;
                    dateTime.setDate(date);
                    u_int64_t d = dateTime.toMSecsSinceEpoch() *1000;
                    tache.setdate(d);
                    break;
                }
            }
            lstTache->addTache(tache);
        }
    }
    interaction->setLstTache(lstTache);

    QString str = document()->toPlainText();
    for (auto tache: *lstTache->getLstTache())
        str.remove(QString::fromStdString(tache->getcontenu()));
    QString contenu;
    for(const auto &line : str.split("\n")){
        if(!line.isEmpty())
            contenu+=line+"\n";
    }
    interaction->setContenu(contenu.toStdString());

    return interaction;
}

void InteractionTextEdit::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
    delete interaction;
}
