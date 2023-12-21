#include <string.h>
#include <stdlib.h>
#include <time.h>

//Fonction pour choisir un mot au hasard
//A FAIRE: choix de mot selon difficulte

char *choixmot(char (*mots)[20], int size) {
    int randomIndex = rand() % size;
    return mots[randomIndex];
}


char *choixMotRaylib(int choixCategorie) {

    srand(time(NULL));

    char *motsecret;

    char plantes[25][20] = {
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

    char fruits[25][20] = {
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

    char animaux[25][20] = {
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

    char astronomie[25][20] = {
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
           "japet",
           "dione"
           };

    switch (choixCategorie) {
        case 1:
            motsecret = choixmot(plantes, 25);
            break;
        case 2:
            motsecret = choixmot(fruits, 25);
            break;
        case 3:
            motsecret = choixmot(animaux, 25);
            break;
        case 4:
            motsecret = choixmot(astronomie, 25);
            break;
    }

    // La taille du mot
    size_t tailleMot = strlen(motsecret);

    // Variable pour stocker le mot
    char *motPourLeJeu = malloc(tailleMot);

    for (int i = 0; i < tailleMot; ++i) {
        motPourLeJeu[i] = toupper(motsecret[i]);
    }

    // On retourne le mot
    return motPourLeJeu;


}


