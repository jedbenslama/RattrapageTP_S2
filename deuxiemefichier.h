#define MAX_JOUEURS 100
#define NOM_MAX 50
#define MINIMUM_JOUEURS 3

int getNombreJoueurs() {
    int n;
    char taillejoueurs[32];
    while (1) {
        printf("Entrez le nombre de joueurs (>= %i) : ", MINIMUM_JOUEURS);
        if (fgets(taillejoueurs, sizeof(taillejoueurs), stdin) == NULL) {
            printf("Erreur de lecture.\n");
            continue;
        }

        if (sscanf(taillejoueurs, "%i", &n) != 1 || n < MINIMUM_JOUEURS) {
            printf("Veuillez entrer un entier valide (>= %i).\n", MINIMUM_JOUEURS);
        } else {
            return n;
        }
    }
}

int inputRole() {
    int r;
    char buffer[16];
    while (1) {
        printf("Entrez le rôle initial\n Crewmate = 0\n Impostor = 1\n> ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erreur de lecture.\n");
            continue;
        }
        
        if (sscanf(buffer, "%i", &r) != 1 || (r != 0 && r != 1)) {
            printf("Veuillez entrer 0 ou 1.\n");
        } else {
            return r;
        }
    }
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
        } else {
            break;
        }
    }
}