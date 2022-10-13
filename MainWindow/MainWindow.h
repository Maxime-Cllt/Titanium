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

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    StdListContact *getLstContact();


private:
    StdListContact *lstContact{};
    QGridLayout *layout{};
    QWidget *central{};
    BD *bd{};
protected:
    void closeEvent(QCloseEvent *event) override;


};


#endif //UNTITLED2_MAINWINDOW_H
