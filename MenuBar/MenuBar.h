//
// Created by Rahman  Yilmaz on 15/10/2022.
//

#ifndef PROJET_QT_MENUBAR_H
#define PROJET_QT_MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar
{
Q_OBJECT

public:
    explicit MenuBar(QWidget *parent);

private:
    QMenu *menu1{};

};


#endif //PROJET_QT_MENUBAR_H
