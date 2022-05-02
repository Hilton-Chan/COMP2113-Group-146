#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>

using namespace std;

void loadFile(vector < vector<int> > &board, int &player_turn);
void saveFile(vector < vector<int> > board, int player_turn);
void printScoreBoard(vector < vector<int> > board, int player_turn, bool show_hint_flag);
void printTitle();
void printFinalScore(vector < vector<int> > board, int player_turn);

#endif