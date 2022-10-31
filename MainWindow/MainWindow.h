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
    explicit MainWindow(QWidget *parent = nullptr);

    StdListContact *getLstContact();

    void addContact(const StdContact &contact);

    void updateNbContact();

    void setNbInteraction(const QString &number);

    void rechercheListContactWidget(StdListContact *lst);

    void setListInteractionWidget(ListInteractionWidget *widget);

    void resetListContactWidget();

private:
    QHBoxLayout *layoutGauche{};
    QHBoxLayout *layoutDroit{};

    ListContactWidget *listContactWidget{};
    ListInteractionWidget *listInteractionWidget{};

    StdListContact *lstContact{};
    BD *bd{};

    QLabel *nbContactLab{};
    QLabel *nbInetractionLab{};

protected:
    void closeEvent(QCloseEvent *event) override;


};


#endif //PROJET_QT_MAINWINDOW_H
