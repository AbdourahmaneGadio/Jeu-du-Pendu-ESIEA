#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct PlayerScore {
  char name[15];
  int score;
};

void addScorePlayer(char statutJoueur, int placeJoueur, int nom[],
                    int scoreTotal) {

  int indiceLigneScore;
  int score;
  char nouveauNom[5];
  char nomTraduitEnChar[5];

  for (int i = 0; i < 5; ++i) {
    nomTraduitEnChar[i] = (char)nom[i];
  }

  FILE *fip = fopen("scores.txt", "r");

  if (fip != NULL) {

    // Collection de tous les joueurs recuperés dans le fichier texte
    struct PlayerScore players[100] = {};

    // Nouvelle liste pour la réorganisation du score
    struct PlayerScore newPlayerList[100] = {};

    int c;
    // Boucle affective qui lira le fichier et le mettra
    while (fscanf(fip, "%s %d", nouveauNom, &score) != EOF &&
           indiceLigneScore < 100) {

      struct PlayerScore player = {"empty", 0};
      strcpy(player.name, nouveauNom);
      player.score = score;

      players[indiceLigneScore] = player;

      indiceLigneScore++;
    }

    // verification
    for (int i = 0; i < 100; ++i) {

      int pseudoTrouve = 0;

      // Pour chaque lettre du pseudo (solution car bug de dédoublage des
      // lettres)
      for (int j = 0; j < 5; j++) {

        if (players[i].name[j] == nomTraduitEnChar[j]) {
          pseudoTrouve = 1;
        }

        if (j == 4 && pseudoTrouve == 1) {
          placeJoueur = i;
          break;
        }
      }
    }

    if (statutJoueur == 'o') {
      players[placeJoueur].score += scoreTotal;

      for (int i = 0; i < 5; i++) {
        players[placeJoueur].name[i] = nomTraduitEnChar[i];
      }

    } else if (statutJoueur == 'n') {
      placeJoueur = 99;
      players[placeJoueur].score += scoreTotal;

      for (int i = 0; i < 5; i++) {
        players[placeJoueur].name[i] = nomTraduitEnChar[i];
      }
    }

    printf("Nom joueur : %s\n", players[placeJoueur].name);

    // Pour chaque ligne
    for (int i = 0; i <= 100; ++i) {

      // Pour chaque colonne
      for (int j = 0; j <= 100; j++) {
        if (players[j].score < players[j + 1].score) {
          newPlayerList[100] = players[j];
          newPlayerList[j] = players[j + 1];
          newPlayerList[j + 1] = players[100];
        }
      }
    }

    fip = fopen("scores.txt", "w");
    for (int i = 1; i < 100; i++) {

      fprintf(fip, "%s %d\n", newPlayerList[i].name, newPlayerList[i].score);
    }
  }

  fclose(fip);
}

/*
int main() {
  char statutJoueur = 'o';
  int pseudo[5] = {65, 65, 65, 65, 65};
  int numeroPlace;
  int points = 7;
  addScorePlayer(statutJoueur, numeroPlace, pseudo, points);
}

*/