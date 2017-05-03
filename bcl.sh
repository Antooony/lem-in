#!/bin/bash

liste_fichiers=`ls ./tests`

for fichier in $liste_fichiers
do
	echo $fichier
        ./lem-in < ./tests/$fichier
	printf '\n'
done
