# Projet de jeu de recherche de trésors

Ce projet est un jeu de recherche de trésors en mode console où les joueurs se déplacent sur une carte pour trouver des trésors tout en évitant les pièges.

## Règles du jeu

1. Les joueurs se déplacent sur la carte en utilisant les touches "q", "d", "z" et "s" pour se déplacer respectivement à gauche, à droite, en haut et en bas.
2. La carte contient un certain nombre de trésors cachés et de pièges.
3. Lorsqu'un joueur trouve un trésor, le nombre de trésors restant à trouver est décrémenté.
4. Lorsqu'un joueur rencontre un piège, il perd un certain nombre de points de vie.
5. Si un joueur perd tous ses points de vie, il est éliminé du jeu.
6. Le jeu se termine lorsqu'il ne reste plus de trésors à trouver. Le joueur ayant trouvé le plus grand nombre de trésors gagne.

## Configuration du jeu

Le fichier `config.h` vous permet de configurer les paramètres du jeu. Voici les options de configuration disponibles :

- `COLONNE`: Nombre de colonnes de la carte (minimum 1)
- `LIGNE`: Nombre de lignes de la carte (minimum 1)
- `NB_TRAPS`: Nombre de pièges sur la carte (minimum 1)
- `HP_LOSS_TRAP`: Nombre de points de vie perdus par le joueur lorsqu'il touche un piège (minimum 1)
- `NB_TREASURES`: Nombre de trésors sur la carte (minimum 1)
- `NB_PLAYERS`: Nombre de joueurs (minimum 1)
- `MAX_PV_PLAYER`: Nombre de points de vie initiaux par joueur (minimum 1)

Vous pouvez modifier ces valeurs pour personnaliser la taille de la carte, le nombre de trésors, de pièges et de joueurs, ainsi que la difficulté du jeu en fonction des points de vie des joueurs et des pièges.

## Compilation du jeu

Pour compiler le jeu, suivez ces étapes :

1. Assurez-vous que tous les fichiers sources (.c) et les fichiers d'en-tête (.h) se trouvent dans les dossiers appropriés (`./src/`, `./headers/` et `./utils/`).
2. Ouvrez un terminal et accédez au répertoire racine du projet.
3. Exécutez la commande `make -f MakeFile_jeu_recherche_tresor.mak` pour compiler le projet. Cela générera un fichier exécutable `jeu_recherche_tresor_exe`.
4. Pour lancer le jeu, exécutez `./jeu_recherche_tresor_exe` dans le terminal.

Le jeu est maintenant compilé et prêt à être joué.


Amusez-vous bien !
