# Moteur de jeu 2D

Création d'un **moteur de jeu** permettant de créer des jeux en **2D**.

## Description

Dans le cadre de la formation du BUT3 d'Informatique à l'IUT du Puy-en-Velay, le but de ce projet est de créer un moteur de jeu 2D prenant en compte les éléments physiques et graphiques necessaire à la création d'un jeu en 2D.

Pour cela nous utiliseront SFML et Visual Studio pour coder en C++.

## Prise en main

### Dépendances

* <a href="https://cmake.org/download/">CMake</a> (dernière version)

* <a href="https://www.sfml-dev.org/download/">SFML</a> (version 3.16 ou plus)

### Installation

1. Clonez le dépôt dans votre dossier de travail :
```
git clone https://github.com/Dragon-de-rage/Moteur-de-jeu-2D.git
cd Moteur-de-jeu-2D
```

2. Vérifiez que vous avez bien installé les outils suivants :
- CMake (version 3.16 ou plus)
- Un compilateur C++ compatible (MSVC, MinGW ou GCC)
- SFML 3.1 (géré automatiquement par CMake via FetchContent dans le projet)

3. Configurez et générez le projet depuis le dossier du jeu :
```
cmake -S template_jeu_sfml -B build
cmake --build build
```

4. Une fois la compilation terminée, lancez le programme généré :
- Sous Windows avec Visual Studio :
```
.\build\Debug\R5A12.exe
```
- Ou selon votre générateur CMake :
```
.\build\R5A12.exe
```

5. Copiez le fichier `arrial.ttf` dans le dossier de sortie du binaire (à côté de l'exécutable généré par CMake).

> Exemple : si le build est dans `build/Debug/`, placez `arrial.ttf` dans ce même dossier.

6. Copiez le dossier `Images` dans le dossier de sortie du binaire, au même endroit que le fichier `arrial.ttf` dans l'étape précédente.

### Execution du programme

* How to run the program
* Step-by-step bullets
```
code blocks for commands
```

## Auteurs

Alizée CHAMBON

Elven BOSC--CHARLÈS

Audrey JULIEN

## Historique de versions

* 0.1
    * Initial Release

## Crédits

*Freebsd demon*, *Animal firefox fox*, *Animal thebat bat e*, *Animal Adium*, *Animal monkey monkeys audio*, *Animal elephant* et *Animal linux penguin Evernote* icones par TurboMilk sur <a href="https://icon-icons.com/authors/21-turbomilk">Icon-Icons.com</a>
