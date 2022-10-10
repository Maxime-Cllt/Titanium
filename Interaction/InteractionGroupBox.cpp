//
// Created by Rahman  Yilmaz on 10/10/2022.
//

#include "InteractionGroupBox.h"
#include <QDateTime>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

InteractionGroupBox::InteractionGroupBox(Interaction *interaction, QWidget *parent) : QGroupBox(parent),
                                                                                      interaction(interaction)
{
    setTitle(QDateTime::fromMSecsSinceEpoch(interaction->getDate() * 1000).toString("dddd MMMM d yyyy"));

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    auto *layout = new QVBoxLayout(this);

    textEdit = new QTextEdit(this);
    textEdit->setText(QString::fromStdString(interaction->getContenu()));

    layout->addWidget(textEdit);

    modifBtn = new QPushButton("Modifier", this);
    modifBtn->setEnabled(false);

    layout->addWidget(modifBtn);


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
        interaction->setDate(std::time_t(time(nullptr)));
        QMessageBox::information(this,"Succes","La modification à bien été prise en compte.");
    });

}