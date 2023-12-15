#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
//void du pendu
void pendu(int w)
{
    switch (w)
    {
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
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("-----\n");
            break;
        case 1:
            printf("-----------------------\n");
            printf(" |             |\n");
            printf(" |             o\n");
            printf(" |           -----\n");
            printf(" |             /\\\n");
            printf("-----\n");
            break;
    }
}
// fonction qui permet de limiter le faite d'utiliser d'autres caractère que l'alphabet
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
    int c;


    char joueur[100];

    int score = 0;
    char continu = 'o';
    while(continu != 'n')
    {
        //variable du score
        // grand dictionnaire. à améliorer
        char *capitaine[] = {"BYAKUYA", "KYORAKU", "MAYURI"};
        char *viceCapitaine[] = {"IZURU", "SHUHEI", "RENJI"};
        char *sansGrade[] = {"ICHIGO", "AIZEN", "ISSHIN"};

        char *espada[] = {"GRIMMJOW", "ULQUIORRA", "STARRK"};
        char *simpleArrancar[] = {"CIRUCCI", "DORDONIE", "ILLFORT"};

        char **shinigami[] = {capitaine, viceCapitaine, sansGrade};
        char **arrancar[] = {espada, simpleArrancar};
        char ***race[] = {shinigami, arrancar};

        // code qui permet de choisir un nombre aléatoire et a les afféctés dans différente variables
        srand(time(NULL));

        int nombreAleatoire1 = rand() % 2;
        int nombreAleatoire2 = rand() % 2;
        int nombreAleatoire3 = rand() % 3;

        //mot long relié et affectation des différentes aléatoire
        char mot[100];
        strcpy(mot, race[nombreAleatoire1][nombreAleatoire2][nombreAleatoire3]);

        //longueur du mot
        size_t longueur = strlen(mot);

        //devinette la variable du pendu. une variable ou il y aura autant de - que de lettre qui compose $mot
        char devinette[longueur - 1];

        // l'entré utilisateur
        char motus;


        for (int i = 0; i < longueur; i++) {
            devinette[i] = '-';
        }

        devinette[longueur] = '\0';

        //le nombre de vie
        int vie = 7;
        char lettre[100];
        size_t longueur2 = strlen(lettre);
        // la boucle de jeu
        while (vie > 0)
        {
            //lettre est la variable des mauvaise lettre et a une grande longueur


            //un boolean k pour faux et o pour vrai. elle servira a voir si la lettre a deja etait rentré
            char place = 'k';

            //un petit etat des lieu du jeux. cad le nmbre de vie, les trou du mot et le pendu
            printf("il te reste %d", vie);
            printf("essai\n");
            printf("%s\n", devinette);
            pendu(vie);
            //l'entré utilisateur
            motus = getchar();

            //verification de la lettre. Si c'est de l'alphabet, si elle est bonne ou fausse, si elle a déjà était utilisé
            if (verification(motus) == 'o')
            {

                //conversion de la lettre en majuscule
                char majuscule = toupper(motus);

                //problème d'affichage. le code d'entré s'afficher 2 fois
                while ((c = getchar()) != '\n' && c != EOF);

                //affectation de la lettre à devinette et retiré le -
                for (int j = 0; j < longueur; j++)
                {
                    if (majuscule == mot[j])
                    {
                        devinette[j] = majuscule;
                        place = 'o';
                    }
                }

                //si la lettre est fausse
                if (place == 'k') {
                    //verifier si elle a déjà était rentré en verifiant le tableau $lettre.
                    for (int k = 0; k <= longueur2; k++) {
                        //empeché le fait de perdre une vie
                        if (lettre[k] == majuscule) {
                            printf("vous avez deja saisi ce caractere\n");
                            place = 'o';
                            break;
                        }
                    }
                    //si la lettre n'a jamais était rentré, affectation de la lettre dans $lettre
                    if (place == 'k') {
                        strcat(lettre, &majuscule);
                        vie -= 1;
                    }
                }

                //sortir de la fonction si le mot est bon
                int resultat = strcmp(devinette, mot);
                if (resultat == 0)
                {
                    printf("\nbravo\n");
                    score = score + 1;
                    vie = 0;
                }
            }
                //ne pas perdre de vie si tu mets 1 % ou !
            else
            {
                printf("saisi non valide\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }

        }

        //retour du vrai mot
        printf("%s",mot);
        //impression du score
        printf("\ntu es a %d", score);
        printf(" points.\n");
        lettre[0] = '\0';
        //impression du mot
        printf("voulez vous continuer? \nsi vous voulez arretez, appuyez sur n\n");
        continu = getchar();


    }

    printf("Bye Bye");
    return 0;
}