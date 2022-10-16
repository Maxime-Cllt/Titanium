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
#include "../Modification/ModificationMap.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    StdListContact *getLstContact();

    void addContact(const StdContact &contact);

    void setListInteractionWidget(QWidget *widget);

private:
    QHBoxLayout *layout{};

    ListContactWidget *listContactWidget{};

    StdListContact *lstContact{};
    ModificationMap *modificationMap{};
    BD *bd{};
public:
    ModificationMap *getModificationMap() const;

protected:
    void closeEvent(QCloseEvent *event) override;


};


#endif //UNTITLED2_MAINWINDOW_H
