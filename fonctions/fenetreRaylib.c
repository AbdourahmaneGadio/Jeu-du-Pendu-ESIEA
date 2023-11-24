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
    TITLE, GAMEPLAY, CREDITS
} GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void fenetreRaylib() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    GameScreen currentScreen = TITLE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        switch (currentScreen) {
            case TITLE: {
                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
                    currentScreen = GAMEPLAY;
                }
            }
                break;
            case GAMEPLAY: {
                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
                    currentScreen = CREDITS;
                }
            }
                break;
            case CREDITS: {
                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
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

            // Titre du jeu
            case TITLE: {
                DrawText("Jeu du pendu", 190, 200, 20, LIGHTGRAY);
            }
                break;

                // Boutons
            case GAMEPLAY: {
                DrawText("Nouvelle partie", screenWidth / 2, screenHeight / 2, 10, BLACK);
                DrawRectangle(screenWidth / 2, screenHeight / 2, 100, 50, Fade(GREEN, 0.5f));
                DrawRectangleLines(screenWidth / 2, screenHeight / 2, 100, 50, Fade(GREEN, 0.8f));
            }
                break;

                // Crédits
            case CREDITS: {
                DrawText("Crédits", 10, 10, 10, BLACK);
                DrawRectangle(10, 10, 100, 50, Fade(SKYBLUE, 0.5f));
                DrawRectangleLines(10, 10, 100, 50, Fade(BLUE, 0.8f));
            }
                break;
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