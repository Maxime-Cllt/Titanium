//
// Created by Rahman  Yilmaz on 06/10/2022.
//

#ifndef PROJET_QT_CONTACTDIALOG_H
#define PROJET_QT_CONTACTDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QDateTime>
#include "../Utility/Utility.h"

class ContactDialog : public QDialog
{
Q_OBJECT
public:
    explicit ContactDialog(QWidget *parent = nullptr);

protected:
    QGridLayout *layout{};
    QLabel *labIm{};
    QLabel *labDateCreation{};
    QLineEdit *line1{};
    QLineEdit *line2{};
    QLineEdit *line3{};
    QLineEdit *line4{};
    QLineEdit *line5{};
    QLineEdit *line6{};
    QPushButton *bt6{};
    QPushButton *btAction{};

public slots:

    void bt6Clicked();

    virtual void btActionClicked();

    QtContact getContact();
};


#endif //PROJET_QT_CONTACTDIALOG_H
