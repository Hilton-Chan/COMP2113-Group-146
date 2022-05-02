#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "isValidMove.h"

using namespace std;

//row = vertical, col = horizontal
//checks for x direction of where tile is placed
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
        break;
      }
      else{
        tiles.push_back(position[0]);
        tiles.push_back(i);
      }
    }
  }
  return 0;
}

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
        break;
      }
      else{
        tiles.push_back(position[0]);
        tiles.push_back(position[i]);
      }
    }
  }
  return 0;
}

bool verticalUpwardCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  
  if (position[0] >= 2) {
    if ((board[position[0]-1][position[1]]) == player || (board[position[0]-1][position[1]]) == 0) {
        return 0;
    }
    tiles.push_back(position[0] - 1);
    tiles.push_back(position[1]);
    for (int i=position[0] - 2;i<=0; i--) {
      if (board[i][position[1]] == player) {
        flip_tiles.push_back(tiles);
        return 1;
      }
      else if(board[position[i]][1] == 0) {
        break;
      }
      else{
        tiles.push_back(i);
        tiles.push_back(position[1]);
      }
    }
  }
  return 0;
}

bool verticalDownwardCheck(vector < vector<int> > board, int position[], int player, vector < vector<int> > &flip_tiles) {
  vector<int> tiles;
  int size = board.size();
  if (position[0] <= (size - 3)) {
    if ((board[position[0]+1][position[1]]) == player || (board[position[0]+1][position[1]]) == 0) {
        return 0;
    }
    tiles.push_back(position[0]);
    tiles.push_back(position[1] + 1);
    for (int i=position[0] + 2;i<=(size - 1); i++) {
      if (board[i][position[1]] == player) {
        flip_tiles.push_back(tiles);
        return 1;
      }
      else if(board[position[i]][1] == 0) {
        break;
      }
      else{
        tiles.push_back(i);
        tiles.push_back(position[1]);
      }
    }
  }
  return 0;
}

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
    while (position[0] != 0 && position[1] != 0) {
      if (board[position[0] - incrementor][position[1] - incrementor] == player) {
        flip_tiles.push_back(tiles);
        return 1;
      }
      else if(board[position[0] - incrementor][position[1] - incrementor] == 0) {
        break;
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
    while (position[0] != 0 && position[1] != (size - 3)) {
      if (board[position[0] - incrementor][position[1] + incrementor] == player) {
        flip_tiles.push_back(tiles);        
        return 1;
      }
      else if(board[position[0] - incrementor][position[1] + incrementor] == 0) {
        break;
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
    while (position[0] != (size - 3) && position[1] != 0) {
      if (board[position[0] + incrementor][position[1] - incrementor] == player) {
        flip_tiles.push_back(tiles);        
        return 1;
      }
      else if(board[position[0] + incrementor][position[1] - incrementor] == 0) {
        break;
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
    while (position[0] != (size - 3) && position[1] != (size - 3)) {
      if (board[position[0] + incrementor][position[1] + incrementor] == player) {
        flip_tiles.push_back(tiles);        
        return 1;
      }
      else if(board[position[0] + incrementor][position[1] + incrementor] == 0) {
        break;
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

  cout << (flip_tiles.size()) << endl;
  return flip_tiles;
}
