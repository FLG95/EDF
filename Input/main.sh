#!/bin/bash

# Message de bienvenue
echo "Hello"

# Chemin du fichier source C
main="../CodeC/main.c"
ref="c-wire_v00.dat"
ref2="c-wire_v25.dat"

# Nom du fichier binaire généré
binaire="./exe"
mkdir ../tmp/data
cp $ref ../tmp/data/c-wire_v00_cpy.dat
cp $ref2 ../tmp/data/c-wire_v25_cpy.dat

gcc "$main" -o "$binaire"

./$binaire


rm exe
rm ../main
rm -r ../tmp/*


