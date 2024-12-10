#!/bin/bash


function help(){
  echo "Aide : "
  echo "Command : main.sh [ARGUMENT] [OPTION]]"
  echo "Argument"
  echo "ARG[1] : csv file path"
  echo "ARG[2] : station type ( hvb hva lv )"
  echo "ARG[3] : consumer type ( comp indiv all)"
  acho "ARG[4] : number of the power plant you want to take ( if you want to take all the power plant just dont use this argument"
  echo "Option :"
  echo "-n to selected the power plant you want to take ( only one station can be selected if you want to take all the station just dont use this command)"
  echo "-h show help for this command"
  echo "Additional help : you can't do : hvb all, hvb indiv, hva all, hva indiv "
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
  echo "Error : Number of argument is invalid"
  exit 0;
fi

if [ -z $1 ]; then
  echo "Error : No file specified "
  exit 0
fi


if [ -e $1 ]; then
  echo "le fichier passé en premier argument est correct"
else
  echo "erreur : le fichier passé en premier argument est incorrect"
  exit 0
fi


BiggestPowerPlant=$(tail -n 1 $1 | awk '{print $1}')
if [ $4 -le 0 ] || [ $4 -gt $BiggestPowerPlant ]; then
  echo "Error the selected power plant is invalid"
  exit 0
fi


ascii1="
                        .,.*/(,
                        ((((((,
                       ((((((((
                        ((((((/
              .(,         (((/       .,,,.            ..
            ((((((*             /((((((((((((*    #&&&&&&&&%   &&&&%&&&&&*  ,&&&&&&&&
            /(((((((((((/             ./((((((   #&&&    %&&%  &&&/    &&&( ,&&&
               ./((((/,                          &&&&&&&&&&&%  &&&/    #&&% ,&&&&&&&*
                               .((/.             (&&&*     *   &&&/   ,&&&, ,&&&
                       *(((.     /(((((/          .&&&&&&&&&(  &&&&&&&&&*   ,&&&
                (**/(((((((,       (((((((
                *(((((((((*        ((((((((
                   .***.              ,/*

                                                                                  "
ascii2="
                __          __       _ ____                                       __
          ___  / /__  _____/ /______(_) __/_  __   __  ______  __  _______   ____/ /___ ___  __
         / _ \/ / _ \/ ___/ __/ ___/ / /_/ / / /  / / / / __ \/ / / / ___/  / __  / __  / / / /
        /  __/ /  __/ /__/ /_/ /  / / __/ /_/ /  / /_/ / /_/ / /_/ / /     / /_/ / /_/ / /_/ /
        \___/_/\___/\___/\__/_/  /_/_/  \__, /   \__, /\____/\__,_/_/      \__,_/\__,_/\__, /
                                       /____/   /____/                                /____/   "
ascii3="
        ████████╗██╗  ██╗ █████╗ ███╗   ██╗██╗  ██╗███████╗       ███████╗███████╗███████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗ ██████╗  ██████╗ ███╗   ██╗
        ╚══██╔══╝██║  ██║██╔══██╗████╗  ██║██║ ██╔╝██╔════╝       ██╔════╝██╔════╝██╔════╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝██╔═══██╗██╔═══██╗████╗  ██║
           ██║   ███████║███████║██╔██╗ ██║█████╔╝ ███████╗       ███████╗█████╗  █████╗       ╚████╔╝ ██║   ██║██║   ██║    ███████╗██║   ██║██║   ██║██╔██╗ ██║
           ██║   ██╔══██║██╔══██║██║╚██╗██║██╔═██╗ ╚════██║       ╚════██║██╔══╝  ██╔══╝        ╚██╔╝  ██║   ██║██║   ██║    ╚════██║██║   ██║██║   ██║██║╚██╗██║
           ██║   ██║  ██║██║  ██║██║ ╚████║██║  ██╗███████║▄█╗    ███████║███████╗███████╗       ██║   ╚██████╔╝╚██████╔╝    ███████║╚██████╔╝╚██████╔╝██║ ╚████║
           ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝╚═╝    ╚══════╝╚══════╝╚══════╝       ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝
                                                                                                                                                                 "
exe_name="exe"

dir_makefile="CodeC"
dir_origine="../"
dir_tmp="tmp"
dir_graph="graph"

echo "$ascii1"
echo "$ascii2"




#vérifie si le dossier tmp existe
if [ -d $dir_tmp ]; then
  rm -r $dir_tmp/*
else
  mkdir $dir_tmp;
fi


#vérifie si le dossier graph existe
if [ -d $dir_graph ]; then
  rm -f $dir_graph/*
else
  mkdir $dir_graph;
fi

START_TIME=$(date +%s)
echo "We are extracting your data, Please Wait few seconds"

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
      awk -F ';' 'NR == 1 || ($4 != "-" && $6 != "-") || ($4 !="-" && $5 == "-")' $1 > tmp/data.txt

  elif [ $3 == "comp" ]; then
      awk -F ';' 'NR == 1 || ($4 != "-" && $5 != "-") || ($4 != "-" && $6 == "-")' $1 > tmp/data.txt
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



if [ -d $exe_name  ]; then # Si l'éxécutable éxiste on le lance directement
  ./$exe_name
else  #Sinon lancement du code C avec le Makefile en passant le fichier en paramètre

  cd $dir_makefile || exit 0
  make all ARGS="../tmp/data.txt $2 $3"
  make clean
  cd $dir_origine || exit 0
fi


if [ $2 = 'lv' ] && [ $3 = 'all' ]; then
gnuplot -persist << EOF
  set terminal png size 1920,1080
  set output 'graph/lv_all_load_graph.png'
  set autoscale
  set style fill solid
  set title 'Titre'
  set ylabel 'Load (kWh)'
  set xlabel 'Station ID'
  set datafile separator ":"
  set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb "white" behind
  set style fill solid 0.5 border lc rgb "black"  # Remplissage semi-transparent avec bordure noire
  plot 'tmp/lv_minmax.csv' using 3:xtic(1) with boxes linecolor rgb "#008B8B" title 'Load'
EOF
fi

END_TIME=$(date +%s)
PROCESSUS_TIME=$((END_TIME - START_TIME))
echo "Le programme a mit : $PROCESSUS_TIME secondes"

rm tmp/*

echo "$ascii3"
