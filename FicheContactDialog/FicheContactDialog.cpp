//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#include "FicheContactDialog.h"


//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include <QLabel>
#include <QPushButton>
#include <QCalendarWidget>
#include <QFileDialog>
#include <QString>
#include <QList>


QHBoxLayout *getLay(const QList<QWidget *> &list);

FicheContactDialog::FicheContactDialog(QWidget *parent) : QDialog(parent)
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
    layoutCenter->addLayout(getLay({lab5, line5}));

    auto *lab6 = new QLabel("Photo : ", this);
    line6 = new QLineEdit(this);
    line6->setReadOnly(true);
    bt6 = new QPushButton("Choisir image", this);

    connect(bt6, &QPushButton::clicked, this, &FicheContactDialog::bt6Clicked);

    layoutCenter->addLayout(getLay({lab6, line6, bt6}));

    auto *lab7 = new QLabel("Date de creation de l'entreprise : ", this);
    lab7->setWordWrap(true);
    line7 = new QLineEdit(this);
    line7->setObjectName("date");
    line7->setReadOnly(true);
    bt7 = new QPushButton("Choisir date", this);

    layoutCenter->addLayout(getLay({lab7, line7, bt7}));

    connect(bt7, &QPushButton::clicked, this, &FicheContactDialog::bt7Clicked);
    btAdd = new QPushButton("Ajouter");

    connect(btAdd, &QPushButton::clicked, this, &FicheContactDialog::btAddClicked);

    layout->addWidget(btAdd);

    for (auto *line: findChildren<QLineEdit *>())
    {
        line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    for (auto *lab: findChildren<QLabel *>()) { lab->setMinimumWidth(100); }


}

void FicheContactDialog::bt7Clicked()
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
        QDateTime date;
        date.setDate(calendar->selectedDate());
        findChildren<QLabel *>("creation")[0]->setText(calendar->selectedDate().toString());
        findChildren<QLineEdit *>("date")[0]->setText(calendar->selectedDate().toString());
        diag->close();
    });
    diag->exec();
}


void FicheContactDialog::bt6Clicked()
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

void FicheContactDialog::btAddClicked()
{
    bool pass = true;
    int autreQueLettreOuNombre = 0;
    for (auto *line: findChildren<QLineEdit *>())
    {
        for (auto c: line->text())
        {
            if (!c.isDigit() && !c.isLetter())
                autreQueLettreOuNombre++;
        }
        if (autreQueLettreOuNombre == line->text().size() && !line->text().isEmpty())
            pass = false;
        autreQueLettreOuNombre = 0;
    }
    if (!pass)
    {
        QMessageBox::critical(this, "Erreur", "Des champs de texte sont vide !!");
    } else
    {
        int rep = QMessageBox::information(this, "Information", "Le contact à été ajouté avec succès.");
        if (rep == QMessageBox::Ok)
        {
            close();
        }
    }
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