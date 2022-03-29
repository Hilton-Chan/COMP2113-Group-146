#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

// 0 = NONE
// 1 = WHITE
// 2 = BLACK
// POSSIBLE based on validMovesArr[]

string BLACK = "\u25CB";
string WHITE = "\u25CF";
string NONE = " ";
string POSSIBLE = "\u2022";
string LINEROW = "+---+---+---+---+---+---+---+---+";
string NUMBER = "  1   2   3   4   5   6   7   8";
string ALPHABET = "ABCDEFGH";

void printBoard(int board[][8]) {
  int row = 0;
  string piece;
  cout << LINEROW << endl;
  
  while (row != 8) {
    for (int col=0; col < 8; col++) {
      if (board[row][col] == 0) {
        piece = NONE;
      } else if (board[row][col] == 1) {
        piece = WHITE;
      } else {
        piece = BLACK;
      }
      if (col == 0) {
        cout << ALPHABET[row] << "| " << piece << " | ";
      } else if (col == 7) {
        cout << piece << " | " << endl;
      } else {
        cout << piece << " | ";
      }
    }

    cout << LINEROW << endl;
    row++;
  }
}

// validMovesArr[64] = (row * 8) + (col % 8)

void showPossibleMoves(int board[][8], int validMovesArr[]) {
  int row = 0;
  string piece;
  cout << 
  cout << LINEROW << endl;
  
  while (row != 8) {
    for (int col=0; col < 8; col++) {
      if (board[row][col] == 0 && validMovesArr[(row * 8 + col % 8)] == 1) {
        piece = POSSIBLE;
      } else if (board[row][col] == 0) {
        piece = NONE;
      } else if (board[row][col] == 1) {
        piece = WHITE;
      } else {
        piece = BLACK;
      }
      if (col == 0) {
        cout << ALPHABET[row] << "| " << piece << " | ";
      } else if (col == 7) {
        cout << piece << " | " << endl;
      } else {
        cout << piece << " | ";
      }
    }

    cout << LINEROW << endl;
    row++;
  }
}

int countTotalPieces(int board[][8], int player) {
  int counter = 0;
  for (int row=0; row<8; row++) {
    for (int col=0; col<8; col++) {
      if (board[row][col] == player) {
        counter++;
      }
    }
  }
  return counter;
}