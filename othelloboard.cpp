#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "othelloboard.h"

using namespace std;

// 0 = NONE
// 1 = WHITE
// 2 = BLACK
// POSSIBLE based on validMovesArr[]

string BLACK = "\u25CB";
string WHITE = "\u25CF";
string NONE = " ";
string POSSIBLE = "\u2022";
string LINEROW = "  +---+---+---+---+---+---+---+---+";
string NUMBER = "   1   2   3   4   5   6   7   8";
string ALPHABET = "ABCDEFGH";


// prereqs: ensure the board size value is even number
//          ensure the size is larger or equal to 6 
vector < vector<int> > boardInitalize(int size) {  
  vector<vector<int> > board(
    size,
    vector<int>(size));

  int start_tile_player_1 = (size / 2) - 1;
  board[start_tile_player_1][start_tile_player_1] = 1;
  board[start_tile_player_1][start_tile_player_1 + 1] = 2;
  board[start_tile_player_1 + 1][start_tile_player_1] = 2;
  board[start_tile_player_1 + 1][start_tile_player_1 + 1] = 1;
  
  return board;
}

void printBoard(vector < vector<int> > board) {
  int size = board.size();
  int row = 0;
  string piece;
  cout << NUMBER << endl;
  cout << LINEROW << endl;
  
  while (row != size) {
    for (int col=0; col < size; col++) {
      if (board[row][col] == 0) {
        piece = NONE;
      } else if (board[row][col] == 1) {
        piece = BLACK;
      } else {
        piece = WHITE;
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

void showPossibleMoves(vector < vector<int> > board, vector < vector<int> > validMovesArr) {
  int size = board.size();
  int row = 0;
  string piece;
  cout << NUMBER << endl;
  cout << LINEROW << endl;
  
  while (row != size) {
    for (int col=0; col < size; col++) {
      if (board[row][col] == 0 && validMovesArr[row][col] != 0) {
        piece = POSSIBLE;
      } else if (board[row][col] == 0) {
        piece = NONE;
      } else if (board[row][col] == 1) {
        piece = BLACK;
      } else {
        piece = WHITE;
      }
      if (col == 0) {
        cout << ALPHABET[row] << " | " << piece << " | ";
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

bool boardEmpty(vector < vector<int> > board) {
  int size = board.size();
  for (int row=0; row<size; row++) {
    for (int col=0; col<size; col++) {
      if (board[row][col] == 0) {
        return 1;
      }
    }
  }
  return 0;
}