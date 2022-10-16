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

GroupBoxInteraction::GroupBoxInteraction(Interaction *interaction, QWidget *parent) : QGroupBox(parent),
                                                                                      interaction(interaction)
{
    QLocale local(QLocale::Language::French);
    QDateTime date;
    date.setMSecsSinceEpoch(interaction->getId());
    setTitle(local.toString(date, "dddd, d MMMM yyyy hh:mm:ss"));

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    auto *layout = new QVBoxLayout(this);

    textEdit = new QTextEdit(this);
    textEdit->setText(QString::fromStdString(interaction->getContenu()));
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
        if (textEdit->document()->toRawText().toStdString() != interaction->getContenu())
            modifBtn->setEnabled(true);
        else
            modifBtn->setEnabled(false);
    });

    connect(modifBtn, &QPushButton::clicked, this, [=]()
    {
        interaction->setContenu(textEdit->document()->toRawText().toStdString());
        QMessageBox::information(this, "Succes", "La modification à bien été prise en compte.");
        BD::modifyInteraction(*interaction);
    });

    connect(supBtn, &QPushButton::clicked, this, [=]()
    {
        auto *lstInteractionWidget = new QWidget(this);
        while (lstInteractionWidget->parentWidget())
        {
            lstInteractionWidget = lstInteractionWidget->parentWidget();
            if (strcmp(lstInteractionWidget->metaObject()->className(), "ListInteractionWidget") == 0)
                break;
        }
        qobject_cast<ListInteractionWidget *>(lstInteractionWidget)->getLstInteraction()->supInteraction(interaction);

        BD::supInteraction(*interaction);
        delete interaction;
        close();
    });
}