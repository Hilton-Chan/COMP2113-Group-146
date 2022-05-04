#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "isValidMove.h"

using namespace std;

// Returns true if there are pieces to flip in the left horizontal direction 
// Stores the position of tiles flipped inside flip_tiles variable if the move is valid
bool horizontalLeftCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  if (position[1] >= 2) {
    if ((board[position[0]][position[1]-1]) == player || (board[position[0]][position[1]-1]) == 0) { 
        return 0;
    }
    tiles.push_back(position[0]);
    tiles.push_back(position[1] - 1);
    for (int i=position[1] - 2;i>=0; i--) {
      if (board[position[0]][i] == player) {
        flip_tiles.push_back(tiles);
        return 1;
      }
      else if(board[position[0]][i] == 0) {
        return 0;
      }
      else{
        tiles.push_back(position[0]);
        tiles.push_back(i);
      }
    }
  }
  return 0;
}

// Returns true if there are pieces to flip in the right horizontal direction 
// Stores the position of tiles flipped inside flip_tiles variable if the move is valid
bool horizontalRightCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  int size = board.size();
  if (position[1] <= (size - 3)) {
    if ((board[position[0]][position[1]+1]) == player || (board[position[0]][position[1]+1]) == 0) {
        return 0;
    }
    tiles.push_back(position[0]);
    tiles.push_back(position[1] + 1);
    for (int i=position[1] + 2;i<=(size - 1); i++) {
      if (board[position[0]][i] == player) {
        flip_tiles.push_back(tiles);
        return 1;
      }
      else if(board[position[0]][i] == 0) {
        return 0;
      }
      else{
        tiles.push_back(position[0]);
        tiles.push_back(i);
      }
    }
  }
  return 0;
}

// Returns true if there are pieces to flip in the upward vertical direction 
// Stores the position of tiles flipped inside flip_tiles variable if the move is valid
bool verticalUpwardCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  
  if (position[0] >= 2) {
    if ((board[position[0]-1][position[1]]) == player || (board[position[0]-1][position[1]]) == 0) {
        return 0;
    }
    tiles.push_back(position[0] - 1);
    tiles.push_back(position[1]);
    for (int i=position[0] - 2;i>=0; i--) {
      if (board[i][position[1]] == player) {
        flip_tiles.push_back(tiles);
        return 1;
      }
      else if(board[i][position[1]] == 0) {
        return 0;
      }
      else{
        tiles.push_back(i);
        tiles.push_back(position[1]);
      }
    }
  }
  return 0;
}

// Returns true if there are pieces to flip in the downward vertical direction 
// Stores the position of tiles flipped inside flip_tiles variable if the move is valid
bool verticalDownwardCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  int size = board.size();
  if (position[0] <= (size - 3)) {
    if ((board[position[0]+1][position[1]]) == player || (board[position[0]+1][position[1]]) == 0) {
        return 0;
    }
    tiles.push_back(position[0] + 1);
    tiles.push_back(position[1]);
    for (int i=position[0] + 2;i<=(size - 1); i++) {
      if (board[i][position[1]] == player) {
        flip_tiles.push_back(tiles);
        return 1;
      }
      else if(board[i][position[1]] == 0) {
        return 0;
      }
      else{
        tiles.push_back(i);
        tiles.push_back(position[1]);
      }
    }
  }
  return 0;
}

// Returns true if there are pieces to flip in the diagonal upper left (north-west) direction 
// Stores the position of tiles flipped inside flip_tiles variable if the move is valid
bool diagonalLeftUpCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  if (position[0] >= 2 && position[1] >= 2) {
    if ((board[position[0]-1][position[1]-1]) == player || (board[position[0]-1][position[1]-1]) == 0) {
      return 0;
    }
    // subtract i from row and col, to check diagonals
    tiles.push_back(position[0] - 1);
    tiles.push_back(position[1] - 1);
    int incrementor = 2;
    while ((position[0] - incrementor) >= 0 && (position[1] - incrementor) >= 0) {
      if (board[position[0] - incrementor][position[1] - incrementor] == player) {
        flip_tiles.push_back(tiles);
        return 1;
      }
      else if(board[position[0] - incrementor][position[1] - incrementor] == 0) {
        return 0;
      }
      else{
        tiles.push_back(position[0] - incrementor);
        tiles.push_back(position[1] - incrementor);
      }
      incrementor++;
    }
  }
  return 0;
}

// Returns true if there are pieces to flip in the diagonal upper right (north-east) direction 
// Stores the position of tiles flipped inside flip_tiles variable if the move is valid
bool diagonalRightUpCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  int size = board.size();
  if (position[0] >= 2 && position[1] <= (size - 3)) {
    if ((board[position[0]-1][position[1]+1]) == player || (board[position[0]-1][position[1]+1]) == 0) {
      return 0;
    }
    tiles.push_back(position[0] - 1);
    tiles.push_back(position[1] + 1);
    int incrementor = 2;
    while ((position[0] - incrementor) >= 0 && (position[1] + incrementor) <= (size - 1)) {
      if (board[position[0] - incrementor][position[1] + incrementor] == player) {
        flip_tiles.push_back(tiles);        
        return 1;
      }
      else if(board[position[0] - incrementor][position[1] + incrementor] == 0) {
        return 0;
      }
      else{
        tiles.push_back(position[0] - incrementor);
        tiles.push_back(position[1] + incrementor);
      }
      incrementor++;
    }
  }
  return 0;
}

// Returns true if there are pieces to flip in the diagonal lower left (south-west) direction 
// Stores the position of tiles flipped inside flip_tiles variable if the move is valid
bool diagonalLeftDownCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  int size = board.size();
  if (position[0] <= (size - 3) && position[1] >= 2) {
    if ((board[position[0]+1][position[1]-1]) == player || (board[position[0]+1][position[1]-1]) == 0) {
      return 0;
    }
    tiles.push_back(position[0] + 1);
    tiles.push_back(position[1] - 1);
    int incrementor = 2;
    while ((position[0] + incrementor) <= (size - 1) && (position[1] - incrementor) >= 0) {
      if (board[position[0] + incrementor][position[1] - incrementor] == player) {
        flip_tiles.push_back(tiles);        
        return 1;
      }
      else if(board[position[0] + incrementor][position[1] - incrementor] == 0) {
        return 0;
      }
      else{
        tiles.push_back(position[0] + incrementor);
        tiles.push_back(position[1] - incrementor);
      }
      incrementor++;
    }
  }
  return 0;
}

// Returns true if there are pieces to flip in the diagonal lower right (south-east) direction 
// Stores the position of tiles flipped inside flip_tiles variable if the move is valid
bool diagonalRightDownCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  int size = board.size();
  if (position[0] <= (size - 3) && position[1] <= (size - 3)) {
    if ((board[position[0]+1][position[1]+1]) == player || (board[position[0]+1][position[1]+1]) == 0) {
      return 0;
    }
    tiles.push_back(position[0] + 1);
    tiles.push_back(position[1] + 1);
    int incrementor = 2;
    while ((position[0] + incrementor) <= (size - 1) && (position[1] + incrementor) <= (size - 1)) {
      if (board[position[0] + incrementor][position[1] + incrementor] == player) {
        flip_tiles.push_back(tiles);        
        return 1;
      }
      else if (board[position[0] + incrementor][position[1] + incrementor] == 0) {
        return 0;
      }
      else{
        tiles.push_back(position[0] + incrementor);
        tiles.push_back(position[1] + incrementor);
      }
      incrementor++;
    }
  }
  return 0;
}

// Returns a vector of integer vectors variable, which stores the tiles flipped from the above functions
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
