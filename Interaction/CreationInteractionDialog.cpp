//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "CreationInteractionDialog.h"
#include <QVBoxLayout>
#include <QMessageBox>

CreationInteractionDialog::CreationInteractionDialog(StdContact *contact, QWidget *parent) : QDialog(parent),
                                                                                             contact(contact)
{
    auto *layout = new QVBoxLayout(this);
    text = new QTextEdit(this);
    ajouter = new QPushButton("Ajouter", this);

    layout->addWidget(text);
    layout->addWidget(ajouter);

    connect(ajouter, &QPushButton::clicked, this, [=]()
    {
        if (text->document()->toRawText().isEmpty())
        {
            QMessageBox::warning(this, "Attention", "Le champs de texte est vide.");
        } else
        {
            contact->addInteraction(Interaction(text->document()->toRawText().toStdString()));
            QMessageBox::information(this, "Succes", "Interaction ajouté avec succes.");
            close();
        }
    });

}