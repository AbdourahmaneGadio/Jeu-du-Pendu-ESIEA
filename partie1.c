#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//Fonction pour choisir un mot au hasard

const char *choixmot(const char *mots[], int size, int longu) {
    const char *motsecret;
    switch (longu) {
        case 0:
            do {
                int randomIndex = rand() % size;
                motsecret = mots[randomIndex];
            } while (strlen(motsecret) > 5);
            break;
        case 1:
            do {
                int randomIndex = rand() % size;
                motsecret = mots[randomIndex];
            } while (strlen(motsecret) < 6 || strlen(motsecret) > 8);
            break;
        case 2:
            do {
                int randomIndex = rand() % size;
                motsecret= mots[randomIndex];
            } while (strlen(motsecret) < 9);
            break;
    }
    return motsecret;
}

int main() {

    srand(time(NULL));

    const char *plantes[] = {
            "rose",
            "tulipe",
            "jonquille",
            "orchidee",
            "lilas",
            "jasmin",
            "tournesol",
            "iris",
            "lavande",
            "pissenlit",
            "fougere",
            "marguerite",
            "cactus",
            "baobab",
            "basilic",
            "menthe",
            "thym",
            "romarin",
            "bambou",
            "myosotis",
            "camelia",
            "hibiscus",
            "pivoine",
            "gerbera",
            "chrysantheme"
    };

    const char *fruits[] = {
            "pomme",
            "banane",
            "kiwi",
            "peche",
            "poire",
            "abricot",
            "orange",
            "clementine",
            "nectarine",
            "datte",
            "grenade",
            "figue",
            "raisin",
            "litchi",
            "kaki",
            "prune",
            "mangue",
            "coing",
            "fraise",
            "framboise",
            "myrtille",
            "mure",
            "pamplemousse",
            "ananas",
            "pastheque"
    };

    const char *animaux[] = {
            "elephant",
            "lion",
            "tigre",
            "guepard",
            "gazelle",
            "giraffe",
            "zebre",
            "cheval",
            "panthere",
            "buffle",
            "vipere",
            "pyhton",
            "boa",
            "rhinoceros",
            "hippopotame",
            "chat",
            "chien",
            "loup",
            "souris",
            "rat",
            "fourmie",
            "araignee",
            "abeille",
            "guepe",
            "mouche"
    };

    const char *astronomie[] = {
            "soleil",
            "mercure",
            "venus",
            "terre",
            "mars",
            "jupiter",
            "saturne",
            "uranus",
            "neptune",
            "pluton",
            "eris",
            "ceres",
            "makemake",
            "haumea",
            "lune",
            "phobos",
            "deimos",
            "ganymede",
            "callisto",
            "io",
            "europe",
            "titan",
            "rhea",
            "desdemone",
            "hippocampe"
    };


    const char *categories[] = {
            plantes,
            fruits,
            animaux,
            astronomie
    };


    const char categoriesNom[5][50] = {
            "plantes",
            "fruits",
            "animaux",
            "astronomie",
            "Toutes categories confondues"
    };


    const char longueur[4][50] = {
            "2 a 5 lettres",
            "6 a 8 lettres",
            "9 lettres ou plus",
            "aleatoire",
    };


    int categ;
    int categRentree;
    printf("\nChoisissez une categorie:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d. %s\n", i+1, categoriesNom[i]);
    }
    printf("\nEntrez le numero de la categorie: ");
    scanf("%d", &categRentree);
    while (categRentree < 1 || categRentree > 5) {
        printf("Choix invalide\nVeuillez choisir un chiffre entre 1 et 5: ");
        scanf("%d", &categRentree);
    }
    if (categRentree != 5) {
        categ = categRentree - 1;
        printf("\nLa categorie est %s.\n", categoriesNom[categ]);
    } else {
        categ = rand() % 4;
        printf("\nFaisons confiance au hasard!\n");
    }




    int longu;
    int longuRentree;
    printf("\nChoisissez la longueur du mot:\n");
    for (int i = 0; i < 4; ++i) {
        printf("%d. %s\n", i+1, longueur[i]);
    }
    printf("\nEntrez le numero correspondant a la longueur souhaitee: ");
    scanf("%d", &longuRentree);
    while (longuRentree < 1 || longuRentree > 4) {
        printf("Choix invalide\nVeuillez choisir un chiffre entre 1 et 4: ");
        scanf("%d", &longuRentree);
    }
    if (longuRentree != 4) {
        longu = longuRentree - 1;
    } else {
        longu = rand() % 3;
    }
    printf("\nLa longueur choisie est %s.\n", longueur[longu]);



    const char *motsecret  = choixmot(categories[categ],25, longu);



}


