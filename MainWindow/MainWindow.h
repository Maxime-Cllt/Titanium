//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef PROJET_QT_MAINWINDOW_H
#define PROJET_QT_MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include "../Contact/StdListContact.h"
#include "../BaseDeDonne/BD.h"
#include "../Contact/Widget/ListContactWidget.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget * = nullptr);

    [[nodiscard]] StdListContact *getLstContact() const;

    [[nodiscard]] StdListContact *getLstContactTmp() const;

    void addContact(const StdContact &);

    void suppContact(StdContact *);

    void updateNbContact();

    void setNbInteraction(const QString &);

    void rechercheListContactWidget(StdListContact *);

    void setListInteractionWidget(ListInteractionWidget *);

    void resetListContactWidget();

    void reactualise();

    void removeListInteractionWidget();

private:
    QHBoxLayout *layoutGauche{};
    QHBoxLayout *layoutDroit{};

    ListContactWidget *listContactWidget{};
    ListInteractionWidget *listInteractionWidget{};

    BD *bd{};
    StdListContact *lstContactTmp{};
    StdListContact *lstContact{};


    QLabel *nbContactLab{};
    QLabel *nbInetractionLab{};


protected:
    void closeEvent(QCloseEvent *event) override;


};


#endif //PROJET_QT_MAINWINDOW_H
