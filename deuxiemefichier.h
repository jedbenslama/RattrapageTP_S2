#define MAX_JOUEURS 100
#define NOM_MAX 50
#define MINIMUM_JOUEURS 3

int getNombre(int typededemande_aussi_nombre_de_joueurs) {
    int n;
    char taillejoueurs[32];
    while (1) {
        if(typededemande_aussi_nombre_de_joueurs==-1){
            printf("Entrez le nombre de joueurs (>= %i) : ", MINIMUM_JOUEURS);
        }else{
            printf("Entrez le nombre d'imposteurs (>= 1 && < %i) : ", MINIMUM_JOUEURS);
        }
        if (fgets(taillejoueurs, sizeof(taillejoueurs), stdin) == NULL) {
            printf("Erreur de lecture.\n");
            continue;
        }

        if ( ( sscanf(taillejoueurs, "%i", &n) != 1 ) || (n < MINIMUM_JOUEURS && typededemande_aussi_nombre_de_joueurs==-1) || ((n<1 || n>=typededemande_aussi_nombre_de_joueurs) && typededemande_aussi_nombre_de_joueurs!=-1)) {
            if(typededemande_aussi_nombre_de_joueurs==-1){
                printf("Veuillez entrer un entier valide (>= %i).\n", MINIMUM_JOUEURS);
            }else{
                printf("Veuillez entrer un entier valide (>= 1 && < %i).\n", typededemande_aussi_nombre_de_joueurs);
            }
        }else{
            return n;
        }
    }
}

int attributeRole(int impostor, int spots_restants) { // spots restants c'est pour etre sur d'avoir le nombre d'impostors demandés tout en maintenant la randomness
    int rien;
    if(impostor!=0){
        if(spots_restants == impostor){
            rien=1;
        }
        else{
            srand(time(NULL));
            rien = rand() % 2;
        }
    }
    else{
        rien = 0;
    }
    return rien;
}

void inputNom(char *nom, int taille) {
    while (1) {
        printf("Nom du joueur : ");
        if (fgets(nom, taille, stdin) == NULL) {
            printf("Erreur de lecture.\n");
            continue;
        }
        size_t len = strlen(nom);
        if (len > 0 && nom[len - 1] == '\n') {
            nom[len - 1] = '\0';
        }
        if (strlen(nom) == 0) {
            printf("Le nom ne peut pas être vide.\n");
        }else{
            break;
        }
    }
}