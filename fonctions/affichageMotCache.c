#include <stdio.h>

/*
 * Affiche le mot caché en pointillés
 *
 * ENTREE : les lettres trouvées, la lettre choisie
 * SORTIE : rien
 */
void affichageMotCache(char lettreChoisie) {
    char motCache[] = "anticonstitutionnellement";
    int i;
    int lettreTrouve = 0;
    int nombreLettresMotCache = (sizeof(motCache) / sizeof(motCache[0])) - 1;
    char nouveauMotCache[nombreLettresMotCache];

    for (i = 0; i < nombreLettresMotCache; i++) {

        /*
         * Si la lettre choisie est dans le mot caché
         */
        if (lettreChoisie == motCache[i]) {
            lettreTrouve = 1;
            nouveauMotCache[i] = lettreChoisie;
        }
        else{
            nouveauMotCache[i] = '_';
        }
    }


    // Sinon on indique que l'on a rien trouvé
    if (lettreTrouve == 0) {
        printf("\nRaté...\n");
        printf("Taille du mot à trouver :\n");

        for (i = 0; i < nombreLettresMotCache; i++) {
            printf("%c", nouveauMotCache[i]);
        }
    }
    else{
        printf("\nLettre trouvée !\n");
        printf("Les lettres restantes :\n");

        for (i = 0; i < nombreLettresMotCache; i++) {
            printf("%c", nouveauMotCache[i]);
        }
    }
}