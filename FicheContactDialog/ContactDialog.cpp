//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "ContactDialog.h"

#include <QLabel>
#include <QPushButton>
#include <QCalendarWidget>
#include <QFileDialog>
#include <QString>
#include <QList>


QHBoxLayout *getLay(const QList<QWidget *> &list);

ContactDialog::ContactDialog(QWidget *parent) : QDialog(parent)
{

    setModal(true);
    setWindowTitle("Creation de la fiche contact");

    setMinimumSize(QSize(500, 400));

    layout = new QVBoxLayout(this);
    layoutTop = new QHBoxLayout;
    layoutCenter = new QVBoxLayout;
    layout->addLayout(layoutTop);
    layout->addLayout(layoutCenter);

    labIm = new QLabel(this);
    layoutTop->addWidget(labIm);

    auto *labDateCreation = new QLabel(this);
    labDateCreation->setObjectName("creation");
    labDateCreation->setAlignment(Qt::AlignTop | Qt::AlignRight);
    layoutTop->addWidget(labDateCreation);

    auto *lab1 = new QLabel("Nom : ", this);
    line1 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab1, line1}));

    auto *lab2 = new QLabel("Prenom : ", this);
    line2 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab2, line2}));

    auto *lab3 = new QLabel("Entreprise : ", this);
    line3 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab3, line3}));

    auto *lab4 = new QLabel("mail : ", this);
    line4 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab4, line4}));

    auto *lab5 = new QLabel("Téléphone : ", this);
    line5 = new QLineEdit(this);
    line5->setObjectName("tel");
    layoutCenter->addLayout(getLay({lab5, line5}));

    auto *lab6 = new QLabel("Photo : ", this);
    line6 = new QLineEdit(this);
    line6->setReadOnly(true);
    bt6 = new QPushButton("Choisir image", this);

    connect(bt6, &QPushButton::clicked, this, &ContactDialog::bt6Clicked);

    layoutCenter->addLayout(getLay({lab6, line6, bt6}));

    auto *lab7 = new QLabel("Date de creation de l'entreprise : ", this);
    lab7->setWordWrap(true);
    line7 = new QLineEdit(this);
    line7->setObjectName("date");
    line7->setReadOnly(true);
    bt7 = new QPushButton("Choisir date", this);

    layoutCenter->addLayout(getLay({lab7, line7, bt7}));

    connect(bt7, &QPushButton::clicked, this, &ContactDialog::bt7Clicked);
    btAction = new QPushButton("Ajouter");

    connect(btAction, &QPushButton::clicked, this, &ContactDialog::btActionClicked);

    layout->addWidget(btAction);

    for (auto *line: findChildren<QLineEdit *>())
    {
        line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    for (auto *lab: findChildren<QLabel *>())
    { lab->setMinimumWidth(100); }


}

void ContactDialog::bt7Clicked()
{
    auto *diag = new QDialog();
    auto *lay = new QVBoxLayout(diag);
    diag->setMinimumSize(350, 250);
    auto *calendar = new QCalendarWidget();
    calendar->setMinimumDate(QDate(1800, 1, 1));
    calendar->setMaximumDate(QDate(2023, 1, 1));
    lay->addWidget(calendar);
    auto *bt = new QPushButton("Valider");
    lay->addWidget(bt);
    connect(bt, &QPushButton::clicked, this, [=]()
    {
        dateTime.setDate(calendar->selectedDate());
        findChildren<QLabel *>("creation")[0]->setText(calendar->selectedDate().toString());
        findChildren<QLineEdit *>("date")[0]->setText(calendar->selectedDate().toString());
        diag->close();
    });
    diag->exec();
}


void ContactDialog::bt6Clicked()
{
    auto *fileDiag = new QFileDialog;
    fileDiag->setNameFilter(tr("Fichier video (*.png *.jpg *.JPG *.jpeg *.tif .svg)"));
    fileDiag->setFilter(QDir::Files);
    fileDiag->setDirectory(QDir::homePath());
    fileDiag->setFileMode(QFileDialog::ExistingFiles);
    fileDiag->setModal(true);
    if (fileDiag->exec() == QDialog::Accepted)
    {
        QString path(fileDiag->selectedFiles()[0]);
        QPixmap pix(path);
        labIm->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
        line6->setText(path);
    }
    delete fileDiag;
}

void ContactDialog::btActionClicked()
{
}

QtContact ContactDialog::getContact()
{
    return QtContact(line1->text(), line2->text(), line3->text(), line4->text(), line5->text(), line6->text(), dateTime,
                     QList<Interaction>());
}


QHBoxLayout *getLay(const QList<QWidget *> &list)
{
    auto *lay = new QHBoxLayout;
    for (auto *wid: list)
    {
        lay->addWidget(wid);
    }
    return lay;
}