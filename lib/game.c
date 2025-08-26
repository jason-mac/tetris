#include "../include/game.h"
#include "../include/board.h"
#include "../include/shape.h"
#include "../include/shapes.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

bool Game_IsShapeOutOfBounds(Game *g) {
  Shape shape = g->currentShape;
  Vector2 cells[4];
  Shape_Get_Cell_Positions(&g->currentShape, cells);
  for (int i = 0; i < 4; i++) {
    if (Board_IsCellOutOfBounds((int)cells[i].x, (int)cells[i].y)) {
      return true;
    }
  }
  return false;
}
void SetShapes(Game *g) {
  // this is troll, super troll
  g->shapes[0] = ShapeO_Init(&(ShapeO){0});
  g->shapes[1] = ShapeI_Init(&(ShapeI){0});
  g->shapes[2] = ShapeS_Init(&(ShapeS){0});
  g->shapes[3] = ShapeZ_Init(&(ShapeZ){0});
  g->shapes[4] = ShapeL_Init(&(ShapeL){0});
  g->shapes[5] = ShapeJ_Init(&(ShapeJ){0});
  g->shapes[6] = ShapeT_Init(&(ShapeT){0});
}

void Game_Init(Game *g) {
  Board_Init(&g->board);
  g->score = 0;
  g->isGameOver = false;
  SetShapes(g);
  for (int i = 0; i < 7; i++) {
    g->seen[i] = false;
  }
  g->currentShape = Game_GetRandomShape(g);
  g->nextShape = Game_GetRandomShape(g);
}

void Game_Reset(Game *g) { Game_Init(g); }

Shape Game_GetRandomShape(Game *g) {
  int randomShapesIndex = GetRandomValue(0, 6);
  int count = 0;
  while (count != 7) {
    if (!g->seen[randomShapesIndex]) {
      g->seen[randomShapesIndex] = true;
      return g->shapes[randomShapesIndex];
    }
    count++;
    randomShapesIndex = (randomShapesIndex + 1) % 7;
  }
  SetShapes(g);
  for (int i = 0; i < count; i++) {
    g->seen[i] = false;
  }
  return g->shapes[randomShapesIndex];
}

void Game_Draw(Game *g) {
  Board_Draw(&g->board);
  Shape_Draw(&g->currentShape, 11, 11);
  Shape shape = g->nextShape;
  shape.colOffSet = 0;
  shape.rowOffSet = 0;
  switch (shape.type) {
  case SHAPE_O:
    Shape_Draw(&shape, 225 + 60, 320 + 50);
    break;
  case SHAPE_T:
    Shape_Draw(&shape, 315 - 30, 400 - 45);
    break;
  case SHAPE_S:
    Shape_Draw(&shape, 315 - 30, 400 - 45);
    break;
  case SHAPE_Z:
    Shape_Draw(&shape, 315 - 30, 400 - 45);
    break;
  case SHAPE_L:
    Shape_Draw(&shape, 315 - 45, 400 - 45);
    break;
  case SHAPE_J:
    Shape_Draw(&shape, 315 - 45, 400 - 45);
    break;
  case SHAPE_I:
    Shape_Draw(&shape, 315 - 45, 400 - 60);
    break;
  }
}

void Game_MoveShapeLeft(Game *g) {
  if (g->isGameOver) {
    return;
  }
  Shape_Move(&g->currentShape, 0, -1);
  if (Game_IsShapeOutOfBounds(g) || !Game_ShapeFits(g)) {
    Shape_Move(&g->currentShape, 0, 1);
  }
}

void Game_MoveShapeRight(Game *g) {
  if (g->isGameOver) {
    return;
  }
  Shape_Move(&g->currentShape, 0, 1);
  if (Game_IsShapeOutOfBounds(g) || !Game_ShapeFits(g)) {
    Shape_Move(&g->currentShape, 0, -1);
  }
}

void Game_MoveShapeDown(Game *g) {
  if (g->isGameOver) {
    return;
  }
  Shape_Move(&g->currentShape, 1, 0);
  if (Game_IsShapeOutOfBounds(g) || !Game_ShapeFits(g)) {
    Shape_Move(&g->currentShape, -1, 0);
    Game_HoldShape(g);
  }
}

void Game_RotateShape(Game *g) {
  if (g->isGameOver) {
    return;
  }
  Shape_Rotate(&g->currentShape);
  if (Game_IsShapeOutOfBounds(g) || !Game_ShapeFits(g)) {
    Shape_Undo_Rotation(&g->currentShape);
  }
}

void Game_Input(Game *g) {
  int keyPressed = GetKeyPressed();
  if (g->isGameOver && keyPressed != 0) {
    Game_Reset(g);
  }
  switch (keyPressed) {
  case KEY_LEFT:
    Game_MoveShapeLeft(g);
    break;
  case KEY_RIGHT:
    Game_MoveShapeRight(g);
    break;
  case KEY_DOWN:
    Game_MoveShapeDown(g);
    break;
  case KEY_UP:
    Game_RotateShape(g);
    break;
  }
}

void Game_HoldShape(Game *g) {
  Vector2 cells[4];
  Shape_Get_Cell_Positions(&g->currentShape, cells);
  for (int i = 0; i < 4; i++) {
    Vector2 cell = cells[i];
    g->board.board[(int)cell.x][(int)cell.y] = g->currentShape.type + 1;
  }
  g->currentShape = g->nextShape;
  g->nextShape = Game_GetRandomShape(g);
  if (!Game_ShapeFits(g)) {
    g->isGameOver = true;
  }
  g->score += Board_ClearRows(&g->board);
}

bool Game_ShapeFits(Game *g) {
  Vector2 cells[4];
  Shape_Get_Cell_Positions(&g->currentShape, cells);
  for (int i = 0; i < 4; i++) {
    Vector2 cell = cells[i];
    if (!Board_IsCellEmpty(&g->board, cell.x, cell.y)) {
      return false;
    }
  }
  return true;
}
