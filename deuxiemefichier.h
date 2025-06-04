#define NOM_MAX 50
#define MINIMUM_JOUEURS 3

typedef struct {
    char nom[NOM_MAX];
    int role;
    int votes;
} Joueur;

int getNombre(int typededemande_aussi_nombre_de_joueurs) {
    int n;
    char taillejoueurs[32];
    while (1) {
        if(typededemande_aussi_nombre_de_joueurs==-1){
            printf("Entrez le nombre de joueurs (>= %i) : ", MINIMUM_JOUEURS);
        }else{
            printf("Entrez le nombre d'imposteurs (>= 1 && < %i) : ", typededemande_aussi_nombre_de_joueurs);
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
            srand((unsigned)time(NULL));
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

void afficherJoueurs(int roles, int nbJoueurs, Joueur joueurs[]){
    printf("\n");
    if(roles==1){
        for (int i = 0; i < nbJoueurs; i++) {
            printf("Nom: %s\nVotes: %i\nImpostor: %i\n", joueurs[i].nom, joueurs[i].votes, joueurs[i].role);
        }
    }else{
        for (int i = 0; i < nbJoueurs; i++) {
            printf("Nom: %s\nVotes: %i\n\n", joueurs[i].nom, joueurs[i].votes);
        }
    }
}

void reinitialiserCompteursVotes(int nbJoueurs, Joueur joueurs[]){
    for (int i = 0; i < nbJoueurs; i++) {
        joueurs[i].votes=0;
    }
}

void voterAleatoirement(int nbJoueurs, Joueur joueurs[]){
    srand((unsigned)time(NULL));
    for (int i = 0; i < nbJoueurs; i++) {
        joueurs[i].votes+= rand() % 2;
    }
}

Joueur* supprimerJoueurAvecPlusDeVotes(Joueur *joueurs, int *nbJoueurs) {
    int maxVotes = joueurs[0].votes;
    int indexMax = 0;

    for (int i = 1; i < *nbJoueurs; i++) {
        if (joueurs[i].votes > maxVotes) {
            maxVotes = joueurs[i].votes;
            indexMax = i;
        }
    }
    char role[50];

    if(joueurs[indexMax].role==1){
        strcpy(role, "Impostor");
    }else{
        strcpy(role, "Crewmate");
    }
    printf("Le joueur %s avec %i vote(s) a été éliminé.\nSon role: %s\n", joueurs[indexMax].nom, joueurs[indexMax].votes, role);

    for (int i = indexMax; i < *nbJoueurs - 1; i++) {
        joueurs[i] = joueurs[i + 1];
    }

    (*nbJoueurs)--;

    Joueur *tmp = realloc(joueurs, (*nbJoueurs) * sizeof(Joueur));
    if (tmp == NULL && *nbJoueurs > 0) {
        fprintf(stderr, "Erreur realloc.\n");
        return joueurs;
    }

    return tmp;
}


int recompterNombreImpostors(Joueur joueurs[], int nbJoueurs){
    int impostors = 0;
    for (int i = 0; i < nbJoueurs; i++) {
        if (joueurs[i].role == 1) {
            impostors++;
        }
    }
    return impostors;
}