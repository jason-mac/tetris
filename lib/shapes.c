#include "../include/shapes.h"
#include "../include/shape.h"

Shape ShapeT_Init(ShapeT *t) {
  Shape *super = &t->shape;
  Shape_Init(super);
  super->type = SHAPE_T;
  super->rotationState = ONE;

  super->stateOne[0] = (Vector2){0, 1};
  super->stateOne[1] = (Vector2){1, 0};
  super->stateOne[2] = (Vector2){1, 1};
  super->stateOne[3] = (Vector2){1, 2};

  super->stateTwo[0] = (Vector2){0, 1};
  super->stateTwo[1] = (Vector2){1, 1};
  super->stateTwo[2] = (Vector2){2, 1};
  super->stateTwo[3] = (Vector2){1, 2};

  super->stateThree[0] = (Vector2){1, 0};
  super->stateThree[1] = (Vector2){1, 1};
  super->stateThree[2] = (Vector2){1, 2};
  super->stateThree[3] = (Vector2){2, 1};

  super->stateFour[0] = (Vector2){0, 1};
  super->stateFour[1] = (Vector2){1, 1};
  super->stateFour[2] = (Vector2){2, 1};
  super->stateFour[3] = (Vector2){1, 0};
  Shape_Move(super, 0, 3);
  return *super;
}

Shape ShapeO_Init(ShapeO *O) {
  Shape *super = &O->shape;
  Shape_Init(super);
  super->type = SHAPE_O;
  super->rotationState = ONE;

  super->stateOne[0] = (Vector2){0, 0};
  super->stateOne[1] = (Vector2){0, 1};
  super->stateOne[2] = (Vector2){1, 1};
  super->stateOne[3] = (Vector2){1, 0};

  super->stateTwo[0] = (Vector2){0, 0};
  super->stateTwo[1] = (Vector2){0, 1};
  super->stateTwo[2] = (Vector2){1, 1};
  super->stateTwo[3] = (Vector2){1, 0};

  super->stateThree[0] = (Vector2){0, 0};
  super->stateThree[1] = (Vector2){0, 1};
  super->stateThree[2] = (Vector2){1, 1};
  super->stateThree[3] = (Vector2){1, 0};

  super->stateFour[0] = (Vector2){0, 0};
  super->stateFour[1] = (Vector2){0, 1};
  super->stateFour[2] = (Vector2){1, 1};
  super->stateFour[3] = (Vector2){1, 0};
  Shape_Move(super, 0, 4);
  return *super;
}

Shape ShapeI_Init(ShapeI *i) {
  Shape *super = &i->shape;
  Shape_Init(super);
  super->type = SHAPE_I;
  super->rotationState = ONE;

  super->stateOne[0] = (Vector2){1, 0};
  super->stateOne[1] = (Vector2){1, 1};
  super->stateOne[2] = (Vector2){1, 2};
  super->stateOne[3] = (Vector2){1, 3};

  super->stateTwo[0] = (Vector2){0, 2};
  super->stateTwo[1] = (Vector2){1, 2};
  super->stateTwo[2] = (Vector2){2, 2};
  super->stateTwo[3] = (Vector2){3, 2};

  super->stateThree[0] = (Vector2){2, 0};
  super->stateThree[1] = (Vector2){2, 1};
  super->stateThree[2] = (Vector2){2, 2};
  super->stateThree[3] = (Vector2){2, 3};

  super->stateFour[0] = (Vector2){0, 1};
  super->stateFour[1] = (Vector2){1, 1};
  super->stateFour[2] = (Vector2){2, 1};
  super->stateFour[3] = (Vector2){3, 1};
  Shape_Move(super, -1, 3);
  return *super;
}

Shape ShapeS_Init(ShapeS *s) {
  Shape *super = &s->shape;
  Shape_Init(super);
  super->type = SHAPE_S;
  super->rotationState = ONE;

  super->stateOne[0] = (Vector2){1, 0};
  super->stateOne[1] = (Vector2){1, 1};
  super->stateOne[2] = (Vector2){0, 1};
  super->stateOne[3] = (Vector2){0, 2};

  super->stateTwo[0] = (Vector2){0, 1};
  super->stateTwo[1] = (Vector2){1, 1};
  super->stateTwo[2] = (Vector2){1, 2};
  super->stateTwo[3] = (Vector2){2, 2};

  super->stateThree[0] = (Vector2){2, 0};
  super->stateThree[1] = (Vector2){2, 1};
  super->stateThree[2] = (Vector2){1, 1};
  super->stateThree[3] = (Vector2){1, 2};

  super->stateFour[0] = (Vector2){0, 0};
  super->stateFour[1] = (Vector2){1, 0};
  super->stateFour[2] = (Vector2){1, 1};
  super->stateFour[3] = (Vector2){2, 1};
  Shape_Move(super, 0, 3);
  return *super;
}

Shape ShapeZ_Init(ShapeZ *z) {
  Shape *super = &z->shape;
  Shape_Init(super);
  super->type = SHAPE_Z;
  super->rotationState = ONE;

  super->stateOne[0] = (Vector2){0, 0};
  super->stateOne[1] = (Vector2){0, 1};
  super->stateOne[2] = (Vector2){1, 1};
  super->stateOne[3] = (Vector2){1, 2};

  super->stateTwo[0] = (Vector2){0, 2};
  super->stateTwo[1] = (Vector2){1, 1};
  super->stateTwo[2] = (Vector2){1, 2};
  super->stateTwo[3] = (Vector2){2, 1};

  super->stateThree[0] = (Vector2){1, 0};
  super->stateThree[1] = (Vector2){1, 1};
  super->stateThree[2] = (Vector2){2, 1};
  super->stateThree[3] = (Vector2){2, 2};

  super->stateFour[0] = (Vector2){0, 2};
  super->stateFour[1] = (Vector2){1, 1};
  super->stateFour[2] = (Vector2){1, 2};
  super->stateFour[3] = (Vector2){2, 1};
  Shape_Move(super, 0, 3);
  return *super;
}

Shape ShapeL_Init(ShapeL *l) {
  Shape *super = &l->shape;
  Shape_Init(super);
  super->type = SHAPE_L;
  super->rotationState = ONE;

  super->stateOne[0] = (Vector2){1, 0};
  super->stateOne[1] = (Vector2){1, 1};
  super->stateOne[2] = (Vector2){1, 2};
  super->stateOne[3] = (Vector2){0, 2};

  super->stateTwo[0] = (Vector2){0, 1};
  super->stateTwo[1] = (Vector2){1, 1};
  super->stateTwo[2] = (Vector2){2, 1};
  super->stateTwo[3] = (Vector2){2, 2};

  super->stateThree[0] = (Vector2){1, 0};
  super->stateThree[1] = (Vector2){1, 1};
  super->stateThree[2] = (Vector2){1, 2};
  super->stateThree[3] = (Vector2){2, 0};

  super->stateFour[0] = (Vector2){0, 0};
  super->stateFour[1] = (Vector2){0, 1};
  super->stateFour[2] = (Vector2){1, 1};
  super->stateFour[3] = (Vector2){2, 1};
  Shape_Move(super, 0, 3);
  return *super;
}

Shape ShapeJ_Init(ShapeJ *j) {
  Shape *super = &j->shape;
  Shape_Init(super);
  super->type = SHAPE_J;
  super->rotationState = ONE;

  super->stateOne[0] = (Vector2){0, 0};
  super->stateOne[1] = (Vector2){1, 0};
  super->stateOne[2] = (Vector2){1, 1};
  super->stateOne[3] = (Vector2){1, 2};

  super->stateTwo[0] = (Vector2){0, 2};
  super->stateTwo[1] = (Vector2){0, 1};
  super->stateTwo[2] = (Vector2){1, 1};
  super->stateTwo[3] = (Vector2){2, 1};

  super->stateThree[0] = (Vector2){1, 0};
  super->stateThree[1] = (Vector2){1, 1};
  super->stateThree[2] = (Vector2){1, 2};
  super->stateThree[3] = (Vector2){2, 2};

  super->stateFour[0] = (Vector2){2, 0};
  super->stateFour[1] = (Vector2){0, 1};
  super->stateFour[2] = (Vector2){1, 1};
  super->stateFour[3] = (Vector2){2, 1};
  Shape_Move(super, 0, 3);
  return *super;
}
