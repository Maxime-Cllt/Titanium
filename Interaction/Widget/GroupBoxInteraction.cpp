//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "GroupBoxInteraction.h"
#include <QDateTime>
#include <iostream>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "ListInteractionWidget.h"
#include "../../BaseDeDonne/BD.h"
#include "../../MainWindow/MainWindow.h"
#include "../../Utility/Utility.h"

/**
 * @details Constructeur de la classe GroupBoxInteraction
 * @param interaction
 * @param parent
 */
GroupBoxInteraction::GroupBoxInteraction(Interaction *interaction, QWidget *parent) : QGroupBox(parent),
                                                                                      interaction(interaction)
{
    setStyleSheet("QGroupBox::title {subcontrol-origin: margin;subcontrol-position: top;}");

    QLocale local(QLocale::Language::French);
    QDateTime date;
    date.setMSecsSinceEpoch(this->interaction->getDateCreation() / 1000);
    setTitle("Date de creation : " + local.toString(date, "dddd, d MMMM yyyy hh:mm:ss"));

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);


    auto *layout = new QVBoxLayout(this);

    date.setMSecsSinceEpoch(this->interaction->getDateModif() / 1000);
    labDateModif = new QLabel("Dernière modification : " + local.toString(date, "dddd, d MMMM yyyy hh:mm:ss"), this);
    labDateModif->setAlignment(Qt::AlignHCenter);
    labDateModif->setWordWrap(true);

    layout->addWidget(labDateModif);

    textEdit = new InteractionTextEdit(interaction, this);
    textEdit->setMinimumHeight(200);

    layout->addWidget(textEdit);

    auto *layBottom = new QHBoxLayout;

    layout->addLayout(layBottom);

    modifBtn = new QPushButton("Modifier", this);
    modifBtn->setEnabled(false);

    supBtn = new QPushButton("Supprimer", this);

    layBottom->addWidget(modifBtn);
    layBottom->addWidget(supBtn);


    connect(textEdit, &QTextEdit::textChanged, this, [=, this]()
    {
        if (textEdit->document()->toRawText().toStdString() != this->interaction->getContenu())
            modifBtn->setEnabled(true);
        else
            modifBtn->setEnabled(false);
    });

    connect(modifBtn, &QPushButton::clicked, this, [=, this]()
    {
        textEdit->parseTache()->modif();
        QMessageBox::information(this, "Succès", "La modification à bien été prise en compte.");
        BD::modifyInteraction(*this->interaction);
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getHistorique()->addLog(
                ListHistorique::ModificationInteraction, *interaction);
        emit modifBtnClicked();

    });

    connect(supBtn, &QPushButton::clicked, this, [=, this]()
    {
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getHistorique()->addLog(
                ListHistorique::SuppressionInteraction, *interaction);
        emit supBtnClicked(this->interaction);
        close();
    });
}

