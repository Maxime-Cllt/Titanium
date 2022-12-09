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
    QApplication::setWindowIcon(QIcon("src/app.ico"));

    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
