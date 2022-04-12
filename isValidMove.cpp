#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

//row = vertical, col = horizontal
//checks for x direction of where tile is placed
bool horizontalLeftCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > flip_tiles) {
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
        vector<int> tiles;
        tiles.push_back(position[0]);
        tiles.push_back(i);
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool horizontalRightCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > flip_tiles) {
  int size = board.size();
  if (position[1] <= (size - 3)) {
    if ((board[position[0]][position[1]+1]) == player) {
        return 0;
    }
    for (int i=position[1] + 1;i<=(size - 1); i++) {
      if (board[position[0]][i] == player) {
        return 1;
      }
      else{
        vector<int> tiles;
        tiles.push_back(position[0]);
        tiles.push_back(i);
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool verticalUpwardCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > flip_tiles) {
  if (position[0] >= 2) {
    if ((board[position[0]-1][position[1]]) == player) {
        return 0;
    }
    for (int i=position[0] + 1;i<=0; i--) {
      if (board[i][position[1]] == player) {
        return 1;
      }
      else{
        vector<int> tiles;
        tiles.push_back(i);
        tiles.push_back(position[1]);
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool verticalDownwardCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > flip_tiles) {
  int size = board.size();
  if (position[0] <= (size - 3)) {
    if ((board[position[0]+1][position[1]]) == player) {
        return 0;
    }
    for (int i=position[0] + 1;i<=(size - 1); i++) {
      if (board[i][position[1]] == player) {
        return 1;
      }
      else{
        vector<int> tiles;
        tiles.push_back(i);
        tiles.push_back(position[1]);
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool diagonalLeftUpCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > flip_tiles) {
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
        vector<int> tiles;
        tiles.push_back(position[0]-i);
        tiles.push_back(position[1]-i);
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool diagonalRightUpCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > flip_tiles) {
  int size = board.size();
  if (position[0] >= 2 && position[1] <= (size - 3)) {
    if ((board[position[0]+1][position[1]-1]) == player) {
      return 0;
    }
    for (int i= position[0]; i >= 1; i--) {
      if (board[position[0]-i][position[1]+i] == player) {
        return 1;
      }
      else{
        vector<int> tiles;
        tiles.push_back(position[0]-i);
        tiles.push_back(position[1]+i);
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool diagonalLeftDownCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > flip_tiles) {
  int size = board.size();
  if (position[0] <= (size - 3) && position[1] >= 2) {
    if ((board[position[0]-1][position[1]+1]) == player) {
      return 0;
    }
    for (int i= (size - 1) - position[0]; i >= 1; i--) {
      if (board[position[0]+i][position[1]-i] == player) {
        return 1;
      }
      else{
        vector<int> tiles;
        tiles.push_back(position[0]+i);
        tiles.push_back(position[1]-i);
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

bool diagonalRightDownCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > flip_tiles) {
  int size = board.size();
  if (position[0] <= (size - 3) && position[1] <= (size - 3)) {
    if ((board[position[0]+1][position[1]+1]) == player) {
      return 0;
    }
    for (int i= (size - 1) - position[0]; i >= 1; i--) {
      if (board[position[0]+i][position[1]+i] == player) {
        return 1;
      }
      else{
        vector<int> tiles;
        tiles.push_back(position[0]+i);
        tiles.push_back(position[1]+i);
        flip_tiles.push_back(tiles);
      }
    }
  }
  return 0;
}

// input: board[row][col]
//        position: [row, col]
//        player: 1: black, 2: white

vector < vector<int> > isValidMove(vector < vector<int> > board, int position[], int player) {
  //define tiles to flip global vector
  vector<vector<int> > flip_tiles;

  horizontalLeftCheck(board, position, player, flip_tiles); 
  horizontalRightCheck(board, position, player, flip_tiles);
  verticalUpwardCheck(board, position, player, flip_tiles);
  verticalDownwardCheck(board, position, player, flip_tiles);
  diagonalLeftUpCheck(board, position, player, flip_tiles);
  diagonalRightUpCheck(board, position, player, flip_tiles);
  diagonalLeftDownCheck(board, position, player, flip_tiles);
  diagonalRightDownCheck(board, position, player, flip_tiles);

  return flip_tiles;
}
