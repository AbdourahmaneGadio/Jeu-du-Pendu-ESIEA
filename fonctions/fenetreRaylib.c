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

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen {
    TITLE, NOUVELLE_PARTIE, CREDITS, JEU_EN_COURS
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

    // Ecran TITRE
    //--------------------------------------------------------------------------------------
    
    const int coordonnesNouvellePartieX = (screenWidth / 2) - longueurRectangle - espaceEntreCases / 2;
    const int coordonnesNouvellePartieY = (screenHeight / 2) + hauteurRectangle / 2;

    const int coordonnesNouvellePartieTexteY = coordonnesNouvellePartieY + hauteurRectangle / 2;
    const int coordonnesNouvellePartieTexteX = coordonnesNouvellePartieX + longueurRectangle / 8;

    Rectangle rectangleNouvellePartie = {coordonnesNouvellePartieX, coordonnesNouvellePartieY, longueurRectangle,
                                         hauteurRectangle};

    //-------------------------------
    // Ecran jeu en cours

    const int coordonnesQuitterJeuEnCoursX = (screenWidth / 2) - (longueurRectangle / 2);
    const int coordonnesQuitterJeuEnCoursY = (screenHeight) - hauteurRectangle * 2;

    const int coordonnesQuitterJeuEnCoursTexteX = coordonnesQuitterJeuEnCoursX + longueurRectangle / 12;
    const int coordonnesQuitterJeuEnCoursTexteY = coordonnesQuitterJeuEnCoursY + hauteurRectangle / 2;

    Rectangle rectangleQuitterJeuEnCours = {coordonnesQuitterJeuEnCoursX, coordonnesQuitterJeuEnCoursY,
                                            longueurRectangle,
                                            hauteurRectangle};

    //-------------------------------
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

    // Case crédits
    const int coordonnesCreditsX = coordonnesNouvellePartieX + espaceEntreCases;
    const int coordonnesCreditsY = (screenHeight / 2);

    const int coordonnesCreditsTexteY = coordonnesCreditsY + hauteurRectangle / 2;
    const int coordonnesCreditsTexteX = coordonnesCreditsX + longueurRectangle / 3;

    // Case quitter
    const int coordonnesQuitterX = coordonnesCreditsX + espaceEntreCases;
    const int coordonnesQuitterY = coordonnesNouvellePartieY;

    const int coordonnesQuitterTexteY = coordonnesQuitterY + hauteurRectangle / 2;
    const int coordonnesQuitterTexteX = coordonnesQuitterX + longueurRectangle / 3;

    Rectangle rectangleQuitter = {coordonnesQuitterX, coordonnesQuitterY, longueurRectangle, hauteurRectangle};


    // Ecran Credits
    //--------------------------------------------------------------------------------------
    const int coordonnesEcranCreditsX = (screenWidth / 4) + 50;
    const int coordonnesEcranCreditsY = (screenHeight / 2);

    // Paramètres de la fenêtre
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Jeu Du Pendu ESIEA v1.0");

    GameScreen currentScreen = TITLE;

    bool exitWindow = false;    // Flag to set window to exit

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Music
    //----------
    InitAudioDevice();              // Initialize audio device

    // Les musiques utilisées
    Music musicCredits = LoadMusicStream("music/Daft Punk - Motherboard.mp3");
    Music musicMainMenu = LoadMusicStream("music/Arcade Player - Racing Menu (From -Mario Kart Wii-).mp3");

    Music musicGetReady = LoadMusicStream("music/get-ready.mp3");
    float timePlayedGetReady = 0.0f;

    Music musicPartieJeuEnCours = LoadMusicStream("music/Arcade Player - Racing Menu (From -Mario Kart Wii-).mp3");
    Music musicPartiePerdue = LoadMusicStream("music/Daft Punk - Motherboard.mp3");


    // Main game loop
    while (!exitWindow) {

        // Update
        //----------------------------------------------------------------------------------
        UpdateMusicStream(musicCredits);   // Update music buffer with new stream data
        UpdateMusicStream(musicMainMenu);
        UpdateMusicStream(musicGetReady);
        UpdateMusicStream(musicPartiePerdue);
        UpdateMusicStream(musicPartieJeuEnCours);

        switch (currentScreen) {
            case TITLE: {

                // La musique du menu principal
                PlayMusicStream(musicMainMenu);

                if (IsGestureDetected(GESTURE_TAP)) {

                    // Si on clique sur le rectangle Nouvelle Partie
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleNouvellePartie)) {
                        currentScreen = NOUVELLE_PARTIE;
                        StopMusicStream(musicMainMenu);


                    }

                    // Si on clique sur le rectangle Quitter
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleQuitter)) {
                        StopMusicStream(musicMainMenu);

                        currentScreen = CREDITS;
                    }
                }
            }
                break;

            case NOUVELLE_PARTIE: {

                // La musique de la nouvelle partie
                PlayMusicStream(musicGetReady);

                // Si la musique n'est pas finie
                // Temps de chargement pour nouvelle partie
                if (timePlayedGetReady < 0.9f) {
                    timePlayedGetReady = GetMusicTimePlayed(musicGetReady) / GetMusicTimeLength(musicGetReady);
                }

                // Si la musique est finie
                else {
                    StopMusicStream(musicGetReady);
                    currentScreen = JEU_EN_COURS; // L'écran du jeu du pendu
                    timePlayedGetReady = 1.0f; // On réinitialise le chargement
                }
            }
                break;

            // La partie du jeu en cours
            case JEU_EN_COURS: {

                // La musique du jeu du pendu
                PlayMusicStream(musicPartieJeuEnCours);

                if (IsGestureDetected(GESTURE_TAP)) {

                    // Retour au menu
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleQuitterJeuEnCours)) {
                        StopMusicStream(musicPartieJeuEnCours);
                        StopMusicStream(musicPartiePerdue);
                        
                        // On réinitialise le nombre d'essais et le
                        nombreEssais = 6;
                        currentScreen = TITLE;
                    }
                }

                // Tant que l'on a pas perdu
                if (nombreEssais > 0) {

                    // Get char pressed (unicode character) on the queue
                    int key = GetCharPressed();

                    // De A à Z en MAJUSCULE, et de a à z en MINUSCULE
                    // Source : https://www.ascii-code.com/
                    if ((key >= 65) && (key <= 90) || (key >= 97) && (key <= 122)) {

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

                            // On sort de la boucle
                            break;
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
        switch (currentScreen) {

            // Menu principal du jeu
            case TITLE: {
                DrawText("Jeu du pendu", 190, 200, 20, LIGHTGRAY);

                // Nouvelle partie
                DrawText("Nouvelle partie", coordonnesNouvellePartieTexteX, coordonnesNouvellePartieTexteY, 10, BLACK);
                DrawRectangleRec(rectangleNouvellePartie, Fade(GREEN, 0.5f));
                DrawRectangleLines(coordonnesNouvellePartieX, coordonnesNouvellePartieY, 100, 50, Fade(GREEN, 0.8f));



                // Quitter
                DrawText("Quitter", coordonnesQuitterTexteX, coordonnesQuitterTexteY, 10, RED);
                DrawRectangleRec(rectangleQuitter, Fade(BLACK, 0.5f));
                DrawRectangleLines(coordonnesQuitterX, coordonnesQuitterY, longueurRectangle, hauteurRectangle,
                                   Fade(RED, 0.8f));
            }
                break;

            case NOUVELLE_PARTIE: {
                DrawText("La partie commence !", 190, 200, 20, LIGHTGRAY);
                DrawRectangle(200, 250, (int) (timePlayedGetReady * 400.0f), 12, MAROON);
                DrawRectangleLines(200, 250, 400, 12, GRAY);
            }
                break;

            // Le jeu du pendu en lui-même
            case JEU_EN_COURS: {

                // Le mot à trouver
                DrawText(devinette, 190, 200, 20, LIGHTGRAY);

                // Le nombre d'essais
                DrawText(TextFormat("Il te reste %01i essais", nombreEssais), 190, 220, 20, RED);

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
    UnloadMusicStream(musicGetReady);
    UnloadMusicStream(musicPartieJeuEnCours);
    UnloadMusicStream(musicPartiePerdue);

    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}
