# Projet_airwatcher
B3121 : Ngoc Minh NGO, Laetitia BÉZIE
B3125 : Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX

## Généralité du programme:
- Toutes les fonctionnalités sont dans "system"
- Les données de User (Admin, IndividualUser, Provider) sont chargées dans la structure de données de C++ (map) au début du programme.
Chaque fois quelqu'un s'inscrit, les données sont écrites dans le fichier login.csv. C'est mieux car id est généré automatiquement,
facile de manipuler, plus "MVC". On peut facilement gérer les gens qui saisit le mot de passe incorrect, inscrire avec le même mail, etc.
- Le console est bon. Mais quand IndividualUser et Provider ont la connexion échouée, la transition de l'affichage sur Console n'est pas
bonne.

## Editions des liens :
Commande : make

## Verification la fuite des données 
Commande : make memoryCheck

## Lancer le programme, jouer sur le console
Commande : ./main

## Supprimer l'executable
Commande : make clean
