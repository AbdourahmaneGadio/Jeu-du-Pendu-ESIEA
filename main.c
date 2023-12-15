// Jeu du pendu
#include <stdio.h>
#include "fonctions/devinetteMot.c"
#include "fonctions/choixMot.c"
#include "fonctions/fenetreRaylib.c"

int main() {

// Le choix du type de version du pendu
    int choix = 0;

// Tant que l'on a pas choisi
    while (choix == 0) {

        printf("Comment voulez vous jouer au jeu ?\n\n");
        printf("---------------------------------------------------\n");
        printf("Appuyez sur 1 pour la version ligne de commande\n");
        printf("Appuyez sur 2 pour la version graphique\n");
        printf("---------------------------------------------------\n");

        scanf("%d", &choix);

// Tant que l'on n'a ni choisi 1 ou 2
        while (choix != 1 && choix != 2) {
            printf("Entrée incorrecte.\n\n");
            printf("---------------------------------------------------\n");
            printf("Appuyez sur 1 pour la version ligne de commande\n");
            printf("Appuyez sur 2 pour la version graphique\n");
            printf("---------------------------------------------------\n");

            scanf("%d", &choix);
        }

        // On choisit le jeu du pendu en ligne de commande
        if (choix == 1) {

            printf("\nLancement du pendu en ligne de commande...\n\n");


            // On prend un mot au hasard à trouver
            char *mot = choixMot();


            // Le pendu en lui-même
            devinetteMot(mot);
        }

            // On choisit le jeu du pendu en interface graphique
        else if (choix = 1) {

            printf("\nLancement du pendu en mode graphique...\n\n");

            // Fenêtre raylib
            fenetreRaylib();
        }

    }


}