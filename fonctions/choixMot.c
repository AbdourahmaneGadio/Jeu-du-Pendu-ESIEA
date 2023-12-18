#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
 * Sélectionne un mot au hasard parmi ceux définis dans la fonction
 *
 * ENTREE : rien
 * SORTIE : le mot choisi au hasard
 */
char *choixMot() {

    // Les mots que l'on a défini pour le jeu
    char *capitaine[] = {"BYAKUYA", "KYORAKU", "MAYURI"};
    char *viceCapitaine[] = {"IZURU", "SHUHEI", "RENJI"};
    char *sansGrade[] = {"ICHIGO", "AIZEN", "ISSHIN"};

    char *espada[] = {"GRIMMJOW", "ULQUIORRA", "STARRK"};
    char *simpleArrancar[] = {"CIRUCCI", "DORDONIE", "ILLFORT"};

    char **shinigami[] = {capitaine, viceCapitaine, sansGrade};
    char **arrancar[] = {espada, simpleArrancar};
    char ***race[] = {shinigami, arrancar};

    // La taille du mot
    int tailleMot = 100;

    // Initialise le générateur de nombres aléatoires avec le temps actuel
    srand(time(NULL));

    // Génère des nombres aléatoires entre 0 et 2 (indices valides pour les tableaux)
    int nombreAleatoire1 = rand() % 2;  // shinigami ou arrancar
    int nombreAleatoire2 = rand() % 2;  // capitaine, viceCapitaine, sansGrade ou espada, simpleArrancar
    int nombreAleatoire3 = rand() % 3;  // noms individuels

    // Copie le nom correspondant dans mot
    char mot[tailleMot]; // ajustez la taille selon vos besoins
    strcpy(mot, race[nombreAleatoire1][nombreAleatoire2][nombreAleatoire3]);

    // Variable pour stocker le mot
    char *motPourLeJeu = malloc(tailleMot);

    for (int i = 0; i < tailleMot; ++i) {
        motPourLeJeu[i] = mot[i];
    }

    // On retourne le mot
    return motPourLeJeu;

}