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
//collection de joueur
struct Player
{
    char name[15];
    int score;
};

int main()
{
    //temps pour l'aleatoire
    srand(time(NULL));

    //dictionnaire
    char *plantesF[] ={"ROSE","TULIPE","ORCHIDEE", "LYS", "TOURNESOL", "IRIS", "MARGUERITE", "JASMIN"};
    char *plantesM[] ={"PIVOINE", "HORTENESIA", "LAVANDE", "CAMELIA", "HIBISCUS", "CHRYSANTHEME", "JONQUILLE", "MENTHE"};
    char *plantesD[] = {"ROMARIN",  "MYOSOTIS", "FOUGERE", "PISSENLIT", "BASILIC", "BAMBOU", "CACTUS", "BAOBAB"};

    char **plantes[] = {plantesF, plantesM, plantesD};

    char *fruitsF[] = {"BANANE","POMME","ORANGE","FRAISE","RAISIN","POIRE","KIWI","MANGUE"};
    char *fruitsM[] = {"PECHE","ABRICOT","CERISE","GRENADE","CITRON","NECTARINE","MURE","FRAMBOISE"};
    char *fruitD[] = {"LITCHI","KAKI","PRUNE","DATTE","FIGUE","CLEMENTINE","COING","PASTEQUE"};

    char **fruits[] = {fruitsF, fruitsM, fruitD};


    char *animauxF[] = {"CHIEN", "CHAT","CHEVAL","LION","TIGRE","ELEPHANT","LOUP","GIRAFE"};
    char *animauxM[] = {"PANTHERE","GAZELLE","RHINOCEROS","HIPPOPOTAME","BUFFLE","GUEPARD","VIPERE","BOA",};
    char *animauxD[] = {"RAT","FOURMI","ARAIGNEE","ABEILLE","GUEPE","MOUCHE", "SOURIS", "ZEBRE"};

    char **animaux[] = {animauxF, animauxM, animauxD};


    char *astronomieF[] = {"SOLEIL","LUNE","MERCURE","VENUS","TERRE","MARS","JUPITER","IO"};
    char *astronomieM[] = {"PLUTON","ERIS","CERES","MAKEMAKE","PHOBOS","DEIMOS","GANYMEDE","CALLISTO",};
    char *astronomieD[] = {"EUROPE","TITAN","RHEA","LAPPETUS","DIONE", "SATURNE","URANUS","NEPTUNE"};

    char **astronomie[] = {astronomieF, astronomieM, astronomieD};

    char ***categories[] = {plantes,fruits,animaux,astronomie};


    //ouverture du fichier en mode lecture
    //si le fichier ne mène a rien, code annulé
    FILE *fip = fopen("scores.txt", "r");
    if (fip == NULL) {
        return 1;
    }


    int d; //variable de recuperation de joueur provenant du fichier
    int c; //variable c utile pour le while qui empêche la lecture du retour a la ligne
    char joueurActuelle[10];//variable du joueur
    struct Player players[100] = {}; //collection de tout les joeurs recuperer dans le fichier text
    char nom[10];//nom du joueur connecter
    int present = 0;//variable de verification si deja present comme joueur
    int game = 0;//variable qui autorise le debut du jeu
    int score;// score du joueur connecter
    int place;//variable pour definir la place au classement d'un jour

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
                //variable pour savoir si le joueur est un ancien ou un nouveau joueur
                printf("Etes vous un ancien joueur? o pour oui n pour non\n");
                ancien = getchar();
                //1er utilisation du suppresseur de retour a la ligne
                while ((c = getchar()) != '\n' && c != EOF);
                //boucle oblicatoire où l'on peut sortir uniquement par aprobation de l'ordinateur
                while (game != 1)
                {
                    //saisie du nom du joueur
                    printf("Veillez saisir votre nom de joueur: (maximum 10 lettre pas d'importance entre minuscule et majuscule)\n");
                    scanf("%s", joueurActuelle);

                    while ((c = getchar()) != '\n' && c != EOF);
                    //majuculisation du nom
                    for (int i = 0; i < 11; ++i)
                    {
                        joueurActuelle[i] = toupper(joueurActuelle[i]);
                    }

                    //verification
                    for (int i = 0; i < 100; ++i)
                    {
                        if (strcmp(players[i].name, joueurActuelle) == 0)
                        {
                            present = 1;
                            place = i;
                            break;
                        }
                    }


                    //si ancien alors il peut pas utiliser un nom non existant
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
                    //si nouveau ne peut utiliser un nom deja present
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

                int continuite = 0;//variable qui augmente pendant le jeu. Utilse pour la prochaine variable
                char lettreDejaSaisi[] = "-------";//variable des lettre deja saisie
                //choix du theme
                printf("quel theme voulez vous prendre pour jouer ?\n 1: plante\n 2: fruits \n 3: animaux \n 4: astronomie\n 5: aleatoire\n");
                char t = getchar();
                while ((c = getchar()) != '\n' && c != EOF);
                //choix de la difficulte
                printf("choisissez une difficultes.\n 1: facile\n 2: moyen\n 3: difficile\n 4: aleatoire\n");
                char d = getchar();
                while ((c = getchar()) != '\n' && c != EOF);
                //f1 et f2 qui vont se connecter au dictionnaire selon le resulta
                int f1;
                int f2;

                switch (t)
                {
                    case '1':
                        f1 = 0;
                        break;
                    case '2':
                        f1 = 1;
                        break;
                    case '3':
                        f1 = 2;
                        break;
                    case '4':
                        f1 = 3;
                        break;
                    default:
                        f1 = rand() %4;
                }
                int barem;
                switch (d) {
                    case '1': {
                        f2 = 0;
                        break;
                    }
                    case '2': {
                        f2 = 1;
                        break;
                    }
                    case '3': {
                        f2 = 2;
                        break;
                    }
                    default: {
                        f2 = rand() % 3;
                        break;
                    }
                }

                //initialisation du mot a deviner
                char mot[20];
                //affectation du mot du dictionnaire
                strcpy(mot, categories[f1][f2][rand()%7]);
                size_t longueur = strlen(mot);//longueur du mot
                char devinette[longueur];//variable de l'avance du mot.
                for (int i = 0; i < longueur; ++i) {
                    devinette[i] = '-';
                }
                //annulation des caractere allant de la fin du mot a la fin de la variable
                devinette[longueur] = '\0';

                int vie = 7;//nombre de vie

                //boucle de partie
                while (vie > 0)
                {
                    printf("\nnombre de vie: %d\n", vie);//nombre de vie actuelle
                    printf("\n avance de votre jeu: %s\n", devinette);//avance de jeu
                    //saisie de la lettre
                    char lettre = getchar();
                    char majuscule = toupper(lettre);//majusculisation de la lettre saisie
                    int dejaSaisi = 0; //variable pour verifier si la lettre a deja etait saisi
                    int dansMot = 0;// variable pour savoir si la lettre est deja dans le mot
                    size_t longueur2 = strlen(lettreDejaSaisi); //longueur de lettre deja saisi. utile pour une prochaine boucle
                    while ((c = getchar()) != '\n' && c != EOF);
                    char vrai = verification(lettre); //voir si la lettre fait partie de l'alphabet
                    //si oui
                    if (vrai == 'o')
                    {
                        //modification des pointillet
                        for (int i = 0; i <= longueur; i++) {
                            if (mot[i] == majuscule) {
                                devinette[i] = majuscule;
                                dansMot = 1;
                            }
                            //
                            else if (mot[i] != majuscule)
                            {
                                //verification si la lettre a deja etait saisi
                                for (int i = 0; i <= longueur2; i++)
                                {

                                    if (lettreDejaSaisi[i] == majuscule) {
                                        dejaSaisi = 1;
                                        break;
                                    }
                                }

                                //si la lettre n'a pas etait saisie
                                if (dejaSaisi == 0)
                                {
                                    //entre dans le tableau des lettre deja saisie
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

                                    //perte d'une vie si lettre n'est pas dans mot ou dans dejasaisie
                                    if (dansMot == 0) {
                                        lettreDejaSaisi[continuite] = majuscule;
                                        continuite += 1;
                                        vie -= 1;
                                        pendu(vie);
                                    }
                                }
                            }
                        }

                        //verification si le mot est egal au pointier
                        int verification = strcmp(devinette, mot);
                        //si le mot a etait deviner (il n'y a plus de pointier
                        if (verification == 0)
                        {
                            //victoire et bareme selon la difficulte
                            printf("Victory\n");
                            if(f2 == 0)
                            {
                                score += 3;
                            }
                            else if(f2 == 1)
                            {
                                score += 5;
                            }
                            else if(f2 == 2)
                            {
                                score += 10;
                            }
                            //retour du score qui va etre ajouter au joueur une fois deconnecte
                            printf("%d\n", score);
                            //le break nous ramenera directement en ligne 395
                            break;
                        }
                        //retour des lettre deja saisi
                        printf("lettre deja saisi: ");
                        for (int j = 0; j < continuite; j++)
                            printf("%c", lettreDejaSaisi[j]);

                    }
                    //si lettre ne fait pas partie de l'alphabet
                    else if (vrai == 'k')
                    {
                        printf("saisi non valide\n");
                    }
                }
                //retour du mot
                printf("Le mot etait: %s\n", mot);
                //rester sur la meme session
                printf("Voulez-vous continuer sur le meme compte? n pour non\n");
                char continu = getchar();// variable de continuite
                while ((c = getchar()) != '\n' && c != EOF);
                if (continu == 'n')
                {
                    break; //nous fait aller directement ligne 407
                }

            }
            //affectation du score selon s'il est ancien ou nouveau(entre dans le classement ou modification d'un deja present
            if(ancien == 'o')
            {
                players[place].score += score;
            }
            else if(ancien == 'n')
            {
                players[99].score += score;
            }
            //reclassement
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
            //affichage du classement actuelle
            for (int i = 0; i < 10; i++)
            {
                printf("%d: ", i + 1);
                printf( "%s %d\n", players[i].name, players[i].score);
            }
            //se connecter a une autre session
            printf("Voulez vous continuer sur un autre nom? n pour non\n");
            char continu = getchar();
            while ((c = getchar()) != '\n' && c != EOF);
            if(continu == 'n')
            {
                break;//nous fait aller ligne 446
            }
        }
        //voir s'il veut quitter completement le jeu
        printf("Voulez vous continuer a jouer?");
        char last = getchar();
        if(last == 'n')
            break;

    }
    //reouverture du fichier score en mode ecriture cette fois
    fip = fopen("scores.txt", "w");

    //modification de son contenue
    for (int i = 1; i < 100; i++)
    {
        fprintf(fip, "%s %d\n", players[i].name, players[i].score);
    }

    //bonne soiree
    printf("Bye Bye");
    fclose(fip);
    return 0;
}

