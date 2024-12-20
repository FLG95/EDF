#!/bin/bash

# function to display the help and exit after
function help(){
  echo "Aide : "
  echo "Command : main.sh [ARGUMENT] [OPTION]]"
  echo "Argument"
  echo "ARG[1] : csv file path"
  echo "ARG[2] : station type ( hvb hva lv )"
  echo "ARG[3] : consumer type ( comp indiv all)"
  echo "ARG[4] : number of the power plant you want to take ( if you want to take all the power plant just dont use this argument"
  echo "Option :"
  echo "-n to selected the power plant you want to take ( only one station can be selected if you want to take all the station just dont use this command)"
  echo "-h show help for this command"
  echo "Additional help : you can't do : hvb all, hvb indiv, hva all, hva indiv "
  exit 0
}

# Check if any argument is -h
for arg in "$@"; do
  case "$arg" in # if the argument is -h display the help
      -h)
        help 
        ;;
  esac
done

# Check if the number argument is lowest than 3 or greater than 4
if [ $# -lt 3 ] || [ $# -gt 4 ]; then
  echo -e "\033[31mError : Number of argument is invalid\033[0m"
  exit 20
fi

# Check if the first argument is empty
if [ -z $1 ]; then
  echo -e "\033[31mError : No file specified\033[0m"
  exit 30
fi


# Check is the file path is exist
if [ -e $1 ]; then
  echo
else
  echo -e "\033[31mError : the specified file is invalid\033[0m"
  exit 30
fi



# Get the biggest Power Plant possible
BiggestPowerPlant=$(tail -n 1 $1 | cut -d';' -f1)

if [ -n "$4" ]; then
  nb=$4
  # Check if the value of $4 is less than or equal to 0 OR greater than the value of 'BiggestPowerPlant'
  if [ $4 -le 0 ] || [ $4 -gt $BiggestPowerPlant ]; then
    echo -e "\033[31mError the selected power plant is invalid\033[0m"
    exit 10
  fi
fi


asciiEDF="input/asciiCYEDF.txt"
asciiEYD="input/asciiEYD.txt"
asciiTSYS="input/asciiTSYS.txt"

# Get all the file path in variable
exe_name="exe"
dir_makefile="CodeC"
dir_origine="../"
dir_tmp="tmp"
dir_graph="graph"
dir_result="results"
dir_test="test"

#Display the two first ASCII
cat $asciiEDF
cat $asciiEYD

# Check if the directory tmp exist if not create it
if [ -d $dir_tmp ]; then
  rm -rf $dir_tmp/*
else
  mkdir $dir_tmp;
fi

# Check if the directory result exist if not create it
if [ -d $dir_result ]; then
  # Check if the directory result exist if not create it and move file into it
  if [ -d $dir_test ]; then
        mv $dir_result/* $dir_test
  else
        mkdir $dir_test;
        mv $dir_result/* $dir_test
  fi
else
  mkdir $dir_result;
  # Check if the directory result exist if not create it and move file into it
  if [ -d $dir_test ]; then
          mv $dir_result/* $dir_test
  else
          mkdir $dir_test;
          mv $dir_result/* $dir_test
  fi
fi

#Check if the directory graph exist if not create it
if [ -d $dir_graph ]; then
  rm -rf $dir_graph/*
else
  mkdir $dir_graph;
fi

START_TIME=$(date +%s) # Get the actual time and stock it in the END_TIME variable

echo -e "\033[32mWe are extracting your data, Please Wait few seconds\033[0m"


# Switch case on the second argument then check all the possibility for the third argument according to the first argument

case $2 in
  "hvb")
  if [ $3 == "all" ]; then # If the argument are "hvb" and "all" display and error and exit
    echo -e "\033[31mYou cant do hvb all\033[0m"
    exit 10

  elif [ $3 == "indiv" ]; then # If the argument are "hvb" and "indiv" display and error and exit
    echo -e "\033[31mYou cant do hvb indiv\033[0m"
    exit 10


  elif [ $3 == "comp" ]; then #If the third argument is "comp" we check if the power plant is selected then extract the correct line
    if [ -n "$4" ]; then
          awk -F ';' -v nb="$nb" 'NR == 1 || (($2 != "-" && $5 != "-" && $4 == "-" && $3 == "-" && $1 == nb) || ($2 != "-" && $3 == "-" && $4 == "-" && $1 == nb))' $1 > tmp/data.txt
        else
          awk -F ';' 'NR == 1 || (($2 != "-" && $5 != "-" && $4 == "-" && $3 == "-") || ($2 != "-" && $3 == "-" && $4 == "-"))' $1 > tmp/data.txt
        fi


  else # If the third argument aren't correct we display an error and exit
    echo -e "\033[31mError : one of the argument is invalid\033[0m"
    exit 10

  fi
  ;;

  "hva")
  if [ $3 == "all" ]; then # If the argument are "hva" and "all" display and error and exit
    echo -e "\033[31mYou cant do hva all\033[0m"
    exit 10

  elif [ $3 == "indiv" ]; then # If the argument are "hva" and "indiv" display and error and exit
    echo -e "\033[31mYou cant do hva indiv\033[0m"
    exit 10

  elif [ $3 == "comp" ]; then #If the third argument is "comp" we check if the power plant is selected then extract the correct line
    if [ -n "$4" ]; then
      awk -F ';' -v nb="$nb" 'NR == 1 || (($3 != "-" && $5 != "-" && $4 == "-" && $1 == nb) || ($3 != "-" && $4 == "-" && $1 == nb))' $1 > tmp/data.txt
    else
      awk -F ';' 'NR == 1 || (($3 != "-" && $5 != "-" && $4 == "-") || ($3 != "-" && $4 == "-"))' $1 > tmp/data.txt
    fi
  else # If the third argument aren't correct we display an error and exit
    echo -e "\033[31mError : one of the argument is invalid\033[0m"
    exit 10
  fi
  ;;

  "lv") # Case argument 2 is "lv"
  if [ $3 == "all" ]; then #If the third argument is "all" we check if the power plant is selected then extract the correct line
    if [ -n "$4" ]; then
      awk -F ';' -v nb="$nb" 'NR == 1 || ($4 != "-" && $1 == nb)' $1 > tmp/data.txt
    else
      awk -F ';' 'NR == 1 || ($4 != "-")' $1 > tmp/data.txt
    fi


  elif [ $3 == "indiv" ]; then #If the third argument is "indiv" we check if the power plant is selected then extract the correct line
    if [ -n "$4" ]; then
      awk -F ';' -v nb="$nb" 'NR == 1 || ($4 != "-" && $6 != "-" && $1 == nb) || ($4 != "-" && $5 == "-" && $1 == nb)' "$1" > tmp/data.txt
    else
      awk -F ';' 'NR == 1 || ($4 != "-" && $6 != "-") || ($4 !="-" && $5 == "-")' $1 > tmp/data.txt
    fi


  elif [ $3 == "comp" ]; then #If the third argument is "comp" we check if the power plant is selected then extract the correct line
    if [ -n "$4" ]; then
      awk -F ';' -v nb="$nb" 'NR == 1 || ($4 != "-" && $5 != "-" && $1 == nb) || ($4 != "-" && $6 == "-" && $1 == nb)' "$1" > tmp/data.txt
    else
      awk -F ';' 'NR == 1 || ($4 != "-" && $5 != "-") || ($4 != "-" && $6 == "-")' $1 > tmp/data.txt
    fi


  else # If the third argument aren't correct we display an error and exit
      echo -e "\033[31mError : one of the argument is invalid\033[0m"
      exit 10
  fi
  ;;

  *) # Default case = if the second argument isn't valid we display an error and exit
    echo -e "\033[31mError : one of the argument is invalid\033[0m"
    exit 10
  ;;
esac

cd $dir_makefile || exit 0
if [ -d $exe_name  ]; then # If the exe already exist launch it
  ./$exe_name
  echo "1"
  make clean
else  # Else launch the compilation with the Makefile
  make clean
  if [ -z $4 ]; then
      make all ARGS="../tmp/data.txt $2 $3" # Give the argument needed by the code in c
    else
      make all ARGS="../tmp/data.txt $2 $3 $4" # Give the argument needed by the code in c
  fi
  make clean
  cd $dir_origine || exit 0
fi

if [ $2 == 'lv' ] && [ $3 == 'all' ]; then # If Argument 2 == "lv" and Argument 3 == "all" we create add the graph in the grah directory
input_file_lv_all="tmp/lv_all_minmax_temp.csv"
if [ -z $4 ]; then
    output_file="results/lv_all_minmax.csv"
  else
    output_file="results/lv_all_minmax_$4.csv"
fi
# Extraire l'en-tête
head -n 1 "$input_file_lv_all" > "$output_file"

# Sort the file by difference between the 2 and the 3 column
tail -n +2 "$input_file_lv_all" | \
awk -F: '{print $1 ":" $2 ":" $3 ":" $2 - $3}' | \
sort -t: -k4,4g | \
awk -F: '{print $1 ":" $2 ":" $3}' >> "$output_file"

# Make the graphic
gnuplot -persist << EOF
  set terminal png size 1600,900
  set output 'graph/lv_all_load_graph.png'

  set style data histogram
  set style histogram cluster gap 1
  set style fill solid border -1
  set autoscale
  set style fill solid
  set title 'Graph of the 10 biggest and lowest load'
  set ylabel 'Load (kWh)'
  set xlabel 'Station ID'
  set grid ytics
  set key outside
  set boxwidth 1
  set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb "grey" behind
  set datafile separator ":"
  plot '$output_file' using 2:xtic(1) lc rgb "navy" title 'Capacity','' using 3 lc rgb "gold" title 'Consumption'
EOF
# Delete the temporary file
if [[ -f "$input_file_lv_all" ]]; then
    rm "$input_file_lv_all"
fi
fi

END_TIME=$(date +%s) # Get the actual time and stock it in the END_TIME variable
PROCESSUS_TIME=$((END_TIME - START_TIME)) # Calculs the processus time

echo "The program last : $PROCESSUS_TIME seconds" # Display the processus time
cat $asciiTSYS # Display the third ASCII

rm tmp/* # Empty the tmp file