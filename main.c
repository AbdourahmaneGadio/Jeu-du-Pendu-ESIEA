// Jeu du pendu
#include "fonctions/choixMot.c"
#include "fonctions/devinetteMot.c"
#include "fonctions/fenetreRaylib.c"
#include <stdio.h>

int main() {

  // Le choix du type de version du pendu
  int choix = 0;

  int theme = 0;
  int difficulte = 0;

  int score = 0;
  int place = 0;
  char statutJoueur = 'n';
  char joueurActuelle[10]; // variable du joueur
  // Pseudo par défaut avec que des "A"
  // A vaut 65 en ASCII
  int pseudo[5] = {65, 65, 65, 65, 65};
  int present = 0; // variable de verification si deja present comme joueur

  int c; // Utilisé pour vider le tampon

  // Tant que l'on a pas choisi
  while (choix == 0) {

    printf("Comment voulez vous jouer au jeu ?\n\n");
    printf("---------------------------------------------------\n");
    printf("Appuyez sur 1 pour la version ligne de commande\n");
    printf("Appuyez sur 2 pour la version graphique\n");
    printf("---------------------------------------------------\n");

    scanf("%d", &choix);

    // On choisit le jeu du pendu en ligne de commande
    if (choix == 1) {

      printf("\nLancement du pendu en ligne de commande...\n\n");

      // variable pour savoir si le joueur est un ancien ou un nouveau joueur
      printf("Etes vous un ancien joueur ? [o/n] \n");
      statutJoueur = getchar();
      // 1er utilisation du suppresseur de retour a la ligne
      while ((c = getchar()) != '\n' && c != EOF)
        ;

      printf("Veillez saisir votre nom de joueur: (10 lettres maximum )\n");
      scanf("%s", joueurActuelle);

      while ((c = getchar()) != '\n' && c != EOF)
        ;
      // On met le nom en majuscule
      for (int i = 0; i < 11; ++i) {
        pseudo[i] = (int)joueurActuelle[i];
      }

      handlePlayerSave(statutJoueur, pseudo, place, score);

      // Le jeu du pendu en lui-même pendu en lui-même
      while (1) {

        printf("Choisissez un thème : \n");
        printf("0: Plantes\n");
        printf("1: Fruits\n");
        printf("2: Animaux\n");
        printf("3: Astronomie\n");

        scanf("%d", &theme);

        printf("Choisissez une difficulté : \n");
        printf("0: Facile\n");
        printf("1: Moyenne\n");
        printf("2: Difficile\n");

        scanf("%d", &difficulte);

        // On prend un mot au hasard à trouver
        char *mot = choixMotRaylib(theme, difficulte);

        score += devinetteMot(mot, difficulte);

        printf("Votre score : %d\n", score);

        addScorePlayer(statutJoueur, place, pseudo, score);

        printf("Voulez-vous continuer à jouer ? [o/n]\n");
        char continu = getchar(); // variable de continuite
        while ((c = getchar()) != '\n' && c != EOF) {
        };
        if (continu == 'n') {
          printf("Bye bye !\n");
          break;
        }
      } // Boucle infinie
    }   // Si on choisit le jeu en ligne de commande

    // On choisit le jeu du pendu en interface graphique
    else if (choix == 2) {

      printf("\nLancement du pendu en mode graphique...\n\n");

      // Fenêtre raylib
      fenetreRaylib();
    }

    else {

      printf("Entrée incorrecte.\n\n");
      printf("Sortie du programme.\n");
    }
  }
}