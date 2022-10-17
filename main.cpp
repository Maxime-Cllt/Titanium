#include <QApplication>
#include "MainWindow/MainWindow.h"

/**
 * Classe principale du projet
 * @param argc
 * @param argv
 * @return Execution de mainWindow
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
