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
  rm -r $dir_tmp/*
else
  mkdir $dir_tmp;
fi


# Nom du fichier binaire généré
if [ -d ../tmp/data ]; then
  rm ../tmp/data/*
else
  mkdir ../tmp/data;
fi


#Copie du fichier dans le dossier temporaire
cp $1 ../tmp/data/c-wire_v00_cpy.dat

#extrait les données utiles dans un fichier temporaire dans le dossier temporaire
awk -F ';' '$4 == 2' c-wire_v00.dat > ../tmp/temp.txt

#lancement du code C avec le Makefile en passant le fichier en paramètre
cd $dir_makefile || exit
make all FILE=../tmp/temp.txt
make clean
cd $dir_origine || exit

#suppression des fichiers et/ou dossiers du dossiers tmp
rm -r ../tmp/data/
rm ../tmp/*