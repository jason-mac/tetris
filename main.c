#include "include/board.h"
#include "include/colors.h"
#include "include/config.h"
#include "include/game.h"
#include "include/shape.h"
#include "include/shapes.h"

#include "raylib.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_pthread/_pthread_t.h>
#include <time.h>

bool windowShouldClose = false;

// HELPER FUNCTIONS
void Init();

void PrintBoard(const Board b);

void *MoveDownThread(void *arg) {
  Game *g = (Game *)arg;
  struct timespec ts = {.tv_nsec = 200 * 1000000L};
  while (!windowShouldClose) {
    nanosleep(&ts, NULL);
    if (!g->isGameOver) {
      Game_MoveShapeDown(g);
    }
  }
  return NULL;
};

int main(void) {
  Init();
  Font font = LoadFontEx("font/Cabal-w5j3.ttf", 64, 0, 0);
  pthread_t tMoveDown;
  Game game;
  char scoreBuffer[sizeof(int) * 8];
  Game_Init(&game);
  pthread_create(&tMoveDown, NULL, MoveDownThread, &game);
  pthread_detach(tMoveDown);
  while (!(windowShouldClose = WindowShouldClose())) {

    Game_Input(&game);
    BeginDrawing();

    ClearBackground(INDIGO);
    DrawTextEx(font, "Score", (Vector2){350, 15}, 38, 2, WHITE);
    DrawTextEx(font, "Next", (Vector2){350, 170}, 38, 2, WHITE);
    if (game.isGameOver) {
      DrawTextEx(font, "GAME OVER", (Vector2){320, 425}, 30, 2, WHITE);
    }

    DrawRectangleRounded((Rectangle){320, 55, 160, 60}, 0.2, 6, SKYBLUE);
    sprintf(scoreBuffer, "%d", game.score);
    Vector2 textSize = MeasureTextEx(font, scoreBuffer, 38, 2);
    DrawTextEx(font, scoreBuffer, (Vector2){320 + (160 - textSize.x) / 2, 65},
               38, 2, WHITE);

    DrawRectangleRounded((Rectangle){320, 225, 160, 180}, 0.2, 6, darkGrey);
    DrawCircle(320, 225, 5.0, WHITE);
    Game_Draw(&game);

    EndDrawing();
  }
  CloseWindow();
  return EXIT_SUCCESS;
}

void Init() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
  SetTargetFPS(60);
}
