#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "isValidMove.h"
#include "listAllValidMoves.h"
#include "othelloBoard.h"
#include "interface.h"

using namespace std;

const string alphabet = "ABCDEFGH";

// returns true if string passed is a string of numbers
bool isNumber(string s) {
  for (int i=0; i<s.length(); i++) {
    if (isdigit(s[i]) == 0) {
      return 0;
    }
  }
  return 1;
}

// prints the scoreboard and the board
void printPage(vector < vector<int> > board, int player, bool hint) {
  system("clear");
  printScoreBoard(board, player, hint);
  printBoard(board);
}

// prints the scoreboard and the board with hints
void printPageWithHints(vector < vector<int> > board, int player, bool hint) {
  system("clear");
  printScoreBoard(board, player, hint);
  vector < vector<int> > validMovesArr = findAllPossibleMoves(board, player);
  showPossibleMoves(board, validMovesArr);
}

// checks for valid move, with format A1 - H8
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
  // asks if the player wants to load a game file, or start a new game
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

  bool save_flag = 0;
  bool load_flag = 0;
  bool hint_flag = 0;
  bool log_flag = 0;
  bool invalid_move_flag = 0;
  bool show_hint_flag = 0;
  bool skip_player_flag = 0;
  bool bot_flag = 0;
  int bot_move[2] ={};
  string log = "\nPrevious player and bot moves:\n";
  int log_counter = 1;
  
  system("clear");
  while (boardEmpty(board)) {
    hint_flag = 0;
    if(show_hint_flag){
      printPageWithHints(board, player_turn, show_hint_flag);
    }
    else{
      printPage(board, player_turn, show_hint_flag);
    }

    vector < vector<int> > player1moves = findAllPossibleMoves(board, 1);
    vector < vector<int> > botmoves = findAllPossibleMoves(board, 2);
    // display text if no possible moves can be made from both sides, or either the player
    // or bot have no possible moves
    if (noPossibleMoves(player1moves) && noPossibleMoves(botmoves)) {
      cout << "No possible moves can be made from both sides. Game ends" << endl;
      break;
    } else if (noPossibleMoves(player1moves)) {
      skip_player_flag = 1;
      cout << "No possible moves can be made by player. Bot's Turn" << endl;
    } else if (noPossibleMoves(botmoves)) {
      cout << "No possible moves can be made by Bot. Player's Turn" << endl;
    }

    // skip the player's turn if they have no possible moves
    if (!skip_player_flag) {
      // display text if player successfully saved their file
      if(save_flag){
        cout << "File saved successfully\n";
        save_flag = 0;
      }
      // display text if successfully loaded their file
      else if(load_flag){
        cout << "File loaded successfully\n";
        load_flag = 0;
        bot_flag = 0;
      }
      // display log of previous player moves, if hotkey was pressed
      if(log_flag){
        cout << log;
        log_flag = 0;
      }
      // display text if user has inputted an invalid move
      if(invalid_move_flag){
        cout << "Invalid move. Please input a move from A1 to H8:\n";
        invalid_move_flag = 0;
      }
      // display bot move if the player has already made a move
      else if(bot_flag){
        cout << "\nBot played " << alphabet[bot_move[0]] << bot_move[1] + 1 << "\n";
      }
      cout << "Please input hotkey or next move:\n";
      string userInput;
      cin >> userInput;

      // hotkey "s" - save game file
      if (userInput == "s") {
          saveFile(board, player_turn);
          save_flag = 1;
      // hotkey "l" - load game file
      } else if (userInput == "l") {
          loadFile(board, player_turn);
          load_flag = 1;
          log = "Previous player and bot moves:\n";
          log_counter = 1;
      // hotkey "h" - display hints on board
      } else if (userInput == "h" && show_hint_flag == 0) { // show move key
          show_hint_flag = 1;
          hint_flag = 1;
      // hotkey "h" - hide hints on board
      } else if (userInput == "h" && show_hint_flag == 1) {
          show_hint_flag = 0;
          hint_flag = 1;
      // hotkey "p" - view log of previous moves
      } else if (userInput == "p"){
          log_flag = 1;
      // checks if userInput fits format of A1 - H8
      }  else if (validMoveInput(userInput)) {
          int row = alphabet.find(userInput[0]);
          int col = stoi(userInput.substr(1)) - 1;
          int position[2] = {row, col};
          vector<vector<int> > flip_tiles = isValidMove(board, position, player_turn);
          // if there are no tiles to flip, the move is invalid
          if (flip_tiles.empty()) {
              invalid_move_flag = 1;
          // else, let the player make their move
          } else {
              makeMove(board, row, col, 1);
              flip_tiles.clear();
              // adding player moves to log
              log += to_string(log_counter) + ": Player played " + alphabet[row] + to_string(col + 1) + "\n";
              log_counter++;
              log_flag = 0;
          }
      } else {
        cout << "Invalid Input. Please input a move from A1 to H8:\n";
        invalid_move_flag = 1;
      }
    }
    
    // if no hotkeys have been pressed, and the input is a valid move, let the Bot make its move
    if(!save_flag && !load_flag && !hint_flag && !log_flag && !invalid_move_flag){
      if (skip_player_flag) {
        skip_player_flag = 0;
      }
      vector < vector<int> > botMoves = findAllPossibleMoves(board, 2);
      // skip the bot's turn if it has no possible move
      if (!noPossibleMoves(botMoves)) {
          int bot_position[2] = { };
          botMove(board, bot_position, botMoves, 2);

          bot_flag = 1;
          bot_move[0] = bot_position[0];
          bot_move[1] = bot_position[1];
          //adding bot move to log
          log += string("   Bot played ") + alphabet[bot_move[0]] + to_string(bot_move[1] + 1) + "\n";
      } else {
          cout << "No possible moves can be made by bot 1. Player's Turn" << endl;
      }
      botMoves.clear();
    }
  }

  // Game Ends
  // Prints out final scoreboard of Player and Bot scores, and whether there was a win/loss or draw
  system("clear");
  printFinalScore(board, player_turn);
}
