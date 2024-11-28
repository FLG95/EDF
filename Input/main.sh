#!/bin/bash

# Message de bienvenue
echo "Hello"

# Chemin du fichier source C
main="../CodeC/main.c"
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
if [ -d ../tmp/data ]; then
  rm ../tmp/data/*
else
  mkdir ../tmp/data;
fi



cp $1 ../tmp/data/c-wire_v00_cpy.dat



cat ../tmp/data/c-wire_v00_cpy.dat






#lancement du code C avec le Makefile
cd $dir_makefile || exit

make all
make clean

cd $dir_origine || exit




#suppression des fichiers et/ou dossiers du dossiers tmp
rm -r ../tmp/*

