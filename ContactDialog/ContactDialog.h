//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef UNTITLED2_CONTACTDIALOG_H
#define UNTITLED2_CONTACTDIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QDateTime>
#include "../Contact/TraductionQtStd.h"

class ContactDialog : public QDialog
{
Q_OBJECT
public:
    explicit ContactDialog(QWidget *parent = nullptr);

protected:
    QVBoxLayout *layout{};
    QHBoxLayout *layoutTop{};
    QVBoxLayout *layoutCenter{};
    QLabel *labIm{};
    QLineEdit *line1{};
    QLineEdit *line2{};
    QLineEdit *line3{};
    QLineEdit *line4{};
    QLineEdit *line5{};
    QLineEdit *line6{};
    QLineEdit *line7{};
    QPushButton *bt6{};
    QPushButton *bt7{};
    QPushButton *btAction{};
    QDateTime dateTime{};


public slots:

    void bt6Clicked();

    void bt7Clicked();

    virtual void btActionClicked();

    QtContact getContact();
};


#endif //UNTITLED2_CONTACTDIALOG_H
