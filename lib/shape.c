#include "../include/shape.h"
#include "../include/colors.h"
#include "../include/config.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

void Shape_Init(Shape *s) {
  s->colors = getColors();
  s->rowOffSet = 0;
  s->colOffSet = 0;
  s->rotationState = ONE;
}

void Shape_Get_Cell_Positions(Shape *s, Vector2 *movedCells) {
  Vector2 *cells = NULL;
  switch (s->rotationState) {
  case ONE:
    cells = s->stateOne;
    break;
  case TWO:
    cells = s->stateTwo;
    break;
  case THREE:
    cells = s->stateThree;
    break;
  case FOUR:
    cells = s->stateFour;
    break;
  }
  for (int i = 0; i < 4; i++) {
    movedCells[i].x = cells[i].x + s->rowOffSet;
    movedCells[i].y = cells[i].y + s->colOffSet;
  }
}

void Shape_Rotate(Shape *s) { s->rotationState = (s->rotationState + 1) % 4; }
void Shape_Undo_Rotation(Shape *s) {
  s->rotationState = (s->rotationState - 1) % 4;
}

void Shape_Move(Shape *s, int rows, int cols) {
  s->rowOffSet += rows;
  s->colOffSet += cols;
}

void Shape_Draw(Shape *s, int offSetX, int offSetY) {
  Vector2 cells[4];
  Shape_Get_Cell_Positions(s, cells);
  for (int i = 0; i < 4; i++) {
    Vector2 vec = cells[i];
    DrawRectangle(vec.y * CELL_SIZE + offSetY, vec.x * CELL_SIZE + offSetX,
                  CELL_SIZE - 1, CELL_SIZE - 1, s->colors[s->type + 1]);
  }
}
