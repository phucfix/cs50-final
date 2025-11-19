#include "../include/game_screen.h"
#include "../include/helper.h"
#include "../include/draw.h"

#include "raylib.h"

void Update(GameScreen* screen, int* framesCounter)
{
    switch (*screen)
    {
        case LOGO:
        {
            (*framesCounter)++;
            if (*framesCounter > 120)
            {
                *screen = TITLE;
            }
        } break;
        case TITLE:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                *screen = GAMEPLAY;
            }
        } break;
        case GAMEPLAY:
        {

        } break;
        case ENDING:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                *screen = TITLE;
            }
        } break;
        default: break;
    }
}

void Draw(GameScreen screen, int screenWidth, int screenHeight, bool exitRequested)
{
    BeginDrawing();
    
        ClearBackground(RAYWHITE);

        switch (screen)
        {
            case LOGO:
            {
                DrawLogo();
            } break;
            case TITLE:
            {
                DrawTitle();
            } break;
            case GAMEPLAY:
            {
                DrawGamePlay();
            } break;
            case ENDING:
            {
                DrawEnding();
            } break;

            default: break;
        }

        if (exitRequested) DrawExitConfirmationMessage(screenWidth, screenHeight);

    EndDrawing();
}
