#include "board.h"
#include "raylib.h"
#include "shape.h"
#include "shapes.h"

typedef struct Game {
  Board board;
  Shape shapes[7];
  bool seen[7];
  Shape currentShape;
  Shape nextShape;
  bool isGameOver;
  int score;

} Game;

void Game_Init(Game *g);
void Game_Draw(Game *g);
Shape Game_GetRandomShape(Game *g);
void Game_Input(Game *g);
void Game_MoveShapeLeft(Game *g);
void Game_MoveShapeRight(Game *g);
void Game_MoveShapeDown(Game *g);
bool Game_IsShapeOutOfBounds(Game *g);
void Game_RotateShape(Game *g);
void Game_HoldShape(Game *g);
bool Game_ShapeFits(Game *g);
void Game_Reset(Game *g);
