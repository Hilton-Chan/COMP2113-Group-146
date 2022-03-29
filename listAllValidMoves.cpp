#include <iostream>
#include <string>
#include <stdio.h>

// Finished Functions (require importing)
bool isValidMove(int board[][8], int position[], int player);

// Not Yet Finished Functions
int calculateMoveFlips(int board[][8], int position);
void makeMove(int board[][8], int position[], int player);

// validMovesArr array shape int arr[8][8], 1 = validMove, 0 = invalidMove
void listAllValidMoves(int board[][8], int validMovesArr[][8], int player) {
  int counter = 0;
  for (int row=0; row<8; row++) {
    for (int col=0; col<8; col++) {
      int position[2] = {row, col};
      if (board[row][col] == 0 && isValidMove(board, position, player)) {
        validMovesArr[row][col] = 1;
        counter++;
      }
    }
  }
  return;
}

void botMoveDecision(int board[][8], int validMovesArr[][8], int player) {
  int flips[64] = { 0 };

  for (int row=0; row<8; row++) {
    for (int col=0; col<8; col++) {
      if (validMovesArr[row][col] == 1) {
        flips[(row * 8) + col] = calculateMoveFlips(board, board[row][col]);
      }
    }
  }

  int max = 0;
  for (int i = 0; i < 64; i++) {
    if (flips[i] > max) {
      max = flips[i];
    }
  }
  
  int position[2] = {(max / 8), (max % 8)};
  makeMove(board, position, player);
}