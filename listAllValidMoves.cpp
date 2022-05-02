#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "isValidMove.h"
#include "listAllValidMoves.h"

using namespace std;

void makeMove(vector < vector<int> > &board, int row, int col, int player) {
  int position[2] = {row, col};
  vector<vector<int> > flip_tiles = isValidMove(board, position, player);
  board[position[0]][position[1]] = player;
  
  for (int i = 0; i < flip_tiles.size(); i++) {
    for (int j = 0; j < flip_tiles[i].size(); j += 2) {
      board[flip_tiles[i][j]][flip_tiles[i][j + 1]] = player;
    }
  }
}

void botMove(vector < vector<int> > &board, int bot_position[] ,vector < vector<int> > validMovesArr, int player) {
  srand(time(NULL));
  int size = board.size();
  vector<int> validPositionList;
  validPositionList.clear();
  for (int row=0; row<size; row++) {
    for (int col=0; col<size; col++) {
      if (validMovesArr[row][col] != 0) {
        int value = (row * size) + col;
        validPositionList.push_back(value);
      }
    }
  }

  int validsize = validPositionList.size();
  if (validsize != 1) {
    int randomMove = rand() % validsize;
    bot_position[0] = validPositionList[randomMove] / 8;
    bot_position[1] = validPositionList[randomMove] % 8;
  } else {
    bot_position[0] = (validPositionList[0] / 8);
    bot_position[1] = (validPositionList[0] % 8);
  }
  
  makeMove(board, bot_position[0], bot_position[1], 2);
}

vector < vector<int> > findAllPossibleMoves(vector < vector<int> > board, int player) {
  int size = board.size();
  vector < vector<int> > validMovesArr(size, vector<int> (size));
  for (int row=0; row<size; row++) {
    for (int col=0; col<size; col++) {
      int position[2] = {row, col};
      if (board[row][col] == 0) {
        vector < vector<int> > moves = isValidMove(board, position, player);
        if (!moves.empty()) {
          validMovesArr[row][col] = moves.size();
        } else {
          validMovesArr[row][col] = 0;
        }
      }
    }
  }
  return validMovesArr;
}

bool noPossibleMoves(vector < vector<int> > validMovesArr) {
  int size = validMovesArr.size(); 
  for (int row=0; row<size; row++) {
    for (int col=0; col<size; col++) {
      if (validMovesArr[row][col] != 0) {
        return 0;
      }
    }
  }
  return 1;
}