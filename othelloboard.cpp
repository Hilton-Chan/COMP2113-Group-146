#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

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


// prereqs: ensure the board size value is even number
//          ensure the size is larger or equal to 6 
vector < vector<int> > boardInitalize(int size) {
  vector < vector<int> > board;
  
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

void showPossibleMoves(vector < vector<int> > board, vector < vector<int> > validMovesArr) {
  int row = 0;
  string piece;
  cout << 
  cout << LINEROW << endl;
  
  while (row != 8) {
    for (int col=0; col < 8; col++) {
      if (board[row][col] == 0 && validMovesArr[row][col] != 0) {
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

int countTotalPieces(vector < vector<int> > board, int player) {
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