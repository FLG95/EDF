#!/bin/bash

# Message de bienvenue
echo "Hello"

# Chemin du fichier source C
main="../CodeC/main.c"
ref="c-wire_v00.dat"
ref2="c-wire_v25.dat"
dir_makefile="../CodeC"


# Nom du fichier binaire généré
mkdir ../tmp/data
cp $ref ../tmp/data/c-wire_v00_cpy.dat
cp $ref2 ../tmp/data/c-wire_v25_cpy.dat


cd $dir_makefile

make all

rm exe
rm -r ../tmp/*


