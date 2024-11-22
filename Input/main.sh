#!/bin/bash

# Message de bienvenue
echo "Hello"

# Chemin du fichier source C
main="../CodeC/main.c"
ref="c-wire_v00.dat"
ref2="c-wire_v25.dat"
dir_makefile="../CodeC"
dir_origine="../Input"
dir_tmp="../tmp"

#vérifie si le dossier tmp existe
if [ -d $dir_tmp ]; then
  rm $dir_tmp/*
else
  mkdir $dir_tmp;
fi


# Nom du fichier binaire généré
mkdir ../tmp/data
cp $ref ../tmp/data/c-wire_v00_cpy.dat
cp $ref2 ../tmp/data/c-wire_v25_cpy.dat

#lancement du code C avec le Makefile
cd $dir_makefile

make all
make clean

cd $dir_origine

#suppression des fichiers et/ou dossiers du dossiers tmp
rm -r ../tmp/*




