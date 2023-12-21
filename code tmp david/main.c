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
    char verite = 'k';
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t longueur = strlen(alphabet);
    for(int i = 0; i <= longueur; i++)
    {
        if(s == alphabet[i])
        {
            verite = 'o';
        }

    }

    return verite;
};
struct Player
{
    char name[15];
    int score;
};

int main()
{
    //dictionnaire
    //
    //
    //
    //
    //

    //ouverture du fichier en mode lecture
    //si le fichier ne mène a rien, code annulé
    FILE *fip = fopen("scores.txt", "r");
    if (fip == NULL) {
        return 1;
    }

    int d;
    int c; //variable c utile pour le while qui empêche la lecture du retour a la ligne
    char joueurActuelle[10];//variable du joueur
    struct Player players[100] = {}; //collection de tout les joeurs recuperer dans le fichier text
    char nom[10];//nom du joueur connecter
    int present = 0;
    int game = 0;
    int score;// score du joueur connecter
    int place;



    //boucle affective qui lira le fichier et le mettra
    while (fscanf(fip, "%s %d", nom, &score) != EOF && d < 100)
    {
        struct Player player = {0};
        strcpy(player.name, nom);
        player.score = score;

        players[d] = player;
        d++;
    }


    //on ferme le fichier pour l'instant. on le rouvrira pour modifier le classement
    fclose(fip);
    //boucle d'entre de jeu
    while (1)
    {
        //boucle utilisateur
        while (1)
        {
            game = 0;
            //connexion au joueur
            char ancien = 'r';
            while (ancien == 'r')
            {
                //1er utilisation du suppresseur de retour a la ligne

                printf("Etes vous un ancien joueur? o pour oui n pour non\n");
                ancien = getchar();
                while ((c = getchar()) != '\n' && c != EOF);
                while (game != 1)
                {
                    printf("Veillez saisir votre nom de joueur: (maximum 10 lettre pas d'importance entre minuscule et majuscule)\n");
                    scanf("%s", joueurActuelle);

                    while ((c = getchar()) != '\n' && c != EOF);
                    for (int i = 0; i < 11; ++i)
                    {
                        joueurActuelle[i] = toupper(joueurActuelle[i]);
                    }

                    for (int i = 0; i < 100; ++i)
                    {
                        if (strcmp(players[i].name, joueurActuelle) == 0)
                        {
                            present = 1;
                            place = i;
                            break;
                        }
                    }


                    if (ancien == 'o')
                    {
                        if (present == 1)
                        {
                            printf("\nVous etes bien present dans la base des joueurs. Bon jeu!\n");
                            game = 1;
                        }
                        else if(present == 0)
                        {
                            printf("\nVous n'etes pas present dans la base joueur. Veuillez saisir un nom ou redemarez pour creer un nouveau joueur\n");
                            game = 0;
                        }
                    }
                    else if (ancien == 'n')
                    {

                        if (present == 0)
                        {
                            printf("\nVotre nom n'a pas encore etait utilise. Bienvenue\n");
                            struct Player newPlayer = {};
                            strcpy(newPlayer.name, joueurActuelle);
                            newPlayer.score = 0;
                            players[99] = newPlayer;
                            game = 1;
                        }
                        else if(present == 1)
                        {
                            printf("\nVotre nom est deja utiliser\n");
                            game = 0;
                            present = 0;
                        }

                    }

                }

            }
            while(1)
            {
                int continuite = 0;
                char lettreDejaSaisi[] = "-------";
                char mot[] = "BANANE";
                size_t longueur = strlen(mot);
                char devinette[longueur];
                for (int i = 0; i < longueur; ++i) {
                    devinette[i] = '-';
                }

                int vie = 7;

                //boucle de partie
                while (vie > 0) {
                    printf("\nnombre de vie: %d\n", vie);
                    printf("\n avance de votre jeu: %s\n", devinette);
                    char lettre = getchar();
                    char majuscule = toupper(lettre);
                    int dejaSaisi = 0;
                    int dansMot = 0;
                    size_t longueur2 = strlen(lettreDejaSaisi);
                    while ((c = getchar()) != '\n' && c != EOF);
                    char vrai = verification(lettre);
                    if (vrai == 'o') {
                        for (int i = 0; i <= longueur; i++) {
                            if (mot[i] == majuscule) {
                                devinette[i] = majuscule;
                                dansMot = 1;
                            } else if (mot[i] != majuscule) {
                                for (int i = 0; i <= longueur2; i++) {
                                    if (lettreDejaSaisi[i] == majuscule) {
                                        dejaSaisi = 1;
                                        break;
                                    }
                                }

                                if (dejaSaisi == 0)
                                {
                                    for (int i = 0; i <= longueur; i++)
                                    {
                                        if (mot[i] == majuscule)
                                        {
                                            lettreDejaSaisi[continuite] = majuscule;
                                            continuite += 1;
                                            dansMot = 1;
                                            break;
                                        }
                                    }
                                    if (dansMot == 0) {
                                        lettreDejaSaisi[continuite] = majuscule;
                                        continuite += 1;
                                        vie -= 1;
                                        pendu(vie);
                                    }
                                }
                            }
                        }

                        int verification = strcmp(devinette, mot);
                        if (verification == 0)
                        {
                            printf("Victory\n");
                            score += 3;
                            printf("%d", score);
                            break;
                        }
                        printf("lettre deja saisi: ");

                        for (int j = 0; j < continuite; j++)
                            printf("%c", lettreDejaSaisi[j]);

                    }
                    else if (vrai == 'k')
                    {
                        printf("saisi non valide\n");
                    }
                }

                printf("Voulez-vous continuer sur le meme compte? n pour non\n");
                char continu = getchar();
                while ((c = getchar()) != '\n' && c != EOF);
                if (continu == 'n')
                {
                    break;
                }

            }
            if(ancien == 'o')
            {
                players[place].score += score;
            }
            else if(ancien == 'n')
            {
                players[99].score += score;
            }
            for (int i = 0; i <= 100 ; ++i)
            {
                for(int j = 0; j <= 100; j++)
                {
                    if(players[j].score < players[j + 1].score)
                    {
                        players[100] = players[j];
                        players[j] = players[j+1];
                        players[j+1] = players[100];

                    }
                }
            }

            for (int i = 0; i < 10; i++)
            {
                printf("%d: ", i + 1);
                printf( "%s %d\n", players[i].name, players[i].score);
            }

            printf("Voulez vous continuer sur un autre nom? n pour non\n");
            char continu = getchar();
            while ((c = getchar()) != '\n' && c != EOF);
            if(continu == 'n')
            {
                break;
            }
        }

        printf("Voulez vous continuer a jouer?");
        char last = getchar();
        if(last == 'n')
            break;

    }
    fip = fopen("scores.txt", "w");

    for (int i = 1; i < 100; i++)
    {
        fprintf(fip, "%s %d\n", players[i].name, players[i].score);
    }

    printf("Bye Bye");
    fclose(fip);
    return 0;
}
