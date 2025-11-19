#include "raylib.h"

#include "../include/game_screen.h"

const int DEFAULT_FPS = 60;
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    // Set width and height to 0 to get original resolution of the screen
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(0, 0, "CS50-Final");
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    int framesCounter = 0;
    SetTargetFPS(DEFAULT_FPS);
    
    SetExitKey(KEY_NULL);
    bool exitWindowRequested = false; // Flag to request window to exit
    bool exitWindow = false; // Flag to set window to exit
    
    GameScreen currentScreen = LOGO;
    // ---------------------------------------------------

    // Main game loop
    while (!exitWindow)    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        Update(&currentScreen, &framesCounter);

        //----------------------------------------------------------------------------------
        // Detect if X-button or KEY_ESCAPE have been pressed to close window
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;

        if (exitWindowRequested)
        {
            // A request for close window has been issued, we can save data before closing
            // or just show a message asking for confirmation
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }

        // Draw
        //----------------------------------------------------------------------------------
        Draw(currentScreen, screenWidth, screenHeight, exitWindowRequested);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
