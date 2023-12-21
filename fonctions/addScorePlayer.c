#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct PlayerScore {
  char name[15];
  int score;
};

void addScorePlayer(char statutJoueur, int placeJoueur, int nom[], int score) {

  int indiceLigneScore;
  char nouveauNom[5];

  for (int i = 0; i < 5; ++i) {
    nouveauNom[i] = (char)nom[i];
  }

  FILE *fip = fopen("scores.txt", "r");

  if (fip != NULL) {

    // Collection de tous les joueurs recuperés dans le fichier texte
    struct PlayerScore players[100] = {};

    // Boucle affective qui lira le fichier et le mettra
    while (fscanf(fip, "%s %d", nouveauNom, &score) != EOF &&
           indiceLigneScore < 100) {
      struct PlayerScore player = {0};
      strcpy(player.name, nouveauNom);
      player.score = score;

      players[indiceLigneScore] = player;
      indiceLigneScore++;
    }

    if (statutJoueur == 'o') {
      players[placeJoueur].score += score;
    } else if (statutJoueur == 'n') {
      players[99].score += score;
    }
    for (int i = 0; i <= 100; ++i) {
      for (int j = 0; j <= 100; j++) {
        if (players[j].score < players[j + 1].score) {
          players[100] = players[j];
          players[j] = players[j + 1];
          players[j + 1] = players[100];
        }
      }
    }

    fip = fopen("scores.txt", "w");

    for (int i = 1; i < 100; i++) {
      
        fprintf(fip, "%s %d\n", players[i].name, players[i].score);
      
    }
  }

  fclose(fip);
}

/*
int main() {
  char statutJoueur = 'o';
  int pseudo[5] = {65, 65, 65, 65, 65};
  int numeroPlace = 99;
  int points = 6;
  addScorePlayer(statutJoueur, numeroPlace, pseudo, points);
}
*/
