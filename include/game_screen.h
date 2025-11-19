#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

typedef enum GameScreen {
    LOGO = 0, TITLE, GAMEPLAY, ENDING
} GameScreen;

void Update(GameScreen* screen, int* framesCounter);
void Draw(GameScreen screen, int screenWidth, int screenHeight, bool exitRequested);

#endif
