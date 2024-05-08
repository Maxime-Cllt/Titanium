<div align="center">
<img src="https://github.com/Sudo-Rahman/QT_L3/blob/main/images/app.ico" width="50" height="50" align="center" alt="logo"/> 
<h1 >Titanium</h1>
</div>

## Application graphique de gestion de contact codée en C++ et en utilisant le framework Qt

## Fonctionnalités

* Ajout d'un contact
* Modification d'un contact
* Ajout d'interaction(s) à un contact
* ajout de tache(s) dans une interaction avec le mot clé @todo obligatoire, et possibillité de spécifier la date de la
  tache avec le mot clé @date jj/mm/aaaa
* Recherche basique ou avancé de contact
* Affichage des taches d'un contact, possibilité de filtrer, trier les taches est masqué ceux déjà passés
* Affichage des taches de tous les contacts trié par ajout croissant, possibilité de masqué les taches passés
* Visionnage d'un historique d'ajout, suppression, modification de contact et interaction
* Suppression d'un contact
* Suppression multiple de contact, interaction et tache
* Possibilité d'exporter en json les contacts avec leur(s) interaction(s) et tache(s)
* Possibilité d'importer en json des contacts avec leur(s) interaction(s) et tache(s), uniquement les jsons exportés
  avec l'application fonctionnent
* Possibillité de trié les contacts en fonction de leur nom ou leur date de création

## Screenshots

##### Theme claire du système

<img src="https://github.com/Sudo-Rahman/QT_L3/blob/main/presentation/presentation_1.png" width="350" height="300" alt="theme claire"/>

</br>

<img src="https://github.com/Sudo-Rahman/QT_L3/blob/main/presentation/presentation_2.png" width="400" height="300" alt="theme claire"/>

##### Theme sombre du système

<img src="https://github.com/Sudo-Rahman/QT_L3/blob/main/presentation/presentation_3.png" width="400" height="300"  alt="theme sombre"/>

## Compilation

### GNU/Linux et MacOS

#### Prérequis

* QT 5/6
* Qmake ou Cmake
* make
* g++

##### avec Qmake

```
mkdir build; cd build
```

```
qmake ../Titanium.pro 
```

```
make
```

##### avec Cmake

```
mkdir build; cd build
```

```
cmake -DCMAKE_PREFIX_PATH=path/to/Qt ../
```

```
make
```

### Windows

Installer Qtcreator <a href="https://www.qt.io/download-open-source">ici</a>
Ouvrez Qtcreator importer Titanium.pro, compiler le programme et utilisez windeployqt.exe pour les dependances et copier
coller dans le dossier de l'application les fichiers :

- libgcc_s_dw2-1.dll
- libgcc_s_seh-1.dll
- libstdc++-6.dll
- libwinpthread-1.dll

Contenu dans le dossier Qt\x.x.x\mingw_64\bin 
