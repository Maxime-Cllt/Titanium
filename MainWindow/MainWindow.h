//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef UNTITLED2_MAINWINDOW_H
#define UNTITLED2_MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include "../Contact/StdListContact.h"
#include "../BaseDeDonne/BD.h"
#include "../ListContact/ListContactWidget.h"
#include "../Modification/ListModification.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    StdListContact *getLstContact();

    void addContact(const StdContact &contact);

    void setListInteractionWidget(ListInteractionWidget *widget);

private:
    QHBoxLayout *layout{};

    ListContactWidget *listContactWidget{};
    ListInteractionWidget *listInteractionWidget{};

    StdListContact *lstContact{};
    ListModification *listModification{};
    BD *bd{};

protected:
    void closeEvent(QCloseEvent *event) override;


};


#endif //UNTITLED2_MAINWINDOW_H
