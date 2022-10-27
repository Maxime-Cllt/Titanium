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

    layout = new QVBoxLayout(this);
    layoutTop = new QHBoxLayout;
    layoutCenter = new QHBoxLayout;
    layout->addLayout(layoutTop);
    layout->addLayout(layoutCenter);


    auto *layGauche = new QVBoxLayout;
    auto *layDroit = new QVBoxLayout;

    layoutCenter->addLayout(layGauche);
    layoutCenter->addLayout(layDroit);

    labIm = new QLabel(this);
    layoutTop->addWidget(labIm);

    labDateCreation = new QLabel(this);
    labDateCreation->setAlignment(Qt::AlignTop | Qt::AlignRight);
    layoutTop->addWidget(labDateCreation);

    layGauche->addWidget(new QLabel("Nom : ", this));

    line1 = new QLineEdit(this);
    layDroit->addWidget(line1);


    layGauche->addWidget(new QLabel("Prenom : ", this));

    line2 = new QLineEdit(this);
    layDroit->addWidget(line2);


    layGauche->addWidget(new QLabel("Entreprise : ", this));

    line3 = new QLineEdit(this);
    layDroit->addWidget(line3);


    layGauche->addWidget(new QLabel("mail : ", this));

    line4 = new QLineEdit(this);
    layDroit->addWidget(line4);


    layGauche->addWidget(new QLabel("Téléphone : ", this));

    line5 = new QLineEdit(this);
    line5->setObjectName("tel");
    layDroit->addWidget(line5);


    layGauche->addWidget(new QLabel("Photo : ", this));

    line6 = new QLineEdit(this);
    line6->setReadOnly(true);
    bt6 = new QPushButton("Choisir image", this);
    bt6->setDefault(false);

    connect(bt6, &QPushButton::clicked, this, &ContactDialog::bt6Clicked);

    layDroit->addLayout(getLay({line6, bt6}));

    btAction = new QPushButton(this);
    btAction->setDefault(true);

    connect(btAction, &QPushButton::clicked, this, &ContactDialog::btActionClicked);

    layout->addWidget(btAction);

    for (auto *line: findChildren<QLineEdit *>())
    {
        line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

}

/**
 * @details Clic sur bouton pour ouvrir QFileDialog
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

void ContactDialog::btActionClicked()
{
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

/**
 *
 * @param list
 * @return QHBoxLayout
 */
QHBoxLayout *getLay(const QList<QWidget *> &list)
{
    auto *lay = new QHBoxLayout;
    for (auto *wid: list)
    {
        lay->addWidget(wid);
    }
    return lay;
}