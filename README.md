Cy EDF

Pre-Ing-2 S1 project

Subject CyWire subject.pdf



Arguments

    input_file: path to the input file
    station_type: type of station (hvb, hva, lv)
    consumer_type: type of consumer (indiv, comp, all)
    OPTIONAL: power_plant_id: id of the power plant 

not all case are allowed (hvb all/indiv) & (hva all/indiv)

./main.sh Input/[input_file] [station_type(hvb, hva, lv)] [consumer_type(indiv, comp, all)] exemple:

./main.sh Input/c-wire_v25.dat hva comp
















Dependencies

    pthread

Env variables

    RUNNING_BENCHMARK: Set to 1 to run benchmarks

Shell script exit code

    0: Success
    20: Error when creating directory
    21: Error when compiling C program
    22: Error with given arguments

if c program exit code is not 0, shell script exit code will be the c program exit code
C program exit code

    0: Success
    2: Error when parsing arguments
    3: Invalid argument
    4: Error when reading file and building AVL tree
    5: Error while using data from AVL tree
    6: Error while writing csv file
    7: Error while writing minmax csv file
