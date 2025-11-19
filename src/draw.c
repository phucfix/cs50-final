#include "stdio.h"
#include "../include/draw.h"
#include "raylib.h"
#include "raymath.h"

void DrawLogo()
{

}

void DrawTitle()
{

}

void DrawGamePlay()
{

}

void DrawEnding()
{

}

void DrawExitConfirmationMessage(int screenWidth, int screenHeight)
{
    // Define the rectangle will draw the text in
    Rectangle textContainerRect = (Rectangle) { 
        screenWidth * 0.2f, screenHeight * 0.2f, screenWidth * 0.6f, screenHeight * 0.6f 
    };
    DrawRectangleRec(textContainerRect, BLACK);

    // Text to draw
    Font font = GetFontDefault();
    const char* message = "Are you sure you want to exit program? [Y/N]";

    // Get the size of the text to draw
    Vector2 textSize = MeasureTextEx(font, message, 40, 4.0f);

    // Calculate the top-left text position based on the rectangle and alignment
    Vector2 textPos = (Vector2) {
        textContainerRect.x + Lerp(0.0f, textContainerRect.width  - textSize.x, 0.5f),
        textContainerRect.y + Lerp(0.0f, textContainerRect.height - textSize.y, 0.5f)
    };

    DrawTextEx(font, message, textPos, 40, 4.0f, RAYWHITE);
}