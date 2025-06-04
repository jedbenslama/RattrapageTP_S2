#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include "deuxiemefichier.h"

int main() {
    Joueur *joueurs = NULL;

    int nbJoueurs = getNombre(-1);
    joueurs = malloc(nbJoueurs * sizeof(Joueur));
    if (joueurs == NULL) {
        fprintf(stderr, "Erreur\n");
        return 1;
    }

    int nbImpostors = getNombre(nbJoueurs);

    initSession(nbJoueurs, nbImpostors, joueurs);

    afficherJoueurs(0, nbJoueurs, joueurs);
    
    voterAleatoirement(nbJoueurs, joueurs);

    afficherJoueurs(0, nbJoueurs, joueurs);

    joueurs=supprimerJoueurAvecPlusDeVotes(joueurs, &nbJoueurs);
    
    afficherJoueurs(0, nbJoueurs, joueurs);

    printf("%i",nbJoueurs);
    
    system("clear");
    
    return 0;
}
