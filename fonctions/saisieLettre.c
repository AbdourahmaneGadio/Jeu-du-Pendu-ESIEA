#include <stdio.h>

// Librairie nous permettant de comparer des types
#include <ctype.h>

/* Récupère la saisie de l'utilisateur,
 * et retourne la lettre choisie
 *
 * ENTREE : rien
 * SORTIE : la lettre sélectionnée
 */
char saisieLettre(){

    // On attend la saisie
    printf("\nEntrez votre lettre...\n");
    char lettreChoisie = ' ';

    scanf(" %c", &lettreChoisie);

    // Tant que la valeur saisie n'est pas un caractère
    while( isalpha(lettreChoisie) == 0 )  {
        printf("\nLe format n'est pas correct, veuillez entrer UNIQUEMENT une lettre\n");
        scanf(" %c", &lettreChoisie);
    }

    return lettreChoisie;
}