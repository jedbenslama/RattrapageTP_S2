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
    
    voterAleatoirement(nbJoueurs, joueurs);

    afficherJoueurs(0, nbJoueurs, joueurs);

    nbJoueurs=supprimerJoueurAvecPlusDeVotes(joueurs, nbJoueurs);

    return 0;
}
