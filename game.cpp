#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

const string alphabet = "ABCDEFGH";


bool boardEmpty(vector < vector<int> > board);
vector < vector<int> > boardInitalize(int size);
void printBoard(vector < vector<int> > board);
void showPossibleMoves(vector < vector<int> > board, vector < vector<int> > validMovesArr);
vector < vector<int> > findAllPossibleMoves(vector < vector<int> > board, int player);
vector < vector<int> > isValidMove(vector < vector<int> > board, int position[], int player);
void makeMove(vector < vector<int> > board, int position[], int player);
int* botMove(vector < vector<int> > board, vector < vector<int> > validMovesArr, int player);
bool noPossibleMoves(vector < vector<int> > validMovesArr);

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
  system("CLS");
  printScoreBoard(board, player, hint);
  printBoard(board);
}

void printPageWithHints(vector < vector<int> > board, int player, bool hint) {
  system("CLS");
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
  vector < vector<int> > board;
  string sizeInput;
  // standard Othello board size 8x8
  int size = 8;
  boardInitalize(size);

  string player_choice;
  int player_turn;
  // Pick Vs. Bot or Player
  // chcp 65001 - Display utf characters
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

  // If playing a new game, user picks to play against Bot or Player
  if(loadFlag == "N"){
    cout << "Playing against Bot, or Player vs Player?\n";
    cout << "Input '1' for Bot, '2' for Player:";
    while(player_choice != "1" && player_choice != "2"){
      cin >> player_choice;
      if (player_choice == "1") {
        player_turn = -1;
      } else if(player_choice == "2") {
        player_turn = 1;
      }
      else{
        cout << "Input 1 for Bot, 2 for Player:";
      }
    }
  }
  
  system("CLS");
  bool show_hint_flag = 0;
  bool bot_next_flag = 0;
  bool undoFlag = 0;
  printScoreBoard(board, player_turn, show_hint_flag);
  printBoard(board);


  while (boardEmpty(board)) {
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
        int col = stoi(userInput.substr(1));
        int position[2] = {row, col};
        vector<vector<int> > flip_tiles = isValidMove(board, position, player_turn);
        if (flip_tiles.empty()) {
            cout << "Invalid Move" << endl;
        } else {
            if (player_turn == 1) {
                makeMove(board, position, player_turn);
                player_turn = 2;
            } else if (player_turn == 2) {
                makeMove(board, position, player_turn);
                player_turn = 1;
            } else {
                makeMove(board, position, 1);
                bot_next_flag = 1;
            }
            flip_tiles.clear();
        }
    } 

    if (bot_next_flag && player_turn == -1) {
      vector < vector<int> > botMoves = findAllPossibleMoves(board, 2);
      if (!noPossibleMoves(botMoves)) {
          int* bot_position = botMove(board, botMoves, 2);
      } else {
          cout << "No Possible Moves can be made by Bot" << endl;
          // add more text
      }
      bot_next_flag = 0;
      botMoves.clear();
    }
    if (player_turn == 1 || player_turn == 2) {
      vector < vector<int> > nextMoves = findAllPossibleMoves(board, player_turn);
      if (noPossibleMoves(nextMoves)) {
        cout << "No Possible Moves can be made by Player " << player_turn << endl;
        if (player_turn == 1) {
            player_turn = 2;
        } else {
            player_turn = 1;
        }
      }
    }
  }

  // Game Ends here
  // Print out scoreboard and asks if player wants to replay again (?)
  system("CLS");
  printFinalScore(board, player_turn);
}
