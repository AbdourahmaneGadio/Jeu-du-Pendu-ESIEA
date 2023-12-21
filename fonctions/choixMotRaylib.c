#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *choixMotRaylib(int choixCategorie, int choixDifficulte) {

  srand(time(NULL));

  // dictionnaire
  char *plantesF[] = {"ROSE",      "TULIPE", "ORCHIDEE",   "LYS",
                      "TOURNESOL", "IRIS",   "MARGUERITE", "JASMIN"};
  char *plantesM[] = {"PIVOINE",  "HORTENESIA",   "LAVANDE",   "CAMELIA",
                      "HIBISCUS", "CHRYSANTHEME", "JONQUILLE", "MENTHE"};
  char *plantesD[] = {"ROMARIN", "MYOSOTIS", "FOUGERE", "PISSENLIT",
                      "BASILIC", "BAMBOU",   "CACTUS",  "BAOBAB"};

  char **plantes[] = {plantesF, plantesM, plantesD};

  char *fruitsF[] = {"BANANE", "POMME", "ORANGE", "FRAISE",
                     "RAISIN", "POIRE", "KIWI",   "MANGUE"};
  char *fruitsM[] = {"PECHE",  "ABRICOT",   "CERISE", "GRENADE",
                     "CITRON", "NECTARINE", "MURE",   "FRAMBOISE"};
  char *fruitD[] = {"LITCHI", "KAKI",       "PRUNE", "DATTE",
                    "FIGUE",  "CLEMENTINE", "COING", "PASTEQUE"};

  char **fruits[] = {fruitsF, fruitsM, fruitD};

  char *animauxF[] = {"CHIEN", "CHAT", "CHEVAL", "LION",
                      "TIGRE", "ELEPHANT", "LOUP", "GIRAFE"};
  char *animauxM[] = {
      "PANTHERE", "GAZELLE", "RHINOCEROS", "HIPPOPOTAME",
      "BUFFLE",   "GUEPARD", "VIPERE",     "BOA",
  };
  char *animauxD[] = {"RAT",   "FOURMI", "ARAIGNEE", "ABEILLE",
                      "GUEPE", "MOUCHE", "SOURIS",   "ZEBRE"};

  char **animaux[] = {animauxF, animauxM, animauxD};

  char *astronomieF[] = {"SOLEIL", "LUNE", "MERCURE", "VENUS",
                         "TERRE",  "MARS", "JUPITER", "IO"};
  char *astronomieM[] = {
      "PLUTON", "ERIS",   "CERES",    "MAKEMAKE",
      "PHOBOS", "DEIMOS", "GANYMEDE", "CALLISTO",
  };
  char *astronomieD[] = {"EUROPE", "TITAN",   "RHEA",   "LAPPETUS",
                         "DIONE",  "SATURNE", "URANUS", "NEPTUNE"};

  char **astronomie[] = {astronomieF, astronomieM, astronomieD};

  char ***categories[] = {plantes, fruits, animaux, astronomie};

  // La taille du mot
  int tailleMot = 100;
  char motsecret[tailleMot];

  // affectation du mot du dictionnaire
  strcpy(motsecret, categories[choixCategorie][choixDifficulte][rand() % 7]);

  // Variable pour stocker le mot
  char *motPourLeJeu = malloc(tailleMot);

  for (int i = 0; i < tailleMot; ++i) {
    motPourLeJeu[i] = toupper(motsecret[i]);
  }

  // On retourne le mot
  return motPourLeJeu;
}

/*
int main() {
  char *mot = choixMotRaylib(1, 0);
  printf("%s", mot);
}
*/
