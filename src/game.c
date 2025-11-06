#include "raylib.h"

int main(void)
{
    // Initialization
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(0, 0, "CS50-Final");

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    // Confirm close
    SetExitKey(KEY_NULL);
    bool exitWindowRequested = false;
    bool exitWindow = false;

    SetTargetFPS(60);
    // ---------------------------------------------------

    // Main game loop
    while (!exitWindow)
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Detect if X-button or KEY_ESCAPE have been pressed to close window
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
        {
            exitWindowRequested = true;
        }

        if (exitWindowRequested)
        {
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (exitWindowRequested)
            {
                DrawRectangle(0, 100, screenWidth, 200, BLACK);
                DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
            }
            else
            {

                DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
