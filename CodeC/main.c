#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/create_avl.h"
#include "include/parcours.h"
#include "include/type_avl.h"
#include "include/createData.h"
#include "include/fonction_utile.h"
#include "include/outFile.h"

int main(int argc, char* argv[]){
    //Check if the number of argument is correct
    if (argc < 4 || argc > 5){
        printf("\033[31mERROR : not enough argument\033[0m\n");
        exit(10);
    }

    //Check if argv[2] is correct
    if (strcmp(argv[2], "hva") != 0 && strcmp(argv[2], "hvb") != 0 && strcmp(argv[2], "lv") != 0){
        exit(20);
    }

    //Check if argv[3] is correct
    if (strcmp(argv[3], "all") != 0 && strcmp(argv[3], "comp") != 0 && strcmp(argv[3], "indiv") != 0){
        exit(20);
    }

    //Check if the association of the two arguments 2 and 3 are allowed by the program
    if ((strcmp(argv[2], "hva") == 0 && strcmp(argv[3], "indiv") == 0)|| (strcmp(argv[3], "all") == 0 && strcmp(argv[2], "hva") == 0) || (strcmp(argv[2], "hvb") == 0 && strcmp(argv[3], "indiv") == 0)|| (strcmp(argv[3], "all") == 0 && strcmp(argv[2], "hvb") == 0)){
        exit(20);
    }

    //Define the type of the station
    char* type = argv[2];

    //Initialize the parameters for the height anf the stability of an avl
    int hStation = 0;
    int hConso = 0;

    //Initialize the tree of the station and of the consumers
    tree* stationTree = NULL;
    tree* consoTree = NULL;

    //Open the file which contains the data and check if all is right
    FILE* fichier = fopen(argv[1], "r");
    if (fichier == NULL){
        printf("\033[31mERROR : argument 1 file is empty\033[0m\n");
        exit(30);
    }

    printf("\033[32mWe are sorting your data, please wait few seconds\033[0m\n");

    //Take data of a file and add it to a tree
    ensembleDonne(fichier, &hStation, &hConso, &stationTree, &consoTree, type);
    parcoursInfixeSum(consoTree, &stationTree);
    freeAvl(consoTree);

    //Initialize tree
    tree* stationTreeSortProduction = NULL;

    //Initialize the parameters for the height anf the stability of an avl
    int h_Prod = 0;

    //Add Nodes to the different tree with the right method for each one

    stationTreeSortProduction = parcoursSortProduction(stationTreeSortProduction, stationTree, &h_Prod);

    //Check if the tree are not empty
    if (stationTreeSortProduction == NULL){
        exit(60);
    }

    //Write the nodes of the tree in external files
    centerWrite(stationTreeSortProduction, argv[2], argv[3], argv[4]);

    //Check if arg2 == lv and arg3 == all to make the file lv_all_minmax
    if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "all") == 0){
        tree* stationTreeSortConsumption = NULL;
        int h_Consumption = 0;
        stationTreeSortConsumption = parcoursSortConsumption(stationTreeSortConsumption, stationTree, &h_Consumption);
        if (stationTreeSortConsumption == NULL){
            exit(60);
        }
        centerWrite10(stationTreeSortConsumption, argv[2], argv[3]);
        freeAvl(stationTreeSortConsumption);
    }

    //free the memory
    freeAvl(stationTree);
    freeAvl(stationTreeSortProduction);
    return 0;
}