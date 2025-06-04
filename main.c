#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "deuxiemefichier.h"

typedef struct {
    char nom[NOM_MAX];
    int role;
    int votes;
} Joueur;

int main() {
    Joueur joueurs[MAX_JOUEURS];
    int nbJoueurs = getNombreJoueurs();

    for (int i = 0; i < nbJoueurs; i++) {
        printf("\nJoueur %i\n", i + 1);
        inputNom(joueurs[i].nom, NOM_MAX);
        joueurs[i].role = inputRole();
        joueurs[i].votes = 0;
    }

    for (int i = 0; i < nbJoueurs; i++) {
        printf("%s %i %i\n", joueurs[i].nom, joueurs[i].role, joueurs[i].votes);
    }

    return 0;
}
