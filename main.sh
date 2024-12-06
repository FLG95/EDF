#!/bin/bash

function help(){
  echo "Aide : "
  echo "Command : main.sh [ARGUMENT] [OPTION]]"
  echo "Argument"
  echo "ARG[0] : csv file path"
  echo "ARG[0] : station type ( hvb hva lv )"
  echo "ARG[1] : consumer type ( comp indiv all)"
  echo "Option :"
  echo "-h show help for this command"
  echo "Aditional help : you can't do : hvb all, hvb indiv, hva all, hva indiv "
  exit 0
}

for arg in "$@"; do
  case "$arg" in
      -h) # si un argument est -h on affiche l'aide
        help
        ;;
  esac
done

if [ $# -lt 3 ]; then
  echo "Number of argument is invalid"
  exit 0;
fi



exe_name="exe"

dir_makefile="CodeC"
dir_origine="../"
dir_tmp="tmp"
dir_graph="graph"


if [ -z $1 ]; then
  echo "erreur : aucun fichier spécifié "
  exit 0
fi


if [ -e $1 ]; then
  echo "le fichier passé en premier argument est correct"
else
  echo "erreur : le fichier passé en premier argument est incorrect"
  exit 0
fi


#vérifie si le dossier tmp existe
if [ -d $dir_tmp ]; then
  rm -r $dir_tmp/*
else
  mkdir $dir_tmp;
fi


#vérifie si le dossier graph existe
if [ -d $dir_graph ]; then
  rm $dir_graph/*
else
  mkdir $dir_graph;
fi

echo $2

case $2 in
  "hvb")
  if [ $3 == "all" ]; then
    echo "impossible de faire hvb all"
    exit 0

  elif [ $3 == "indiv" ]; then
    echo "impossible de faire hvb indiv"
    exit 0


  elif [ $3 == "comp" ]; then
    awk -F ';' 'NR == 1 || (($3 != "-" && $5 != "-" && $4 == "-" && $3 == "-") || ($2 != "-" && $3 == "-" && $4 == "-"))' $1 > tmp/data.txt

  else
    echo "erreur: l'un des arguments spécifiés est incorrect"
    exit 0

  fi
  ;;

  "hva")
  if [ $3 == "all" ]; then
    eccho"impossible de faire hva all"
    exit 0

  elif [ $3 == "indiv" ]; then
    echo "impossible de faire hva indiv"
    exit 0

  elif [ $3 == "comp" ]; then
    awk -F ';' 'NR == 1 || (($3 != "-" && $5 != "-" && $4 == "-") || ($3 != "-" && $4 == "-"))' $1 > tmp/data.txt

  else
    echo "erreur : l'un des arguments spécifiés est incorrect"
    exit 0
  fi
  ;;

  "lv")
  if [ $3 == "all" ]; then
      awk -F ';' 'NR == 1 || ($4 != "-")' $1 > tmp/data.txt

  elif [ $3 == "indiv" ]; then
      awk -F ';' 'NR > 1 || ($4 != "-" && $6 != "-")' $1 > tmp/data.txt

  elif [ $3 == "comp" ]; then
      awk -F ';' 'NR == 1 || ($4 != "-" && $5 != "-")' $1 > tmp/data.txt
  else
      echo "erreur : l'un des arguments spécifiés est incorrect"
      exit 0
  fi
  ;;

  *)
    echo "erreur : l'un des arguments spécifiés est incorrect"
    exit 0
  ;;
esac


START_TIME=$(date +%s)

if [ -d $exe_name  ]; then # Si l'éxécutable éxiste on le lance directement
  ./$exe_name
else  #Sinon lancement du code C avec le Makefile en passant le fichier en paramètre

  cd $dir_makefile || exit 0
  make all ARGS="../tmp/data.txt $2"
  make clean
  cd $dir_origine || exit 0
fi


if [ $2 = 'lv' ] && [ $3 = 'all' ]; then

gnuplot -persist << EOF
EOF
fi

END_TIME=$(date +%s)

PROCESSUS_TIME=$((END_TIME - START_TIME))



echo "Le programme a mit : $PROCESSUS_TIME secondes"

#suppression des fichiers et/ou dossiers du dossiers tmp
rm tmp/*
