#ifndef OTHELLOBOARD_H
#define OTHELLOBOARD_H

#include <vector>

using namespace std;

bool boardEmpty(vector < vector<int> > board);
vector < vector<int> > boardInitalize(int size);
void printBoard(vector < vector<int> > board);
void showPossibleMoves(vector < vector<int> > board, vector < vector<int> > validMovesArr);
#endif