#!/bin/bash

# Message de bienvenue
echo "Hello"

# Chemin du fichier source C
main="../CodeC/main.c"
ref="c-wire_v00.dat"

# Nom du fichier binaire généré
binaire="./exe"

cp $ref ../tmp/data



gcc "$main" -o "$binaire"


./$binaire


rm ../tmp/data

