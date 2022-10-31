//
// Created by Rahman  Yilmaz on 26/10/2022.
//

#include "RechercheContactDialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateTimeEdit>
#include "../../MainWindow/MainWindow.h"
#include "../../Utility/Utility.h"

/**
 * @brief Constructeur de la classe RechercheContactDialog
 * @param parent
 */
RechercheContactDialog::RechercheContactDialog(QWidget *parent) : QDialog(parent)
{
    auto *lay = new QVBoxLayout(this);

    lstContact = new StdListContact;

    centerLay = new QGridLayout;

    auto *topLay = new QHBoxLayout;

    auto *labComboBox = new QLabel("Rechercher par : ", this);
    labComboBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    topLay->addWidget(labComboBox);

    comboBox = new QComboBox(this);
    comboBox->addItems({"Nom", "Prénom", "Entreprise", "Date d'ajout", "Téléphone", "Mail"});
    connect(comboBox, &QComboBox::currentTextChanged, this, &RechercheContactDialog::comboBoxTextChanged);

    topLay->addWidget(comboBox);


    auto *quitBtn = new QPushButton("Quitter la recherche", this);
    connect(quitBtn, &QPushButton::clicked, this, &RechercheContactDialog::close);

    lay->addLayout(topLay);
    lay->addLayout(centerLay);
    lay->addWidget(quitBtn);


    rechercheParNom();
}

void RechercheContactDialog::rechercheParNom()
{
    auto *lay = new QHBoxLayout;

    auto *lab = new QLabel("Nom du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    lstWidget.append(lab);

    lay->addWidget(lab);

    auto *line = new QLineEdit(this);
    line->setPlaceholderText("Toto");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lstWidget.append(line);

    connect(line, &QLineEdit::textChanged, this, [this, line]()
    {
        lstContact->getLstContact()->clear();
        for (auto contact: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->getLstContact())
        {
            QString str = QString::fromStdString(contact->getNom()).toLower();
            if (str.contains(line->text().toLower()))
            {
                lstContact->addContact(contact);
            }
        }
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);
    });

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);


}


/**
 * @brief Gestion de la combobox pour le mode de recherche
 * @param str
 */
void RechercheContactDialog::comboBoxTextChanged(const QString &str)
{
    clearBottomLayout();
    lstContact->getLstContact()->clear();
    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->resetListContactWidget();
    if (str == "Nom")
    {
        rechercheParNom();
        return;
    }
    if (str == "Prénom")
    {
        rechercheParPrenom();
        return;
    }
    if (str == "Entreprise")
    {
        rechercheParEntreprise();
        return;
    }
    if (str == "Mail")
    {
        rechercheParMail();
        return;
    }
    if (str == "Téléphone")
    {
        rechercheParTelephone();
        return;
    }
    if (str == "Date d'ajout")
    {
        rechercheParDateAjout();
        return;
    }
}


/**
 * @brief Fonction de recherche en fonction du preénom
 */
void RechercheContactDialog::rechercheParPrenom()
{
    auto *lay = new QHBoxLayout;

    auto *lab = new QLabel("Prénom du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    lstWidget.append(lab);

    lay->addWidget(lab);

    auto *line = new QLineEdit(this);
    line->setPlaceholderText("Tutu");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lstWidget.append(line);

    connect(line, &QLineEdit::textChanged, this, [this, line]()
    {
        lstContact->getLstContact()->clear();
        for (auto contact: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->getLstContact())
        {
            QString str = QString::fromStdString(contact->getPrenom()).toLower();
            if (str.contains(line->text().toLower()))
            {
                lstContact->addContact(contact);
            }
        }
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);
    });

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);
}


/**
 * @brief Fonction de gestion du layout
 */
void RechercheContactDialog::clearBottomLayout()
{
    for (auto wid: lstWidget)
    {
        wid->close();
    }
}


/**
 * @brief Fonction de recherche par entreprise
 */
void RechercheContactDialog::rechercheParEntreprise()
{
    auto *lay = new QHBoxLayout;

    auto *lab = new QLabel("Entreprise du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    lstWidget.append(lab);

    lay->addWidget(lab);

    auto *line = new QLineEdit(this);
    line->setPlaceholderText("sarl...");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lstWidget.append(line);

    connect(line, &QLineEdit::textChanged, this, [this, line]()
    {
        lstContact->getLstContact()->clear();
        for (auto contact: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->getLstContact())
        {
            QString str = QString::fromStdString(contact->getEntreprise()).toLower();
            if (str.contains(line->text().toLower()))
            {
                lstContact->addContact(contact);
            }
        }
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);
    });

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);
}

/**
 * @brief Fonction de recherche par mail
 */
void RechercheContactDialog::rechercheParMail()
{
    auto *lay = new QHBoxLayout;

    auto *lab = new QLabel("Mail du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    lstWidget.append(lab);

    lay->addWidget(lab);

    auto *line = new QLineEdit(this);
    line->setPlaceholderText("Toto@tutu.com");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lstWidget.append(line);

    connect(line, &QLineEdit::textChanged, this, [this, line]()
    {
        lstContact->getLstContact()->clear();
        for (auto contact: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->getLstContact())
        {
            QString str = QString::fromStdString(contact->getMail()).toLower();
            if (str.contains(line->text().toLower()))
            {
                lstContact->addContact(contact);
            }
        }
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);
    });

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);
}

/**
 * @brief Fonction de recherche par mail
 */
void RechercheContactDialog::rechercheParTelephone()
{
    auto *lay = new QHBoxLayout;

    auto *lab = new QLabel("Téléphone du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    lstWidget.append(lab);

    lay->addWidget(lab);

    auto *line = new QLineEdit(this);
    line->setPlaceholderText("0123456789");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lstWidget.append(line);

    connect(line, &QLineEdit::textChanged, this, [this, line]()
    {
        lstContact->getLstContact()->clear();
        for (auto contact: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->getLstContact())
        {
            QString str = QString::fromStdString(contact->getTelephone()).toLower();
            if (str.contains(line->text().toLower()))
            {
                lstContact->addContact(contact);
            }
        }
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);
    });

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);
}

/**
 * @brief Fonction de recherche par date d'ajout
 */
void RechercheContactDialog::rechercheParDateAjout()
{
    auto *lay = new QGridLayout;

    auto *lab = new QLabel("Date d'ajout du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    lab->setAlignment(Qt::AlignHCenter);
    lstWidget.append(lab);

    centerLay->addWidget(lab, 0, 0);

    auto *labDebut = new QLabel("Debut : ", this);
    lstWidget.append(labDebut);
    lay->addWidget(labDebut, 0, 0);

    auto *lineDebut = new QDateTimeEdit(this);
    lineDebut->setMaximumDateTime(QDateTime::currentDateTime());
    lineDebut->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lstWidget.append(lineDebut);
    lay->addWidget(lineDebut, 0, 1);


    auto *labFin = new QLabel("Fin : ", this);
    lstWidget.append(labFin);
    lay->addWidget(labFin, 1, 0);

    auto *lineFin = new QDateTimeEdit(this);
    lineFin->setDateTime(QDateTime::currentDateTime());
    lineFin->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lstWidget.append(lineFin);
    lay->addWidget(lineFin, 1, 1);

    connect(lineDebut, &QDateTimeEdit::dateTimeChanged, this, [this, lineDebut, lineFin]()
    {
        lstContact->getLstContact()->clear();
        for (auto contact: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->getLstContact())
        {
            if (contact->getDateCreation() > (lineDebut->dateTime().toMSecsSinceEpoch() * 1000) &&
                contact->getDateCreation() < (lineFin->dateTime().toMSecsSinceEpoch() * 1000))
                lstContact->addContact(contact);
        }
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);
    });

    connect(lineFin, &QDateTimeEdit::dateTimeChanged, this, [this, lineDebut, lineFin]()
    {
        lstContact->getLstContact()->clear();
        for (auto contact: *qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContact()->getLstContact())
        {
            if (contact->getDateCreation() > lineDebut->dateTime().toMSecsSinceEpoch() * 1000 &&
                contact->getDateCreation() < lineFin->dateTime().toMSecsSinceEpoch() * 1000)
                lstContact->addContact(contact);
        }
        qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);
    });


    centerLay->addLayout(lay, 1, 0);
}


/**
 * @brief Destructeur de la classe
 */
RechercheContactDialog::~RechercheContactDialog()
{
    // on clear la liste avant car les contacts seront delete par la liste dans le MainWindow
    lstContact->getLstContact()->clear();
    delete lstContact;

}

/**
 * @brief Gestion de fermeture du widget
 * @param event
 */
void RechercheContactDialog::closeEvent(QCloseEvent *event)
{
    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->resetListContactWidget();
    QDialog::closeEvent(event);
}

