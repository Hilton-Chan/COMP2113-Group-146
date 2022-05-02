#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "isValidMove.h"
#include "listAllValidMoves.h"
#include "othelloboard.h"
#include "interface.h"

using namespace std;

const string alphabet = "ABCDEFGH";

// True/false values should be swapped
// Also, isdigit will always be false because we are passing a string?
// Don't need .length(), as there won't be two digit numbers with 8x8 board
bool isNumber(string s) {
  for (int i=0; i<s.length(); i++) {
    if (isdigit(s[i]) == 0) {
      return 0;
    }
  }
  return 1;
}


void printPage(vector < vector<int> > board, int player, bool hint) {
  system("cls");
  printScoreBoard(board, player, hint);
  printBoard(board);
}

void printPageWithHints(vector < vector<int> > board, int player, bool hint) {
  system("cls");
  printScoreBoard(board, player, hint);
  vector < vector<int> > validMovesArr = findAllPossibleMoves(board, player);
  showPossibleMoves(board, validMovesArr);
}

//Checks for valid move, with format A1 - H8
bool validMoveInput(string input) {
  if (input.length() != 2) {
    return 0;
  }
  if (isNumber(input.substr(1)) && alphabet.find(input[0]) != -1) {
    if (stoi(input.substr(1)) <= 8) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // standard Othello board size 8x8
  int size = 8;
  vector < vector<int> > board = boardInitalize(size);
  int player_turn = 1;

  printTitle();
  string loadFlag;
  cout << "Loading from saved game file?\n";
  cout << "Input 'Y' to load, or 'N' to play a new game: ";
  while(loadFlag != "Y" && loadFlag != "N"){
    cin >> loadFlag;
    if(loadFlag == "Y"){
      loadFile(board, player_turn);
    }
    else if(loadFlag == "N"){
      break;
    }
    else{
      cout << "Input 'Y' to load, or 'N' to play a new game: ";
    }
  }

  bool show_hint_flag = 0;
  bool undoFlag = 0;
  bool invalid_move_flag = 0;
  bool bot_flag = 0;
  int bot_move[2] ={};

  system("cls");
  while (boardEmpty(board)) {
    printScoreBoard(board, player_turn, show_hint_flag);
    printBoard(board);

    if(invalid_move_flag){
      cout << "Invalid move. Please input a move from A1 to H8:\n";
    }
    else if(bot_flag){
      cout << "\nBot played " << alphabet[bot_move[0]] << bot_move[1] + 1 << "\n";
    }
    string userInput;
    cin >> userInput;

    if (userInput == "s") {
        saveFile(board, player_turn);
    } else if (userInput == "l") {
        loadFile(board, player_turn);
    } else if (userInput == "h" && show_hint_flag == 0) { // show move key
        show_hint_flag = 1;
        printPageWithHints(board, player_turn, show_hint_flag);
    } else if (userInput == "h" && show_hint_flag == 1) {
        show_hint_flag = 0;
        printPage(board, player_turn, show_hint_flag);
    } else if (validMoveInput(userInput)) {
        int row = alphabet.find(userInput[0]);
        int col = stoi(userInput.substr(1)) - 1;
        int position[2] = {row, col};
        vector<vector<int> > flip_tiles = isValidMove(board, position, player_turn);
        if (flip_tiles.empty()) {
            invalid_move_flag = 1;
        } else {
            makeMove(board, row, col, 1);
            flip_tiles.clear();
            invalid_move_flag = 0;
            cout << "\nPlayer 1 played " << alphabet[row] << col + 1 << ":\n";
            printBoard(board);
            cout << "\n";
        }
    } 

    if(invalid_move_flag == 0){
      vector < vector<int> > botMoves = findAllPossibleMoves(board, 2);
      if (!noPossibleMoves(botMoves)) {
          int bot_position[2] = { };
          botMove(board, bot_position, botMoves, 2);

          bot_flag = 1;
          bot_move[0] = bot_position[0];
          bot_move[1] = bot_position[1];
      } else {
          cout << "No Possible Moves can be made by Bot" << endl;
          // add more text
      }
      botMoves.clear();
    }
  }
  // Game Ends here
  // Print out scoreboard and asks if player wants to replay again (?)
  system("cls");
  printFinalScore(board, player_turn);
}
