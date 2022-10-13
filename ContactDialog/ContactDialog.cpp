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

    setMinimumSize(QSize(500, 400));

    layout = new QVBoxLayout(this);
    layoutTop = new QHBoxLayout;
    layoutCenter = new QVBoxLayout;
    layout->addLayout(layoutTop);
    layout->addLayout(layoutCenter);

    labIm = new QLabel(this);
    layoutTop->addWidget(labIm);

    labDateCreation = new QLabel(this);
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
    bt6->setDefault(false);

    connect(bt6, &QPushButton::clicked, this, &ContactDialog::bt6Clicked);

    layoutCenter->addLayout(getLay({lab6, line6, bt6}));

    btAction = new QPushButton(this);
    btAction->setDefault(true);

    connect(btAction, &QPushButton::clicked, this, &ContactDialog::btActionClicked);

    layout->addWidget(btAction);

    for (auto *line: findChildren<QLineEdit *>())
    {
        line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    for (auto *lab: findChildren<QLabel *>()) { lab->setMinimumWidth(100); }

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

QtContact ContactDialog::getContact(long time, std::list<Interaction *> lst)
{
    QList<Interaction * > qList;
    for(auto elmt : lst){qList << elmt;}
    return QtContact(line1->text(), line2->text(), line3->text(), line4->text(), line5->text(), line6->text(),
                             time,qList);
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