#!/bin/bash


# Chemin du fichier source C

#main="../CodeC/main.c"

exe="./exe"
dir_makefile="../CodeC"
dir_origine="../Input"
dir_tmp="../tmp"
dir_data="../tmp/data"
dir_graph="../graph"



#vérifie si le dossier tmp existe
if [ -d $dir_tmp ]; then
  rm -r $dir_tmp/*
else
  mkdir $dir_tmp;
fi


# vérifie si le dossier data existe
if [ -d $dir_data ]; then
  rm $dir_data/*
else
  mkdir $dir_data;
fi


#vérifie si le dossier grahps existe
if [ -d $dir_graph ]; then
  rm $dir_graph/*
else
  mkdir $dir_graph;
fi


#Copie du fichier dans le dossier temporaire
#cp $1 ../tmp/data/c-wire_v00_cpy.dat

case $2 in
  "hvb")
  echo hvb
  if [ $3 == "all" ]; then
    echo "impossible de faire hvb all"
  elif [ $3 == "indiv" ]; then
    echo "impossible defaire hvb indiv"
  elif [ $3 == "comp" ]; then
    #TRIER LE FICHIER AVEC LES DONNÉES VOULUES
    echo "comp"
  else
    echo "ERREUR ARGUMENT"
  fi
  ;;

  "hva")
  echo "hva"
  if [ $3 == "all" ]; then
    eccho"impossible de faire hva all"
  elif [ $3 == "indiv" ]; then
    echo "impossible de faire hva indiv"
  elif [ $3 == "comp" ]; then
        #TRIER LE FICHIER AVEC LES DONNÉES voulues
        echo "all"
  else
    echo "ERREUR ARGUMENT"
  fi
  ;;


  "lv")
  echo "lv"

  ;;
esac



#extrait les données utiles dans un fichier temporaire dans le dossier temporaire
awk -F ';' '$1 == 1' c-wire_v25.dat > ../tmp/temp.txt



if [ -d $exe  ]; then # Si l'éxécutable éxiste on le lance directement
  ./exe
else  #Sinon lancement du code C avec le Makefile en passant le fichier en paramètre
  cd $dir_makefile || exit
  make all FILE=../tmp/temp.txt
  make clean
  cd $dir_origine || exit
fi


#suppression des fichiers et/ou dossiers du dossiers tmp
rm -r ../tmp/data/
rm ../tmp/*