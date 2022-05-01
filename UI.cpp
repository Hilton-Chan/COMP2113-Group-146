#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;
string upper_left_corner = "\u2554";
string upper_right_corner = "\u2557";
string bottom_left_corner = "\u255A";
string bottom_right_corner = "\u255D";
string horizontal = "\u2550";
string vertical = "\u2551";
string divider = "\u2503";

string BLACK = "\u25CB";
string WHITE = "\u25CF";

void printTitle(){
  cout << upper_left_corner << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << upper_right_corner << "\n";
  cout << vertical << " OTHELLO " << BLACK << WHITE << vertical << "\n";
  cout << bottom_left_corner << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << bottom_right_corner << "\n";
}

// Prints description of hotkeys, player turn, displays if hints are enabled/disabled
// and tallies of total white and black pieces on the current board
void printScoreBoard(vector < vector<int> > board, int player_turn, bool show_hint_flag){
  cout << vertical << " HOTKEYS:" << "\n";
  cout << vertical << " \"s\" - save/load files\n";
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

  int white, black;
  for(int i = 0; i < 8; i++){
    for(int j = 0; i < 8; i++){
      if(board[i][j] == 1){
        white++;
      }
      else if(board[i][j] == 2){
        black++;
      }
    }
  }
  cout << "White " << WHITE << ": x" << white << " " << divider << " Black "<< BLACK << ": x" << black << "\n";
}

//save files - file input / output?