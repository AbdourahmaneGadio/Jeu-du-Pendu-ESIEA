#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
 * Prend le mot sélectionné au hasard, et compte le nombre de points.
 * Retire un essai à chaque faute, jusqu'à ce que le score atteigne 0
 *
 * ENTREE : le mot sélectionné au hasard
 * SORTIE : rien
 */
void devinetteMot(char *mot) {

  // On prend le mot, et on donne la longueur de celui-ci
  size_t longueur = strlen(mot);
  char devinette[longueur - 1];

  int nombreEssais = 6;
  int lettreTrouvee = 1; // 0 si on la trouve, 1 si on ne la trouve pas

  char motus;

  /*
   * On ajout des tirets au mot à deviner
   * Ex : _ _ _ _ pour un mot à 4 caractères
   */
  for (int i = 0; i < longueur; i++) {
    devinette[i] = '-';
  }

  devinette[longueur] = '\0';

  // Tant que l'on a pas perdu
  while (nombreEssais > 0) {
    pendu(nombreEssais);

    printf("Il te reste %d essais\n", nombreEssais);
    printf("%s\n", devinette);

    // On demande à l'utilisateur d'entrer une lettre
    motus = getchar();

    // On convertit la lettre en MAJUSCULE
    char majuscule = toupper(motus);

    // On convertit la lettre en MINUSCULE
    char minuscule = tolower(motus);

    // Vider le tampon d'entrée
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    // Pour chaque lettre du mot
    for (int j = 0; j < longueur; j++) {

      // Si on trouve la lettre
      if (majuscule == mot[j] || minuscule == mot[j]) {

        /*
         * On met celle-ci dans le mot à deviner
         * Ex:
         * si le mot est "Java" et qu'on entre la lettre "a",
         * alors le mot deviné sera "_a_a"
         */
        devinette[j] = majuscule;
        lettreTrouvee = 0;
      }
    }

    // Si on n'a pas trouvé la lettre
    if (lettreTrouvee == 1) {
      nombreEssais--;
    }

    // On réinitialise l'état de la lettre trouvée
    lettreTrouvee = 1;

    int resultat = strcmp(devinette, mot);

    // Si on a tout trouvé
    if (resultat == 0) {
      printf(mot);
      printf("\nBravo, vous avez gagné !\n");

      // On sort de la boucle
      break;
    }
  }

  // Si on a perdu, on affiche le mot qu'il fallait deviner
  if (nombreEssais == 0) {
    pendu(nombreEssais);
    printf("\nPerdu...\nLe mot à deviner était : %s\n", mot);
  }
}

void pendu(int w) {
  switch (w) {
  case 6:
    printf("-----\n");
    break;
  case 5:
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf("-----\n");
    break;
  case 4:
    printf("-----------------------\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf("-----\n");
    break;
  case 3:
    printf("-----------------------\n");
    printf(" |             |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf("-----\n");
    break;
  case 2:
    printf("-----------------------\n");
    printf(" |             |\n");
    printf(" |             o\n");
    printf(" |              \n");
    printf(" |             \n");
    printf("-----\n");
    break;
  case 1:
    printf("-----------------------\n");
    printf(" |             |\n");
    printf(" |             o\n");
    printf(" |             |\n");
    printf(" |              \n");
    printf("-----\n");
    break;
  case 0:

    printf("-----------------------\n");
    printf(" |             |\n");
    printf(" |             o\n");
    printf(" |            \\|/\n");
    printf(" |             |\n");
    printf(" |            / \\ \n");
    printf("-----\n");
    break;
  }
}
