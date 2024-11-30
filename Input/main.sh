#!/bin/bash


exe="./exe"
dir_makefile="../CodeC"
dir_origine="../Input"
dir_tmp="../tmp"
#dir_data="../tmp/data"
dir_graph="../graph"

if [ -z $1 ]; then
  echo "erreur : aucun fichier spécifié "
  exit 1
fi

if [ -e $1 ]; then
  echo "le fichier passé en premier argument est correct"
else
  echo "erreur : le fichier passé en premier argument est incorrect"
  exit 1
fi


#vérifie si le dossier tmp existe
if [ -d $dir_tmp ]; then
  rm -r $dir_tmp/*
else
  mkdir $dir_tmp;
fi


#vérifie si le dossier grahps existe
if [ -d $dir_graph ]; then
  rm $dir_graph/*
else
  mkdir $dir_graph;
fi


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
    awk -F ';' 'NR == 1 || ($2 != "-" && $5 != "-")' c-wire_v00.dat > ../tmp/data.txt  # Si on veut enlever l'entête il faut enlever NR == 1

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
        echo "all"
        awk -F ';' 'NR == 1 || ($3 != "-" && $5 != "-")' c-wire_v00.dat > ../tmp/data.txt

  else
    echo "ERREUR ARGUMENT"
  fi
  ;;



  "lv")
  echo "lv"
  if [ $3 == "all" ]; then
      echo "all"
      awk -F ';' 'NR == 1 || ($4 != "-")' c-wire_v00.dat > ../tmp/data.txt

  elif [ $3 == "indiv" ]; then
      echo "all"
      awk -F ';' 'NR == 1 || ($4 != "-" && $6 != "-")' c-wire_v00.dat > ../tmp/data.txt

  elif [ $3 == "comp" ]; then
      echo "all"
      awk -F ';' 'NR == 1 || ($4 != "-" && $5 != "-")' c-wire_v00.dat > ../tmp/data.txt
  fi
  ;;
esac



if [ -d $exe  ]; then # Si l'éxécutable éxiste on le lance directement
  ./exe
else  #Sinon lancement du code C avec le Makefile en passant le fichier en paramètre
  cd $dir_makefile || exit 1
  make all FILE=../tmp/data.txt
  make clean
  cd $dir_origine || exit 1
fi


#suppression des fichiers et/ou dossiers du dossiers tmp
rm ../tmp/*