#include <iostream>
#include <string>
#include <stdio.h>


bool horizontalLeftCheck(int board[][8], int position[], int player) {
  if (position[1] >= 2) {
    if ((board[position[0]][position[1]-1]) == player) {
        return 0;
    }
    for (int i=(position[0] - 2);i>=0; i--) {
      if (board[position[0]][i] == player) {
        return 1;
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
    for (int i=(position[0] + 2);i<=7; i++) {
      if (board[position[0]][i] == player) {
        return 1;
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
    for (int i=(position[1] - 2);i<=0; i--) {
      if (board[i][position[1]] == player) {
        return 1;
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
    for (int i=(position[1] + 2);i<=7; i++) {
      if (board[i][position[1]] == player) {
        return 1;
      }
    }
  }
  return 0;
}

bool diagonalLeftUpCheck(int board[][8], int position[], int player) {
  if (position[0] >= 2 && position[0] >= 2) {
    if ((board[position[0]-1][position[1]-1]) == player) {
      return 0;
    }
    for (int i=((position[0] + position[1]) / 2);i<=0; i++) {
      if (board[position[0]-i][position[1]-i] == player) {
        return 1;
      }
    }
  }
  return 0;
}

bool diagonalRightUpCheck(int board[][8], int position[], int player) {
  if (position[0] >= 2 && position[0] <= 5) {
    if ((board[position[0]+1][position[1]-1]) == player) {
      return 0;
    }
    for (int i=((position[0] + position[1]) / 2);i<=0; i++) {
      if (board[position[0]+i][position[1]-i] == player) {
        return 1;
      }
    }
  }
  return 0;
}

bool diagonalLeftDownCheck(int board[][8], int position[], int player) {
  if (position[0] <= 5 && position[0] >= 2) {
    if ((board[position[0]-1][position[1]+1]) == player) {
      return 0;
    }
    for (int i=((position[0] + position[1]) / 2);i<=0; i++) {
      if (board[position[0]-i][position[1]+i] == player) {
        return 1;
      }
    }
  }
  return 0;
}

bool diagonalRightDownCheck(int board[][8], int position[], int player) {
  if (position[0] <= 5 && position[0] <= 5) {
    if ((board[position[0]+1][position[1]+1]) == player) {
      return 0;
    }
    for (int i=((position[0] + position[1]) / 2);i<=0; i++) {
      if (board[position[0]+i][position[1]+i] == player) {
        return 1;
      }
    }
  }
  return 0;
}

// input: board[row][col]
//        position: [row, col]
//        player: 1: black, 2: white

bool isValidMove(int board[], int position[], int player) {
  if (horizontalLeftCheck || horizontalRightCheck || verticalUpwardCheck || 
    verticalDownwardCheck || diagonalLeftUpCheck || diagonalRightUpCheck || 
    diagonalLeftDownCheck || diagonalRightDownCheck) {
    return 1;
  }
  return 0;
}
