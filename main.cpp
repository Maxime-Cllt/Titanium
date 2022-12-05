#include <QApplication>
#include "MainWindow/MainWindow.h"


/**
 * @details Fonction principale où est éxécuté mainWindow
 * @param argc
 * @param argv
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
