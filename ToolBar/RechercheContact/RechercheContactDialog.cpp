//
// Created by rahman on 01/11/22.
//

#include "RechercheContactDialog.h"
#include <QTimeEdit>
#include <QDebug>
#include "../../Utility/Utility.h"
#include "../../MainWindow/MainWindow.h"


/**
 * @brief Constructeur de la classe RechercheContactDialog.
 * @param parent
 */
RechercheContactDialog::RechercheContactDialog(QWidget *parent) : QDialog(parent)
{

    lstContactReference = qobject_cast<MainWindow *>(Utility::getMainWindow(this))->getLstContactTmp();
    lstContact = new StdListContact;

    avance = false;

    layout = new QVBoxLayout(this);

    auto *layoutTop = new QVBoxLayout;
    layout->addLayout(layoutTop);

    buttonAvance = new QPushButton("Mode avancé", this);

    layoutTop->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    buttonAvance->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    connect(buttonAvance, &QPushButton::clicked, this, &RechercheContactDialog::btnAvanceClicked);

    layoutTop->addWidget(buttonAvance);

    auto *layoutCenter = new QHBoxLayout;
    auto *layoutGauche = new QVBoxLayout;
    auto *layoutDroit = new QVBoxLayout;

    layout->addLayout(layoutCenter);


    layoutCenter->addLayout(layoutGauche);
    layoutCenter->addLayout(layoutDroit);

    layoutCenter->setAlignment(Qt::AlignTop);

    label = new QLabel("Rechercher un contact : ");
    layoutGauche->addWidget(label);
    allRecherche = new QLineEdit(this);
    allRecherche->setPlaceholderText("toto");
    layoutDroit->addWidget(allRecherche);

    connect(allRecherche, &QLineEdit::textChanged, this, &RechercheContactDialog::allRechercheLineTextChanged);

    createAvanceUi();


}

/**
 * @brief Destructeur de la classe RechercheContactDialog.
 */
RechercheContactDialog::~RechercheContactDialog() noexcept
{
    lstContact->getLstContact()->clear();
    delete lstContact;
}

/**
 * @brief Surcharge de l’événement de fermeture de la fenêtre qui emet un signal closeDialog.
 * @param event
 */
void RechercheContactDialog::closeEvent(QCloseEvent *event)
{
    emit closeDialog();
}

/**
 * @details Fonction qui affiche ou cache le mode avancé ou mode normal de recherche.
 */
void RechercheContactDialog::btnAvanceClicked()
{
    if (!avance)
    {
        buttonAvance->setText("Mode normal");
        allRecherche->hide();
        label->hide();
        afficheUiAvance();
    } else
    {
        buttonAvance->setText("Mode avancé");
        cacheUiAvance();
        allRecherche->show();
        label->show();
    }
    avance = !avance;

}

/**
 * @brief Fonction qui crée les widgets pour le mode avancé de recherche.
 */
void RechercheContactDialog::createAvanceUi()
{
    auto *layoutCenterbottom = new QHBoxLayout;
    auto *layoutGauche = new QVBoxLayout;
    auto *layoutDroit = new QVBoxLayout;

    layout->addLayout(layoutCenterbottom);


    layoutCenterbottom->addLayout(layoutGauche);
    layoutCenterbottom->addLayout(layoutDroit);

    auto *labNom = new QLabel("Nom : ", this);
    layoutGauche->addWidget(labNom);
    lineNom = new QLineEdit(this);
    lineNom->setPlaceholderText("toto");
    layoutDroit->addWidget(lineNom);

    auto *labPrenom = new QLabel("prenom : ", this);
    layoutGauche->addWidget(labPrenom);
    linePrenom = new QLineEdit(this);
    linePrenom->setPlaceholderText("tutu");
    layoutDroit->addWidget(linePrenom);

    auto *labEntreprise = new QLabel("Entreprise : ", this);
    layoutGauche->addWidget(labEntreprise);
    lineEntreprise = new QLineEdit(this);
    lineEntreprise->setPlaceholderText("sarl....");
    layoutDroit->addWidget(lineEntreprise);

    auto *labMail = new QLabel("Mail : ", this);
    layoutGauche->addWidget(labMail);
    lineMail = new QLineEdit(this);
    lineMail->setPlaceholderText("toto@titi.com");
    layoutDroit->addWidget(lineMail);

    auto *labTel = new QLabel("Téléphone : ", this);
    layoutGauche->addWidget(labTel);
    lineTel = new QLineEdit(this);
    lineTel->setPlaceholderText("0123456789");
    layoutDroit->addWidget(lineTel);

    auto layoutDate = new QHBoxLayout;

    auto *labDate = new QLabel("Date d'ajout : ", this);
    layoutDate->addWidget(labDate);
    auto *lay = new QHBoxLayout;

    auto *lay1 = new QVBoxLayout;
    auto *lay2 = new QVBoxLayout;


    auto *labDateDeb = new QLabel("Début : ", this);
    lay1->addWidget(labDateDeb);
    lineDateDeb = new QDateTimeEdit(this);
    lineDateDeb->setMaximumDateTime(QDateTime::currentDateTimeUtc());
    lay1->addWidget(lineDateDeb);

    auto *labDateFin = new QLabel("Fin : ", this);
    lay2->addWidget(labDateFin);
    lineDateFin = new QDateTimeEdit(this);
    lineDateFin->setMaximumDateTime(QDateTime::currentDateTimeUtc());
    lineDateFin->setDateTime(QDateTime::currentDateTimeUtc());
    lay2->addWidget(lineDateFin);

    lay->addLayout(lay1);
    lay->addLayout(lay2);

    layoutDate->addLayout(lay);

    layout->addLayout(layoutDate);


    lstWidget = {labNom, lineNom, labPrenom, linePrenom, labEntreprise, lineEntreprise, labMail, lineMail, labTel,
                 lineTel, labDate, labDateDeb, lineDateDeb, labDateFin, lineDateFin};

    for (auto widget: lstWidget)
    {
        if (!strcmp(widget->metaObject()->className(), "QLabel"))
            widget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        else
            widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    }

    labDate->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    labDateDeb->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    labDateDeb->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    labDateFin->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    labDateFin->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    lineDateDeb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    lineDateFin->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    // connection des lineEdit au slot rechercheAvance
    connect(lineNom, &QLineEdit::textChanged, this, &RechercheContactDialog::rechercheAvance);
    connect(linePrenom, &QLineEdit::textChanged, this, &RechercheContactDialog::rechercheAvance);
    connect(lineEntreprise, &QLineEdit::textChanged, this, &RechercheContactDialog::rechercheAvance);
    connect(lineMail, &QLineEdit::textChanged, this, &RechercheContactDialog::rechercheAvance);
    connect(lineTel, &QLineEdit::textChanged, this, &RechercheContactDialog::rechercheAvance);
    connect(lineDateDeb, &QDateTimeEdit::dateTimeChanged, this, &RechercheContactDialog::rechercheAvance);
    connect(lineDateFin, &QDateTimeEdit::dateTimeChanged, this, &RechercheContactDialog::rechercheAvance);

    cacheUiAvance();
}

/**
 * @brief Fonction qui cache les widgets de la recherche avancée.
 */
void RechercheContactDialog::cacheUiAvance()
{
    for (auto widget: lstWidget)
        widget->hide();

}

/**
 * @brief Fonction qui affiche les widgets de la recherche avancée.
 */
void RechercheContactDialog::afficheUiAvance()
{
    for (auto widget: lstWidget)
        widget->show();
}

/**
 * @details Fonction qui recherche dans tous les attributs des contacts (sauf la date de creation) si la
 * chaine de caractère écrit dans le line Edit de la recherche normale, si un attribut contient la chaine, on demande à la mainWindow d’afficher la liste des contacts.
 */
void RechercheContactDialog::allRechercheLineTextChanged()
{
    // on clear la liste
    lstContact->getLstContact()->clear();

    for (auto contact: *lstContactReference->getLstContact())
    {
        // creation d’une liste qui stock tous les attributs (sauf la date de creation) du contact {contact}
        QStringList lstStr;
        lstStr << QString::fromStdString(contact->getNom()).toLower();
        lstStr << QString::fromStdString(contact->getPrenom()).toLower();
        lstStr << QString::fromStdString(contact->getEntreprise()).toLower();
        lstStr << QString::fromStdString(contact->getMail()).toLower();
        lstStr << QString::fromStdString(contact->getTelephone()).toLower();

        //on parcourt la liste des attributs
        for (const auto &str: lstStr)
        {
            // si l’attribut contient la chaine de la lineEdit, on ajoute le contact a la liste.
            if (str.contains(allRecherche->text().toLower()))
            {
                lstContact->addContact(contact);
                break;
            }
        }
    }
    // on demande à la mainWindow de nous afficher la liste des contacts.
    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);

}

/**
 * @details Recherche avancée, elle fait correspondre tous les LineEdit du mode de recherche avancé avec les attributs des contacts.
 */
void RechercheContactDialog::rechercheAvance()
{
    lstContact->getLstContact()->clear();

    //creation d’un boolean qui va servir à savoir si les attributs d’un contact contiennent la chaine d’une lineEdit.
    bool ok = true;

    for (auto contact: *lstContactReference->getLstContact())
    {

        // on regarde que la lineEdit n’est pas vide.
        if (!lineNom->text().isEmpty())
        {
            // on récupère l’attribut du contact.
            QString str = QString::fromStdString(contact->getNom()).toLower();
            // si l'attribut ne ocntient pas la chaine
            if (!str.contains(lineNom->text().toLower()))
                continue;


        }

        if (!linePrenom->text().isEmpty())
        {
            QString str = QString::fromStdString(contact->getPrenom()).toLower();
            if (!str.contains(linePrenom->text().toLower()))
                continue;
        }

        if (!lineEntreprise->text().isEmpty())
        {
            QString str = QString::fromStdString(contact->getEntreprise()).toLower();
            if (!str.contains(linePrenom->text().toLower()))
                continue;

        }

        if (!lineMail->text().isEmpty())
        {
            QString str = QString::fromStdString(contact->getMail()).toLower();
            if (!str.contains(lineMail->text().toLower()))
                continue;
        }

        if (!lineTel->text().isEmpty())
        {
            QString str = QString::fromStdString(contact->getTelephone()).toLower();
            if (!str.contains(lineTel->text().toLower()))
                continue;
        }

        if (!(contact->getDateCreation() > (lineDateDeb->dateTime().toMSecsSinceEpoch() * 1000) &&
              contact->getDateCreation() < (lineDateFin->dateTime().toMSecsSinceEpoch() * 1000)))
            continue;

        lstContact->addContact(contact);

    }

    // on demande à la mainWindow de nous afficher la liste des contacts.
    qobject_cast<MainWindow *>(Utility::getMainWindow(this))->rechercheListContactWidget(lstContact);
}


