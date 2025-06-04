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

    while(nbImpostors!=0 || nbJoueurs-nbImpostors >= 2){ // dans l'etape 5 ligne 1 il dit "au moins deux joueurs" mais je pense la boucle va run à l'infini si je met au moins 2 joueurs alors je met au moins 2 crewmates

        afficherJoueurs(0, nbJoueurs, joueurs);

        voterAleatoirement(nbJoueurs, joueurs);

        afficherJoueurs(0, nbJoueurs, joueurs);

        supprimerJoueurAvecPlusDeVotes(joueurs, &nbJoueurs);

        afficherJoueurs(0, nbJoueurs, joueurs);

        nbImpostors=recompterNombreImpostors(joueurs, nbJoueurs);

    }

    if(nbImpostors>=nbJoueurs-nbImpostors){
        printf("Les impostors gagnent\n");
    }else{
        printf("Les crewmates gagnent\n");
    }

    free(joueurs);
    
    return 0;
}
