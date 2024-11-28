#ifndef creerDonnees
#define creerDonnees

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"

FILE* transformerFichier(FILE* fichier);
void ensembleDonne(FILE* fichier);
file2* creerChainon(donnees b);
file2* creation(file2* tete, donnees b);
void afficher(file2* tete);

#endif //CreerDonnees