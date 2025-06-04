#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "deuxiemefichier.h"


typedef struct {
    char nom[NOM_MAX];
    int role;
    int votes;
} Joueur;

void initSession(int nbJoueurs, int nbImpostors, Joueur joueurs[]){
    int impostorsAttributed = 0;
    for (int i = 0; i < nbJoueurs; i++) {
        printf("\nJoueur %i\n", i + 1);
        inputNom(joueurs[i].nom, NOM_MAX);
        joueurs[i].role = attributeRole(nbImpostors-impostorsAttributed, nbJoueurs-i);
        if(joueurs[i].role==1){
            impostorsAttributed++;
        }
        joueurs[i].votes = 0;
    }
}

int main() {
    Joueur joueurs[MAX_JOUEURS];
    int nbJoueurs = getNombre(-1);
    int nbImpostors = getNombre(nbJoueurs);

    initSession(nbJoueurs, nbImpostors, joueurs);

    for (int i = 0; i < nbJoueurs; i++) {
        printf("%s %i %i\n", joueurs[i].nom, joueurs[i].role, joueurs[i].votes);
    }

    return 0;
}
