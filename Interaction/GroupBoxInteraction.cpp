//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "GroupBoxInteraction.h"
#include <QDateTime>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "ListInteractionWidget.h"
#include "../BaseDeDonne/BD.h"

/**
 * @details Constructeur de la classe GroupBoxInteraction
 * @param interaction
 * @param parent
 */
GroupBoxInteraction::GroupBoxInteraction(Interaction *interaction, QWidget *parent) : QGroupBox(parent),
                                                                                      interaction(interaction)
{
    QLocale local(QLocale::Language::French);
    QDateTime date;
    date.setMSecsSinceEpoch(this->interaction->getId());
    setTitle("Date de creation : " + local.toString(date, "dddd, d MMMM yyyy hh:mm:ss"));

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);


    auto *layout = new QVBoxLayout(this);

    date.setMSecsSinceEpoch(this->interaction->getDateModif());
    labDateModif = new QLabel("Dernière modification : " + local.toString(date, "dddd, d MMMM yyyy hh:mm:ss"), this);

    layout->addWidget(labDateModif);

    textEdit = new QTextEdit(this);
    textEdit->setText(QString::fromStdString(this->interaction->getContenu()));
    textEdit->setMinimumHeight(200);

    layout->addWidget(textEdit);

    auto *layBottom = new QHBoxLayout;

    layout->addLayout(layBottom);

    modifBtn = new QPushButton("Modifier", this);
    modifBtn->setEnabled(false);

    supBtn = new QPushButton("Supprimer", this);

    layBottom->addWidget(modifBtn);
    layBottom->addWidget(supBtn);


    connect(textEdit, &QTextEdit::textChanged, this, [=]()
    {
        if (textEdit->document()->toRawText().toStdString() != this->interaction->getContenu())
            modifBtn->setEnabled(true);
        else
            modifBtn->setEnabled(false);
    });

    connect(modifBtn, &QPushButton::clicked, this, [=]()
    {
        this->interaction->setContenu(textEdit->document()->toRawText().toStdString());
        this->interaction->modif();
        QMessageBox::information(this, "Succes", "La modification à bien été prise en compte.");
        BD::modifyInteraction(*this->interaction);

        qobject_cast<ListInteractionWidget *>(getListInteractionParent())->reactualiseUi();
    });

    connect(supBtn, &QPushButton::clicked, this, [=]()
    {
        qobject_cast<ListInteractionWidget *>(getListInteractionParent())->getLstInteraction()->supInteraction(
                this->interaction);

        BD::supInteraction(*this->interaction);
        delete this->interaction;
        close();
    });
}

QWidget *GroupBoxInteraction::getListInteractionParent()
{
    auto *lstInteractionWidget = new QWidget(this);
    while (lstInteractionWidget->parentWidget())
    {
        lstInteractionWidget = lstInteractionWidget->parentWidget();
        if (strcmp(lstInteractionWidget->metaObject()->className(), "ListInteractionWidget") == 0)
            break;
    }
    return lstInteractionWidget;
}