//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef UNTITLED2_MAINWINDOW_H
#define UNTITLED2_MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include "../Contact/QtFicheContact.h"
#include "../Contact/StdFicheContact.h"

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void addContact(StdFicheContact *contact);

    QList<StdFicheContact *> *getLstContact() const;

private:
    QList<StdFicheContact *> *lstContact{};
    QGridLayout *layout{};
    QWidget *central{};


};


#endif //UNTITLED2_MAINWINDOW_H
