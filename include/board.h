#ifndef BOARD_H
#define BOARD_H

#define NUM_ROWS 20
#define NUM_COLUMNS 10

#include "config.h"
#include "raylib.h"

typedef struct Board {
  int board[NUM_ROWS][NUM_COLUMNS];
  const Color *colors;
} Board;

void Board_Init(Board *b);
void Board_Draw(Board *b);
bool Board_IsCellOutOfBounds(int row, int col);
bool Board_IsCellEmpty(const Board *b, int row, int col);
bool Board_IsRowFull(Board *b, int row);
void Board_ClearRow(Board *b, int row);
void Board_MoveRowDown(Board *b, int row, int numRows);
int Board_ClearRows(Board *b);

#endif
