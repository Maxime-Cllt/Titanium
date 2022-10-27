//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef UNTITLED2_MAINWINDOW_H
#define UNTITLED2_MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include "../Contact/StdListContact.h"
#include "../BaseDeDonne/BD.h"
#include "../ListContactWidget/ListContactWidget.h"
#include "../Modification/ListModification.h"

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

    void setListContactWidgetDefault();

private:
    QHBoxLayout *layoutGauche{};
    QHBoxLayout *layoutDroit{};

    ListContactWidget *listContactWidget{};
    ListInteractionWidget *listInteractionWidget{};

    StdListContact *lstContact{};
    ListModification *listModification{};
    BD *bd{};

    QLabel *nbContactLab{};
    QLabel *nbInetractionLab{};

protected:
    void closeEvent(QCloseEvent *event) override;


};


#endif //UNTITLED2_MAINWINDOW_H
