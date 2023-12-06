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

    // Case Nouvelle Partie
    const int coordonnesNouvellePartieX = (screenWidth/2) - longueurRectangle - espaceEntreCases/2;
    const int coordonnesNouvellePartieY = (screenHeight / 2) + hauteurRectangle / 2;

    const int coordonnesNouvellePartieTexteY = coordonnesNouvellePartieY + hauteurRectangle / 2;
    const int coordonnesNouvellePartieTexteX = coordonnesNouvellePartieX + longueurRectangle / 8;

    Rectangle rectangleNouvellePartie = {coordonnesNouvellePartieX, coordonnesNouvellePartieY, longueurRectangle,
                                         hauteurRectangle};

// Ecran jeu en cours
 const int coordonnesQuitterJeuEnCoursX = (screenWidth / 2) - (longueurRectangle/2);
    const int coordonnesQuitterJeuEnCoursY= (screenHeight) - hauteurRectangle * 2;

    const int coordonnesQuitterJeuEnCoursTexteX = coordonnesQuitterJeuEnCoursX  +  longueurRectangle / 12;
    const int coordonnesQuitterJeuEnCoursTexteY = coordonnesQuitterJeuEnCoursY  +hauteurRectangle / 2;

    Rectangle rectangleQuitterJeuEnCours = {coordonnesQuitterJeuEnCoursX, coordonnesQuitterJeuEnCoursY, longueurRectangle,
                                         hauteurRectangle};

char mot_a_trouver[] = "_ _ _ _ _";

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

        switch (currentScreen) {
            case TITLE: {

                PlayMusicStream(musicMainMenu);

                if (IsGestureDetected(GESTURE_TAP)) {

                    

                    // Le rectangle Nouvelle Partie
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleNouvellePartie)) {
                        currentScreen = NOUVELLE_PARTIE;
                        StopMusicStream(musicMainMenu);


                    }

                    // Le rectangle Quitter
                    if (CheckCollisionPointRec(GetMousePosition(), rectangleQuitter)) {
                                                StopMusicStream(musicMainMenu);

                        currentScreen = CREDITS;
                    }
                }
            }
                break;

            case NOUVELLE_PARTIE: {
                PlayMusicStream(musicGetReady);
                        // Temps de chargement pour nouvelle partie
        // Si la musique n'est pas finie
        if (timePlayedGetReady < 0.9f) {
            timePlayedGetReady = GetMusicTimePlayed(musicGetReady) / GetMusicTimeLength(musicGetReady);
        }

            // Sinon
        else {
            StopMusicStream(musicGetReady);
            currentScreen = JEU_EN_COURS; // L'écran du jeu du pendu
            timePlayedGetReady = 1.0f; // On réinitialise le chargement
        }
            }
                break;

// Le jeu du pendu en lui-même
        case JEU_EN_COURS:{
                if (IsGestureDetected(GESTURE_TAP)) {

                    // Retour au menu
                                        if (CheckCollisionPointRec(GetMousePosition(), rectangleQuitterJeuEnCours)) {
                        currentScreen = TITLE;
                    }
                }

                      // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

// De A à Z en MAJUSCULE, et de a à z en MINUSCULE
// Source : https://www.ascii-code.com/
                if ((key >= 65) && (key <= 90) || (key >= 97) && (key <= 122) )
                {
                 
                 //mot_a_trouver[0] = (char) key;
                }

        } break;

            case CREDITS: {
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
                DrawText(mot_a_trouver, 190, 200, 20, LIGHTGRAY);
                // Quitter
                DrawText("Quitter la partie", coordonnesQuitterJeuEnCoursTexteX, coordonnesQuitterJeuEnCoursTexteY, 10, RED);
                DrawRectangleRec(rectangleQuitterJeuEnCours, Fade(BLACK, 0.5f));
                DrawRectangleLines(coordonnesQuitterJeuEnCoursX, coordonnesQuitterJeuEnCoursY, longueurRectangle, hauteurRectangle,
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
    
    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}
