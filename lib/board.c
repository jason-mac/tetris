#include "../include/board.h"
#include "../include/colors.h"
#include "raylib.h"

void Board_Init(Board *b) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLUMNS; j++) {
      b->board[i][j] = 0;
    }
  }
  b->colors = getColors();
}

void Board_Draw(Board *b) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLUMNS; j++) {
      Color color = b->colors[b->board[i][j]];
      DrawRectangle(j * CELL_SIZE + 11, i * CELL_SIZE + 11, CELL_SIZE - 1,
                    CELL_SIZE - 1, color);
    }
  }
}

bool Board_IsCellOutOfBounds(int row, int col) {
  return !(row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLUMNS);
}

bool Board_IsCellEmpty(const Board *b, int row, int col) {
  return b->board[row][col] == 0;
}

bool Board_IsRowFull(Board *b, int row) {
  for (int col = 0; col < NUM_COLUMNS; col++) {
    if (b->board[row][col] == 0) {
      return false;
    }
  }
  return true;
}

void Board_ClearRow(Board *b, int row) {
  for (int col = 0; col < NUM_COLUMNS; col++) {
    b->board[row][col] = 0;
  }
}

void Board_MoveRowDown(Board *b, int row, int numRows) {
  for (int col = 0; col < NUM_COLUMNS; col++) {
    b->board[row + numRows][col] = b->board[row][col];
    b->board[row][col] = 0;
  }
}

int Board_ClearRows(Board *b) {
  int numCompletedRows = 0;
  for (int row = NUM_ROWS - 1; row >= 0; row--) {
    if (Board_IsRowFull(b, row)) {
      Board_ClearRow(b, row);
      numCompletedRows++;
    } else if (numCompletedRows > 0) {
      Board_MoveRowDown(b, row, numCompletedRows);
    }
  }
  return numCompletedRows;
}
