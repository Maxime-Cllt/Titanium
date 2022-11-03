//
// Created by rahman on 03/11/22.
//

#include "RechercheTaches.h"
#include <QLabel>


/**
 * @brief Constructeur de la classe RechercheTaches.
 * @param lst
 * @param parent
 */
RechercheTaches::RechercheTaches(ListInteraction *lst, QWidget *parent) : QDialog(parent), lstInteraction(lst)
{

    setWindowTitle("Recherche de Todo");

    layout = new QGridLayout(this);


    layout->addWidget(new QLabel("Définissez les champs de recherche", this), 0, 0, 1, 2, Qt::AlignHCenter);

    layout->addWidget(new QLabel("Début : ", this), 1, 0, 1, 1, Qt::AlignHCenter);
    layout->addWidget(new QLabel("Fin : ", this), 1, 1, 1, 1, Qt::AlignHCenter);

    debut = new QDateTimeEdit(this);
    debut->setMaximumDateTime(QDateTime::currentDateTime());

    layout->addWidget(debut, 2, 0, 1, 1);

    fin = new QDateTimeEdit(this);
    fin->setDateTime(QDateTime::currentDateTime());
    fin->setMaximumDateTime(QDateTime::currentDateTime());

    layout->addWidget(fin, 2, 1, 1, 1);

    textEdit = new QTextEdit(this);
    textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    textEdit->setReadOnly(true);
    textEdit->setWordWrapMode(QTextOption::NoWrap);

    layout->addWidget(textEdit, 3, 0, 1, 2);

    remplirTextEdit();

    connect(debut, &QDateTimeEdit::dateTimeChanged, this, &RechercheTaches::remplirTextEdit);
    connect(fin, &QDateTimeEdit::dateTimeChanged, this, &RechercheTaches::remplirTextEdit);


}

/**
 * @details Fonction qui est appelée a change fois que la date des QDateTimeEdit change et met à jour le contenu
 * de la QTextEdit.
 */
void RechercheTaches::remplirTextEdit()
{
    // on récupère la date des QDateTimeEdit, on multiplie par 1000, car la date d'une tache est en microseconde.
    uint64_t dateDebut = debut->dateTime().toMSecsSinceEpoch() * 1000;
    uint64_t dateFin = fin->dateTime().toMSecsSinceEpoch() * 1000;

    textEdit->clear();

    int i = 1;

    // variable qui stockera tout le contenu des taches.
    QString str;

    for (const auto interaction: *lstInteraction->getListInteraction())
    {
        for (const auto tache: *interaction->getLstTache()->getLstTache())
        {
            // si la date de la tache est compris entre le debut et la fin des QDateTimeEdit
            if (tache->getdate() > dateDebut and tache->getdate() < dateFin)
            {
                QDateTime dateTache;
                dateTache.setMSecsSinceEpoch((qint64) tache->getdate() / 1000);

                str += QString::number(i) + " : ";

                // une fois sur deux la couleur de la tache ajoutée change pour plus de lisibilité.
                if (i % 2)
                    str += "<font color=red>";
                else
                    str += "<font color=blue>";
                str += QString::fromStdString(tache->getcontenu()) + " -> [" +
                       dateTache.toString("dd/MM/yyyy hh:mm:ss") + " ]</font><br>";
                i++;
            }
        }
    }
    textEdit->insertHtml(str);
}
