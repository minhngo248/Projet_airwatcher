# Projet_airwatcher

## Commit Minh
- Enlever tous les notions pointeur pour éviter erreur de segmentation
- Structure de données pour sauvagarder les données de fichier measurements.csv : map<int, list<Measurements>> 
// int : Id capteur
- GetListeCapteurs dans System, je pense que c'est plus logic ...
- Dans Measurements, periode se change en instant.
- Il faut private car c'est programmation objet orienté

## Note : 
+ ClassifierCapteurs : done
+ CalculerQualiteAir : done
