#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "interface.h"

using namespace std;
string upper_left_corner = "\u2554";
string upper_right_corner = "\u2557";
string bottom_left_corner = "\u255A";
string bottom_right_corner = "\u255D";
string horizontal = "\u2550";
string vertical = "\u2551";
string divider = "\u2503";

string BLACK_UI = "\u25CB";
string WHITE_UI = "\u25CF";

void printTitle(){
  cout << upper_left_corner << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << upper_right_corner << "\n";
  cout << vertical << " OTHELLO " << BLACK_UI << WHITE_UI << vertical << "\n";
  cout << bottom_left_corner << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << bottom_right_corner << "\n";
}

// Prints description of hotkeys, player turn, displays if hints are enabled/disabled
// and tallies of total WHITE_UI and BLACK_UI pieces on the current board
void printScoreBoard(vector < vector<int> > board, int player_turn, bool show_hint_flag){
  cout << vertical << " HOTKEYS:" << "\n";
  cout << vertical << " \"s\" - save game file\n";
  cout << vertical << " \"l\" - load recently saved game file\n";
  cout << vertical << " \"u\" - undo last move\n";
  cout << vertical << " \"h\" - display/hide hints on board\n";
  cout << setw(40) << setfill('-') << "\n";

  // If playing against bot, display text should only be for Player 1
  if(player_turn == -1){
    cout << "PLayer 1's Turn. ";
  }
  else{
    cout << "Player " << player_turn << "'s Turn. ";
  }
  
  if(player_turn == -1 && show_hint_flag == 1){
    cout << "Hints enabled for Player 1\n";
  }
  else if(player_turn == -1 && show_hint_flag == 0){
    cout << "Hints disabled for Player 1\n";
  }
  else if(show_hint_flag == 1){
    cout << "Hints enabled for Player " << player_turn << "\n";
  }
  else if(show_hint_flag == 0){
    cout << "Hints disabled for Player " << player_turn << "\n";
  }

  int WHITE_UI, BLACK_UI;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(board[i][j] == 1){
        WHITE_UI++;
      }
      else if(board[i][j] == 2){
        BLACK_UI++;
      }
    }
  }
  cout << "WHITE " << WHITE_UI << ": x" << WHITE_UI << " " << divider << " BLACK "<< BLACK_UI << ": x" << BLACK_UI << "\n";
}

// writing board state into file
void saveFile(vector < vector<int> > board, int player_turn){
  // new line, to print below the board
  ofstream fout("gamefile.txt");
  if(fout.fail()){
    cout << "Error in file opening!";
    exit(1);
  }
  // writing player_turn as first line;
  fout << player_turn << "\n";
  // writing out each line of board into the file
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      fout << board[i][j] << " ";
    }
    fout << "\n";
  }

  fout.close();
  cout << "File saved successfully\n";
}

// reading board state from file
void loadFile(vector < vector<int> > &board, int &player_turn){
  ifstream fin("gamefile.txt");
  if(fin.fail()){
    cout << "Error in file opening!";
    exit(1);
  }

  fin >> player_turn;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      fin >> board[i][j];
    }
  }

  fin.close();
  cout << "File loaded successfully\n";
}

int countTotalPieces(vector < vector<int> > board, int player) {
  int size = board.size();
  int counter = 0;
  for (int row=0; row<size; row++) {
    for (int col=0; col<size; col++) {
      if (board[row][col] == player) {
        counter++;
      }
    }
  }
  return counter;
}

void printFinalScore(vector < vector<int> > board, int player_turn){
  int WHITE_UI = countTotalPieces(board, 2);
  int BLACK_UI = countTotalPieces(board, 1);

  cout << upper_left_corner << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << upper_right_corner << "\n";
  cout << vertical << " FINAL SCORE " << vertical << "\n";
  cout << bottom_left_corner << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << bottom_right_corner << "\n";

  if(player_turn == -1){
    cout << "Player 1 - " << BLACK_UI << " points. Bot - " << WHITE_UI << " points.\n";
    if(WHITE_UI > BLACK_UI){
    cout << "Bot beat Player 1 by " << WHITE_UI - BLACK_UI << " points.\n";
    }
    else if(BLACK_UI > WHITE_UI){
      cout << "Player 1 beat the Bot by" << BLACK_UI - WHITE_UI << " points.\n";
    }
    else{
      cout << "Player 1 and Bot tied.\n";
    }
  }
  else{
    cout << "Player 1 - " << BLACK_UI << " points. Player 2 - " << WHITE_UI << " points.\n";
    if(WHITE_UI > BLACK_UI){
    cout << "Player 2 beat Player 1 by " << WHITE_UI - BLACK_UI << " points.\n";
    }
    else if(BLACK_UI > WHITE_UI){
      cout << "Player 1 beat Player 2 by" << BLACK_UI - WHITE_UI << " points.\n";
    }
    else{
      cout << "Player 1 and Player 2 tied.\n";
    }
  }

  //cout << "Would you like to play again? (Y/N)\n";
  //cin >> replay;
  //while(replay != 'Y' && replay != 'N'){
  //  cout >> "Invalid choice. Input 'Y' or 'N': ";
  //}
}