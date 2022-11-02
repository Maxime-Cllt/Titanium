//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "CreationInteractionDialog.h"
#include <QVBoxLayout>
#include <QMessageBox>


/**
 * @details Constructeur de la classe CreationInteractionDialog
 * @param contact
 * @param parent
 */
CreationInteractionDialog::CreationInteractionDialog(StdContact *contact, QWidget *parent) : QDialog(parent),
                                                                                             contact(contact)
{
    auto *layout = new QVBoxLayout(this);
    text = new QTextEdit(this);
    ajouter = new QPushButton("Ajouter", this);

    layout->addWidget(text);
    layout->addWidget(ajouter);

    connect(ajouter, &QPushButton::clicked, this, [=, this]()
    {
        if (text->document()->toRawText().isEmpty())
        {
            QMessageBox::warning(this, "Attention", "Le champs de texte est vide.");
        } else
        {
            emit addInteractionClicked(new Interaction(text->document()->toRawText().toStdString()));
            QMessageBox::information(this, "Succès", "Interaction ajouté avec succès.");
            close();
        }
    });

}