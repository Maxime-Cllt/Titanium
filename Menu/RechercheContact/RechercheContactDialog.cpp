//
// Created by Rahman  Yilmaz on 26/10/2022.
//

#include "RechercheContactDialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../../MainWindow/MainWindow.h"

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
    comboBox->addItems({"Nom", "Prénom", "Entrepise", "Date d'ajout", "Téléphone", "Mail"});
    connect(comboBox, &QComboBox::currentTextChanged, this, &RechercheContactDialog::comboBoxTextChanged);

    topLay->addWidget(comboBox);


    auto *quitBtn = new QPushButton("Quitter la recherche",this);
    connect(quitBtn,&QPushButton::clicked, this,&RechercheContactDialog::close);

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

    connect(line,&QLineEdit::textChanged,this,[this,line](){
        lstContact->getLstContact()->clear();
        for(auto contact : *qobject_cast<MainWindow *>(getMainWindowWidget())->getLstContact()->getLstContact()){
            QString str = QString::fromStdString(contact->getNom());
            if(str.contains(line->text())){
                lstContact->addContact(contact);
            }
        }
        qobject_cast<MainWindow *>(getMainWindowWidget())->rechercheListContactWidget(lstContact);
    });

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);


}

QWidget *RechercheContactDialog::getMainWindowWidget()
{
    auto *lstInteractionWidget = new QWidget(this);
    while (lstInteractionWidget->parentWidget())
    {
        lstInteractionWidget = lstInteractionWidget->parentWidget();
        if (strcmp(lstInteractionWidget->metaObject()->className(), "ListInteractionWidget") == 0)
            break;
    }
    return lstInteractionWidget;
}

void RechercheContactDialog::comboBoxTextChanged(const QString &str)
{
    clearBottomLayout();
    lstContact->getLstContact()->clear();
    qobject_cast<MainWindow *>(getMainWindowWidget())->setListContactWidgetDefault();
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

    connect(line,&QLineEdit::textChanged,this,[this,line](){
        lstContact->getLstContact()->clear();
        for(auto contact : *qobject_cast<MainWindow *>(getMainWindowWidget())->getLstContact()->getLstContact()){
            QString str = QString::fromStdString(contact->getPrenom());
            if(str.contains(line->text())){
                lstContact->addContact(contact);
            }
        }
        qobject_cast<MainWindow *>(getMainWindowWidget())->rechercheListContactWidget(lstContact);
    });

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);
}

void RechercheContactDialog::clearBottomLayout()
{
    for (auto wid: lstWidget)
    {
        wid->close();
    }
}

void RechercheContactDialog::rechercheParEntreprise()
{
    auto *lay = new QHBoxLayout;

    auto *lab = new QLabel("Entreprise du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    lay->addWidget(lab);

    auto *line = new QLineEdit(this);
    line->setPlaceholderText("sarl...");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);
}

void RechercheContactDialog::rechercheParMail()
{
    auto *lstContact = qobject_cast<MainWindow *>(getMainWindowWidget())->getLstContact();
    auto *lay = new QHBoxLayout;

    auto *lab = new QLabel("Entreprise du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    lay->addWidget(lab);

    auto *line = new QLineEdit(this);
    line->setPlaceholderText("Toto@tutu.com");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);
}

void RechercheContactDialog::rechercheParTelephone()
{
    auto *lstContact = qobject_cast<MainWindow *>(getMainWindowWidget())->getLstContact();
    auto *lay = new QHBoxLayout;

    auto *lab = new QLabel("Entreprise du contact :", this);
    lab->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    lay->addWidget(lab);

    auto *line = new QLineEdit(this);
    line->setPlaceholderText("0123456789");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    lay->addWidget(line);

    centerLay->addLayout(lay, 0, 0);
}

void RechercheContactDialog::rechercheParDateAjout()
{

}

RechercheContactDialog::~RechercheContactDialog()
{
    // on clear la liste avant car les contact seront delete par la liste dans le MainWindow
    lstContact->getLstContact()->clear();
    delete lstContact;

}

void RechercheContactDialog::closeEvent(QCloseEvent *event)
{
    qobject_cast<MainWindow *>(getMainWindowWidget())->setListContactWidgetDefault();
    QDialog::closeEvent(event);
}

