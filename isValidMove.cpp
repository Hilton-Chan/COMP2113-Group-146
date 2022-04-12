#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

//row = vertical, col = horizontal
//checks for x direction of where tile is placed
bool horizontalLeftCheck(int board[][8], int position[], int player, vector<int>& flip_tiles) {
  if (position[1] >= 2) {
    if ((board[position[0]][position[1]-1]) == player) { 
        return 0;
    }
    for (int i=position[1] + 1;i>=0; i--) {
      if (board[position[0]][i] == player) {
        return 1;
      }
      else{
        //pushing vector containing row, col coordinates of tile into vector
        vector<int> tiles = {position[0], [i]};
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool horizontalRightCheck(int board[][8], int position[], int player) {
  if (position[1] <= 5) {
    if ((board[position[0]][position[1]+1]) == player) {
        return 0;
    }
    for (int i=position[1] + 1;i<=7; i++) {
      if (board[position[0]][i] == player) {
        return 1;
      }
      else{
        vector<int> tiles = {position[0], [i]};
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool verticalUpwardCheck(int board[][8], int position[], int player) {
  if (position[0] >= 2) {
    if ((board[position[0]-1][position[1]]) == player) {
        return 0;
    }
    for (int i=position[0] + 1;i<=0; i--) {
      if (board[i][position[1]] == player) {
        return 1;
      }
      else{
        vector<int> tiles = {[i], position[1]};
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool verticalDownwardCheck(int board[][8], int position[], int player) {
  if (position[0] <= 5) {
    if ((board[position[0]+1][position[1]]) == player) {
        return 0;
    }
    for (int i=position[0] + 1;i<=7; i++) {
      if (board[i][position[1]] == player) {
        return 1;
      }
      else{
        vector<int> tiles = {[i], position[1]};
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool diagonalLeftUpCheck(int board[][8], int position[], int player) {
  if (position[0] >= 2 && position[1] >= 2) {
    if ((board[position[0]-1][position[1]-1]) == player) {
      return 0;
    }
    // subtract i from row and col, to check diagonals
    for (int i= position[0]; i >= 1; i--) {
      if (board[position[0]-i][position[1]-i] == player) {
        return 1;
      }
      else{
        vector<int> tiles = {position[0]-i, position[1]-i};
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool diagonalRightUpCheck(int board[][8], int position[], int player) {
  if (position[0] >= 2 && position[1] <= 5) {
    if ((board[position[0]+1][position[1]-1]) == player) {
      return 0;
    }
    for (int i= position[0]; i >= 1; i--) {
      if (board[position[0]-i][position[1]+i] == player) {
        return 1;
      }
      else{
        vector<int> tiles = {position[0]-i, position[1]+i};
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool diagonalLeftDownCheck(int board[][8], int position[], int player) {
  if (position[0] <= 5 && position[1] >= 2) {
    if ((board[position[0]-1][position[1]+1]) == player) {
      return 0;
    }
    for (int i= 7 - position[0]; i >= 1; i--) {
      if (board[position[0]+i][position[1]-i] == player) {
        return 1;
      }
      else{
        vector<int> tiles = {position[0]+i, position[1]-i};
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool diagonalRightDownCheck(int board[][8], int position[], int player) {
  if (position[0] <= 5 && position[1] <= 5) {
    if ((board[position[0]+1][position[1]+1]) == player) {
      return 0;
    }
    for (int i= 7 - position[0]; i >= 1; i--) {
      if (board[position[0]+i][position[1]+i] == player) {
        return 1;
      }
      else{
        vector<int> tiles = {position[0]+i, position[1]+i};
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

// input: board[row][col]
//        position: [row, col]
//        player: 1: black, 2: white

vector<int> isValidMove(int board[], int position[], int player) {
  //define tiles to flip global vector
  vector<int> flip_tiles;

  if (horizontalLeftCheck(flip_tiles) || horizontalRightCheck(flip_tiles) || verticalUpwardCheck(flip_tiles) || 
    verticalDownwardCheck(flip_tiles) || diagonalLeftUpCheck(flip_tiles) || diagonalRightUpCheck(flip_tiles) || 
    diagonalLeftDownCheck(flip_tiles) || diagonalRightDownCheck(flip_tiles) {
    return flip_tiles;
  }
  return flip_tiles;
}
