//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#include "CreateFicheWidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QCalendarWidget>
#include <QFileDialog>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QRegExpValidator>


QHBoxLayout* getLay(const QList<QWidget *>& list);

CreateFicheWidget::CreateFicheWidget(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Creation de la fiche contact");

    setMinimumSize(QSize(500,400));

    layout = new QVBoxLayout(this);
    layoutTop = new QHBoxLayout;
    layoutCenter = new QVBoxLayout;
    layout->addLayout(layoutTop);
    layout->addLayout(layoutCenter);

    auto *labIm = new QLabel(this);
    layoutTop->addWidget(labIm);

    auto *labDateCreation = new QLabel(this);
    labDateCreation->setObjectName("creation");
    labDateCreation->setAlignment(Qt::AlignTop | Qt::AlignRight);
    layoutTop->addWidget(labDateCreation);

    auto *lab1 = new QLabel("Nom : ",this);
    auto *le1 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab1,le1}));

    auto *lab2 = new QLabel("Prenom : ",this);
    auto *le2 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab2,le2}));

    auto *lab3 = new QLabel("Entreprise : ",this);
    auto *le3 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab3,le3}));

    auto *lab4 = new QLabel("mail : ",this);
    auto *le4 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab4,le4}));

    auto *lab5 = new QLabel("Téléphone : ",this);
    auto *le5 = new QLineEdit(this);
    layoutCenter->addLayout(getLay({lab5,le5}));

    auto *lab6 = new QLabel("Photo : ",this);
    auto *le6 = new QLineEdit(this);
    le6->setReadOnly(true);
    auto *bt6 = new QPushButton("Choisir image",this);

    connect(bt6,&QPushButton::clicked,this,[=](){
        auto *fileDiag = new QFileDialog;
        fileDiag->setNameFilter(tr("Fichier video (*.png *.jpg *.JPG *.jpeg *.tif .svg)"));
        fileDiag->setFilter(QDir::Files);
        fileDiag->setDirectory(QDir::homePath());
        fileDiag->setFileMode(QFileDialog::ExistingFiles);
        fileDiag->setModal(true);
        if (fileDiag->exec() == QDialog::Accepted)
        {
            QString path(fileDiag->selectedFiles()[0]);
            contact.setPhoto(path);
            QPixmap pix(path);
            labIm->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
            le6->setText(path);
        }
        delete fileDiag;
    });

    layoutCenter->addLayout(getLay({lab6,le6,bt6}));

    auto *lab7 = new QLabel("Date de creation de l'entreprise : ",this);
    lab7->setWordWrap(true);
    auto *le7 = new QLineEdit(this);
    le7->setObjectName("date");
    le7->setReadOnly(true);
    auto *bt7 = new QPushButton("Choisir date",this);

    layoutCenter->addLayout(getLay({lab7,le7,bt7}));

    connect(bt7,&QPushButton::clicked,this,[=]()
    {
        dateWidget();
    });
    auto *bt = new QPushButton("Ajouter");

    layout->addWidget(bt);

    QPalette* palette = new QPalette();



        connect(bt,&QPushButton::clicked, this, [=](){
        bool pass = true;
        for (auto *line : findChildren<QLineEdit*>()){
//            QTextStream(stdout) << "[" <<line->text() << "]" << endl;
            if(!line->text().contains(QRegExp("^[A-Za-z0-9\\/_\\*\\\\]+"))){
                pass = false;
                palette->setColor(QPalette::Base,QColor(255,0,0));
                line->setPalette(*palette);
//                break;
            }
            else{
                palette->setColor(QPalette::Base,QColor(255,255,255));
                line->setPalette(*palette);
            }

        }
        if(!pass){
            QMessageBox::critical(this,"Erreur","Des champs de texte sont vide !!");
        }else{
            QMessageBox::information(this,"Information","Le contact à été ajouté avec succès.");
        }
    });


    for (auto *line : findChildren<QLineEdit*>()){line->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);}
    for (auto *lab : findChildren<QLabel*>()){lab->setMinimumWidth(100);}


}

void CreateFicheWidget::dateWidget(){
    auto *diag = new QDialog();
    auto *lay = new QVBoxLayout(diag);
    diag->setMinimumSize(350,250);
    auto *calendar = new QCalendarWidget();
    calendar->setMinimumDate(QDate(1800,1,1));
    calendar->setMaximumDate(QDate(2023,1,1));
    lay->addWidget(calendar);
    auto *bt = new QPushButton("Valider");
    lay->addWidget(bt);
    connect(bt,&QPushButton::clicked,this,[=](){
        contact.setDateCreation(calendar->selectedDate());
        findChildren<QLabel*>("creation")[0]->setText(calendar->selectedDate().toString());
        findChildren<QLineEdit*>("date")[0]->setText(calendar->selectedDate().toString());
        diag->close();
    });
    diag->exec();
}

QHBoxLayout* getLay(const QList<QWidget *>& list){
    auto *lay = new QHBoxLayout;
    for(auto *wid :list ){
        lay->addWidget(wid);
    }
    return lay;
}