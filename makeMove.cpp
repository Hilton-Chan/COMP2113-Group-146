#include <iostream>
#include <string>
#include <stdio.h>
//link isValidMove()

// vector.isempty
bool makeMove(int board[][8], int position[], int player){
  vector<int> flip_tiles = isValidMove(int board[][8], int position[], int player);

  if(flip_tiles.empty()){
    return false;
  }
  else{
    board[position[0]][position[1]] = player;
    
    for(int i = 0; i < flip_tiles.size(); i ++){
      board[flip_tiles[i][0]][flip_tiles[i][1]] = player;
    }
    return true;
  }
}