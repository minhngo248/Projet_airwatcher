# Projet_airwatcher
B3121 : Ngoc Minh NGO, Laetitia BÉZIE
B3125 : Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX

## Généralité du programme:
- Toutes les fonctionnalités sont dans "system"
- Les données de User (Admin, IndividualUser, Provider) sont stockées dans la structure de données de C++ (map, pas dans fichier). 
C'est mieux car id est généré automatiquement, facile de manipuler, plus "MVC". Pendant l'inscription des utilisateur, on peut vérifier
dans cette "map" si email saisi existe déjà ou pas. Mais pour se connecter, si on saisit mal, ça va renvoyer segmentation fault. C'est
normal à cause de toutes les instructions suivantes dans le "main". Je n'ai pas encore trouvé des solutions pour ça. 

## Editions des liens :
Commande : make

## Verification la fuite des données 
Commande : make memoryCheck

## Lancer le programme, jouer sur le console
Commande : ./main

## Supprimer l'executable
Commande : make clean
