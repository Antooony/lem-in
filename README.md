# lem-in
Ce projet consiste en la simulation d'une fourmilliere que l'on souhaite faire traverser par un nombre n de fourmis.
la fourmilliere est constituée des élements suivants :
- des salles au format suivant : ``` Nom_de_la_salle Coordonnée_X Coordonnée_Y```
- Des tubes au format suivant : ```salle_1-salle_2```
- une salle de départ, precedée par le flag ```##start```
- une salle de sortie, precedée par le flag ```##end```

Le programme reçoit, sur l'entrée standard la description de la fourmillière au format suivant
```
nombre_de_fourmis
les_salles
les_tubes
```

Un exemple de fourmilliere :
```
##start
1 23 3
2 16 7
#commentaire
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#autre commentaire
4-2
2-1
7-6
7-2
7-4
6-5
```

Le resultat est affiché sous le format suivant :
```
nombre_de_fourmis
les_salles
les_tubes
Lx-y Lz-w Lr-o
```
Où x, z, r sont des numéros de fourmis (allant de 1 à nombre_de_fourmis) et y, w, o des noms de salles.

## Usage
pour compiler, on appelle le Makefile avec la commande ```make```
On appelle ensuite le programme en redirigeant la fourmilliere sur l'entrée standard:
```
./lem_in < [fourmilliere]
```

exemple:
```
$> ./lem_in test/comments
3
#you
##start
start 0 0
#lost
##end
end 1 1
start-end
#the
#game
#!!

L1-end
L2-end
L3-end
```
