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
#include <QLocale>

QHBoxLayout *getLay(const QList<QWidget *> &list);

/**
 * @details Constructeur de ContactDialog
 * @param parent
 */
ContactDialog::ContactDialog(QWidget *parent) : QDialog(parent)
{

    setModal(true);

    setMinimumSize(QSize(500, 400));

    layout = new QGridLayout(this);


    labIm = new QLabel(this);
    layout->addWidget(labIm, 0, 0, 1, 2);

    labDateCreation = new QLabel(this);
    labDateCreation->setAlignment(Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(labDateCreation, 0, 2, 1, 3);

    layout->addWidget(new QLabel("Nom : ", this), 1, 0, 1, 1);

    line1 = new QLineEdit(this);
    layout->addWidget(line1, 1, 1, 1, 4);


    layout->addWidget(new QLabel("Prenom : ", this), 2, 0, 1, 1);

    line2 = new QLineEdit(this);
    layout->addWidget(line2, 2, 1, 1, 4);


    layout->addWidget(new QLabel("Entreprise : ", this), 3, 0, 1, 1);

    line3 = new QLineEdit(this);
    layout->addWidget(line3, 3, 1, 1, 4);


    layout->addWidget(new QLabel("mail : ", this), 4, 0, 1, 1);

    line4 = new QLineEdit(this);
    layout->addWidget(line4, 4, 1, 1, 4);


    layout->addWidget(new QLabel("Téléphone : ", this), 5, 0, 1, 1);

    line5 = new QLineEdit(this);
    line5->setObjectName("tel");
    layout->addWidget(line5, 5, 1, 1, 4);


    layout->addWidget(new QLabel("Photo : ", this), 6, 0, 1, 1);

    line6 = new QLineEdit(this);
    line6->setReadOnly(true);
    bt6 = new QPushButton("Choisir image", this);
    bt6->setDefault(false);

    connect(bt6, &QPushButton::clicked, this, &ContactDialog::bt6Clicked);

    layout->addWidget(line6, 6, 1, 1, 3);
    layout->addWidget(bt6, 6, 4, 1, 1);

    btAction = new QPushButton(this);
    btAction->setDefault(true);

    connect(btAction, &QPushButton::clicked, this, &ContactDialog::btActionClicked);

    layout->addWidget(btAction, 7, 0, 1, 5);

    for (auto *line: findChildren<QLineEdit *>())
        line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    for (auto *line: findChildren<QLabel *>())
        line->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    layout->setColumnStretch(1, 1);

}

/**
 * @details Clic sur bouton pour ajouter une image au contact.
 */
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

/**
 *
 * @param time
 * @return QtContact
 */
QtContact ContactDialog::getContact()
{
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    return QtContact(line1->text(), line2->text(), line3->text(), line4->text(), line5->text(), line6->text(), time);
}
