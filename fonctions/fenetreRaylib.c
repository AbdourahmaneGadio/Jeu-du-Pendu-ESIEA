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
    TITLE, NOUVELLE_PARTIE, CREDITS
} GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void fenetreRaylib() {

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    const int espaceEntreCases = 150;

    const int longueurRectangle = 100;
    const int hauteurRectangle = 52;

    // Ecran TITRE
    //--------------------------------------------------------------------------------------

    // Case Nouvelle Partie
    const int coordonnesNouvellePartieX = 200;
    const int coordonnesNouvellePartieY = (screenHeight / 2);

    const int coordonnesNouvellePartieTexteY = coordonnesNouvellePartieY + hauteurRectangle / 2;
    const int coordonnesNouvellePartieTexteX = coordonnesNouvellePartieX + longueurRectangle / 8;

    Rectangle rectangleNouvellePartie = {coordonnesNouvellePartieX, coordonnesNouvellePartieY, longueurRectangle,
                                         hauteurRectangle};

// Case crédits
    const int coordonnesCreditsX = coordonnesNouvellePartieX + espaceEntreCases;
    const int coordonnesCreditsY = (screenHeight / 2);

    const int coordonnesCreditsTexteY = coordonnesCreditsY + hauteurRectangle / 2;
    const int coordonnesCreditsTexteX = coordonnesCreditsX + longueurRectangle / 3;

// Case quitter
    const int coordonnesQuitterX = coordonnesCreditsX + espaceEntreCases;
    const int coordonnesQuitterY = (screenHeight / 2);

    const int coordonnesQuitterTexteY = coordonnesQuitterY + hauteurRectangle / 2;
    const int coordonnesQuitterTexteX = coordonnesQuitterX + longueurRectangle / 3;

    Rectangle rectangleQuitter = {coordonnesQuitterX, coordonnesQuitterY, longueurRectangle, hauteurRectangle};


    // Ecran Credits
    //--------------------------------------------------------------------------------------
    const int coordonnesEcranCreditsX = (screenWidth / 4) + 50;
    const int coordonnesEcranCreditsY = (screenHeight / 2);

    Rectangle rectangleCredits = {coordonnesCreditsX, coordonnesCreditsY, longueurRectangle, hauteurRectangle};


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

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

    // Main game loop
    while (!exitWindow) {

        // Update
        //----------------------------------------------------------------------------------
        UpdateMusicStream(musicCredits);   // Update music buffer with new stream data
        UpdateMusicStream(musicMainMenu);
        UpdateMusicStream(musicGetReady);

        // Temps de chargement pour nouvelle partie
        // Si la musique n'est pas finie
        if (timePlayedGetReady < 0.99f) {
            timePlayedGetReady = GetMusicTimePlayed(musicGetReady) / GetMusicTimeLength(musicGetReady);
        }

            // Sinon
        else {
            StopMusicStream(musicGetReady);
            currentScreen = TITLE; // L'écran du jeu du pendu
            timePlayedGetReady = 0.0f; // On réinitialise le chargement
        }


        switch (currentScreen) {
            case TITLE: {

                PlayMusicStream(musicMainMenu);

                if (IsGestureDetected(GESTURE_TAP)) {

                    // Le rectangle des crédits
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleCredits)) {
                        currentScreen = CREDITS;
                        StopMusicStream(musicMainMenu);

                    }

                    // Le rectangle Nouvelle Partie
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleNouvellePartie)) {
                        currentScreen = NOUVELLE_PARTIE;
                        StopMusicStream(musicMainMenu);


                    }

                    // Le rectangle Quitter
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleQuitter)) {
                        exitWindow = true;
                    }
                }
            }
                break;

            case NOUVELLE_PARTIE: {
                PlayMusicStream(musicGetReady);

                // Si on veut revenir au menu
                if (IsGestureDetected(GESTURE_TAP)) {
                    currentScreen = TITLE;
                }
            }
                break;
            case CREDITS: {
                PlayMusicStream(musicCredits);

                // Si on veut revenir au menu
                if (IsGestureDetected(GESTURE_TAP)) {
                    StopMusicStream(musicCredits);
                    currentScreen = TITLE;
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

                // Crédits
                DrawText("Crédits", coordonnesCreditsTexteX, coordonnesCreditsTexteY, 10, BLACK);
                DrawRectangleRec(rectangleCredits, Fade(SKYBLUE, 0.5f));
                DrawRectangleLines(coordonnesCreditsX, coordonnesCreditsY, longueurRectangle, hauteurRectangle,
                                   Fade(BLUE, 0.8f));

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

                // Crédits
            case CREDITS: {
                DrawText("Equipe: GADIO Abdourahmane, KADOUCHIM David, LEVY Ilona", coordonnesEcranCreditsX,
                         coordonnesEcranCreditsY, 10, LIGHTGRAY);
                DrawText("https://github.com/AbdourahmaneGadio/Jeu-du-Pendu-ESIEA", coordonnesEcranCreditsX,
                         coordonnesEcranCreditsY + 30, 10, LIGHTGRAY);
            }

            default:
                break;
        } // switch
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}
