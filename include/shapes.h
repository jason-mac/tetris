#ifndef SHAPES_H
#define SHAPES_H

#include "raylib.h"
#include "shape.h"

typedef struct ShapeT {
  Shape shape;
} ShapeT;
Shape ShapeT_Init(ShapeT *t);

typedef struct ShapeO {
  Shape shape;
} ShapeO;
Shape ShapeO_Init(ShapeO *o);

typedef struct ShapeI {
  Shape shape;
} ShapeI;
Shape ShapeI_Init(ShapeI *i);

typedef struct ShapeS {
  Shape shape;
} ShapeS;
Shape ShapeS_Init(ShapeS *s);

typedef struct ShapeZ {
  Shape shape;
} ShapeZ;
Shape ShapeZ_Init(ShapeZ *z);

typedef struct ShapeL {
  Shape shape;
} ShapeL;
Shape ShapeL_Init(ShapeL *l);

typedef struct ShapeJ {
  Shape shape;
} ShapeJ;
Shape ShapeJ_Init(ShapeJ *j);

#endif // SHAPES_H
