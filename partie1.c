#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Fonction pour choisir la categorie

int choisirCategorie() {
    const char* categories[] = {
            "plantes",
            "fruits",
            "animaux",
            "astronomie",
            "toutes categories confondues"
    };

    int categ;
    printf("\nChoisissez une categorie:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d. %s\n", i+1, categories[i]);
    }
    printf("\nEntrez le numero de la categorie:  ");
    scanf("%d", &categ);
    if (categ < 1 || categ > 9) {
        printf("Choix invalide\n");
    }
    return categ;
    //A FAIRE: relier nb a liste
}


//Fonction pour choisir un mot au hasard
//A FAIRE: choix de mot selon difficulte

const char* choixmot(const char (*mots)[20], int size) {
    int randomIndex = rand() % size;
    return mots[randomIndex];
}


int main() {

    srand(time(NULL));

    const char plantes[25][20] = {
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

    const char fruits[25][20] = {
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

    const char animaux[25][20] = {
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

    const char astronomie[25][20] = {
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



    int categ = choisirCategorie();


    const char *motsecret;


    switch (categ) {
        case 1:
            motsecret = choixmot(plantes, 25);
            printf("La plante est: %s\n", motsecret);
            break;
        case 2:
            motsecret = choixmot(fruits, 25);
            printf("Le fruit est: %s\n", motsecret);
            break;
        case 3:
            motsecret = choixmot(animaux, 25);
            printf("L'animal est: %s\n", motsecret);
            break;
        case 4:
            motsecret = choixmot(astronomie, 25);
            printf("Le mot est: %s\n", motsecret);
            break;
    }


}


