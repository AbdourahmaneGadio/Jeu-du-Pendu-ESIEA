// Jeu du pendu
#include <stdio.h>
#include "fonctions/devinetteMot.c"
#include "fonctions/choixMot.c"
#include "fonctions/fenetreRaylib.c"

int main() {

    // Fenêtre raylib
    fenetreRaylib();

    // On prend un mot au hasard à trouver
    char *mot = choixMot();

    // Le pendu en lui-même
    devinetteMot(mot);


}