#include "../include/helper.h"

void DrawExitConfirmationMessage(int screenWidth)
{
    DrawRectangle(0, 100, screenWidth, 200, BLACK);
    DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
}
