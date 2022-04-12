#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
//link isValidMove()

using namespace std;

vector < vector<int> > isValidMove(vector < vector<int> > board, int position[], int player);


void makeMove(vector < vector<int> > board, int position[], int player) {
  vector<vector<int> > flip_tiles = isValidMove(board, position, player);

  board[position[0]][position[1]] = player;
  
  for(int i = 0; i < flip_tiles.size(); i++){
    board[flip_tiles[i][0]][flip_tiles[i][1]] = player;
  }
}