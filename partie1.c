#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Fonction pour choisir un mot au hasard
//A FAIRE: choix de mot selon difficulte

const char *choixmot(const char *mots[], int size) {
    int randomIndex = rand() % size;
    return mots[randomIndex];
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
            "japet",
            "dione"
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
    } else {
        categ = rand() % 4;
    }





    const char *motsecret = choixmot(categories[categ],25);

    printf("La categorie est %s et le mot est %s.\n", categoriesNom[categ], motsecret);

    return 0;

}


