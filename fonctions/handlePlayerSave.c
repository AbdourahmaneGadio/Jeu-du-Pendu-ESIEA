#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Player {
  char name[15];
  int score;
};

int handlePlayerSave(char statutJoueur, int pseudo[], int place, int score) {

  // Ouverture du fichier en mode lecture
  // Si le fichier ne mène a rien, code annulé
  FILE *fip = fopen("scores.txt", "r");
  if (fip != NULL) {
    int indiceLigneScore;

    char joueurActuelle[10]; // Variable du joueur

    // Collection de tous les joueurs recuperés dans le fichier texte
    struct Player players[100] = {};
    char nom[5];
    int present = 0;

    // Boucle affective qui lira le fichier et le mettra
    while (fscanf(fip, "%s %d", nom, &score) != EOF && indiceLigneScore < 100) {
      struct Player player = {0};
      strcpy(player.name, nom);
      player.score = score;

      players[indiceLigneScore] = player;
      indiceLigneScore++;
    }

    // On ferme le fichier pour l'instant.
    // On le rouvrira pour modifier le classement
    fclose(fip);

    // Connexion au joueur
    char ancien = statutJoueur;

    for (int i = 0; i < 5; ++i) {
      joueurActuelle[i] = toupper((char)pseudo[i]);
    }

    // On détecte si le pseudo fait bien parti des anciens joueurs
    for (int i = 0; i < 100; ++i) {
      if (strcmp(players[i].name, joueurActuelle) == 0) {
        present = 1;
        place = i;
        break;
      }
    }

    // Si ancien joueur
    if (ancien == 'o') {

      // Si on trouve rien
      if (present == 0) {
        printf("Ancien joueur pseudo incorrect");
        present = 2;
      }

      // Si on retrouve le profil
      else {
        printf("Ancien joueur pseudo valide");
        present = 1;
      }

    }

    // Nouveau joueur
    else if (ancien == 'n') {

      // Si on ne trouve rien
      if (present == 0) {
        present = 1;
        printf("Nouveau joueur à ajouter");
        struct Player newPlayer = {};
        strcpy(newPlayer.name, joueurActuelle);
        newPlayer.score = 0;
        players[99] = newPlayer;
      }

      // Si le nom est pris par un autre joueur
      else if (present == 1) {
        printf("Nom déjà pris.");
        present = 2;
      }
    }

    return present;

  } // Si le fichier existe

  else {
    return 3; // 3 représente une erreur de fichier
  }
}

/*
int main() {
    char statutJoueur = 'n';
    int pseudo[5] = {65, 65, 65, 65, 65};int numeroPlace;int points;
    handlePlayerSave(statutJoueur, pseudo, numeroPlace, points);
    }

   */