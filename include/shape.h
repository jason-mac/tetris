#ifndef SHAPE_H
#define SHAPE_H

#include "raylib.h"

typedef enum ShapeType {
  SHAPE_O,
  SHAPE_I,
  SHAPE_S,
  SHAPE_Z,
  SHAPE_L,
  SHAPE_J,
  SHAPE_T,
} ShapeType;

typedef enum RotationState { ONE, TWO, THREE, FOUR } RotationState;

typedef struct Shape {
  ShapeType type;
  const Color *colors;
  RotationState rotationState;
  int rowOffSet;
  int colOffSet;
  Vector2 stateOne[4];
  Vector2 stateTwo[4];
  Vector2 stateThree[4];
  Vector2 stateFour[4];
} Shape;

void Shape_Init(Shape *s);
void Shape_Rotate(Shape *s);
void Shape_Undo_Rotation(Shape *s);
void Shape_Get_Cell_Positions(Shape *s, Vector2 *movedCells);
void Shape_Draw(Shape *s, int offSetX, int offSetY);
void Shape_Move(Shape *s, int rows, int cols);
#endif
