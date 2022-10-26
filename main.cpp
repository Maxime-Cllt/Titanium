#include <QApplication>
#include "MainWindow/MainWindow.h"

#include "Contact/StdListContact.h"
#include "Tache/ListTache.h"
#include "Interaction/ListInteraction.h"

#include <chrono>

using namespace std::chrono;

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

    // dans le tas
    // liste de contacts et contact
    std::cout << "*****************************************************************" << std::endl;


    auto *listContact = new StdListContact;
    auto *c1 = new StdContact("toto", "tutu", "sarl", "@", "06", "/home/photo.png",
                              duration_cast<microseconds>(system_clock::now().time_since_epoch()).count(),
                              ListInteraction());

    std::cout << *c1 << std::endl;

    // ajout par pointeur
    listContact->addContact(c1);

    //constructeur de copie
    auto *c2 = new StdContact(*c1);
    c2->setDateCreation(10e15);
    std::cout << *c2 << std::endl;

    //comparaison
    std::cout << "\nLe resultat de la comparaison des contact est : " << (*c1 < *c2) << std::endl;

    //ajout par valeur
    listContact->addContact(*c1);

    // suppresion d'un contact
    listContact->supContact(listContact->getLstContact()->front());

    // c1 et c2 n'est plus utilisé car un nouveau pointeur avec copie des valeurs est effectué à chaque ajout.
    delete c1;
    delete c2;
    std::cout << std::endl << *listContact << std::endl;

    // lite d'interaction et interaction
    auto *listInteraction = new ListInteraction;
    auto *i1 = new Interaction("contenu d'une interaction");
    auto *i2 = new Interaction("contenu d'une deuxieme interaction");
    i2->setDateModif(10e10);

    std::cout << *i1 << std::endl;
    std::cout << *i2 << std::endl;
    std::cout << "\nLe resultat de la comparaison des interacttions est : " << (*i1 < *i2) << std::endl << std::endl;


    // ajout par pointer
    listInteraction->addInteraction(i1);
    // ajout par valeur
    listInteraction->addInteraction(*i2);

    // supression d'une interaction
    listInteraction->supInteraction(listInteraction->getListInteraction()->front());

//     i1 i2 n'est plus utilisé car un nouveau pointeur avec copie des valeurs est effectué à chaque ajout.
    delete i1;
    delete i2;

    std::cout << *listInteraction << std::endl;

    // liste de tache et tache

    auto *lstTache = new ListTache;
    auto *t1 = new Tache("@todo il fait beau");
    auto *t2 = new Tache("@todo il fait moche");
    auto *t3 = new Tache(*t2);
//    t2->setdate(10e10);

    std::cout << *t1 << std::endl;
    std::cout << *t2 << std::endl;

    std::cout << "\nLe resultat de la comparaison des taches est : " << (*t1 < *t2) << std::endl << std::endl;

    // ajout par pointer
    lstTache->addTache(t1);
    // ajout par valeur
    lstTache->addTache(*t2);

    //suppression possible également
    //lstTache->suppTache(lstTache->getLstTache()->front());

    std::cout << *lstTache << std::endl;

    std::cout << "*****************************************************************" << std::endl;



    listContact->getLstContact()->front()->setlstInteraction(listInteraction);

    // listInteraction n'est plus utilisé car un nouveau pointeur avec création de nouveaux pointeurs des interactions à été effectuer avec le setter
    delete listInteraction;

    listContact->getLstContact()->front()->getLstInteraction()->getListInteraction()->front()->setLstTache(lstTache);

    // lstTache n'est plus utilisé car un nouveau pointeur avec création de nouveaux pointeurs des taches à été effectuer avec le setter
    delete lstTache;


    std::cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << *listContact->getLstContact()->front()->getLstInteraction() << std::endl;
    std::cout
            << *listContact->getLstContact()->front()->getLstInteraction()->getListInteraction()->front()->getLstTache()
            << std::endl;
    std::cout << "--------------------------------------------------------------------------" << std::endl;

    // Grace au delete recursive, le simple fait de delete la liste des contacts, deletera tous les contacts de la liste,
    // chaque contact deletera la liste des interactions qui lui est associé qui deletera toutes les interactions,
    // chaque interaction deletera la liste des taches qui lui est associé, qui deletera toutes les taches.
    delete listContact;


    return QApplication::exec();

}
