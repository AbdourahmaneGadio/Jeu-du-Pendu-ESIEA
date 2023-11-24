#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char verification(char s)
{
    char result = 'k';
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t longueur = strlen(alphabet);
    for(int i = 0; i <= longueur; i++)
    {
        if(s == alphabet[i])
        {
            result = 'o';
        }

    }

    return result;
};

int main() {

    char *capitaine[] = {"BYAKUYA", "KYORAKU", "MAYURI"};
    char *viceCapitaine[] = {"IZURU", "SHUHEI", "RENJI"};
    char *sansGrade[] = {"ICHIGO", "AIZEN", "ISSHIN"};

    char *espada[] = {"GRIMMJOW", "ULQUIORRA", "STARRK"};
    char *simpleArrancar[] = {"CIRUCCI", "DORDONIE", "ILLFORT"};

    char **shinigami[] = {capitaine, viceCapitaine, sansGrade};
    char **arrancar[] = {espada, simpleArrancar};
    char ***race[] = {shinigami, arrancar};

    // Initialise le générateur de nombres aléatoires avec le temps actuel
    srand(time(NULL));

    // Génère des nombres aléatoires entre 0 et 2 (indices valides pour les tableaux)
    int nombreAleatoire1 = rand() % 2;  // shinigami ou arrancar
    int nombreAleatoire2 = rand() % 2;  // capitaine, viceCapitaine, sansGrade ou espada, simpleArrancar
    int nombreAleatoire3 = rand() % 3;  // noms individuels

    // Copie le nom correspondant dans mot
    char mot[100]; // ajustez la taille selon vos besoins
    strcpy(mot, race[nombreAleatoire1][nombreAleatoire2][nombreAleatoire3]);

// Affiche le mot
    size_t longueur = strlen(mot);
    char devinette[longueur - 1];

    char motus;

    for (int i = 0; i < longueur; i++)
    {
        devinette[i] = '-';
    }

    devinette[longueur] = '\0';

    int vie = 6;

    while(vie >= 0)
    {
        char erreur[15];
        size_t longueur2 = strlen(erreur);

        char place = 'k';

        printf("il te reste %d", vie);
        printf("essai\n");
        printf("%s\n", devinette);

        motus = getchar();
        if(verification(motus) == 'o')
        {

            char majuscule = toupper(motus);
            // Vider le tampon d'entrée
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            for (int j = 0; j < longueur; j++)
            {
                if(majuscule == mot[j])
                {
                    devinette[j] = majuscule;
                    place = 'o';
                }
            }

            if(place == 'k')
            {
                for(int k = 0; k < longueur2; k++)
                {
                    if(erreur[k] == majuscule)
                    {
                        printf("vous avez dejq saisi ce caractere\n");
                        place = 'o';
                        break;
                    }
                }
                if(place == 'k')
                {
                    strcat(erreur,&majuscule);
                    vie -= 1;
                }
            }



            int resultat = strcmp(devinette, mot);
            if(resultat == 0)
            {
                printf(mot);
                printf("\nbravo\n");
                vie = 0;
            }
        }
        else
        {
            printf("saisi non valide");
        }
    }

    printf(mot);

    return 0;
}