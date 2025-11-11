#include "raylib.h"

#include "../include/player.h"
#include "../include/game_screen.h"

int main(void)
{
    // Initialization
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(0, 0, "CS50-Final");

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    // Texture loading
    Texture2D texKen = LoadTexture("resources/ken.png");
    Texture2D texRyu = LoadTexture("resources/ryu.png");
    Texture2D texBackground = LoadTexture("resources/background.png");

    // Game require variables
    GameScreen screen = GAMEPLAY;

    Player ken = { 0 };
    ken.position = (Vector2) { screenWidth / 2.0f - texKen.width / 2.0,  screenHeight - texKen.height * 4 - 30 };
    ken.speed = (Vector2) { 5.0f, 0.0f };

    Player ryu = { 0 };
    ryu.position = (Vector2) { screenWidth / 2.0f - texKen.width / 2.0,  screenHeight - texKen.height * 4 - 30 };
    ryu.speed = (Vector2) { 5.0f, 0.0f };

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

        // Ken movement logic
        if (IsKeyDown(KEY_A))
        {
            ken.position.x -= ken.speed.x;
        }

        if (IsKeyDown(KEY_D))
        {
            ken.position.x += ken.speed.x;
        }

        if (ken.position.x <= 0) {
            ken.position.x = 0;
        }

        if (ken.position.x + 4 * texKen.width >= screenWidth)
        {
            ken.position.x = screenWidth - 4 * texKen.width;
        }

        // Ryu movement logic
        if (IsKeyDown(KEY_J))
        {
            ryu.position.x -= ryu.speed.x;
        }

        if (IsKeyDown(KEY_L))
        {
            ryu.position.x += ryu.speed.x;
        }

        if (ryu.position.x <= 0) {
            ryu.position.x = 0;
        }

        if (ryu.position.x + 4 * texRyu.width >= screenWidth)
        {
            ryu.position.x = screenWidth - 4 * texRyu.width;
        }
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

            // Todo: Calculate scale to fit background texture to screen
            float screenRatio = (float) screenWidth / screenHeight;
            float imageRatio = (float) texBackground.width / texBackground.height;
            
            Rectangle src = { 0, 0, texBackground.width, texBackground.height };    

            // The screen is wider than the background image
            if (screenRatio > imageRatio)
            {
                // Cut the top and the bottom of image   
                src.height = texBackground.height / screenRatio;
                src.y = (texBackground.height - src.height) / 2.0f;
            }
            else
            {
                // Cut the left and the right of image
                src.width = texBackground.height * screenRatio;
                src.x = (texBackground.width - src.width) / 2.0f;
            }

            Rectangle dest = { 0, 0, screenWidth, screenHeight };

            DrawTexturePro(texBackground, src, dest, (Vector2){ 0, 0}, 0.0f, WHITE);

            if (exitWindowRequested)
            {
                DrawRectangle(0, 100, screenWidth, 200, BLACK);
                DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
            }
            else
            {
                DrawTextureEx(texKen, ken.position, 0.0f, 4.0f, WHITE);
                DrawTextureEx(texRyu, ryu.position, 0.0f, 4.0f, WHITE);
            }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    UnloadTexture(texKen);

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
