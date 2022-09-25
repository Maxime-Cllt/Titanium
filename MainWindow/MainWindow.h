//
// Created by Rahman  Yilmaz on 22/09/2022.
//

#ifndef UNTITLED2_MAINWINDOW_H
#define UNTITLED2_MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QGridLayout *layout{};
    QWidget *central{};


};


#endif //UNTITLED2_MAINWINDOW_H
