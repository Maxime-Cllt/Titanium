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
CreationInteractionDialog::CreationInteractionDialog(QWidget *parent) : QDialog(parent)
{
    auto *layout = new QVBoxLayout(this);
    text = new InteractionTextEdit(nullptr, this);
    ajouter = new QPushButton("Ajouter", this);

    layout->addWidget(text);
    layout->addWidget(ajouter);

    connect(ajouter, &QPushButton::clicked, this, [=, this]()
    {
        if (text->document()->toRawText().isEmpty())
        {
            QMessageBox::warning(this, "Attention", "Les champs de texte est vide.");
        } else
        {
            emit addInteractionClicked(text->parseTache());
            QMessageBox::information(this, "Succès", "Interaction ajouté avec succès.");
            close();
        }
    });

}