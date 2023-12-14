/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <stdlib.h>
#include <time.h>

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen {
    TITLE, NOUVELLE_PARTIE, CLASSEMENTS, CREDITS, JEU_EN_COURS, THEMES, DIFFICULTES
} GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void fenetreRaylib() {




    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    const int espaceEntreCases = 100;

    const int longueurRectangle = 100;
    const int hauteurRectangle = 52;


    bool modeSpecial = false; // false pour le mode normal, true pour le mode spécial


    // Ecran TITRE
    //--------------------------------------------------------------------------------------

    // Case nouvelle partie
    const int coordonnesNouvellePartieX = (screenWidth / 3) - longueurRectangle;
    const int coordonnesNouvellePartieY = (screenHeight / 2) + hauteurRectangle / 2;

    const int coordonnesNouvellePartieTexteY = coordonnesNouvellePartieY + hauteurRectangle / 2;
    const int coordonnesNouvellePartieTexteX = coordonnesNouvellePartieX + longueurRectangle / 8;

    Rectangle rectangleNouvellePartie = {coordonnesNouvellePartieX, coordonnesNouvellePartieY, longueurRectangle,
                                         hauteurRectangle};



    // Case classements
    const int coordonnesClassementX = coordonnesNouvellePartieX + longueurRectangle + espaceEntreCases;
    const int coordonnesClassementY = coordonnesNouvellePartieY;

    const int coordonnesClassementTexteY = coordonnesClassementY + hauteurRectangle / 2;
    const int coordonnesClassementTexteX = coordonnesClassementX + longueurRectangle / 5;

    Rectangle rectangleClassement = {coordonnesClassementX, coordonnesClassementY, longueurRectangle, hauteurRectangle};



    // Case quitter
    const int coordonnesQuitterX = coordonnesClassementX + longueurRectangle + espaceEntreCases;
    const int coordonnesQuitterY = coordonnesNouvellePartieY;

    const int coordonnesQuitterTexteY = coordonnesQuitterY + hauteurRectangle / 2;
    const int coordonnesQuitterTexteX = coordonnesQuitterX + longueurRectangle / 3;

    Rectangle rectangleQuitter = {coordonnesQuitterX, coordonnesQuitterY, longueurRectangle, hauteurRectangle};


    // Mode spécial

    const int coordonneesModeSpecialTexteX = coordonnesClassementTexteX - 70;
    const int coordonneesModeSpecialTexteY = screenHeight - 90;

    Rectangle rectangleModeSpecial = {coordonneesModeSpecialTexteX + 140, coordonneesModeSpecialTexteY, 20, 20};

    // Fin écran TITRE
    //--------------------------------------------------------------------------------------

    // Ecran THEMES
    //--------------------------------------------------------------------------------------

    const int coordonnesTheme1X = (screenWidth / 2) - (longueurRectangle / 2);
    const int coordonnesTheme1Y = (screenHeight) - 70 - hauteurRectangle * 2;

    const int coordonnesTheme1TexteX = coordonnesTheme1X + longueurRectangle / 12;
    const int coordonnesTheme1TexteY = coordonnesTheme1Y + hauteurRectangle / 2;

    Rectangle rectangleTheme1 = {coordonnesTheme1X, coordonnesTheme1Y,
                                 longueurRectangle,
                                 hauteurRectangle};

    // Fin écranTHEMES
    //--------------------------------------------------------------------------------------

    // Ecran DIFFICULTES
    //--------------------------------------------------------------------------------------

    const int coordonnesDifficulteFacileX = (screenWidth / 2) - (longueurRectangle / 2);
    const int coordonnesDifficulteFacileY = (screenHeight) - 70 - hauteurRectangle * 2;

    const int coordonnesDifficulteFacileTexteX = coordonnesDifficulteFacileX + longueurRectangle / 12;
    const int coordonnesDifficulteFacileTexteY = coordonnesDifficulteFacileY + hauteurRectangle / 2;

    Rectangle rectangleDifficulteFacile = {coordonnesDifficulteFacileX, coordonnesDifficulteFacileY,
                                           longueurRectangle,
                                           hauteurRectangle};

    // Fin écran DIFFICULTES
    //--------------------------------------------------------------------------------------





    // Ecran CLASSEMENTS
    //--------------------------------------------------------------------------------------

    // Retour au menu
    const int coordonnesRetourMenuX = (screenWidth / 2) - (longueurRectangle / 2);
    const int coordonnesRetourMenuY = (screenHeight) - hauteurRectangle * 2;

    const int coordonnesRetourMenuTexteX = coordonnesRetourMenuX + longueurRectangle / 12;
    const int coordonnesRetourMenuTexteY = coordonnesRetourMenuY + hauteurRectangle / 2;

    Rectangle rectangleRetourMenu = {coordonnesRetourMenuX, coordonnesRetourMenuY,
                                     longueurRectangle,
                                     hauteurRectangle};

    // Fin écran CLASSEMENTS
    //--------------------------------------------------------------------------------------







    // Ecran JEU_EN_COURS
    //--------------------------------------------------------------------------------------

    const int coordonnesQuitterJeuEnCoursX = (screenWidth / 2) - (longueurRectangle / 2);
    const int coordonnesQuitterJeuEnCoursY = (screenHeight) - hauteurRectangle * 2;

    const int coordonnesQuitterJeuEnCoursTexteX = coordonnesQuitterJeuEnCoursX + longueurRectangle / 12;
    const int coordonnesQuitterJeuEnCoursTexteY = coordonnesQuitterJeuEnCoursY + hauteurRectangle / 2;

    Rectangle rectangleQuitterJeuEnCours = {coordonnesQuitterJeuEnCoursX, coordonnesQuitterJeuEnCoursY,
                                            longueurRectangle,
                                            hauteurRectangle};



    // Lignes copiées du fichier main.c principal, et de la fonction devinetteMot

    // On prend un mot au hasard à trouver
    char *mot = choixMot();

    // On prend le mot, et on donne la longueur de celui-ci
    size_t longueur = strlen(mot);
    char devinette[longueur - 1];

    int nombreEssais = 6;
    int lettreTrouvee = 1; // 0 si on la trouve, 1 si on ne la trouve pas

    /*
     * On ajout des tirets au mot à deviner
     * Ex : ____ pour un mot à 4 caractères
     */
    for (int i = 0; i < longueur; i++) {
        devinette[i] = '-';
    }

    devinette[longueur] = '\0';

    int motTrouve = 0; // 0 si pas trouvé, 1 si trouvé


    // Fin écran JEU_EN_COURS
    //--------------------------------------------------------------------------------------






    // Ecran CREDITS
    //--------------------------------------------------------------------------------------
    const int coordonnesEcranCreditsX = (screenWidth / 4) + 50;
    const int coordonnesEcranCreditsY = (screenHeight / 2);
    // Fin écran CREDITS
    //--------------------------------------------------------------------------------------








    // Paramètres de la fenêtre
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Jeu Du Pendu ESIEA v1.0");

    GameScreen currentScreen = TITLE;

    bool exitWindow = false;    // Flag to set window to exit

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Fin des paramètres de la fenêtre
    //--------------------------------------------------------------------------------------





    // Musique
    //--------------------------------------------------------------------------------------

    InitAudioDevice();              // Initialize audio device

    // Les musiques utilisées

    Music musicCredits;
    Music musicMainMenu;
    Music musicLoading;
    Music musicPartieGagne;
    Music musicPartiePerdue;
    Music musicPartieJeuEnCours;
    Music musicClassement;

    // Mode normal
    Music musicCreditsNormal = LoadMusicStream("music/normal/credits.mp3");
    Music musicMainMenuNormal = LoadMusicStream("music/normal/main_menu.mp3");

    Music musicLoadingNormal = LoadMusicStream("music/normal/loading.mp3");
    float timePlayedLoading = 0.0f;

    Music musicPartieJeuEnCoursNormal = LoadMusicStream("music/normal/game.mp3");
    Music musicPartieGagneNormal = LoadMusicStream("music/normal/win.mp3");

    Music musicPartiePerdueNormal = LoadMusicStream("music/normal/lose.mp3");

    Music musicClassementNormal = LoadMusicStream("music/normal/ranking.mp3");


    // Mode spécial
    /*
    Music musicCreditsSpecial = LoadMusicStream("music/special/credits_special.mp3");

    Music musicMainMenuSpecial = LoadMusicStream("music/special/main_menu_special.mp3");

    Music musicLoadingSpecial = LoadMusicStream("music/special/loading_special.mp3");

    Music musicPartieJeuEnCoursSpecial = LoadMusicStream("music/special/game_special.mp3");
    Music musicPartieGagneSpecial = LoadMusicStream("music/special/win_special.mp3");

    Music musicPartiePerdueSpecial1 = LoadMusicStream("music/special/lose_special.mp3");
    Music musicPartiePerdueSpecial2 = LoadMusicStream("music/special/lose_special_2.mp3");
    Music musicPartiePerdueSpecial3 = LoadMusicStream("music/special/lose_special_3.mp3");

    Music musicClassementSpecial = LoadMusicStream("music/special/ranking_special.mp3");
*/
    // Fin de la partie musique
    //--------------------------------------------------------------------------------------




    // Textures
    //--------------------------------------------------------------------------------------
    Image image = LoadImage("textures/background_16_9.png");     // Loaded in CPU memory (RAM)
    Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(image);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM

    // Fin des textures
    //--------------------------------------------------------------------------------------





    // Main game loop
    while (!exitWindow) {

        // Update
        //----------------------------------------------------------------------------------
        UpdateMusicStream(musicCreditsNormal);   // Update music buffer with new stream data
        UpdateMusicStream(musicMainMenuNormal);
        UpdateMusicStream(musicLoadingNormal);
        UpdateMusicStream(musicPartieGagneNormal);
        UpdateMusicStream(musicPartiePerdueNormal);
        UpdateMusicStream(musicPartieJeuEnCoursNormal);
        UpdateMusicStream(musicClassementNormal);

        // UpdateMusicStream(musicCreditsSpecial);
        // UpdateMusicStream(musicMainMenuSpecial);
        // UpdateMusicStream(musicLoadingSpecial);
        // UpdateMusicStream(musicPartieGagneSpecial);
        // UpdateMusicStream(musicPartiePerdueSpecial1);
        // UpdateMusicStream(musicPartiePerdueSpecial2);
        // UpdateMusicStream(musicPartiePerdueSpecial3);
        // UpdateMusicStream(musicPartieJeuEnCours);
        // UpdateMusicStream(musicClassementSpecial);

        if (modeSpecial == 0) {
            musicCredits = musicCreditsNormal;
            musicMainMenu = musicMainMenuNormal;
            musicLoading = musicLoadingNormal;
            musicPartieGagne = musicPartieGagneNormal;
            musicPartiePerdue = musicPartiePerdueNormal;
            musicPartieJeuEnCours = musicPartieJeuEnCoursNormal;
            musicClassement = musicClassementNormal;
        } else {

            //musicCredits = musicCreditsSpecial;
           // musicMainMenu = musicMainMenuSpecial;
            // musicLoading = musicLoadingSpecial;
            //musicPartieGagne = musicPartieGagneSpecial;

           // musicPartiePerdue = musicPartiePerdueSpecial1;

            // musicPartieJeuEnCours = musicPartieJeuEnCoursSpecial;
            // musicClassement = musicClassementSpecial;
        }

        switch (currentScreen) {
            case TITLE: {

                // La musique du menu principal
                PlayMusicStream(musicMainMenu);

                if (IsGestureDetected(GESTURE_TAP)) {

                    // Si on clique sur le rectangle Nouvelle Partie
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleNouvellePartie)) {
                        currentScreen = THEMES;

                    }

                    // Si on clique sur le rectangle Classements
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleClassement)) {
                        StopMusicStream(musicMainMenu);
                        currentScreen = CLASSEMENTS;
                    }

                    // Si on clique sur le rectangle Quitter
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleQuitter)) {
                        StopMusicStream(musicMainMenu);

                        currentScreen = CREDITS;
                    }

                    // Si on clique sur le rectangle mode special
                    // Si on clique sur le rectangle Quitter
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleModeSpecial)) {
                        StopMusicStream(musicMainMenu);

                        modeSpecial = !modeSpecial;
                    }
                }
            }
                break;

            case THEMES: {
                if (IsGestureDetected(GESTURE_TAP)) {

                    // Retour au menu
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleRetourMenu)) {
                        currentScreen = TITLE;
                    }

                    // Si on clique sur le rectangle Theme1
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleTheme1)) {
                        currentScreen = DIFFICULTES;

                    }
                }
            }
                break;

            case DIFFICULTES: {
                if (IsGestureDetected(GESTURE_TAP)) {

                    // Retour au menu du choix du thème
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleRetourMenu)) {
                        currentScreen = THEMES;
                    }

                    // Choix mode facile
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleDifficulteFacile)) {
                        StopMusicStream(musicMainMenu);
                        currentScreen = NOUVELLE_PARTIE;
                    }
                }
            }
                break;

            case NOUVELLE_PARTIE: {

                // La musique de la nouvelle partie
                PlayMusicStream(musicLoading);

                // Si la musique n'est pas finie
                // Temps de chargement pour nouvelle partie
                if (timePlayedLoading < 0.9f) {
                    timePlayedLoading = GetMusicTimePlayed(musicLoading) / GetMusicTimeLength(musicLoading);
                }

                    // Si la musique est finie
                else {
                    StopMusicStream(musicLoading);
                    currentScreen = JEU_EN_COURS; // L'écran du jeu du pendu
                    timePlayedLoading = 1.0f; // On réinitialise le chargement
                }
            }
                break;

                // La partie du jeu en cours
            case JEU_EN_COURS: {

                // La musique du jeu du pendu
                if (motTrouve == 0 && nombreEssais == 6) {
                    PlayMusicStream(musicPartieJeuEnCours);
                }

                if (IsGestureDetected(GESTURE_TAP)) {

                    // Retour au menu
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleQuitterJeuEnCours)) {
                        StopMusicStream(musicPartieJeuEnCours);
                        StopMusicStream(musicPartieGagne);
                        StopMusicStream(musicPartiePerdue);

                        // On réinitialise le nombre d'essais
                        nombreEssais = 6;
                        motTrouve = 0;
                        currentScreen = TITLE;
                    }
                }

                // Tant que l'on a pas perdu
                if (nombreEssais > 0) {

                    // Get char pressed (unicode character) on the queue
                    int key = GetCharPressed();

                    // De A à Z en MAJUSCULE, et de a à z en MINUSCULE
                    // Source : https://www.ascii-code.com/
                    if ( ((key >= 65) && (key <= 90)) || ((key >= 97) && (key <= 122)) ) {

                        // On convertit la lettre en MAJUSCULE
                        char majuscule = toupper((char) key);

                        // Pour chaque lettre du mot
                        for (int j = 0; j < longueur; j++) {

                            // Si on trouve la lettre
                            if (majuscule == mot[j]) {

                                /*
                                 * On met celle-ci dans le mot à deviner
                                 * Ex:
                                 * si le mot est "Java" et qu'on entre la lettre "a",
                                 * alors le mot deviné sera "_a_a"
                                 */
                                devinette[j] = majuscule;
                                lettreTrouvee = 0;

                            }

                        }

                        // Si on n'a pas trouvé la lettre
                        if (lettreTrouvee == 1) {
                            nombreEssais--;
                        }

                        // On réinitialise l'état de la lettre trouvée
                        lettreTrouvee = 1;

                        int resultat = strcmp(devinette, mot);

                        // Si on a tout trouvé
                        if (resultat == 0) {
                            motTrouve = 1;
                            PlayMusicStream(musicPartieGagne);
                            StopMusicStream(musicPartieJeuEnCours);

                        }

                    }


                } // nombreEssais > 0

                    // Si on a perdu
                else {
                    StopMusicStream(musicPartieJeuEnCours);
                    PlayMusicStream(musicPartiePerdue);
                }


            }
                break;

                // Classement
            case CLASSEMENTS: {
                PlayMusicStream(musicClassement);
                if (IsGestureDetected(GESTURE_TAP)) {

                    // Retour au menu
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleRetourMenu)) {
                        StopMusicStream(musicClassement);
                        currentScreen = TITLE;
                    }
                }
            }
                break;

            case CREDITS: {

                // La musique des crédits
                PlayMusicStream(musicCredits);

                // Si on veut revenir au menu
                if (IsGestureDetected(GESTURE_TAP)) {
                    StopMusicStream(musicCredits);
                    exitWindow = true;

                }
            }
                break;

            default:


                break;
                //----------------------------------------------------------------------------------
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, 0, 0, WHITE);

        switch (currentScreen) {

            // Menu principal du jeu
            case TITLE: {
                DrawText("Jeu du pendu", 190, 200, 20, LIGHTGRAY);

                // Nouvelle partie
                DrawText("Nouvelle partie", coordonnesNouvellePartieTexteX, coordonnesNouvellePartieTexteY, 10, BLACK);
                DrawRectangleRec(rectangleNouvellePartie, Fade(GREEN, 0.5f));
                DrawRectangleLines(coordonnesNouvellePartieX, coordonnesNouvellePartieY, 100, 50, Fade(GREEN, 0.8f));


                // Classements
                DrawText("Classements", coordonnesClassementTexteX, coordonnesClassementTexteY, 10, RED);
                DrawRectangleRec(rectangleClassement, Fade(BLACK, 0.5f));
                DrawRectangleLines(coordonnesClassementX, coordonnesClassementY, longueurRectangle, hauteurRectangle,
                                   Fade(RED, 0.8f));

                // Quitter
                DrawText("Quitter", coordonnesQuitterTexteX, coordonnesQuitterTexteY, 10, RED);
                DrawRectangleRec(rectangleQuitter, Fade(BLACK, 0.5f));
                DrawRectangleLines(coordonnesQuitterX, coordonnesQuitterY, longueurRectangle, hauteurRectangle,
                                   Fade(RED, 0.8f));

                // Mode spécial


                if (modeSpecial == 0) {
                    DrawText("Mode special", coordonneesModeSpecialTexteX, coordonneesModeSpecialTexteY, 20,
                             WHITE);
                    DrawRectangleRec(rectangleModeSpecial, Fade(WHITE, 0.5f));

                } else {
                    DrawText("Mode special activé", coordonneesModeSpecialTexteX - 70, coordonneesModeSpecialTexteY, 20,
                             RED);
                    DrawRectangleRec(rectangleModeSpecial, Fade(RED, 0.5f));

                }
            }
                break;


            case THEMES: {
                DrawText("Choississez le thème", 190, 200, 20, LIGHTGRAY);
                DrawText("Animaux", coordonnesTheme1TexteX, coordonnesTheme1TexteY, 10, BLACK);

                DrawRectangleRec(rectangleTheme1, Fade(GREEN, 0.5f));
                DrawText("Retour au menu", coordonnesRetourMenuTexteX, coordonnesRetourMenuTexteY, 10,
                         BLUE);
                DrawRectangleRec(rectangleRetourMenu, Fade(BLACK, 0.5f));

            }
                break;

            case DIFFICULTES: {
                DrawText("Choississez la difficulté", 190, 200, 20, LIGHTGRAY);
                DrawText("Facile", coordonnesDifficulteFacileTexteX, coordonnesDifficulteFacileTexteY, 10, BLACK);

                DrawRectangleRec(rectangleDifficulteFacile, Fade(GREEN, 0.5f));
                DrawText("Retour à la sélection du thème", coordonnesRetourMenuTexteX, coordonnesRetourMenuTexteY, 10,
                         BLUE);
                DrawRectangleRec(rectangleRetourMenu, Fade(BLACK, 0.5f));

            }
                break;

            case NOUVELLE_PARTIE: {
                DrawText("La partie commence !", 190, 200, 20, LIGHTGRAY);
                DrawRectangle(200, 250, (int) (timePlayedLoading * 400.0f), 12, MAROON);
                DrawRectangleLines(200, 250, 400, 12, GRAY);
            }
                break;

            case CLASSEMENTS: {
                DrawText("Classement", screenWidth / 2 - 50, 30, 20, LIGHTGRAY);

                DrawText("Retour au menu", coordonnesRetourMenuTexteX, coordonnesRetourMenuTexteY, 10,
                         BLUE);
                DrawRectangleRec(rectangleRetourMenu, Fade(BLACK, 0.5f));
                DrawRectangleLines(coordonnesRetourMenuX, coordonnesRetourMenuY, longueurRectangle,
                                   hauteurRectangle,
                                   Fade(GREEN, 0.8f));
            }
                break;

                // Le jeu du pendu en lui-même
            case JEU_EN_COURS: {

                // Le mot à trouver
                DrawText(devinette, 190, 200, 20, LIGHTGRAY);

                // Le nombre d'essais
                if (nombreEssais > 0 && motTrouve == 0) {
                    DrawText(TextFormat("Il te reste %01i essais", nombreEssais), 190, 220, 20, RED);
                } else if (motTrouve == 1) {
                    DrawText(TextFormat("Bravo, tu as trouvé le mot et gagné le jeu !", nombreEssais), 190, 240, 20,
                             GREEN);
                } else {
                    DrawText(TextFormat("Perdu... Le mot à deviner était :"), 190, 230, 20, RED);
                    DrawText(mot, 190, 270, 20, BLUE);
                }
                // Quitter
                DrawText("Quitter la partie", coordonnesQuitterJeuEnCoursTexteX, coordonnesQuitterJeuEnCoursTexteY, 10,
                         RED);
                DrawRectangleRec(rectangleQuitterJeuEnCours, Fade(BLACK, 0.5f));
                DrawRectangleLines(coordonnesQuitterJeuEnCoursX, coordonnesQuitterJeuEnCoursY, longueurRectangle,
                                   hauteurRectangle,
                                   Fade(RED, 0.8f));
            }
                break;

                // Crédits
            case CREDITS: {
                DrawText("Equipe: GADIO Abdourahmane, KADOUCHIM David, LEVY Ilona", coordonnesEcranCreditsX,
                         coordonnesEcranCreditsY, 10, BLACK);
                DrawText("https://github.com/AbdourahmaneGadio/Jeu-du-Pendu-ESIEA", coordonnesEcranCreditsX,
                         coordonnesEcranCreditsY + 30, 10, RED);
            }

            default:
                break;
        } // switch
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadMusicStream(musicCredits);   // Unload music stream buffers from RAM
    UnloadMusicStream(musicMainMenu);
    UnloadMusicStream(musicLoading);
    UnloadMusicStream(musicClassement);
    UnloadMusicStream(musicPartieJeuEnCours);
    UnloadMusicStream(musicPartieGagne);
    UnloadMusicStream(musicPartiePerdue);

    UnloadTexture(texture);       // Texture unloading

    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}
