#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unistd.h"
#include <sys/types.h>
#include <sys/wait.h>

#include "include/create_avl.h"
#include "include/parcours.h"
#include "include/type_avl.h"
#include "include/createData.h"
#include "include/fonction_utile.h"
#include "include/outFile.h"


int main(int argc, char* argv[]){
    //Check if the number of argument is correct
    if (argc != 4){
        printf("\033[31mERROR : not enough argument\033[0m\n");
        exit(10);
    }

    //Check if argv[2] is correct
    if (strcmp(argv[2], "hva") != 0 && strcmp(argv[2], "hvb") != 0 && strcmp(argv[2], "lv") != 0){
        exit(20);
    }


    //Define the type of the station
    char* type = argv[2];

    //Initialize the parameters for the height anf the stability of an avl
    int hStation = 0;

    //Initialize the tree of the station
    tree* stationTree = NULL;


    //Open the file which contains the data and check if all is good
    /*FILE* fichier = fopen(argv[1], "r");
    if (fichier == NULL){
        printf("\033[31mERROR : argument 1 file is empty\033[0m\n");
        exit(30);
    }*/



    printf("\033[32mWe are sorting your data, please wait few seconds\033[0m\n");


    int pipe_fd[2];

    if(pipe(pipe_fd) == -1){
        perror("Error in pipe creation");
        return 100;
    }

    pid_t pid = fork();
    if(pid == -1){
        perror("Error in fork");
        exit(100);
    }

    if(pid == 0){
        close(pipe_fd[1]);
        ensembleDonne(&hStation, &stationTree, type, pipe_fd[0]);
    }
    else{
        transformerFichier(stdin, pipe_fd[1]);
        ssize_t bytes_read;
        char buffer[1024];
        while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[bytes_read] = '\0'; // Terminer la chaîne lue
            printf("%s", buffer);
        }
        //close(pipe_fd[1]);
        wait(NULL);
    }



    //Initialize tree
    tree* stationTreeSortProduction = NULL;
    tree* stationTreeSortAbs = NULL;

    //Initialize the parameters for the height anf the stability of an avl
    int h_abs = 0;
    int h_Prod = 0;

    //Add Nodes to the different tree with the right method for each one
    stationTreeSortAbs = parcoursSortAbs(stationTreeSortAbs, stationTree, &h_abs);
    stationTreeSortProduction = parcoursSortProduction(stationTreeSortProduction, stationTree, &h_Prod);

    //Check if the tree are not empty
    if (stationTreeSortProduction == NULL || stationTreeSortAbs == NULL){
        exit(60);
    }


    //Write the nodes of the tree in external files
    centerWrite(stationTreeSortProduction, argv[2], argv[3]);

    if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "all") == 0){
        centerWrite10(stationTreeSortAbs, argv[2], argv[3]);
    }


    //free the memory
    freeAvl(stationTree);
    freeAvl(stationTreeSortProduction);
    freeAvl(stationTreeSortAbs);
    return 0;
}