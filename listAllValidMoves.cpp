#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

vector < vector<int> > isValidMove(vector < vector<int> > board, int position[], int player);
void makeMove(vector < vector<int> > board, int position[], int player);

int* botMove(vector < vector<int> > board, vector < vector<int> > validMovesArr, int player) {
  int size = board.size();
  int max = 0;
  int position [2] = {-1, -1};
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (validMovesArr[row][col] > max) {
        max = validMovesArr[row][col];
        position[0] = row;
        position[1] = col;
      }
      
      if (position[0] != -1 && position[1] != -1) {
        makeMove(board, position, player);
        return position;
      }
    }
  }
  return position;
}

vector < vector<int> > findAllPossibleMoves(vector < vector<int> > board, int player) {
  vector < vector<int> > validMovesArr;
  int size = board.size(); 
  for (int row=0; row<size; row++) {
    for (int col=0; col<size; col++) {
      int position[2] = {row, col};
      vector < vector<int> > moves = isValidMove(board, position, player);
      if (!moves.empty()) {
        validMovesArr[row][col] = moves.size();
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