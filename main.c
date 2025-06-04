#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "deuxiemefichier.h"

int main() {
    Joueur joueurs[MAX_JOUEURS];
    int nbJoueurs = getNombre(-1);
    int nbImpostors = getNombre(nbJoueurs);

    initSession(nbJoueurs, nbImpostors, joueurs);

    afficherJoueurs(0, nbJoueurs, joueurs);
    
    srand((unsigned)time(NULL));
    for (int i = 0; i < nbJoueurs; i++) {
        joueurs[i].votes+= rand() % 2;;
    }
    afficherJoueurs(0, nbJoueurs, joueurs);

    return 0;
}
